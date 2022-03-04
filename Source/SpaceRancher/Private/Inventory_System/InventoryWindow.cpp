// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryWindow.h"
#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventorySlotWidget.h"
#include "Inventory_System/InventoryTrashSlot.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/WidgetDragOperation.h"
#include "UI/HUDSetting.h"
#include "UI/CMainHUD.h"

void UInventoryWindow::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//Initialize Pointers to Widget settings in Editor
	InventoryTitle = Cast<UTextBlock>(GetWidgetFromName(FName("InventoryTitle")));
	InventoryGrid = Cast<UGridPanel>(GetWidgetFromName(FName("InventoryGrid")));
	CloseInventoryButton = Cast<UButton>(GetWidgetFromName(FName("CloseInventoryButton")));
	TrashSlot = Cast<UInventoryTrashSlot>(GetWidgetFromName(FName("TrashSlot")));

	if (TrashSlot)
	{
		TrashSlot->InventoryWindow = this;
	}

	CloseInventoryButton->OnClicked.AddDynamic(this, &UInventoryWindow::CloseWindow);
	
	if (SortInventoryButton)
	{
		SortInventoryButton->OnClicked.AddDynamic(this, &UInventoryWindow::SortInventory);
	}
}

void UInventoryWindow::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	// TODO: Make drag visual a separate widget to allow for saving position in case the Window is dragged atop another
	OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UWidgetDragOperation::StaticClass());
	OutOperation->DefaultDragVisual = this;
	OutOperation->Pivot = EDragPivot::MouseDown;
	UWidgetDragOperation* OutOp = Cast<UWidgetDragOperation>(OutOperation);
	OutOp->DragOffset = DragOffset;
	OutOp->WidgetReference = this;
	this->RemoveFromParent();
	OutOp->Tag = FString("InventoryWindow");
}

FReply UInventoryWindow::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	const FKey DragKey = FKey(FName("RightMouseButton"));
	FEventReply Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, DragKey);
	return Reply.NativeReply;
}

bool UInventoryWindow::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	UWidgetDragOperation* DragOperation = Cast<UWidgetDragOperation>(InOperation);

	// Handle item dropping on inventory
	if (DragOperation->Tag.Equals(FString("InventorySlot")))
	{
		UInventorySlotWidget* InventorySlot = Cast<UInventorySlotWidget>(DragOperation->WidgetReference);
		if (!ensureAlwaysMsgf(InventorySlot, TEXT("Used Tag 'InventorySlot' on not UInventorySlotWidget widget class in UWidgetDragOperation")))
		{
			return false;
		}
		
		if (Inventory == InventorySlot->InventoryWindow->Inventory)
		{
			const FItem_Struct Item = Inventory->RemoveItemByIndex(InventorySlot->SlotIndex);
			Inventory->AddItem(Item);
			UpdateInventory();
			return true;
		}
		
		if (Inventory->AddItem(InventorySlot->SlotContent))
		{
			InventorySlot->InventoryWindow->Inventory->RemoveItemByIndex(InventorySlot->SlotIndex);
			
			InventorySlot->SetVisibility(ESlateVisibility::Visible);
			InventorySlot->InventoryWindow->UpdateInventory();
			SetVisibility(ESlateVisibility::Visible);
			UpdateInventory();
			return true;
		}
	}

	// Handle InventoryWindow on InventoryWindow dropping
	// return false here to not make the InventoryWindow disappear
	if (DragOperation->Tag.Equals(FString("InventoryWindow")))
	{
		UInventoryWindow* InventoryWindow = Cast<UInventoryWindow>(DragOperation->WidgetReference);

		for (int i = 0; i < InventoryWindow->Inventory->ItemSlots && i < Inventory->ItemSlots; i++)
		{
			const FItem_Struct Item = InventoryWindow->Inventory->RemoveItemByIndex(i);
			if (Item.bValidItem && !Inventory->AddItem(Item))
			{
				InventoryWindow->Inventory->AddItemByIndex(Item, i);
				break;
			}
		}
		UpdateInventory();
		InventoryWindow->UpdateInventory();
		DragOperation->Tag = FString("InventoryWindow dropped");
	}
	return false;
}

