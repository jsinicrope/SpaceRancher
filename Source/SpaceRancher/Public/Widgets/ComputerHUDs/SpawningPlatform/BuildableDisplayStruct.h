// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/PlayerBuildable.h"
#include "UObject/Object.h"
#include "BuildableDisplayStruct.generated.h"

UCLASS()
class SPACERANCHER_API UBuildableDisplayStruct final : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBuildableDisplayable DisplayStyle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBuildablePriceStruct Cost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APlayerBuildable> BuildableClass;
};
