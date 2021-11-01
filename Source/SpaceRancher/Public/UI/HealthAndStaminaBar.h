// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthAndStaminaBar.generated.h"

UCLASS()
class SPACERANCHER_API UHealthAndStaminaBar : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UProgressBar* HealthBar = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UProgressBar* StaminaBar = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMyCharacter* PC = nullptr;
	
	UFUNCTION()
	void UpdateHealthBar() const;
	
	UFUNCTION()
	void UpdateStaminaBar() const;
};
