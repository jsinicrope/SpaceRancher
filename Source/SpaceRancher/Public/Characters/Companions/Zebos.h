// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Zebos.generated.h"

UCLASS()
class SPACERANCHER_API AZebos : public APawn
{
	GENERATED_BODY()

public:
	AZebos();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
