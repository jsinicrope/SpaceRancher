// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/PlayerBuildable.h"
#include "Items/ItemBase.h"

int FBuildableItemChart::GetTotalItemBasePrice() const
{
	return Item->GetDefaultObject<AItemBase>()->Main_Item_Structure.CreditValue * Amount;
}

TArray<AItemBase*> FBuildablePriceStruct::GetRequiredItemsList() const
{
	TArray<AItemBase*> Items;
	for (const FBuildableItemChart& ItemSet : RequiredItems)
	{
		for (int i = 0; i < ItemSet.Amount; i++)
		{
			Items.Add(ItemSet.Item->GetDefaultObject<AItemBase>());
		}
	}
	return Items;
}

APlayerBuildable::APlayerBuildable()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerBuildable::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerBuildable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
