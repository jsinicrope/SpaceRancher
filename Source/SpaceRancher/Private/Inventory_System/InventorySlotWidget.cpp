// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventorySlotWidget.h"
#include "Inventory_System/InventoryComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/WidgetDragOperation.h"

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TextBlock = Cast<UTextBlock>(GetWidgetFromName(FName("TextBlock")));
	ImageThumbnail = Cast<UImage>(GetWidgetFromName(FName("ImageThumbnail")));
}

FReply UInventorySlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	const FKey DragKey = FKey(FName("RightMouseButton"));
	FEventReply Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, DragKey);
	return Reply.NativeReply;
}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	if (SlotContent.bValidItem)
	{
		// Create a copy of the current widget
		UInventorySlotWidget* NewSlotWidget = CreateWidget<UInventorySlotWidget>(GetWorld(), InventoryWindow->InventorySlotWidgetClass);
		NewSlotWidget->ImageThumbnail->SetBrushFromTexture(SlotContent.Thumbnail);
		NewSlotWidget->TextBlock->SetText(FText::FromString(SlotContent.Name));
		NewSlotWidget->InventoryWindow = InventoryWindow;
		NewSlotWidget->SlotIndex = SlotIndex;

		OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UWidgetDragOperation::StaticClass());
		
		OutOperation->DefaultDragVisual = NewSlotWidget;
		// Make InventorySlot not hit testable to avoid dropping on this
		OutOperation->DefaultDragVisual->SetVisibility(ESlateVisibility::HitTestInvisible);
		OutOperation->Pivot = EDragPivot::MouseDown;
		OutOperation->Tag = FString("InventorySlot");
		UWidgetDragOperation* OutOp = Cast<UWidgetDragOperation>(OutOperation);
		OutOp->DragOffset = DragOffset;
		OutOp->WidgetReference = this;
	}
}

bool UInventorySlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	const UWidgetDragOperation* InOp = Cast<UWidgetDragOperation>(InOperation);
	if (InOp->Tag.Equals(FString("InventorySlot")))
	{
		TempSwitchSlot = Cast<UInventorySlotWidget>(InOp->WidgetReference);
		ensureAlwaysMsgf(TempSwitchSlot, TEXT("Used Tag 'InventorySlot' on not UInventorySlotWidget widget class in UWidgetDragOperation"));
		if (this->InventoryWindow->Inventory == TempSwitchSlot->InventoryWindow->Inventory)
		{
			if (TempSwitchSlot->SlotIndex != SlotIndex)
			{
				InventoryWindow->SwitchSlots(TempSwitchSlot, this);
				TempSwitchSlot->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else
		{
			const FItem_Struct FirstItem = InventoryWindow->Inventory->RemoveItemByIndex(SlotIndex);
			const FItem_Struct SecondItem = TempSwitchSlot->InventoryWindow->Inventory->RemoveItemByIndex(TempSwitchSlot->SlotIndex);

			InventoryWindow->Inventory->AddItemByIndex(SecondItem, SlotIndex);
			TempSwitchSlot->InventoryWindow->Inventory->AddItemByIndex(FirstItem, TempSwitchSlot->SlotIndex);

			// Make InventorySlot hit testable
			TempSwitchSlot->SetVisibility(ESlateVisibility::Visible);
			SetVisibility(ESlateVisibility::Visible);
			TempSwitchSlot->InventoryWindow->UpdateInventory();
			InventoryWindow->UpdateInventory();
		}
		return true;
	}
	return false;
}
