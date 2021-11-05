// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/MyCharacter.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interactables/InteractInterface.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "UI/Clock.h"
#include "World/Saves/ActorRecord.h"
#include "World/Saves/ActorSaveArchive.h"
#include "UI/HUDSetting.h"
#include "Kismet/GameplayStatics.h"
#include "UI/CMainHUD.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Health
	Health = 100.0f;
	HealthLastTick = 100.0f;
	HealthRegenPerSecond = 10.0f;
	TimeToHealthRegen = 3.0f;
	MaxHealth = 100.0f;

	// Stamina
	Stamina = 100.0f;
	StaminaLossRunning = 50.0f;
	StaminaRegenPerSecond = 20.0f;
	TimeToStaminaRegen = 2.0f;
	MaxStamina = 100.0f;

	// Movement
	WalkSpeed = 600.0f;
	SprintSpeed = 1000.0f;
	FallingTime = 0.0f;
	FallDamageFactor = 6.0f;
	MinFallDamageVelocity = 5.0f;

	BaseTurnAtRate = 45.0f;
	BaseLookUpAtRate = 45.0f;

	// Interaction
	InteractDistance = 250.0f;

	// Death
	RespawnPoint = FVector(0, 0, 0);
	RespawnViewDirection = FRotator(0, 0, 0);

	// Runtime
	bSprinting = false;

	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("UInventoryComponent"));
	AddOwnedComponent(InventoryComp);

	HUDController = CreateDefaultSubobject<UHUDSetting>(TEXT("HUD Settings"));
	AddOwnedComponent(HUDController);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->LoadGame();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	TArray<UCameraComponent*> comps;

	this->GetComponents(comps);
	for (UCameraComponent* Camera : comps)
	{
		PlayerCamera = Camera;
	}
	
	RespawnPoint = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	RespawnViewDirection = GetControlRotation();
}

// Called every frame
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
			if (bSprinting)
			{
				Stamina -= StaminaLossRunning * DeltaTime;
				ElapsedStaminaDrainTime = 0.0f;
			}
	// Regen Stamina
			else if (ElapsedStaminaDrainTime >= TimeToStaminaRegen)
				Stamina = fmin(MaxStamina, Stamina + StaminaRegenPerSecond * DeltaTime);
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

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::PlayerStartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::PlayerStopSprint);

	PlayerInputComponent->BindAction("Interact", IE_Released, this, &AMyCharacter::PlayerInteract);
	PlayerInputComponent->BindAction("Inventory", IE_Released, this, &AMyCharacter::ToggleInventory);
	PlayerInputComponent->BindAction("SaveGame", IE_Released, this, &AMyCharacter::SaveGame);
	PlayerInputComponent->BindAction("LoadGame", IE_Released, this, &AMyCharacter::LoadGame);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
}

void AMyCharacter::PlayerInteract()
{
	bInventoryOpen = InventoryComp->GetInventoryOpen();
	if (!bInventoryOpen)
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

			//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Actor hit"));

			//DrawDebugLine(GetWorld(), Start, OutHit.ImpactPoint, FColor::Red, false, 1.0f, false, 12.3333f);

			if (Actor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
			{
				//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Actor Implements Interface"));
				//Cast<IInteractInterface>(Actor)->Interact();	//Use this to call C++ only Implementation
				IInteractInterface::Execute_Interact(Actor);
			}
		}

		else
		{
			//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Actor not hit"));

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

bool AMyCharacter::AddItemToInventory(FItem_Struct Item_Struct)
{
	const bool bAddSuccessful = InventoryComp->AddItem(Item_Struct);

	if (bAddSuccessful)
	{
		HUDController->ItemPickUpWidget->ItemImage = Item_Struct.Thumbnail;

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

FItem_Struct AMyCharacter::RemoveItemFromInventory(FItem_Struct Item)
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
	bInventoryOpen = InventoryComp->bInventoryOpen;
	if (!bInventoryOpen)
	{
		HUDController->MainHUD->RemoveAllInteractableWidgets();
	}
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
