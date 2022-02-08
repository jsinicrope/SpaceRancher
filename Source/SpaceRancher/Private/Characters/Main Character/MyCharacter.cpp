// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/MyCharacter.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/InteractInterface.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Interfaces/Equippable.h"
#include "World/Saves/ActorRecord.h"
#include "World/Saves/ActorSaveArchive.h"
#include "UI/HUDSetting.h"
#include "Kismet/GameplayStatics.h"
#include "UI/CMainHUD.h"
#include "UI/ItemSelectionHUD.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	AddOwnedComponent(InventoryComp);
	
	HUDController = CreateDefaultSubobject<UHUDSetting>(TEXT("HUD Settings"));
	AddOwnedComponent(HUDController);
	
	// Setup Player Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	AddOwnedComponent(SpringArm);

	SpringArm->SetRelativeLocation(FVector(17, 0, 68));
	SpringArm->TargetArmLength = 0.0f;
	SpringArm->bUsePawnControlRotation = false;
	
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	AddOwnedComponent(PlayerCamera);

	PlayerCamera->bUsePawnControlRotation = true;
	
	SpringArm->SetupAttachment(RootComponent);
	PlayerCamera->SetupAttachment(SpringArm);
	
	WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteraction"));
	AddOwnedComponent(WidgetInteractionComponent);

	WidgetInteractionComponent->SetupAttachment(PlayerCamera);

	MiniMapCamera = CreateDefaultSubobject<UChildActorComponent>(TEXT("MiniMapCamera"));
	MiniMapCamera->SetupAttachment(RootComponent);

	MiniMapCamera->SetRelativeLocation(FVector(0, 0, 10000));
	MiniMapCamera->SetRelativeRotation(FRotator(270, 0, 0));

	HandItem = CreateDefaultSubobject<UChildActorComponent>(TEXT("RightHandItem"));
	HandItem->SetupAttachment(GetMesh(), "hand_rSocket");
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	// Setup the MiniMap Camera capturing
	MiniMapCamera->SetRelativeLocation(FVector(0, 0, 10000));
	MiniMapCamera->SetRelativeRotation(FRotator(270, 0, 0));
	MiniMapCapture = Cast<ASceneCapture2D>(MiniMapCamera->GetChildActor());
	checkf(MiniMapCapture, TEXT("MiniMap Camera not set to SceneCapture2D in Player Character"));
	MiniMapCapture->GetCaptureComponent2D()->OrthoWidth = DefaultMiniMapSize;
	MiniMapCapture->GetCaptureComponent2D()->HiddenActors.Add(this);
	ZoomMiniMap(ZoomLevel);
	
	RespawnPoint = GetActorLocation();
	RespawnViewDirection = GetControlRotation();
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ElapsedDamageTime += DeltaTime;
	ElapsedStaminaDrainTime += DeltaTime;

	// Heal Player slowly up to MaxRegeneratedHealth if no damage was received in the last 'TimeToHealthRegen' seconds
	{
		if (HealthLastTick > Health)
			ElapsedDamageTime = 0.0f;
		
		HealthLastTick = Health;

		if ((ElapsedDamageTime >= TimeToHealthRegen) && (Health < MaxRegeneratableHealth))
		{
			Health = fmin(MaxHealth, Health + HealthRegenRate * DeltaTime);
		}
	}

	// Drain Stamina if Sprinting and not in Air after 'TimeToStaminaRegen'
	{
		if (GetCharacterMovement()->IsMovingOnGround())
		{
			if (bSprinting && GetMovementComponent()->GetLastInputVector().Size() > 0)
			{
				Stamina -= StaminaLossRunning * DeltaTime;
				ElapsedStaminaDrainTime = 0.0f;
			}
			// Regen Stamina
			else if (ElapsedStaminaDrainTime >= TimeToStaminaRegen)
			{
				Stamina = fmin(MaxStamina, Stamina + StaminaRegenRate * DeltaTime);
			}
		}
	}

	{
		if (Stamina <= 0)
			PlayerStopSprint();
	}

	// Call Pop Up for Interaction if Interactable actor is hit
	{
		if (CheckForInteractable() && !SelectedItem.ItemClass->ImplementsInterface(UEquippable::StaticClass()))
		{
			HUDController->ShowInteractPopUp();
		}
		else
		{
			HUDController->HideInteractPopUp();
		}
	}

	// Check for Fall Damage
	{
		if (GetCharacterMovement()->IsFalling())
		{
			if (GetCharacterMovement()->GetLastUpdateVelocity().Z < 0.0f)
			{
				FallingTime += DeltaTime;
			}
		}

		if (!GetCharacterMovement()->IsFalling() && FallingTime > 0.0f)
		{
			// Calculate Landing Velocity
			// 2 * acceleration * delta time = velocity
			const float FallSpeed = 9.81 * FallingTime;

			FallingTime = 0.0f;

			if (FallSpeed >= MinFallDamageVelocity)
			{
				Health -= FMath::Pow(FallSpeed - MinFallDamageVelocity, FallDamageFactor);
			}
		}
	}

	// Kill Player if Health 0
	{
		if (Health <= 0.0f)
		{
			KillPlayer();
		}
		else
		{
			bPlayerDead = false;
		}
	}

	CurrentVelocity = GetCharacterMovement()->Velocity;
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::PlayerStartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::PlayerStopSprint);

	PlayerInputComponent->BindAction("Interact", IE_Released, this, &AMyCharacter::PlayerInteract);
	PlayerInputComponent->BindAction("Inventory", IE_Released, this, &AMyCharacter::ToggleInventory);
	PlayerInputComponent->BindAction("ItemSelection", IE_Pressed, this, &AMyCharacter::OpenRadialMenu);
	PlayerInputComponent->BindAction("ItemSelection", IE_Released, this, &AMyCharacter::CloseRadialMenu);

	PlayerInputComponent->BindAction("MapZoomIn", IE_Released, this, &AMyCharacter::ZoomMiniMapIn);
	PlayerInputComponent->BindAction("MapZoomOut", IE_Released, this, &AMyCharacter::ZoomMiniMapOut);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
}

