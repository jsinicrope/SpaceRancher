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

bool UInventoryComponent::AddItemByIndex(const FItem_Struct &Item_Struct, int Index)
{
	const int Row = Index % Columns;
	const int Column = Index / Columns;
	return AddItem(Item_Struct, Row, Column);
}

bool UInventoryComponent::AddItem(AItemBase* Item, const int Row, const int Column)
{
	return AddItem(Item->Main_Item_Structure, Row, Column);
}

FItem_Struct UInventoryComponent::RemoveItemFromPosition(int Row, int Column)
{
	FItem_Struct Item = Inventory_Array_Columns[Column].Row_Items[Row];
	const FItem_Struct EmptyItem;
	Inventory_Array_Columns[Column].Row_Items[Row] = EmptyItem;
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, TEXT("Item removed from Inventory"));
	return Item;
}

FItem_Struct UInventoryComponent::RemoveItemFromPosition(const int Index)
{
	const int Row = Index % Columns;
	const int Column = Index / Columns;
	return RemoveItemFromPosition(Row, Column);
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

void UInventoryComponent::UpdateInventory()
{
	InventoryWindow->UpdateInventory();
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

	// Sort by name THEN sort the invalid (empty) item to the back
	Algo::SortBy(Items, &FItem_Struct::Name);
	Algo::SortBy(Items, &FItem_Struct::bValidItem, TGreater<>());
	
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

	UpdateInventory();
	return true;
}

int UInventoryComponent::GetNumMultipleItems(FString ItemName)
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
