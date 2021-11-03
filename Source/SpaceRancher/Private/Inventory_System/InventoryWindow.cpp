// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryWindow.h"
#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventorySlotWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/WidgetDragOperation.h"
#include "UI/HUDSetting.h"
#include "UI/CMainHUD.h"

// Only called once 
void UInventoryWindow::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	//Initialize Pointers to Widget settings in Editor
	InventoryTitle = Cast<UTextBlock>(GetWidgetFromName(FName("InventoryTitle")));
	InventoryGrid = Cast<UGridPanel>(GetWidgetFromName(FName("InventoryGrid")));
	CloseInventoryButton = Cast<UButton>(GetWidgetFromName(FName("CloseInventoryButton")));

	//Function gets called everytime widget is added to viewport
	CloseInventoryButton->OnClicked.AddDynamic(this, &UInventoryWindow::CloseWindow);
	
	if (SortInventoryButton)
	{
		SortInventoryButton->OnClicked.AddDynamic(this, &UInventoryWindow::SortInventory);
	}
}

void UInventoryWindow::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Drag detected"));

	OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UWidgetDragOperation::StaticClass());
	OutOperation->DefaultDragVisual = this;
	OutOperation->Pivot = EDragPivot::MouseDown;
	Cast<UWidgetDragOperation>(OutOperation)->DragOffset = DragOffset;
	this->RemoveFromParent();
}

FReply UInventoryWindow::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	const FKey DragKey = FKey(FName("RightMouseButton"));
	FEventReply Reply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, DragKey);
	return Reply.NativeReply;
}

void UInventoryWindow::SetVariables(UInventoryComponent* InventoryComp, TSubclassOf<UUserWidget> InventorySlotWidgetClassIn)
{
	Inventory = InventoryComp;
	InventorySlotWidgetClass = InventorySlotWidgetClassIn;
	PlayerHUD = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn())->GetHUDController();
}

void UInventoryWindow::ShowWindow()
{
	CanvasSlot = PlayerHUD->MainHUD->AddToCanvas(this);
	CanvasSlot->SetAutoSize(true);
	CanvasSlot->SetPosition(Inventory->WidgetPosition);
	bWindowOpen = true;
}

void UInventoryWindow::CloseWindow()
{
	CloseInventory();
	PC->bShowMouseCursor = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
}

void UInventoryWindow::CloseInventory()
{
	this->RemoveFromParent();
	bWindowOpen = false;
}

void UInventoryWindow::SortInventory()
{
	Inventory->SortInventory();
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

			if (InventoryItem.bIsValidItem)
			{
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 1)));
				InventoryGrid->RemoveChildAt(InventorySlotWidget->SlotIndex);
				InventorySlotWidget->ImageThumbnail->SetBrushFromTexture(InventoryItem.Thumbnail);
				InventorySlotWidget->SlotIndex = SlotIndex;
				InventorySlotWidget->Inventory = Inventory;
				InventorySlotWidget->TextBlock->SetText(FText::FromString(FString("Test Text")));
			}
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

			if (InventoryItem.bIsValidItem)
			{
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 1)));
				InventorySlotWidget->ImageThumbnail->SetBrushFromTexture(InventoryItem.Thumbnail);
				InventorySlotWidget->SlotIndex = SlotIndex;
				InventorySlotWidget->Inventory = Inventory;
				FString ItemName = Inventory->Inventory_Array_Columns[i].Row_Items[j].Name;
				InventorySlotWidget->TextBlock->SetText(FText::FromString(ItemName));
			}
			else
			{
				InventorySlotWidget = CreateWidget<UInventorySlotWidget>(GetWorld(), InventorySlotWidgetClass);
				
				InventorySlotWidget->ImageThumbnail->SetBrushTintColor(FSlateColor(FLinearColor(1, 1, 1, 0)));
			}
			InventoryGrid->ReplaceChildAt(SlotIndex, InventorySlotWidget);
			SlotIndex += 1;
		}
	}
}
