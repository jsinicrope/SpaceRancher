// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Plant.h"
#include "World/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	bIsCollectible = bCanBeHarvested;
	
	if (StateMeshes.Num() > 0)
	{
		StaticMesh->SetStaticMesh(StateMeshes[0]);
	}
}

void APlant::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(GetGameInstance());

	if (StateMeshes.Num() > GrowthState - 1)
	{
		StaticMesh->SetStaticMesh(StateMeshes[GrowthState - 1]);
	}
}

void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlantStateAgeMinutes += GameInstance->bIsDay ? DeltaTime : DeltaTime * NightGrowthSpeed;
	
	if (PlantStateAgeMinutes >= TimePerStage * 60.0f)
	{
		GrowPlant();
	}
}

void APlant::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Interacted with Plant"));
	PickupPlant();
}

void APlant::LoadActor_Implementation()
{
	
}

void APlant::SaveActor_Implementation()
{
	
}

bool APlant::GrowPlant()
{
	if (GrowthState < GrowthStages)
	{
		GrowthState++;
		PlantStateAgeMinutes = 0.0f;
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Plant grew"));
		if (StateMeshes.Num() > GrowthState - 1)
		{
			StaticMesh->SetStaticMesh(StateMeshes[GrowthState - 1]);
		}
		return true;
	}
	
	return false;
}

bool APlant::PickupPlant()
{
	if (GrowthState >= MinHarvestableState && GrowthState <= MaxHarvestableState)
	{
		return CollectItem();
	}
	return false;
}

bool APlant::WaterPlant()
{
	GrowPlant();
	return true;
}
