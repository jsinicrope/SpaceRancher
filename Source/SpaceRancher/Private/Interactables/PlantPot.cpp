// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/PlantPot.h"
#include "Kismet/KismetMathLibrary.h"

APlantPot::APlantPot()
{
	PrimaryActorTick.bCanEverTick = false;

	if (DefaultPlant)
	{
		Plant = Cast<APlant>(DefaultPlant->GetDefaultObject());
		Width -= Plant->GetBottomStemThickness();
		Length -= Plant->GetBottomStemThickness();
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

bool APlantPot::ItemInteract_Implementation(FItem_Struct EquippedItem)
{
	APlant* ItemPlant = Cast<APlant>(EquippedItem.ItemClass->GetDefaultObject());
	if (ItemPlant)
	{
		return SetNewPlant(ItemPlant, true, PlantsToSpawn);
	}
	return false;
}

void APlantPot::LoadActor_Implementation()
{
	
}

FVector APlantPot::GetRandomPlantSpawnPoint()
{
	const float FMinX = GetActorLocation()[0] + Width;
	const float FMaxX = GetActorLocation()[0] - Width;
	const float X = FMath::FRandRange(FMinX, FMaxX);

	const float FMinY = GetActorLocation()[1] + Length;
	const float FMaxY = GetActorLocation()[1] - Length;
	const float Y = FMath::FRandRange(FMinY, FMaxY);

	FVector2D Position2D = FVector2D(X, Y);

	Position2D = UKismetMathLibrary::GetRotated2D(Position2D, GetActorRotation().Yaw);
	FVector NewPosition = FVector(Position2D, GetActorLocation().Z + ZOffset);

	for (int j = 0; j < PlantedPlants.Num(); j++)
	{
		const float MinDistance = Cast<APlant>(PlantedPlants[j])->GetBottomStemThickness() + 5.0f;
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
	if (DefaultPlant || Plant)
	{
		APlant* TempPlant = nullptr;
		if (DefaultPlant)
		{
			TempPlant = Cast<APlant>(DefaultPlant->GetDefaultObject());
		}
		
		if (TempPlant || Plant)
		{
			if (!Plant)
			{
				DestroyAllPlants();
				Plant = TempPlant;
			}
			else
			{
				TempPlant = Plant;
				DestroyAllPlants();
				Plant = TempPlant;
			}
		
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
		
			if (SpawnState == EPlantSpawnState::Random)
			{
				for (int i = 0; i < AmountOfPlants; i++)
				{
					AActor* NewPlant = GetWorld()->SpawnActor<AActor>(Plant->GetClass(), GetRandomPlantSpawnPoint(), GetActorRotation(), SpawnInfo);
					PlantedPlants.Add(NewPlant);
				}
			}
		
			else
			{
				RasteredSpawnPoints.Empty();
				GetRasteredPlantSpawnPoints();
				for (int i = 0; i < RasteredSpawnPoints.Num(); i++)
				{
					AActor* NewPlant = GetWorld()->SpawnActor<AActor>(Plant->GetClass(), RasteredSpawnPoints[i], GetActorRotation(), SpawnInfo);
					PlantedPlants.Add(NewPlant);
				}
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
	Plant = nullptr;
}

bool APlantPot::SetNewPlant(class APlant* NewPlant, bool bSpawnPlants, int AmountOfPlants)
{
	if (!Plant)
	{
		Plant = NewPlant;
		Width -= Plant->GetBottomStemThickness();
		Length -= Plant->GetBottomStemThickness();
		
		if (bSpawnPlants)
		{
			SpawnPlants(AmountOfPlants);
		}

		return true;
	}
	return false;
}
