// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RockSheep.h"
#include "Items/AffectableItemBase.h"

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

	if (BackAttachment)
	{
		GemSpawner->SetChildActorClass(BackAttachment);
		GemSpawner->CreateChildActor();
		MoveIgnoreActorAdd(GemSpawner->GetChildActor());
		Item = Cast<AAffectableItemBase>(GemSpawner->GetChildActor());
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, FString("No item set as BackAttachment for Entity Rock Sheep: ") + GetName());
	}
}

void ARockSheep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARockSheep::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARockSheep::SetItemState(bool Collectible) const
{
	Item->CurrentlyCollectible = Collectible;
}
