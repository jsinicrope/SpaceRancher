// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "World/Saves/MainSaveGame.h"
#include "MainGameInstance.generated.h"

#define REAL_TO_GAME_TIME_FACTOR 48.0f

UCLASS()
class SPACERANCHER_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	bool Tick(float DeltaSeconds);

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Time")
	int GameHour;

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Time")
	int GameMinute;

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Time")
	int Day;

protected:
	FTSTicker::FDelegateHandle TickDelegateHandle;

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Time")
	float GameMinutes = 0.0f;
	
	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite, Category="Time")
	float TimeScale = 1.0f;

	// Time (hours, minutes) to consider as sunrise and start of day time
	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite, Category="Time")
	FIntPoint Sunrise = FIntPoint(6, 30);

	// Time (hours, minutes) to consider as sunset and start of night time
	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite, Category="Time")
	FIntPoint Sunset = FIntPoint(7, 00);

	// Whether the game state is considered as day time or not(night time)
	UPROPERTY(SaveGame, BlueprintReadOnly, BlueprintGetter=IsDay, Category="Time")
	bool bIsDay;

	// Hour/Minute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Time")
	FVector2D InitialStartGameTime = FVector2D(8, 0);

	UPROPERTY(SaveGame, BlueprintReadOnly, Category="Time")
	float RealTimeMinutes = 0.0f;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	int Difficulty;

	UPROPERTY(BlueprintReadOnly, BlueprintGetter=GetSaveGameData)
	UMainSaveGame* SaveGameData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Saving")
	FString SaveName = FString("MainGame");

	UPROPERTY()
	bool bTimeAcceleration = false;

	UPROPERTY()
	float TimeToAccelerate = 0.0f;

	/** @returns false if no save game is available */
	UFUNCTION(BlueprintCallable)
	bool GetSaveGame();

public:
	UFUNCTION(BlueprintGetter)
	bool IsDay();

	UFUNCTION(BlueprintGetter)
	UMainSaveGame* GetSaveGameData() const { return SaveGameData; }
	
	UFUNCTION(Exec)
	void SetTime(const int Hour, const int Minute);

	UFUNCTION(Exec)
	void AccelerateTime(const int Hour, const int Minute, const float Speed);

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void NewSave(FString OldSave);

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	bool LoadGame();

	UFUNCTION(Exec)
	void DeleteActiveSave() const;

	UFUNCTION(BlueprintCallable)
	void LoadMainMenu() const;

	UFUNCTION(BlueprintCallable)
	void PauseGame() const;

	UFUNCTION(BlueprintCallable)
	void UnPauseGame() const;
	
private:
	UPROPERTY()
	TArray<AActor*> SaveActors;

	UPROPERTY()
	AActor* SaveActor;

	UPROPERTY()
	FName MainMenuLevelName = FName("MainMenuLevel");
};