void UInventoryWindow::SetVariables(UInventoryComponent* InventoryComp, TSubclassOf<UUserWidget> InventorySlotWidgetClassIn)
{
	Inventory = InventoryComp;
	InventorySlotWidgetClass = InventorySlotWidgetClassIn;
	AMyCharacter* Player =  Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player)
	{
		PlayerHUD = Player->GetHUDController();
	}
}

void UInventoryWindow::ShowWindow()
{
	CanvasSlot = PlayerHUD->MainHUD->AddInventoryWidgetToCanvas(this);
	CanvasSlot->SetAutoSize(true);
	CanvasSlot->SetPosition(Inventory->WidgetPosition);
	bWindowOpen = true;
}

void UInventoryWindow::CloseWindow()
{
	CloseInventory();
}

void UInventoryWindow::CloseInventory()
{
	Inventory->WidgetPosition = CanvasSlot->GetPosition();
	PlayerHUD->MainHUD->RemoveInventoryWidgetFromCanvas(this);
	bWindowOpen = false;
	bWindowOpen = GetInventoryOpen();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void UInventoryWindow::SortInventory()
{
	Inventory->SortInventory();
}

bool UInventoryWindow::SwitchSlots(const UInventorySlotWidget* FirstSlot, const UInventorySlotWidget* SecondSlot)
{
	const FItem_Struct FirstItem = Inventory->RemoveItemByIndex(FirstSlot->SlotIndex);
	const FItem_Struct SecondItem = Inventory->RemoveItemByIndex(SecondSlot->SlotIndex);
	Inventory->AddItemByIndex(FirstItem, SecondSlot->SlotIndex);
	Inventory->AddItemByIndex(SecondItem, FirstSlot->SlotIndex);
	
	UpdateInventory();
	return true;
}

bool UInventoryWindow::GetInventoryOpen()
{
	bWindowOpen = this->GetParent() ? true : false;
	return bWindowOpen;
}

void UInventoryWindow::SetUpInventory()
{
	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());
	
	InventoryTitle->SetText(Inventory->InventoryName);
	int SlotIndex = 0;

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Inventory Set Up Script Run"));
	for (int i = 0; i < Inventory->Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			InventoryItem = Inventory->Inventory_Array_Columns[i].Row_Items[j];
			InventorySlotWidget = CreateWidget<UInventorySlotWidget>(GetWorld(), InventorySlotWidgetClass);
			InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 0)));

			if (InventoryItem.bValidItem)
			{
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 1)));
				InventoryGrid->RemoveChildAt(InventorySlotWidget->SlotIndex);
				InventorySlotWidget->ImageThumbnail->SetBrushFromTexture(InventoryItem.Thumbnail);
				InventorySlotWidget->TextBlock->SetText(FText::FromString(FString("Test Text")));
			}
			InventorySlotWidget->SlotContent = InventoryItem;
			InventorySlotWidget->SlotIndex = SlotIndex;
			InventorySlotWidget->InventoryWindow = this;
			InventoryGrid->AddChildToGrid(InventorySlotWidget, i, j);
			SlotIndex++;
		}
	}
}

void UInventoryWindow::UpdateInventory()
{
	int SlotIndex = 0;

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Inventory Updated"));
	for (int i = 0; i < Inventory->Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory->Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			InventoryItem = Inventory->Inventory_Array_Columns[i].Row_Items[j];
			InventorySlotWidget = Cast<UInventorySlotWidget>(InventoryGrid->GetChildAt(SlotIndex));
			if (InventoryItem.bValidItem)
			{
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 1)));
				FString ItemName = Inventory->Inventory_Array_Columns[i].Row_Items[j].Name;
				InventorySlotWidget->TextBlock->SetText(FText::FromString(ItemName));
			}
			else
			{
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 0)));
				InventorySlotWidget->TextBlock->SetText(FText::FromString(""));
			}
			InventorySlotWidget->SlotContent = InventoryItem;
			InventorySlotWidget->ImageThumbnail->SetBrushFromTexture(InventoryItem.Thumbnail);
			InventorySlotWidget->SlotIndex = SlotIndex;
			InventorySlotWidget->InventoryWindow = this;
			InventoryGrid->ReplaceChildAt(SlotIndex, InventorySlotWidget);
			SlotIndex += 1;
		}
	}
}
