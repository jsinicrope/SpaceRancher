// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "World/Saves/MainSaveGame.h"
#include "Delegates/IDelegateInstance.h"
#include "MainGameInstance.generated.h"

UCLASS()
class SPACERANCHER_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	bool Tick(float DeltaSeconds);

	FDelegateHandle TickDelegateHandle;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	float PlayerIngameTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RealToGameTimeFactor = 48.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InitialStartGameTime = 10.0f;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	float RealTimeMinutes = 0.0f;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int Difficulty;

	UPROPERTY(EditAnywhere)
	UMainSaveGame* SaveGameData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saving")
	FString SaveName = FString("SmartSave");

	//Functions
	UFUNCTION()
	bool GetSaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void NewSave(FString OldSave);

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	bool LoadGame();
};
