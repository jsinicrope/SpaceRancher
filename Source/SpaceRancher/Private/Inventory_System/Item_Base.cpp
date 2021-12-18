// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory_System/ItemBase.h"
#include "Characters/Main Character/MyCharacter.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Main_Item_Structure.bIsValidItem = true;
	Main_Item_Structure.ItemClass = GetClass();
}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AItemBase::Interact_Implementation()
{
	if (!CollectItem(true))
	{
		
		const FString ObjectName = GetName();
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("No interaction implemented for interacted item: ") + ObjectName);
		UE_LOG(LogTemp, Warning, TEXT("No interaction implemented for interacted item: %s"), *ObjectName);
	}
}

bool AItemBase::CollectItem(bool bAddToInventory)
{
	bool ItemAdded = false;
	if (bAddToInventory && bIsCollectible)
	{
		ItemAdded = PC->AddItemToInventory(Main_Item_Structure);
	}
	if (ItemAdded || !bAddToInventory)
	{
		this->Destroy();
		return true;
	}
	return false;
}
