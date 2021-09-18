// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventoryWindow.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"

FItemRows::FItemRows(int rows)
{
	FItem_Struct Item;
	Row_Items.Init(Item, rows);
}


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Rows = 5; //Length of column
	Columns = 5; //Length of row
	ItemSlots = 25;

}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	int RemainingItemSlots = ItemSlots;
	for (int i = 0; i < Columns; i++)
	{
		if (RemainingItemSlots > 0)
		{
			int SlotsPerColumn = FMath::Min(Columns, RemainingItemSlots);
			FItemRows Inventory_Row(SlotsPerColumn);
			Inventory_Array_Columns.Add(Inventory_Row);
			RemainingItemSlots -= Columns;
		}
	}

	if (InventoryWindowClass)
	{
		InventoryWindow = CreateWidget<UInventoryWindow>(GetWorld(), InventoryWindowClass);
		InventoryWindow->SetVariables(this, InventorySlotWidgetClass);
		InventoryWindow->SetUpInventory();
	}
}

bool UInventoryComponent::AddItem(FItem_Struct Item_Struct, int row, int column)
{
	for (int i = column; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = row; Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			if (!Inventory_Array_Columns[i].Row_Items[j].bIsValidItem)
			{
				Inventory_Array_Columns[i].Row_Items[j] = Item_Struct;

				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item added to Inventory"));
				return true;
			}
		}

	}

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item doesn't fit in Inventory"));
	return false;
}


FItem_Struct UInventoryComponent::RemoveItemClosestPosition(int row, int column)
{
	FItem_Struct Item = Inventory_Array_Columns[column].Row_Items[row];
	FItem_Struct EmptyItem;
	Inventory_Array_Columns[column].Row_Items[row] = EmptyItem;
	return Item;
}

FItem_Struct UInventoryComponent::RemoveItem(FItem_Struct Item)
{
	FItem_Struct EmptyItem;
	for (int i = Inventory_Array_Columns.Num()-1; i >= 0; i--)
	{
		for (int j = Inventory_Array_Columns[i].Row_Items.Num()-1; j >= 0; j--)
		{
			if (Inventory_Array_Columns[i].Row_Items[j].Name.Equals(Item.Name))
			{
				FItem_Struct NewItem = Inventory_Array_Columns[i].Row_Items[j];
				Inventory_Array_Columns[i].Row_Items[j] = EmptyItem;
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item removed from Inventory"));
				return NewItem;
			}
		}
	}
	return EmptyItem;
}

FItem_Struct UInventoryComponent::RemoveItemByName(FString ItemName)
{
	FItem_Struct EmptyItem;
	for (int i = Inventory_Array_Columns.Num() - 1; i >= 0; i--)
	{
		for (int j = Inventory_Array_Columns[i].Row_Items.Num() - 1; j >= 0; j--)
		{
			if (Inventory_Array_Columns[i].Row_Items[j].Name.Equals(ItemName))
			{
				FItem_Struct NewItem = Inventory_Array_Columns[i].Row_Items[j];
				Inventory_Array_Columns[i].Row_Items[j] = EmptyItem;
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item removed from Inventory"));
				return NewItem;
			}
		}
	}
	return EmptyItem;
}

void UInventoryComponent::ToggleInventory()
{
	if (!bInventoryOpen)
	{
		InventoryWindow->UpdateInventory();
		InventoryWindow->AddToViewport();
		bInventoryOpen = true;
		UWidgetBlueprintLibrary::SetInputMode_GameAndUI(PC);
		PC->bShowMouseCursor = true;
	}
	else
	{
		InventoryWindow->RemoveFromViewport();
		bInventoryOpen = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
		PC->bShowMouseCursor = false;
	}
}
	