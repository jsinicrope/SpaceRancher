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


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

FItemRows::FItemRows(int rows)
{
	FItem_Struct Item;
	Row_Items.Init(Item, rows);
}
