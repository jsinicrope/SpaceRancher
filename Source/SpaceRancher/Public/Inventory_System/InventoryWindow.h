// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/GridPanel.h"
#include "Inventory_System/Item_Base.h"
#include "Inventory_System/InventoryComponent.h"
#include "InventoryWindow.generated.h"


UCLASS()
class SPACERANCHER_API UInventoryWindow : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* InventoryTitle = NULL;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ButtonClose = NULL;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UGridPanel* InventoryGrid = NULL;

	UPROPERTY(BlueprintReadWrite)
	UInventoryComponent* Inventory;
};
