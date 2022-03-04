// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/InventoryComponent.h"
#include "Inventory_System/InventoryWindow.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"

FItemRows::FItemRows(const int NewRows)
{
	const FItem_Struct Item;
	Row_Items.Init(Item, NewRows);
}


UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());

	int RemainingItemSlots = ItemSlots;
	for (int i = 0; i < Rows; i++)
	{
		int SlotsPerColumn = 0;
		for (int j = 0; j < Columns; j++)
		{
			SlotsPerColumn += RemainingItemSlots > 0 ? 1 : 0;
			RemainingItemSlots--;
		}
		FItemRows Inventory_Row(SlotsPerColumn);
		Inventory_Array_Columns.Add(Inventory_Row);
	}

	if (InventoryWindowClass)
	{
		InventoryWindow = CreateWidget<UInventoryWindow>(GetWorld(), InventoryWindowClass);
		InventoryWindow->SetVariables(this, InventorySlotWidgetClass);
		InventoryWindow->SetUpInventory();
	}

	for (int i = 0; i < DefaultItems.Num(); i++)
	{
		if (DefaultItems[i])
		{
			AddItem(Cast<AItemBase>(DefaultItems[i]->ClassDefaultObject)->Main_Item_Structure);
		}
	}
}

bool UInventoryComponent::AddItem(const FItem_Struct &Item_Struct, int Row, int Column)
{
	for (int i = Column; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = Row; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			if (!Inventory_Array_Columns[i].Row_Items[j].bValidItem)
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

bool UInventoryComponent::AddItem(AItemBase* Item, const int Row, const int Column)
{
	return AddItem(Item->Main_Item_Structure, Row, Column);
}

bool UInventoryComponent::AddItems(const TArray<FItem_Struct> Item_Structs)
{
	const int ItemsToAdd = Item_Structs.Num();
	int* Indices = new int[ItemsToAdd];
	int CurrentIndex = 0;
	bool bSuccess = false;
	for (int i = 0; i < Columns; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
			if (!Inventory_Array_Columns[i].Row_Items[j].bValidItem)
			{
				if (CurrentIndex > ItemsToAdd)	bSuccess = true;
				Inventory_Array_Columns[i].Row_Items[j] = Item_Structs[CurrentIndex];
				Indices[CurrentIndex] = j * Columns + i;
				CurrentIndex++;
			}
		}
	}
	
	if (!bSuccess)
	{
		for (int i = 0; i <= CurrentIndex; i++)
		{
			RemoveItemByIndex(i);
		}
	}
	
	return bSuccess;
}

bool UInventoryComponent::AddItemByIndex(const FItem_Struct &Item_Struct, const int Index)
{
	const int Row = Index % Columns;
	const int Column = Index / Columns;
	return AddItem(Item_Struct, Row, Column);
}

FItem_Struct UInventoryComponent::ForceAddItem(const AItemBase* Item, const int Row, const int Column)
{
	if (Row && Column == -1)
	{
		return ForceAddItem(Item->Main_Item_Structure);
	}
	return ForceAddItem(Item->Main_Item_Structure, Row, Column);
}

FItem_Struct UInventoryComponent::ForceAddItem(const FItem_Struct& Item)
{
	FItem_Struct OutItem;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			if (!Inventory_Array_Columns[i].Row_Items[j].bValidItem)
			{
				OutItem = Inventory_Array_Columns[i].Row_Items[j];
				Inventory_Array_Columns[i].Row_Items[j] = Item;
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item added to Inventory"));
				return OutItem;
			}
		}
	}

	OutItem = ForceAddItem(Item, 0, 0);
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item added to Inventory"));
	return OutItem;
}

FItem_Struct UInventoryComponent::ForceAddItem(const FItem_Struct& Item, const int Row, const int Column)
{
	FItem_Struct OutItem = Inventory_Array_Columns[Row].Row_Items[Column];
	Inventory_Array_Columns[Row].Row_Items[Column] = Item;
	return OutItem;
}

FItem_Struct UInventoryComponent::RemoveItemByIndex(const int Row, const int Column)
{
	FItem_Struct Item = Inventory_Array_Columns[Column].Row_Items[Row];
	const FItem_Struct EmptyItem;
	Inventory_Array_Columns[Column].Row_Items[Row] = EmptyItem;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item removed from Inventory"));
	return Item;
}

FItem_Struct UInventoryComponent::RemoveItemByIndex(const int Index)
{
	const int Row = Index % Columns;
	const int Column = Index / Columns;
	return RemoveItemByIndex(Row, Column);
}

FItem_Struct UInventoryComponent::RemoveItem(const FItem_Struct &Item)
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

