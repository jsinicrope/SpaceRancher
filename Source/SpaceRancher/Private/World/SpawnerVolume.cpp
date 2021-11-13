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
		SpawnActors(Amount);
	}
}

void ASpawnerVolume::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FVector ASpawnerVolume::GetSpawnPoint()
{
	FVector InOrigin;
	FVector InBoxExtent;
	FBox BoundingBox = GetComponentsBoundingBox();
	BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
	FVector NewPoint = UKismetMathLibrary::RandomPointInBoundingBox(InOrigin, InBoxExtent);
	
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	FHitResult OutHit(ForceInit);
	FVector Start = NewPoint;
	FVector End = Start - (NewPoint.Z * InBoxExtent.Z);
	ECollisionChannel Channel = ECC_Visibility;
	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, Channel, TraceParams);
	if (OutHit.GetActor())
	{
		return OutHit.ImpactPoint;
	}
	
	return FVector();
}

void ASpawnerVolume::SpawnActors(int SpawnAmount)
{
	for (int i = 0; i < SpawnAmount; i++)
	{
		FRotator ActorRotation(0.0f);
		if (bRandomRotation)
		{
			ActorRotation.Yaw += FMath::RandRange(0.0f, 360.0f); 
		}
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClass, GetSpawnPoint(), ActorRotation, SpawnParams);
		if (NewActor)
		{
			SpawnedActors.Add(NewActor);
		}
	}
}

void ASpawnerVolume::DeleteAllActors()
{
	for (int i = 0; i<SpawnedActors.Num(); i++)
	{
		SpawnedActors[i]->Destroy();
	}
	SpawnedActors.Empty();
}
