// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "ItemStruct.generated.h"

USTRUCT(BlueprintType)
struct SPACERANCHER_API FItem_Struct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	/** the Class the Item is from. Used to get default values.
	 * Set this to the last child class in the inheritance hierarchy of the item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* ItemClass;

	// Extra infos about this item. Could be used similarly to a dictionary entry
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Details;

	// Used to give info about the item that can be used to get the item type or similar
	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite)
	FString Tag;

	/** Whether the item is supposed to be treated like a regular item
	 * Should generally be set to true.
	 * Setting it to false will lead to unwanted behaviour */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bValidItem = false;

	// Whether the item should appear in the radial menu if when it's in the players inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSelectable = false;

	FItem_Struct()
	{
		Name = FString("");
		Thumbnail = nullptr;
		ItemClass = nullptr;
	}
};
