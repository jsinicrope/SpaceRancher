// Fill out your copyright notice in the Description page of Project Settings.

#include "World/SpawnerVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

ASpawnerVolume::ASpawnerVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnerVolume::BeginPlay()
{
	Super::BeginPlay();
	
	if (bSpawnOnBeginPlay)
	{
		SpawnActors();
	}
}

void ASpawnerVolume::BeginDestroy()
{
	DeleteAllActors();

	Super::BeginDestroy();
}

void ASpawnerVolume::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool ASpawnerVolume::LineTraceToGround(FVector &NewPoint) const
{
	FVector InOrigin;
	FVector InBoxExtent;
	FBox BoundingBox = GetComponentsBoundingBox();
	BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
	
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	FHitResult OutHit(ForceInit);
	FVector Start = NewPoint;
	
	FVector End = FVector(Start.X, Start.Y, InOrigin.Z * InBoxExtent.Z * -1);
	if (bBoundingBoxIsLowest)
	{
		End = FVector(Start.X, Start.Y, InOrigin.Z - InBoxExtent.Z);
	}
	
	ECollisionChannel Channel = ECC_Visibility;
	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);
	if (OutHit.GetActor())
	{
		NewPoint = OutHit.ImpactPoint;
		return true;
	}
	if (bBoundingBoxIsLowest)
	{
		NewPoint = End;
		return true;
	}
	return false;
}

void ASpawnerVolume::GetRandomSpawnPoints()
{
	for (int i = 0; i < Population; i++)
	{
		FVector InOrigin;
		FVector InBoxExtent;
		FBox BoundingBox = GetComponentsBoundingBox();
		BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
		FVector NewPoint = UKismetMathLibrary::RandomPointInBoundingBox(InOrigin, InBoxExtent);

		if (LineTraceToGround(NewPoint))
		{
			SpawnPoints.Add(NewPoint);
		}
	}
}

void ASpawnerVolume::GetSphereCenteredSpawnPoints()
{
	for (int i = 0; i < Population; i++)
	{
		FVector InOrigin;
		FVector InBoxExtent;
		FBox BoundingBox = GetComponentsBoundingBox();
		BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
		
		// Calculate a point in a circle with a higher chance to spawn near the circles center
		if (bRandomCenterDensity)
		{
			CenterDensity = FMath::FRand();
		}
		
		const float Radius = FMath::Min(InBoxExtent.X, InBoxExtent.Y) * FMath::Pow(FMath::FRand(), CenterDensity);
		const float Degree = FMath::FRandRange(0.0f, 360.0f);
		const float Y = InOrigin.Y + std::cos(Degree) * Radius;
		const float X = InOrigin.X + std::sin(Degree) * Radius;
		FVector NewPoint = FVector(X, Y, InOrigin.Z);
		
		if (LineTraceToGround(NewPoint))
		{
			SpawnPoints.Add(NewPoint);
		}
	}
}

void ASpawnerVolume::GetRasteredSpawnPoints()
{
	FVector InOrigin;
	FVector InBoxExtent;
	const FBox BoundingBox = GetComponentsBoundingBox();
	BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
	
	const float Scaling = 2.0f * BoxRasterScaling;
	const float StartX = RasterLayout.X == 1 ? InOrigin.X : InOrigin.X - InBoxExtent.X / (1 / BoxRasterScaling);
	const float StartY = RasterLayout.Y == 1 ? InOrigin.Y : InOrigin.Y - InBoxExtent.Y / (1 / BoxRasterScaling);
	const float SegmentLengthX = RasterLayout.X == 1 ? 0.0f : InBoxExtent.X * Scaling / (RasterLayout.X - 1);
	const float SegmentLengthY = RasterLayout.Y == 1 ? 0.0f : InBoxExtent.Y * Scaling / (RasterLayout.Y - 1);
	
	for (int i = 0; i < RasterLayout.Y; i++)
	{
		for (int j = 0; j < RasterLayout.X; j++)
		{
			FVector NewPoint = FVector(StartX + SegmentLengthX * j, StartY + SegmentLengthY * i, InOrigin.Z);
			if (LineTraceToGround(NewPoint))
			{
				SpawnPoints.Add(NewPoint);
			}
		}
	}
}

void ASpawnerVolume::SpawnActors()
{
	DeleteAllActors();
	SpawnPoints.Empty();
	
	switch (SpawnState)
	{
		case (ESpawnState::Centered):
			GetSphereCenteredSpawnPoints();
			break;
		
		case (ESpawnState::Rastered):
			GetRasteredSpawnPoints();
			break;
		
		//  Random case as default spawn setting
		default:
			GetRandomSpawnPoints();
			break;
	}
	
	for (int i = 0; i < SpawnPoints.Num(); i++)
	{
		FVector SpawnPoint = SpawnPoints[i];
		FRotator ActorRotation(0.0f);
		if (bRandomRotation)
		{
			ActorRotation.Yaw += FMath::RandRange(0.0f, 360.0f); 
		}
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		ensure(ActorClasses.Num() >= 1);
		const int RandActor = FMath::RandRange(0, ActorClasses.Num() - 1);
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClasses[RandActor], SpawnPoint, ActorRotation, SpawnParams);
		if (NewActor != nullptr)
		{
			SpawnedActors.Add(NewActor);
		}
	}
}

void ASpawnerVolume::DeleteAllActors()
{
	for (int i = 0; i<SpawnedActors.Num(); i++)
	{
		if (SpawnedActors[i])
		{
			SpawnedActors[i]->Destroy();
		}
	}
	SpawnedActors.Empty();
}
