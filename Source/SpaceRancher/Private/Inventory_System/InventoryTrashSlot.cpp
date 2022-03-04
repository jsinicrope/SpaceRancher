// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryTrashSlot.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventoryWindow.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "UI/WidgetDragOperation.h"

void UInventoryTrashSlot::NativeConstruct()
{
	Super::NativeConstruct();

	TextBlock = Cast<UTextBlock>(GetWidgetFromName(FName("TextBlock")));
	ImageThumbnail = Cast<UImage>(GetWidgetFromName(FName("ImageThumbnail")));
}

void UInventoryTrashSlot::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	TimeToReset -= InDeltaTime;
	if (TimeToReset <= 0)
	{
		ResetSlot();
	}
}

bool UInventoryTrashSlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (InOperation->Tag.Equals(FString("InventorySlot")))
	{
		const UWidgetDragOperation* DragOperation = Cast<UWidgetDragOperation>(InOperation);
		const UInventorySlotWidget* InventorySlotWidget = Cast<UInventorySlotWidget>(DragOperation->WidgetReference);
		if (InventorySlotWidget->InventoryWindow != InventoryWindow)	{ return false; }
		
		SlotContent = InventorySlotWidget->InventoryWindow->Inventory->RemoveItemByIndex(InventorySlotWidget->SlotIndex);

		ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 1)));
		ImageThumbnail->SetBrushFromTexture(SlotContent.Thumbnail);
		TextBlock->SetText(FText::FromString(SlotContent.Name));

		InventoryWindow->UpdateInventory();

		TimeToReset = 0.75f;
		
		return true;
	}
	
	return false;
}

void UInventoryTrashSlot::ResetSlot()
{
	SlotContent = FItem_Struct();
	ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 0)));
	TextBlock->SetText(FText::FromString("Trash"));
}
