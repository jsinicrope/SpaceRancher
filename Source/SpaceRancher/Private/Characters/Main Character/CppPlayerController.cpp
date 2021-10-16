// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/CppPlayerController.h"
#include "Inventory_System/InventoryComponent.h"
#include "Characters/Main Character/MyCharacter.h"

ACppPlayerController::ACppPlayerController(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	PlayerCharacter = Cast<AMyCharacter>(GetPawn());
}

void ACppPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent);
}
