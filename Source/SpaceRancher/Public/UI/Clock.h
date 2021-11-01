// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Clock.generated.h"

UCLASS()
class SPACERANCHER_API UClock : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Position = FVector2D(1750.0f, 50.0f);

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
