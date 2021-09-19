// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CppPlayerController.generated.h"

UCLASS()
class SPACERANCHER_API ACppPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACppPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	class AMyCharacter* PlayerCharacter;
};
