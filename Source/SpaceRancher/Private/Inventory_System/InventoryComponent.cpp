// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventoryWindow.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"

FItemRows::FItemRows(int NewRows)
{
	const FItem_Struct Item;
	Row_Items.Init(Item, NewRows);
}


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	int RemainingItemSlots = ItemSlots;
	for (int i = 0; i < Rows; i++)
	{
		if (RemainingItemSlots > 0)
		{
			const int SlotsPerColumn = FMath::Min(Rows, RemainingItemSlots);
			FItemRows Inventory_Row(SlotsPerColumn);
			Inventory_Array_Columns.Add(Inventory_Row);
			RemainingItemSlots -= Rows;
		}
	}

	if (InventoryWindowClass)
	{
		InventoryWindow = CreateWidget<UInventoryWindow>(GetWorld(), InventoryWindowClass);
		InventoryWindow->SetVariables(this, InventorySlotWidgetClass);
		InventoryWindow->SetUpInventory();
	}
}

bool UInventoryComponent::AddItem(FItem_Struct Item_Struct, int Row, int Column)
{
	for (int i = Column; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = Row; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
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

FItem_Struct UInventoryComponent::RemoveItemFromPosition(int Row, int Column)
{
	FItem_Struct Item = Inventory_Array_Columns[Column].Row_Items[Row];
	const FItem_Struct EmptyItem;
	Inventory_Array_Columns[Column].Row_Items[Row] = EmptyItem;
	return Item;
}

FItem_Struct UInventoryComponent::RemoveItem(FItem_Struct Item)
{
	FItem_Struct EmptyItem;
	for (int i = Inventory_Array_Columns.Num() - 1; i >= 0; i--)
	{
		for (int j = Inventory_Array_Columns[i].Row_Items.Num() - 1; j >= 0; j--)
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
	bInventoryOpen = InventoryWindow->bWindowOpen;
	if (!bInventoryOpen)
	{
		if (bAutoSort)
		{
			SortInventory();
		}
		InventoryWindow->UpdateInventory();
		InventoryWindow->ShowWindow();
		UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PC);
		PC->bShowMouseCursor = true;
	}
	else
	{
		InventoryWindow->CloseWindow();
		PC->bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
	}
	bInventoryOpen = InventoryWindow->bWindowOpen;
}

bool UInventoryComponent::GetInventoryOpen()
{
	bInventoryOpen = InventoryWindow->bWindowOpen;
	return bInventoryOpen;
}

bool UInventoryComponent::SortInventory()
{
	// Move Inventory to 2D for easier modification
	// Store values as pointers
	Items.Empty();
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			Items.Add(Inventory_Array_Columns[i].Row_Items[j]);
		}
	}

	Algo::SortBy(Items, &FItem_Struct::Name);
	
	// Move Inventory from 2D back to it's intended shape
	// Read pointer values to inventory
	int index = 0;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			Inventory_Array_Columns[i].Row_Items[j] = Items[index];
			index++;
		}
	}
	
	return true;
}
