// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/InventoryComponent.h"


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

	Rows = 5;
	Columns = 5;

	FItemRows Inventory_Row(Rows);
	Inventory_Array_Columns.Init(Inventory_Row, Columns);

}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; j < Inventory_Array_Columns[i].Row_Items.Num(); j++)
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
