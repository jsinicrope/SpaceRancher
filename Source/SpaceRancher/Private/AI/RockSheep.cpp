// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RockSheep.h"

#include "AI/RockSheepController.h"
#include "Items/Gem.h"

ARockSheep::ARockSheep()
{
	PrimaryActorTick.bCanEverTick = true;

	GemSpawnerComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GemSpawnerComponent"));
	GemSpawnerComponent->SetupAttachment(GetMesh());
	
	GemSpawner = CreateDefaultSubobject<UChildActorComponent>(TEXT("GemSpawner"));
	GemSpawner->SetupAttachment(GemSpawnerComponent);
}

void ARockSheep::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorTickEnabled(false);
}

void ARockSheep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ItemTimeToRespawn -= DeltaTime;
	if (ItemTimeToRespawn <= 0)
	{
		SpawnItem();
	}
}

void ARockSheep::Interact_Implementation()
{
	IInteractInterface::Interact_Implementation();

#if WITH_EDITOR
	DamageActor(30.0f);
#endif
}

bool ARockSheep::ItemInteract_Implementation(const FItem_Struct& EquippedItem)
{
	if (TamingItems.Contains(EquippedItem.ItemClass))
	{
		TamingDifficulty -= 1;
		if (TamingDifficulty <= 0)	{ SetAIControllerState(EAIBehaviorState::Tamed); }
		return true;
	}
	return false;
}

void ARockSheep::SetItemState(bool Collectible) const
{
	Item->CurrentlyCollectible = Collectible;
}

void ARockSheep::ItemDestroyed(AActor* Actor)
{
	Item = nullptr;
	ItemTimeToRespawn = ItemRespawnTime;
	SetActorTickEnabled(true);
	OnItemDestroyed.ExecuteIfBound();
}

// TODO Add animation for spawning (simple, like growing/scaling the item in size)
bool ARockSheep::SpawnItem()
{
	if (BackAttachment)
	{
		GemSpawner->SetChildActorClass(BackAttachment);
		GemSpawner->CreateChildActor();
		MoveIgnoreActorAdd(GemSpawner->GetChildActor());
		Item = Cast<AGem>(GemSpawner->GetChildActor());
		Item->OnDestroyed.AddDynamic(this, &ARockSheep::ItemDestroyed);
		
		SetActorTickEnabled(false);
		OnItemSpawned.ExecuteIfBound();
		return true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, FString("No item set as BackAttachment for Entity Rock Sheep: ") + GetName());
	return false;
}

void ARockSheep::SetAIControllerState(const EAIBehaviorState& NewState) const
{
	ARockSheepController* RockSheepController = Cast<ARockSheepController>(Controller);
	RockSheepController->SetAIControllerState(NewState);
}
