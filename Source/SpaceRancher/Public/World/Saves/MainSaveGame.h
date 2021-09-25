// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Inventory_System/InventoryComponent.h"
#include "World/Saves/ActorRecord.h"
#include "MainSaveGame.generated.h"

UCLASS()
class SPACERANCHER_API UMainSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UMainSaveGame();

	UPROPERTY()
	float IngameTime;

	UPROPERTY()
	TArray<FItemRows> Player_Inventory_Array_Columns;

	UPROPERTY()
	FActorRecord Data;
};
