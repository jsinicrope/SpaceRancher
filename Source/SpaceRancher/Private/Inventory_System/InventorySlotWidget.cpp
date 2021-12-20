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
			// Inventory of this widget
			CurrentInventory.Empty();
			for (int i = 0; i < InventoryWindow->Inventory->Inventory_Array_Columns.Num(); i++)
			{
				for (int j = 0; j < InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
				{
					CurrentInventory.Add(InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items[j]);
				}
			}

			// Inventory of the widget that was dragged from
			DraggedFromInventory.Empty();
			for (int i = 0; i < TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns.Num(); i++)
			{
				for (int j = 0; j < TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
				{
					DraggedFromInventory.Add(TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items[j]);
				}
			}

			// Switch item positions
			const int TempSlotIndex = TempSwitchSlot->SlotIndex;

			const FItem_Struct TempItem = CurrentInventory[SlotIndex];
			CurrentInventory[SlotIndex] = DraggedFromInventory[TempSlotIndex];
			DraggedFromInventory[TempSlotIndex] = TempItem;

			// Move Inventory from 2D back to it's intended shape
			// Read pointer values to inventory
			// this inventory
			int Index = 0;
			for (int i = 0; i < InventoryWindow->Inventory->Inventory_Array_Columns.Num(); i++)
			{
				for (int j = 0; j < InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
				{
					InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items[j] = CurrentInventory[Index];
					Index++;
				}
			}

			// Inventory that was dragged from
			Index = 0;
			for (int i = 0; i < TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns.Num(); i++)
			{
				for (int j = 0; j < TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
				{
					TempSwitchSlot->InventoryWindow->Inventory->Inventory_Array_Columns[i].Row_Items[j] = DraggedFromInventory[Index];
					Index++;
				}
			}
		
			TempSwitchSlot->SetVisibility(ESlateVisibility::Visible);
			SetVisibility(ESlateVisibility::Visible);
			TempSwitchSlot->InventoryWindow->UpdateInventory();
			InventoryWindow->UpdateInventory();
		}
	}
	return true;
}
