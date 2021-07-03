// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Main Character/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.0f;
	Stamina = 100.0f;
	HealthLastTick = 100.0f;
	HealthRegenPerSecond = 10.0f;
	WalkSpeed = 600.0f;
	SprintSpeed = 1000.0f;
	StaminaLossRunning = 50.0f;
	StaminaBaseRegen = 20.0f;
	TimeToHealthRegen = 3.0f;
	TimeToStaminaRegen = 2.0f;
	BaseTurnAtRate = 45.0f;
	BaseLookUpAtRate = 45.0f;
	bSprinting = false;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedDamageTime += DeltaTime;
	ElapsedStaminaDrainTime += DeltaTime;

	// Heal Player slowly up to 35 HP if no damage was received in the last 3 seconds

	{
		if (HealthLastTick < Health)
			ElapsedDamageTime = 0.0f;

		HealthLastTick = Health;

		if ((ElapsedDamageTime >= TimeToHealthRegen) && (Health < 35.0f))
		{
			Health = fmin(100, Health + HealthRegenPerSecond * DeltaTime);
		}
	}

	//Drain Stamina if Sprinting and not in Air
	{
		if (CharacterMovement->IsMovingOnGround())
		{
			if (bSprinting)
			{
				Stamina -= StaminaLossRunning * DeltaTime;
				ElapsedStaminaDrainTime = 0.0f;
			}

			else if (ElapsedStaminaDrainTime >= TimeToStaminaRegen)
				Stamina = fmin(100, Stamina + StaminaBaseRegen * DeltaTime);
		}
	}

	//Stop Running if Stamina below 10
	{
		if (Stamina < 10)
			PlayerStopSprint();
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

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
	
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
	if ((Stamina > 10) && (CharacterMovement->IsMovingOnGround()))
	{
		CharacterMovement->MaxWalkSpeed = SprintSpeed;
		bSprinting = true;
	}
}

void AMyCharacter::PlayerStopSprint()
{
	CharacterMovement->MaxWalkSpeed = WalkSpeed;
	bSprinting = false;
}