TArray<FItem_Struct> UInventoryComponent::RemoveItems(const TArray<FString>& ItemNames, bool& bSucceeded)
{
	bSucceeded = false;
	const int ItemsToRemove = ItemNames.Num();
	int* Indices = new int[ItemsToRemove];
	TArray<FItem_Struct> RemovedItems;
	int NumRemovedItems = 0;
	for (int Index = 0; Index < ItemsToRemove; Index++)
	{
		bool bItemRemoved = false;
		for (int i = Inventory_Array_Columns.Num() - 1; i >= 0; i--)
		{
			for (int j = Inventory_Array_Columns[i].Row_Items.Num() - 1; j >= 0; j--)
			{
				if (Inventory_Array_Columns[i].Row_Items[j].Name.Equals(ItemNames[Index]))
				{
					RemovedItems[NumRemovedItems] = Inventory_Array_Columns[i].Row_Items[j];
					Inventory_Array_Columns[i].Row_Items[j] = FItem_Struct();
					Indices[NumRemovedItems] = j * Columns + i;
					bItemRemoved = true;
					bSucceeded = true;
					NumRemovedItems++;
					GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item removed from Inventory"));
				}
			}
		}
		if (!bItemRemoved)
		{
			bSucceeded = false;
			break;
		}
	}

	if (!bSucceeded)
	{
		for (int i = 0; i < NumRemovedItems; i++)
		{
			AddItemByIndex(RemovedItems[i], Indices[i]);
		}
	}
	
	bAutoSort ? SortInventory() : 0;

	return RemovedItems;
}

TArray<FItem_Struct> UInventoryComponent::RemoveItems(const TArray<FItem_Struct>& Items, bool& bSucceeded)
{
	TArray<FString> ItemNames;
	for (int i = 0; i < Items.Num(); i++)
	{
		ItemNames[i] = Items[i].Name;
	}
	return RemoveItems(ItemNames, bSucceeded);
}

TArray<FItem_Struct> UInventoryComponent::RemoveItems(const TArray<AItemBase*>& Items, bool& bSucceeded)
{
	TArray<FString> ItemNames;
	for (int i = 0; i < Items.Num(); i++)
	{
		ItemNames[i] = Items[i]->Main_Item_Structure.Name;
	}
	return RemoveItems(ItemNames, bSucceeded);
}

FItem_Struct UInventoryComponent::RemoveItemByName(const FString ItemName)
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

FItem_Struct UInventoryComponent::Emplace(FItem_Struct& OutItem, FItem_Struct& InItem)
{
	FItem_Struct RemovedItem = RemoveItemByName(OutItem.Name);
	if (RemovedItem.bValidItem)
	{
		AddItem(InItem);
		return RemovedItem;
	}
	return RemovedItem;
}

void UInventoryComponent::ToggleInventory()
{
	!bInventoryOpen ? OpenInventory() : CloseInventory();
}

void UInventoryComponent::OpenInventory()
{
	ensure(InventoryWindow);
	bInventoryOpen = InventoryWindow->GetInventoryOpen();
	if (!bInventoryOpen || InventoryWindow->GetParent() == nullptr)
	{
		if (bAutoSort)
		{
			SortInventory();
		}
		InventoryWindow->UpdateInventory();
		InventoryWindow->ShowWindow();
	}
	bInventoryOpen = InventoryWindow->GetInventoryOpen();
}

void UInventoryComponent::CloseInventory()
{
	ensure(InventoryWindow);
	bInventoryOpen = InventoryWindow->GetInventoryOpen();
	if (bInventoryOpen || InventoryWindow->GetParent() != nullptr)
	{
		InventoryWindow->CloseWindow();
	}
	bInventoryOpen = InventoryWindow->GetInventoryOpen();
}

void UInventoryComponent::ToggleInventoryWithPlayerInventory()
{
	Player = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player->GetInventoryComp() != this)
	{
		if (GetInventoryOpen() && Player->GetInventoryComp()->GetInventoryOpen() ||
			!GetInventoryOpen() && !Player->GetInventoryComp()->GetInventoryOpen())
		{
			Player->ToggleInventory();
			ToggleInventory();
		}
	}
}

bool UInventoryComponent::GetInventoryOpen()
{
	bInventoryOpen = InventoryWindow->GetInventoryOpen();
	return bInventoryOpen;
}

void UInventoryComponent::UpdateInventory() const
{
	InventoryWindow->UpdateInventory();
}

bool UInventoryComponent::SortInventory()
{
	// Move Inventory to 2D for easier modification
	TArray<FItem_Struct> Items;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			Items.Add(Inventory_Array_Columns[i].Row_Items[j]);
		}
	}

	// Sort by name THEN sort the invalid (empty) item to the back
	Algo::SortBy(Items, &FItem_Struct::Name);
	Algo::SortBy(Items, &FItem_Struct::bValidItem, TGreater<>());
	
	// Move Inventory from 2D back to it's intended shape
	int Index = 0;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			Inventory_Array_Columns[i].Row_Items[j] = Items[Index];
			Index++;
		}
	}

	UpdateInventory();
	return true;
}

int UInventoryComponent::GetOccurrences(const FString ItemName)
{
	int Amount = 0;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			if (Inventory_Array_Columns[i].Row_Items[j].Name.Equals(ItemName))
			{
				Amount++;
			}
		}
	}
	return Amount;
}

TArray<FItem_Struct> UInventoryComponent::GetUniqueSelectables()
{
	TArray<FItem_Struct> Uniques;
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			const FItem_Struct Item = Inventory_Array_Columns[i].Row_Items[j];

			if (Item.bSelectable && !Uniques.Contains(Item))
			{
				Uniques.Add(Item);
			}
		}
	}
	
	return Uniques;
}

bool UInventoryComponent::Contains(const FItem_Struct& Item)
{
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
		{
			if (Inventory_Array_Columns[i].Row_Items[j] == Item)
			{
				return true;
			}
		}
	}
	return false;
}