void AMyCharacter::PlayerInteract()
{
	bInventoryOpen = InventoryComp->GetInventoryOpen();
	if (!bInventoryOpen && HUDController->MainHUD->GetInventoryWidgetsOnScreenScreen() <= 0)
	{
		const FHitResult OutHit = LineTraceFromView(InteractDistance);
		if (OutHit.GetActor())
		{
			AActor* Actor = OutHit.GetActor();

			if (Actor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
			{
				if (SelectedItem.bValidItem)
				{
					if (IInteractInterface::Execute_ItemInteract(Actor, SelectedItem))
					{
						RemoveInventoryItem(SelectedItem);
						UpdateSelectedItem();
					}
				}
				else
				{
					IInteractInterface::Execute_Interact(Actor);
				}
			}
		}
	}
	else
	{
		ToggleInventory();
	}
}

void AMyCharacter::KillPlayer()
{
	bPlayerDead = true;
	RespawnPlayer();
}

void AMyCharacter::RespawnPlayer()
{
	PC->LoadGame();
}

void AMyCharacter::DamagePlayer(float Damage)
{
	Health = FMath::Max(Health - Damage, 0.0f);

	if (Health <= 0.0f)
	{
		KillPlayer();
	}
}

bool AMyCharacter::GetIsPlayerDead()
{
	return bPlayerDead;
}

void AMyCharacter::Save()
{
	UMainSaveGame* SaveData = GameInstance->GetSaveGameData();
	SaveData->Player_Inventory_Array_Columns = InventoryComp->Inventory_Array_Columns;

	FActorRecord PlayerRecord(this);
	FMemoryWriter MemoryWriterPlayer(PlayerRecord.Data, true);
	FActorSaveArchive PlayerAr(MemoryWriterPlayer, false);
	MemoryWriterPlayer.SetIsSaving(true);
	Serialize(PlayerAr);
	GameInstance->GetSaveGameData()->PlayerCharacterData = PlayerRecord;
}

void AMyCharacter::Load()
{
	UMainSaveGame* SaveData = GameInstance->GetSaveGameData();
	InventoryComp->Inventory_Array_Columns = SaveData->Player_Inventory_Array_Columns;

	// De-Serialize
	FActorRecord ActorRecord = SaveData->PlayerCharacterData;
	FMemoryReader MemoryReader(ActorRecord.Data);
	FActorSaveArchive Ar(MemoryReader, false);
	MemoryReader.SetIsLoading(true);
	Serialize(Ar);
	const FVector SpawnLocation = ActorRecord.Transform.GetLocation();
	const FRotator SpawnRotation = ActorRecord.Transform.GetRotation().Rotator();
	GetWorld()->GetFirstPlayerController()->GetPawn()->TeleportTo(SpawnLocation, RespawnViewDirection, false, true);
	GetWorld()->GetFirstPlayerController()->SetControlRotation(SpawnRotation);
	GetCharacterMovement()->Velocity = CurrentVelocity;
}

void AMyCharacter::MoveForward(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMyCharacter::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AMyCharacter::LookUpAtRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpAtRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnAtRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::ZoomMiniMap(const int Level)
{
	ZoomLevel = Level < 0 ? 0 : Level;
	ZoomLevel = Level > MaxZoomLevel ? MaxZoomLevel : ZoomLevel;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString::FromInt(ZoomLevel));
	MiniMapCapture->GetCaptureComponent2D()->OrthoWidth = DefaultMiniMapSize + ZoomLevel * ZoomSize;
	MiniMapCapture->GetCaptureComponent2D()->CaptureScene(); 
}

void AMyCharacter::ZoomMiniMapIn()
{
	ZoomMiniMap(ZoomLevel - 1);
}

void AMyCharacter::ZoomMiniMapOut()
{
	ZoomMiniMap(ZoomLevel + 1);
}

void AMyCharacter::PlayerStartSprint()
{
	if ((Stamina > 10) && (GetCharacterMovement()->IsMovingOnGround()))
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		bSprinting = true;
	}
}

