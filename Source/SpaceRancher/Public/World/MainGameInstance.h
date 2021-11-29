// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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
	float GameMinutes;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int GameHour;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int GameMinute;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeScale = 1.0f;

	// Hour/Minute
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D InitialStartGameTime = FVector2D(8, 0);

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	float RealTimeMinutes = 0.0f;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int Difficulty;

	UPROPERTY(EditAnywhere)
	UMainSaveGame* SaveGameData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saving")
	FString SaveName = FString("MainGame");

	UPROPERTY()
	bool bTimeAcceleration = false;

	UPROPERTY()
	float TimeToAccelerate = 0.0f;

	//Functions
	UFUNCTION(Exec)
	inline void SetTime(int Hour, int Minute);

	UFUNCTION(Exec)
	void AccelerateTime(int Hour, int Minute, float Speed);
	
	UFUNCTION()
	bool GetSaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void NewSave(FString OldSave);

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	bool LoadGame();
	
private:
	UPROPERTY()
	TArray<AActor*> SaveActors;
};
