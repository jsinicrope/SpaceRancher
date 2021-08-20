// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Inventory_System/Item_Base.h"
#include "Inventory_System/InventoryComponent.h"
#include "InventorySlotWidget.generated.h"


UCLASS()
class SPACERANCHER_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextBlock = NULL;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageThumbnail = NULL;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	FItem_Struct SlotContent;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	int SlotIndex;

	UPROPERTY(BlueprintReadWrite)
	UInventoryComponent* Inventory = NULL;
};
