// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryWindow.h"
#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventorySlotWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"

void UInventoryWindow::NativeConstruct()
{
	Super::NativeConstruct();

	//Initialize Pointers to Widget settings in Editor
	InventoryTitle = Cast<UTextBlock>(GetWidgetFromName(FName("InventoryTitle")));
	InventoryGrid = Cast<UGridPanel>(GetWidgetFromName(FName("InventoryGrid")));
	CloseInventoryButton = Cast<UButton>(GetWidgetFromName(FName("CloseInventoryButton")));

	CloseInventoryButton->OnClicked.AddDynamic(this, &UInventoryWindow::CloseWindow);
}

void UInventoryWindow::SetVariables(UInventoryComponent* InventoryComp, TSubclassOf<UUserWidget> InventorySlotWidgetClassIn)
{
	Inventory = InventoryComp;
	InventorySlotWidgetClass = InventorySlotWidgetClassIn;
}

void UInventoryWindow::ShowWindow()
{
	this->AddToViewport();
	bWindowOpen = true;
}

void UInventoryWindow::CloseWindow()
{
	this->RemoveFromViewport();
	bWindowOpen = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
	PC->bShowMouseCursor = false;
}

void UInventoryWindow::CloseInventory()
{
	PC->bShowMouseCursor = true;
	this->RemoveFromViewport();
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
	bWindowOpen = false;
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
