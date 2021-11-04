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
	if (SlotContent.bIsValidItem)
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
		OutOperation->Tag = FString("Not draggable");
		UWidgetDragOperation* OutOp = Cast<UWidgetDragOperation>(OutOperation);
		OutOp->DragOffset = DragOffset;
		OutOp->WidgetReference = this;
	}
}

bool UInventorySlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	const UWidgetDragOperation* InOp = Cast<UWidgetDragOperation>(InOperation);
	TempSwitchSlot = Cast<UInventorySlotWidget>(InOp->WidgetReference);
	
	if (TempSwitchSlot != nullptr)
	{
		InventoryWindow->SwitchSlots(TempSwitchSlot, this);
		TempSwitchSlot->SetVisibility(ESlateVisibility::Visible);
		return true;
	}
	return true;
}