// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/Item_Base.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Characters/Main Character/MyCharacter.h"

// Sets default values
AItem_Base::AItem_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Main_Item_Structure.bIsValidItem = true;
}

void AItem_Base::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AItem_Base::Interact_Implementation()
{
	if (bIsCollectible)
	{
		PC->AddItemToInventory(Main_Item_Structure);
	}
	else
	{
		FString ObjectName = UKismetSystemLibrary::GetObjectName(this);
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("No interaction implemented for interacted item: ") + ObjectName);
	}
}

bool AItem_Base::CollectItem(bool bAddToInventory)
{
	bool ItemAdded = false;
	if (bAddToInventory && bIsCollectible)
	{
		ItemAdded = PC->AddItemToInventory(Main_Item_Structure);
	}
	if (ItemAdded)
	{
		this->Destroy();
		return true;
	}
	else
	{
		return false;
	}
}
