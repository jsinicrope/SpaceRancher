// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "World/Saves/MainSaveGame.h"


#include "Delegates/IDelegateInstance.h"
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

	bool Tick(float DeltaSeconds);

	FDelegateHandle TickDelegateHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlayerIngameTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RealToGameTimeFactor = 48.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialStartGameTime = 15.0f;

	UPROPERTY(EditAnywhere)
	UMainSaveGame* SaveGameData;

	UPROPERTY(EditAnywhere)
	FString SaveSlotName = FString(TEXT("PlayerSaveGame"));
};
