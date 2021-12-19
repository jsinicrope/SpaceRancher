// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/MyCharacter.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interactables/InteractInterface.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/SceneCapture2D.h"
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
	AddOwnedComponent(MiniMapCamera);
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->LoadGame();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	// Setup the MiniMap Camera capturing
	MiniMapCamera->SetRelativeLocation(FVector(0, 0, 10000));
	MiniMapCamera->SetRelativeRotation(FRotator(270, 0, 0));
	MiniMapCapture = Cast<ASceneCapture2D>(MiniMapCamera->GetChildActor());
	checkf(MiniMapCapture, TEXT("MiniMap Camera not set to SceneCapture2D in Player Character"));
	MiniMapCapture->GetCaptureComponent2D()->OrthoWidth = DefaultMiniMapSize;
	MiniMapCapture->GetCaptureComponent2D()->HiddenActors.Add(this);
	ZoomMiniMap(ZoomLevel);
	
	RespawnPoint = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	RespawnViewDirection = GetControlRotation();
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ElapsedDamageTime += DeltaTime;
	ElapsedStaminaDrainTime += DeltaTime;

	// Heal Player slowly up to 35 HP if no damage was received in the last 'TimeToHealthRegen' seconds
	{
		if (HealthLastTick < Health)
			ElapsedDamageTime = 0.0f;

		HealthLastTick = Health;

		if ((ElapsedDamageTime >= TimeToHealthRegen) && (Health < MaxRegeneratedHealth))
		{
			Health = fmin(MaxHealth, Health + HealthRegenPerSecond * DeltaTime);
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
				Stamina = fmin(MaxStamina, Stamina + StaminaRegenPerSecond * DeltaTime);
			}
		}
	}

	{
		if (Stamina <= 0)
			PlayerStopSprint();
	}

	//Call Pop Up for Interaction if Interactable actor is hit
	{
		bInteractableInRange = CheckForInteractable();
		if (bInteractableInRange)
		{
			if (!HUDController->InteractPopUp->IsInViewport())
			{
				HUDController->InteractPopUp->AddToViewport();
			}
		}
		else
		{
			if (HUDController->InteractPopUp->IsInViewport())
			{
				HUDController->InteractPopUp->RemoveFromViewport();
			}
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
			// 9.81 average gravity acceleration; should be same in engine
			const float FallSpeed = 9.81 * FallingTime;

			FallingTime = 0.0f;

			if (FallSpeed >= MinFallDamageVelocity)
			{
				Health -= (FallSpeed - MinFallDamageVelocity) * FallDamageFactor;
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
	
	PlayerInputComponent->BindAction("SaveGame", IE_Released, this, &AMyCharacter::SaveGame);
	PlayerInputComponent->BindAction("LoadGame", IE_Released, this, &AMyCharacter::LoadGame);

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
		FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
		TraceParams.bTraceComplex = true;
		TraceParams.bReturnPhysicalMaterial = false;

		FHitResult OutHit(ForceInit);

		FVector Start = PlayerCamera->GetComponentLocation();
		FVector End = Start + (PlayerCamera->GetForwardVector() * InteractDistance);

		ECollisionChannel Channel = ECC_Visibility;

		GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);

		if (OutHit.GetActor())
		{
			auto Actor = OutHit.GetActor();

			if (Actor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
			{
				if (SelectedItem.bIsValidItem)
				{
					if (IInteractInterface::Execute_ItemInteract(Actor, SelectedItem))
					{
						RemoveItemFromInventory(SelectedItem);
					}
				}
				else
				{
					IInteractInterface::Execute_Interact(Actor);
				}
			}
		}

		else
		{
			DrawDebugLine(GetWorld(), Start, OutHit.TraceEnd, FColor::Red, false, 1.0f, false, 10.0f);
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
	GetWorld()->GetFirstPlayerController()->GetPawn()->TeleportTo(RespawnPoint, RespawnViewDirection, false, true);
	GetCharacterMovement()->StopActiveMovement();
	Health = MaxHealth;
	Stamina = MaxStamina;
	bPlayerDead = false;
}

void AMyCharacter::DamagePlayer(float Damage)
{
	Health = FMath::Max(Health - Damage, 0.0f);

	if (Health <= 0.0f)
	{
		KillPlayer();
	}
}

bool AMyCharacter::bIsPlayerDead()
{
	return bPlayerDead;
}

void AMyCharacter::SaveGame()
{
	GameInstance->SaveGame();
}

void AMyCharacter::LoadGame()
{
	GameInstance->LoadGame();
}

void AMyCharacter::SavePlayerCharacter()
{
	UMainSaveGame* SaveData = GameInstance->SaveGameData;
	CurrentVelocity = GetCharacterMovement()->Velocity;
	SaveData->Player_Inventory_Array_Columns = InventoryComp->Inventory_Array_Columns;

	FActorRecord PlayerRecord(this);
	FMemoryWriter MemoryWriterPlayer(PlayerRecord.Data, true);
	FActorSaveArchive PlayerAr(MemoryWriterPlayer, false);
	Serialize(PlayerAr);
	GameInstance->SaveGameData->PlayerCharacterData = PlayerRecord;
}

void AMyCharacter::LoadPlayerCharacter()
{
	UMainSaveGame* SaveData = GameInstance->SaveGameData;
	InventoryComp->Inventory_Array_Columns = SaveData->Player_Inventory_Array_Columns;

	// De-Serialize
	FActorRecord ActorRecord = SaveData->PlayerCharacterData;
	FMemoryReader MemoryReader(ActorRecord.Data);
	FActorSaveArchive Ar(MemoryReader, false);
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

bool AMyCharacter::AddItemToInventory(FItem_Struct &Item_Struct)
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

FItem_Struct AMyCharacter::RemoveItemFromInventoryFromPosition(int column, int row)
{
	FItem_Struct Item = InventoryComp->RemoveItemFromPosition(row, column);
	return Item;
}

FItem_Struct AMyCharacter::RemoveItemFromInventory(FItem_Struct &Item)
{
	FItem_Struct RemovedItem = InventoryComp->RemoveItem(Item);
	return RemovedItem;
}

FItem_Struct AMyCharacter::RemoveItemFromInventoryByName(FString ItemName)
{
	FItem_Struct RemovedItem = InventoryComp->RemoveItemByName(ItemName);
	return RemovedItem;
}

void AMyCharacter::ToggleInventory()
{
	InventoryComp->ToggleInventory();
	bInventoryOpen = InventoryComp->GetInventoryOpen();
	if (!bInventoryOpen)
	{
		HUDController->MainHUD->RemoveAllInventoryWidgets();
	}
}

void AMyCharacter::OpenRadialMenu()
{
	if (!bItemSelectionOpen)
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

void AMyCharacter::UpdateSelectedItem()
{
	const FItem_Struct ActiveItem = HUDController->RadialMenu->GetSelectedItem();
	SelectedItem = ActiveItem;
	bItemSelectionOpen = false;
	if (SelectedItem.bIsSelectable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Green, FString("Selected Item: ") + SelectedItem.Name);
	}

	OnSelectedItemChanged(SelectedItem);
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

bool AMyCharacter::CheckForInteractable()
{
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FHitResult OutHit(ForceInit);

	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + (PlayerCamera->GetForwardVector() * InteractDistance);

	ECollisionChannel Channel = ECC_Visibility;

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);

	if (OutHit.GetActor())
	{
		return OutHit.GetActor()->GetClass()->ImplementsInterface(UInteractInterface::StaticClass());
	}
	return false;
}
