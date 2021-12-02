// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/PlantPot.h"
#include "Kismet/KismetMathLibrary.h"

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

void APlantPot::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlants(PlantsToSpawn);
}

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
	FVector NewPosition = FVector(Position2D, GetActorLocation().Z + ZOffset);

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

void APlantPot::GetRasteredPlantSpawnPoints()
{
	const float Scaling = 2.0f * BoxRasterScaling;
	const float StartX = RasterLayout.X == 1 ? GetActorLocation().X : GetActorLocation().X - Length / (1 / BoxRasterScaling);
	const float StartY = RasterLayout.Y == 1 ? GetActorLocation().Y : GetActorLocation().Y - Width / (1 / BoxRasterScaling);
	const float SegmentLengthX = RasterLayout.X == 1 ? 0.0f : Length * Scaling / (RasterLayout.X - 1);
	const float SegmentLengthY = RasterLayout.Y == 1 ? 0.0f : Width * Scaling / (RasterLayout.Y - 1);
	
	for (int i = 0; i < RasterLayout.Y; i++)
	{
		for (int j = 0; j < RasterLayout.X; j++)
		{
			FVector NewPoint = FVector(StartX + SegmentLengthX * j, StartY + SegmentLengthY * i, GetActorLocation().Z + ZOffset);
			RasteredSpawnPoints.Add(NewPoint);
		}
	}
}

void APlantPot::Spawn()
{
	SpawnPlants(PlantsToSpawn);
}

void APlantPot::SpawnPlants(int AmountOfPlants)
{
	if (Plant)
	{
		DestroyAllPlants();
		
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = this;
		
		if (SpawnState == EPlantSpawnState::Random)
		{
			for (int i = 0; i < AmountOfPlants; i++)
			{
				AActor* NewPlant = GetWorld()->SpawnActor<AActor>(Plant, GetRandomPlantSpawnPoint(), GetActorRotation(), SpawnInfo);
				PlantedPlants.Add(NewPlant);
			}
		}
		
		else
		{
			RasteredSpawnPoints.Empty();
			GetRasteredPlantSpawnPoints();
			for (int i = 0; i < RasteredSpawnPoints.Num(); i++)
			{
				AActor* NewPlant = GetWorld()->SpawnActor<AActor>(Plant, RasteredSpawnPoints[i], GetActorRotation(), SpawnInfo);
				PlantedPlants.Add(NewPlant);
			}
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
