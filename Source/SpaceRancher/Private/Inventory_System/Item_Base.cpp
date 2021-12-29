// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Inventory_System/ItemBase.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Main_Item_Structure.bValidItem = true;
	Main_Item_Structure.ItemClass = GetClass();
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());
}

void AItemBase::Interact_Implementation()
{
	if (!Collect(true))
	{
		const FString ObjectName = GetName();
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("No interaction implemented for interacted item: ") + ObjectName);
		UE_LOG(LogTemp, Warning, TEXT("No interaction implemented for interacted item: %s"), *ObjectName);
	}
}

// Default function returns true to signal the item was used up.
bool AItemBase::ItemInteract_Implementation(FItem_Struct EquippedItem)
{
	if ((!RequiredItem || EquippedItem.ItemClass == RequiredItem) && bInventoryAddable)
	{
		return true;
	}
	return false;
}

bool AItemBase::PreSaveActor_Implementation()
{
	return true;
}

bool AItemBase::PreLoadActor_Implementation()
{
	return true;
}

void AItemBase::PostSaveActor_Implementation()
{
	
}

void AItemBase::PostLoadActor_Implementation()
{
	
}

bool AItemBase::Collect_Implementation(bool bAddToInventory)
{
	bool ItemAdded = false;
	if (bAddToInventory && bInventoryAddable)
	{
		ItemAdded = PC->GetPlayerCharacter()->AddInventoryItem(Main_Item_Structure);
	}
	if (ItemAdded || !bAddToInventory)
	{
		this->Destroy();
		return true;
	}
	return false;
}
