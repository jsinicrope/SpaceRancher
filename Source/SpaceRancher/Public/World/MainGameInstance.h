// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "World/Saves/MainSaveGame.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UPROPERTY(EditAnywhere)
	UMainSaveGame* SaveGameData;

	UPROPERTY(EditAnywhere)
	FString SaveSlotName = FString(TEXT("PlayerSaveGame"));;
};
