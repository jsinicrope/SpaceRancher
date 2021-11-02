// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/PlantPot.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlantPot::APlantPot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (Plant)
	{
		MainPlant = Cast<APlant>(Plant);
		Width -= MainPlant->BottomStemThickness;
		Length -= MainPlant->BottomStemThickness;
	}
}

// Called when the game starts or when spawned
void APlantPot::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlants(PlantsToSpawn);
}

// Called every frame
void APlantPot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlantPot::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Interacted with Planter"));
	DestroyAllPlants();
}

void APlantPot::LoadActor_Implementation()
{
	
}

FVector APlantPot::GetRandomPlantSpawnPoint()
{

	float fMinX = GetActorLocation()[0] + Width;
	float fMaxX = GetActorLocation()[0] - Width;
	float X = FMath::FRandRange(fMinX, fMaxX);

	float fMinY = GetActorLocation()[1] + Length;
	float fMaxY = GetActorLocation()[1] - Length;
	float Y = FMath::FRandRange(fMinY, fMaxY);

	FVector2D Position2D = FVector2D(X, Y);

	Position2D = UKismetMathLibrary::GetRotated2D(Position2D, GetActorRotation().Yaw);
	FVector NewPosition = FVector(Position2D, GetActorLocation()[2]);

	for (int j = 0; j < PlantedPlants.Num(); j++)
	{
		float MinDistance = Cast<APlant>(PlantedPlants[j])->BottomStemThickness + 5.0f;
		if (NewPosition.Equals(PlantedPlants[j]->GetActorLocation(), MinDistance))
		{
			NewPosition = GetRandomPlantSpawnPoint();
		}
		
	}
	
	return NewPosition;
}

void APlantPot::SpawnPlants(int AmountOfPlants)
{
	if (Plant)
	{
		for (int i = 0; i < AmountOfPlants; i++)
		{
			FVector SpawnPoint = GetRandomPlantSpawnPoint();
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
			AActor* NewPlant = GetWorld()->SpawnActor<AActor>(Plant, SpawnPoint, GetActorRotation(), SpawnInfo);
			PlantedPlants.Add(NewPlant);
		}
	}
}

void APlantPot::DestroyAllPlants()
{
	for (int i = 0; i < PlantedPlants.Num(); i++)
	{
		Cast<APlant>(PlantedPlants[i])->CollectItem(false);
	}
	PlantedPlants.Empty();
	MainPlant = nullptr;
}

bool APlantPot::SetNewPlant(class TSubclassOf<APlant> NewPlant, bool bSpawnPlants, int AmountOfPlants)
{
	if (MainPlant == nullptr)
	{
		Plant = NewPlant;
		MainPlant = Cast<APlant>(Plant);
		Width -= MainPlant->BottomStemThickness;
		Length -= MainPlant->BottomStemThickness;

		if (bSpawnPlants)
		{
			SpawnPlants(AmountOfPlants);
		}

		return true;
	}
	return false;
}
