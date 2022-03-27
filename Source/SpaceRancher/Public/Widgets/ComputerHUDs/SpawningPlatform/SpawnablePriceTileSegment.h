// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawnablePriceTileSegment.generated.h"

class UImage;
class UTextBlock;
struct FBuildableItemChart;

UCLASS()
class SPACERANCHER_API USpawnablePriceTileSegment : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetContent(const FBuildableItemChart& ItemChart) const;

	UFUNCTION(BlueprintCallable)
	void SetAmount(const int ItemAmount) const;

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UImage* ItemThumbnail;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* AmountText;
};
