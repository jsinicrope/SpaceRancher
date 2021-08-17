// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Item_Struct.generated.h"


USTRUCT(BlueprintType)
struct SPACERANCHER_API FItem_Struct : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int ItemSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsValidItem;

	FItem_Struct()
	{
		Name = FString("None");
		ItemSize = 1;
		Thumbnail = NULL;
		bIsValidItem = false;
	}
};