void AMyCharacter::PlayerStopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bSprinting = false;
}

bool AMyCharacter::AddInventoryItem(FItem_Struct &Item_Struct)
{
	const bool bAddSuccessful = InventoryComp->AddItem(Item_Struct);

	if (bAddSuccessful)
	{
		HUDController->ItemPickUpWidget->UpdateWidget(Item_Struct.Thumbnail, Item_Struct.Name);

		if (HUDController->ItemPickUpWidget->IsInViewport())
			HUDController->ItemPickUpWidget->RemoveFromViewport();

		HUDController->ItemPickUpWidget->AddToViewport();
		WidgetToRemove = HUDController->ItemPickUpWidget;
		GetWorldTimerManager().SetTimer(TimerHandler, this, &AMyCharacter::RemoveWidgetFromViewport, 2.0f, false, 2.0f);
	}
	return bAddSuccessful;
}

FItem_Struct AMyCharacter::RemoveInventoryItem(FItem_Struct &Item)
{
	FItem_Struct RemovedItem = InventoryComp->RemoveItem(Item);
	return RemovedItem;
}

FItem_Struct AMyCharacter::RemoveInventoryItemByName(FString ItemName)
{
	FItem_Struct RemovedItem = InventoryComp->RemoveItemByName(ItemName);
	return RemovedItem;
}

void AMyCharacter::ToggleInventory()
{
	if (bItemSelectionOpen)
		return;
	InventoryComp->ToggleInventory();
	bInventoryOpen = InventoryComp->GetInventoryOpen();
	if (!bInventoryOpen)
	{
		HUDController->MainHUD->RemoveAllInventoryWidgets();
	}
}

