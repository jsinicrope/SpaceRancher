// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory_System/ItemStruct.h"
#include "ItemStructTileView.generated.h"

UCLASS()
class SPACERANCHER_API UItemStructTileView : public UObject
{
	GENERATED_BODY()
	
public:
	UItemStructTileView();
	
	UPROPERTY()
	FItem_Struct Item_Struct;
};
