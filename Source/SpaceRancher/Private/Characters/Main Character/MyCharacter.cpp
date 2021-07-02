// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Main Character/MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.0f;
	Stamina = 100.0f;

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

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMyCharacter::GetHealth()
{
	return Health;
}

void AMyCharacter::SetHealth(float MHealth)
{
	Health = MHealth;
}

float AMyCharacter::GetStamina()
{
	return Stamina;
}

void AMyCharacter::SetStamina(float MStamina)
{
	Stamina = MStamina;
}