void AMyCharacter::OpenRadialMenu()
{
	if (!bItemSelectionOpen && !InventoryComp->GetInventoryOpen())
	{
		TArray<FItem_Struct> Selectables = InventoryComp->GetUniqueSelectables();
		HUDController->OpenRadialMenu(Selectables);
		bItemSelectionOpen = true;
	}
}

void AMyCharacter::CloseRadialMenu()
{
	if (bItemSelectionOpen)
	{
		HUDController->CloseRadialMenu();
		UpdateSelectedItem();
	}
}

void AMyCharacter::PrimaryActionPressed_Implementation()
{
	WidgetInteractionComponent->PressPointerKey(FKey(FName("LeftMouseButton")));
	
	if (HeldItem)
	{
		IEquippable::Execute_Activated(HeldItem);
	}
}

void AMyCharacter::PrimaryActionReleased_Implementation()
{
	WidgetInteractionComponent->ReleasePointerKey(FKey(FName("LeftMouseButton")));

	if (HeldItem)
	{
		IEquippable::Execute_Deactivated(HeldItem);
	}
}

void AMyCharacter::UpdateSelectedItem()
{
	const FItem_Struct ActiveItem = HUDController->RadialMenu->GetSelectedItem();
	SelectedItem = InventoryComp->Contains(ActiveItem) ? ActiveItem : FItem_Struct();
	
	bItemSelectionOpen = false;
	if (SelectedItem.bSelectable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, FString("Selected Item: ") + SelectedItem.Name);
		if (SelectedItem.ItemClass->ImplementsInterface(UEquippable::StaticClass()))
		{
			if (HeldItem != HandItem->GetChildActor() || !HeldItem)
			{
				HandItem->SetChildActorClass(SelectedItem.ItemClass);
				HeldItem = HandItem->GetChildActor();
				HeldItem->SetActorEnableCollision(false);
				HeldItem->SetActorScale3D(FVector(0.2f));
				IEquippable::Execute_Selected(HeldItem);
			}
		}

		else
		{
			UnEquipItem();
		}
	}
	else
	{
		UnEquipItem();
	}

	OnSelectedItemChanged(SelectedItem);
}

void AMyCharacter::UnEquipItem()
{
	if (HeldItem)
	{
		IEquippable::Execute_DeSelect(HeldItem);
		HandItem->DestroyChildActor();
		HeldItem = nullptr;
	}
}

void AMyCharacter::OnSelectedItemChanged_Implementation(FItem_Struct &Item)
{
}

void AMyCharacter::RemoveWidgetFromViewport()
{
	GetWorldTimerManager().ClearTimer(TimerHandler);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Removing Widget"));

	WidgetToRemove->RemoveFromViewport();
}

FVector AMyCharacter::GetViewPoint()
{
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FHitResult OutHit(ForceInit);

	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + PlayerCamera->GetForwardVector() * 10000.0f;

	ECollisionChannel Channel = ECC_Visibility;

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);
	return LineTraceFromView(10000.0f).ImpactPoint;
}

FVector AMyCharacter::GetViewForwardVector() const
{
	return PlayerCamera->GetForwardVector();
}

bool AMyCharacter::CheckForInteractable()
{
	const FHitResult OutHit = LineTraceFromView(InteractDistance);

	if (OutHit.GetActor())
	{
		return OutHit.GetActor()->GetClass()->ImplementsInterface(UInteractInterface::StaticClass());
	}
	return false;
}

FHitResult AMyCharacter::LineTraceFromView(float Distance)
{
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FHitResult OutHit(ForceInit);

	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + PlayerCamera->GetForwardVector() * Distance;

	ECollisionChannel Channel = ECC_Visibility;

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);
	
	return OutHit;
}
