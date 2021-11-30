// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "ItemPickUpWidget.generated.h"

UCLASS()
class SPACERANCHER_API UItemPickUpWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* PickedUpItem;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* PickedUpItemName;

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void UpdateWidget(UTexture2D* ItemImage, const FString ItemName) const;
};
