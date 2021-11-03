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
	virtual void NativeConstruct() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextBlock = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* ImageThumbnail = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	FItem_Struct SlotContent;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	int SlotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryWindow* InventoryWindow = nullptr;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D DragOffset;

	UPROPERTY()
	UInventorySlotWidget* TempSwitchSlot;
};
