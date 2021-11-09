// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "FoodCookerTimer.generated.h"

UCLASS()
class SPACERANCHER_API UFoodCookerTimer : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Time;

public:
	UFUNCTION()
	void UpdateTimer(float RemainingTime) const;
};
