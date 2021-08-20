// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Inventory_System/InventoryComponent.h"
#include "MainSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UMainSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UMainSaveGame();

	UPROPERTY()
	float Health;

	UPROPERTY()
	float Stamina;

	UPROPERTY()
	float IngameTime;

	UPROPERTY()
	float PlayerFallingTime;

	UPROPERTY()
	float PlayerElapsedDamageTime;

	UPROPERTY()
	float PlayerElapsedStaminaDrainTime;

	UPROPERTY()
	float PlayerHealthLastTick;

	UPROPERTY()
	FVector PlayerJumpStartPoint;

	UPROPERTY()
	FVector CurrentPosition;

	UPROPERTY()
	TArray<FItemRows> Player_Inventory_Array_Columns;
};
