// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/InventoryComponent.h"

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

bool UInventoryComponent::AddItem(FItem_Struct Item_Struct)
{
	//Loop over inventory slots
	for (int i = 0; i < Inventory_Array_Columns.Num(); i++)
	{
		for (int j = 0; Inventory_Array_Columns[i].Row_Items.Num(); j++)
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


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

FItem_Struct UInventoryComponent::RemoveItem(int row, int column)
{
	return Inventory_Array_Columns[column].Row_Items[row];
}

FItemRows::FItemRows(int rows)
{
	FItem_Struct Item;
	Row_Items.Init(Item, rows);
}
