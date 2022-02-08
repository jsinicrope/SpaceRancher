// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AffectableItemBase.h"
#include "Gem.generated.h"

UCLASS()
class SPACERANCHER_API AGem : public AAffectableItemBase
{
	GENERATED_BODY()

public:
	AGem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
