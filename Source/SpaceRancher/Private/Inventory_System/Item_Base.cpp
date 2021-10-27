// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/Item_Base.h"
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
	if (!CollectItem(true))
	{
		
		const FString ObjectName = GetName();
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("No interaction implemented for interacted item: ") + ObjectName);
		UE_LOG(LogTemp, Warning, TEXT("No interaction implemented for interacted item: %s"), *ObjectName);
	}
}

bool AItem_Base::CollectItem(bool bAddToInventory)
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
