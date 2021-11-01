// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Clock.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UClock : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable, Category = "Time")
	void UpdateClock();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClockTimeTotalMinutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClockTimeMinutes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ClockTimeHour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StringTime;

protected:
	UPROPERTY()
	FString MinutesString;

	UPROPERTY()
	class UMainGameInstance* GameInstance;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlockTime;

	UFUNCTION()
	void SetTextBlock(FText Text) const;
};
