// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Inventory_System/ItemStruct.h"
#include "BuildablesPriceStruct.generated.h"

USTRUCT(BlueprintType)
struct FBuildablesItemChart : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem_Struct Item;

	int GetTotalPrice()	const { return Item.CreditValue * Amount; }
};

USTRUCT(BlueprintType)
struct FBuildablesPriceStruct : public FTableRowBase
{
	GENERATED_BODY()
	
	/* The Credit price if this Object is bought without additional Resources
	 * This price is supposed to be substantially higher than that of the Resource costs combined
	 * TODO Automatically calculate this price based on the current market prices for the given materials */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RawCreditPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBuildablesItemChart> RequiredItems; 
};
