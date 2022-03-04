// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildablesPriceStruct.h"
#include "GameFramework/Actor.h"
#include "PlayerBuildable.generated.h"

UCLASS(Abstract)
class SPACERANCHER_API APlayerBuildable : public AActor
{
	GENERATED_BODY()
	
public:	
	APlayerBuildable();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintGetter)
	const FBuildablesPriceStruct& GetCost()	const { return Cost; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetCost)
	FBuildablesPriceStruct Cost;
};
