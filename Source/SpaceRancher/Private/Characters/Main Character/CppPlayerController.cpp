// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/CppPlayerController.h"
#include "Inventory_System/InventoryComponent.h"
#include "Characters/Main Character/MyCharacter.h"

ACppPlayerController::ACppPlayerController(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
}

void ACppPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent)
	InputComponent->BindAction("SaveGame", IE_Released, this, &ACppPlayerController::SaveGame);
	InputComponent->BindAction("LoadGame", IE_Released, this, &ACppPlayerController::ActionLoadGame);
}

void ACppPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerCharacter = Cast<AMyCharacter>(GetPawn());
	GameInstance = Cast<UMainGameInstance>(GetWorld()->GetGameInstance());
}

void ACppPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACppPlayerController::AddCredits(int Amount)
{
	Credits += Amount;
}

bool ACppPlayerController::DeductCredits(int Amount)
{
	if (Credits - Amount < 0)
	{
		return false;
	}
	Credits -= Amount;
	return true;
}

void ACppPlayerController::SetTime(const int Hour, const int Minute) const
{
	GameInstance->SetTime(Hour, Minute);
}

void ACppPlayerController::SaveGame()
{
	GameInstance->SaveGame();
}

bool ACppPlayerController::LoadGame()
{
	return GameInstance->LoadGame();
}
