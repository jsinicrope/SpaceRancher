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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	class AMyCharacter* PlayerCharacter;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMainGameInstance* GameInstance;
	
public:
	AMyCharacter* GetPlayerCharacter() const { return PlayerCharacter; }

	UMainGameInstance* GetMainGameInstance() const {return GameInstance;}

	UFUNCTION(BlueprintGetter)
	int GetCredits() const {return Credits;}

	UFUNCTION(BlueprintCallable)
	void AddCredits(int Amount);

	UFUNCTION(BlueprintCallable)
	bool DeductCredits(int Amount);

	UFUNCTION(Exec)
	void SetTime(const int Hour, const int Minute = 0) const;

	UFUNCTION(BlueprintCallable, Category = "Saving")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "Saving")
	bool LoadGame();

	void ActionLoadGame() {LoadGame();}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetCredits)
	int Credits = 0;
};
