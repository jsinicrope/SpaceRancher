// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NeededItemPopUp.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UNeededItemPopUp : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	UPROPERTY(BlueprintReadwrite, meta=(BindWidget))
	class UImage* ItemImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* AmountText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quantity = 1;

	UPROPERTY()
	FString InText;

	UFUNCTION(BlueprintCallable)
	void SetTextAmount(int Amount = 1, FString ItemName = FString(""));
};
