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

	check(InputComponent);
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

void ACppPlayerController::SetTime(int Hour, int Minute) const
{
	const float NewTime = Hour * 1.25f + Minute / 60.0f * 1.25f;
	GameInstance->GameMinutes = NewTime;
}
