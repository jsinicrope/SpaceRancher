// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySlotWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/GridPanel.h"
#include "Items/ItemBase.h"
#include "Components/Button.h"
#include "InventoryWindow.generated.h"

UCLASS()
class SPACERANCHER_API UInventoryWindow : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	
	UPROPERTY(BlueprintReadWrite)
	class UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetUpInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetVariables(UInventoryComponent* InventoryComp, TSubclassOf<UUserWidget> InventorySlotWidgetClassIn);

	UFUNCTION()
	void ShowWindow();

	UFUNCTION()
	void CloseWindow();

	UFUNCTION()
	bool SwitchSlots(const UInventorySlotWidget* FirstSlot, const UInventorySlotWidget* SecondSlot);

	UFUNCTION(BlueprintGetter)
	bool GetInventoryOpen();

protected:
	UPROPERTY(BlueprintReadOnly)
	class UInventorySlotWidget* InventorySlotWidget;

	UPROPERTY()
	FItem_Struct InventoryItem;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* InventoryTitle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UGridPanel* InventoryGrid;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* CloseInventoryButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	UButton* SortInventoryButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidgetOptional))
	class UInventoryTrashSlot* TrashSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCanvasPanelSlot* CanvasSlot = nullptr;

	UPROPERTY()
	bool bWindowOpen = false;

	UPROPERTY()
	class ACppPlayerController* PC;

	UPROPERTY()
	class UHUDSetting* PlayerHUD;

	UPROPERTY()
	FVector2D DragOffset;

	UFUNCTION()
	void CloseInventory();

	/** Sorts Inventory
	 * Delegate function for sort button */
	UFUNCTION()
	void SortInventory();

private:
	UPROPERTY()
	FVector2D FirstPosition;

	UPROPERTY()
	FVector2D SecondPosition;
};
