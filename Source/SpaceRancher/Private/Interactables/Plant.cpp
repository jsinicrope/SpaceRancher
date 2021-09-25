// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Plant.h"
#include "World/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GrowState = 0;
	GameInstanceTimeStart = 0.0f;
	bIsCollectible = bCanBeHarvested;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(GetGameInstance());
	GameInstanceTimeStart = GameInstance->RealTimeMinutes;

	PlantScale[2] = PlantScale[2] * 0.3f;
	this->SetActorScale3D(PlantScale * 0.3f);

	int SetGrowState = GrowState;
	GrowState = 0;
	for (int i = 0; i < SetGrowState; i++)
	{
		GrowPlant();
	}
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlantStateAgeMinutes = GameInstance->RealTimeMinutes - GameInstanceTimeStart;

	if (PlantStateAgeMinutes >= TimePerStage)
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
	PlantScale[2] = PlantScale[2] * 0.3f;
	this->SetActorScale3D(PlantScale * 0.3f);

	int SetGrowState = GrowState;
	GrowState = 0;
	for (int i = 0; i < SetGrowState; i++)
	{
		GrowPlant();
	}
}

bool APlant::GrowPlant()
{
	if (GrowState < GrowthStages)
	{
		GrowState++;
		PlantStateAgeMinutes = 0.0f;
		GameInstanceTimeStart = GameInstance->RealTimeMinutes;

		if (GrowState == 1)
		{
			PlantScale[2] = PlantScale[2] * 3;
			PlantScale = PlantScale * GrowFactor;
			this->SetActorScale3D(PlantScale);
		}
		else
		{
			PlantScale = PlantScale * GrowFactor;
			this->SetActorScale3D(PlantScale);
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool APlant::PickupPlant()
{
	if (GrowState >= MinHarvestableState && GrowState <= MaxHarvestableState)
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
