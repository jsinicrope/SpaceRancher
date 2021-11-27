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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Details;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsValidItem;

	FItem_Struct()
	{
		Name = FString("zzz");
		Thumbnail = nullptr;
		bIsValidItem = false;
	}
};
