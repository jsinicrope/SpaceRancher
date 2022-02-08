// Fill out your copyright notice in the Description page of Project Settings.

#include "World/SpawnerVolume.h"

#include "Components/BrushComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "World/SpawnerMeshInstance.h"

ASpawnerVolume::ASpawnerVolume()
{
	PrimaryActorTick.bCanEverTick = true;
	GetBrushComponent()->SetMobility(EComponentMobility::Movable);
}

void ASpawnerVolume::BeginPlay()
{
	Super::BeginPlay();
	
	if (bSpawnOnBeginPlay)
	{
		SpawnObjects();
	}

	SetActorTickEnabled(false);
	if (bCanRespawn)
	{
		SetActorTickEnabled(true);
	}
}

void ASpawnerVolume::BeginDestroy()
{
	DeleteAllObjects();

	Super::BeginDestroy();
}

bool ASpawnerVolume::PreSaveActor_Implementation()
{
	SpawnedObjectsLastSave = SpawnedObjects;
	return true;
}

bool ASpawnerVolume::PreLoadActor_Implementation()
{
	return true;
}

void ASpawnerVolume::PostSaveActor_Implementation()
{
	
}

void ASpawnerVolume::PostLoadActor_Implementation()
{
	if (!SpawnedActors[0]) return;
	while (SpawnedObjects > SpawnedObjectsLastSave && SpawnedObjectsLastSave != 0)
	{
		DeleteLastAddedActor();
	}
}

void ASpawnerVolume::SetCanRespawn(const bool bValue)
{
	bCanRespawn = bValue;
	if (bCanRespawn) SetActorTickEnabled(true);
	else SetActorTickEnabled(false);
}

void ASpawnerVolume::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	TimeSinceRespawn += DeltaSeconds;
	if (TimeSinceRespawn > TimeToRespawn)
	{
		VerifyActiveActors();
		if (SpawnedObjects <= MaxNumberBeforeRespawn)
		{
			AddObjects(AmountToRespawn);
		}
		TimeSinceRespawn = 0.0f;
	}
}

bool ASpawnerVolume::LineTraceToGround(FVector &NewPoint, FRotator &OutRotation) const
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
		OutRotation = (OutHit.ImpactNormal + Start.DownVector).Rotation();
		return true;
	}
	if (bBoundingBoxIsLowest)
	{
		NewPoint = End;
		return true;
	}
	return false;
}

void ASpawnerVolume::GetRandomSpawnPoints(int Amount)
{
	for (int i = 0; i < Amount; i++)
	{
		FVector InOrigin;
		FVector InBoxExtent;
		FBox BoundingBox = GetComponentsBoundingBox();
		BoundingBox.GetCenterAndExtents(InOrigin, InBoxExtent);
		FVector NewPoint = UKismetMathLibrary::RandomPointInBoundingBox(InOrigin, InBoxExtent);
		FRotator OutRotation;
		if (LineTraceToGround(NewPoint, OutRotation))
		{
			SpawnPoints.Add(NewPoint);
			SpawnRotation.Add(OutRotation);
		}
	}
}

void ASpawnerVolume::GetSphereCenteredSpawnPoints(int Amount)
{
	for (int i = 0; i < Amount; i++)
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

		// Radius is unified
		float Radius = FMath::Pow(FMath::FRand(), CenterDensity);
		Radius = Radius < InnerRing ? InnerRing : Radius;
		Radius = Radius > OuterRing ? OuterRing : Radius;
		Radius *= FMath::Min(InBoxExtent.X, InBoxExtent.Y);
		
		const float Degree = FMath::FRandRange(0.0f, 360.0f);
		const float Y = InOrigin.Y + std::cos(Degree) * Radius;
		const float X = InOrigin.X + std::sin(Degree) * Radius;
		FVector NewPoint = FVector(X, Y, InOrigin.Z);
		
		FRotator OutRotation;
		if (LineTraceToGround(NewPoint, OutRotation))
		{
			SpawnPoints.Add(NewPoint);
			SpawnRotation.Add(OutRotation);
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
			FRotator OutRotation;
			if (LineTraceToGround(NewPoint, OutRotation))
			{
				SpawnPoints.Add(NewPoint);
				SpawnRotation.Add(OutRotation);
			}
		}
	}
}

bool ASpawnerVolume::PrepareMeshInstancing()
{
	if (Meshes.Num() == 0)	return false;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	if (InstancedMeshes.Num() == Meshes.Num())
	{
		return true;
	}
	
	for (int i = 0; i < Meshes.Num(); i++)
	{
		checkf(Meshes[i], TEXT("Meshes Array in SpawnerVolume Object has empty field"));
		ASpawnerMeshInstance* InstancedMesh = GetWorld()->SpawnActor<ASpawnerMeshInstance>(ASpawnerMeshInstance::StaticClass(), SpawnParams);
		InstancedMesh->InstancedStaticMeshComponent->SetStaticMesh(Meshes[i]);
		InstancedMeshes.Add(InstancedMesh);
	}
	return true;
}

AActor* ASpawnerVolume::SpawnActor(FVector SpawnPoint, FRotator Rotation)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	if (!bAlignToGround)
	{
		Rotation.Roll = FMath::RandRange(0.0f, ActorsRandomXRotation);
		Rotation.Pitch = FMath::RandRange(0.0f, ActorsRandomYRotation);
	}
	
	const int RandActor = FMath::RandRange(0, ActorClasses.Num() - 1);
	checkf(ActorClasses[RandActor], TEXT("ActorClasses Array in SpawnerVolume Object has empty field"));
	AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClasses[RandActor], SpawnPoint, Rotation, SpawnParams);
	
	const FVector RandomScale = FVector(FMath::RandRange(ActorsMinScale, ActorsMaxScale));
	NewActor->SetActorScale3D(RandomScale);
	return NewActor;
}

void ASpawnerVolume::SpawnMesh(FVector SpawnPoint, FRotator Rotation)
{
	FTransform Spawn = FTransform();
	if (!bAlignToGround)
	{
		Rotation.Roll = FMath::RandRange(0.0f, MeshesRandomXRotation);
		Rotation.Pitch = FMath::RandRange(0.0f, MeshesRandomYRotation);
	}
	
	const FVector RandomScale = FVector(FMath::RandRange(MeshesMinScale, MeshesMaxScale));
	Spawn.SetLocation(SpawnPoint);
	Spawn.SetRotation(Rotation.Quaternion());
	Spawn.SetScale3D(RandomScale);

	const int RandMesh = FMath::RandRange(0, Meshes.Num() - 1);
	InstancedMeshes[RandMesh]->InstancedStaticMeshComponent->AddInstanceWorldSpace(Spawn);
}

void ASpawnerVolume::SpawnObjects()
{
	SpawnPoints.Empty();
	SpawnRotation.Empty();
	DeleteAllObjects();
	if (Meshes.Num() >= 1)	PrepareMeshInstancing();
	AddObjects();
}

void ASpawnerVolume::AddObjects()
{
	AddObjects(Population);
}

void ASpawnerVolume::AddObjects(int Amount)
{
	SpawnPoints.Empty();
	SpawnRotation.Empty();
	
	switch (SpawnState)
	{
	case ESpawnState::Centered:
		GetSphereCenteredSpawnPoints(Amount);
		break;
		
	case ESpawnState::Rastered:
		GetRasteredSpawnPoints();
		break;
		
		//  Random case as default spawn setting
		default:
			GetRandomSpawnPoints(Amount);
		break;
	}

	SpawnedObjects += SpawnPoints.Num();
	for (int i = 0; i < SpawnPoints.Num(); i++)
	{
		const FVector SpawnPoint = SpawnPoints[i];
		FRotator ActorRotation = SpawnRotation[i];
		if (bRandomRotation)
		{
			ActorRotation.Yaw += FMath::RandRange(0.0f, 360.0f); 
		}

		int CanUseMesh = 0;
		int CanUseActors = 0;
		if (Meshes.Num() >= 1 && bUseMeshes)	CanUseMesh = 1;
		if (ActorClasses.Num() >= 1 && bUseActors)	CanUseActors = 1; 
		
		const int Spawner = CanUseMesh && CanUseActors ? 2 : 1;

		// Determine whether to spawn an actor or mesh if both are used
		if (Spawner == 2)
		{
			const int Switch = FMath::RandRange(0, 1);
			if (Switch == 0)
			{
				SpawnMesh(SpawnPoint, ActorRotation);
			}
			else
			{
				AActor * NewActor = SpawnActor(SpawnPoint, ActorRotation);
				if (NewActor != nullptr)
				{
					SpawnedActors.Add(NewActor);
				}
			}
		}
		else if (Spawner == 1)
		{
			if (CanUseMesh)
			{
				SpawnMesh(SpawnPoint, ActorRotation);
			}
			else if (CanUseActors)
			{
				AActor * NewActor = SpawnActor(SpawnPoint, ActorRotation);
				if (NewActor != nullptr)
				{
					SpawnedActors.Add(NewActor);
				}
			}
		}
	}
}

void ASpawnerVolume::VerifyActiveActors()
{
	SpawnedObjects = 0;
	for (int i = 0; i < SpawnedActors.Num(); i++)
	{
		if (IsValid(SpawnedActors[i]))
		{
			SpawnedObjects++;
		}
	}
	
	for (int i = 0; i < InstancedMeshes.Num(); i++)
	{
		if (IsValid(InstancedMeshes[i]))
		{
			SpawnedObjects++;
		}
	}
}

void ASpawnerVolume::DeleteLastAddedActor()
{
	if (SpawnedActors.IsEmpty() || SpawnedActors.Last() == nullptr) return;
	SpawnedActors.Last()->Destroy();
	SpawnedActors.RemoveAt(SpawnedActors.Num() - 1);
	SpawnedObjects--;
}

void ASpawnerVolume::DeleteLastAddedMesh()
{
	InstancedMeshes.Last()->Destroy();
	SpawnedObjects--;
}

void ASpawnerVolume::DeleteAllObjects()
{
	for (int i = 0; i < SpawnedActors.Num(); i++)
	{
		if (SpawnedActors[i])
		{
			SpawnedActors[i]->Destroy();
		}
	}

	for (int i = 0; i < InstancedMeshes.Num(); i++)
	{
		if (InstancedMeshes[i])
		{
			InstancedMeshes[i]->Destroy();
		}
	}

	for (int i = 0; i < SpawnedActors.Num(); i++)
	{
		if (!SpawnedActors[i]) {SpawnedActors.RemoveAt(i, 1, true);}
		
	}

	for (int i = 0; i < InstancedMeshes.Num(); i++)
	{
		if (!InstancedMeshes[i]) {InstancedMeshes.RemoveAt(i, 1, true);}
	}
	
	SpawnedObjects = 0;
	InstancedMeshes.Empty();
	SpawnedActors.Empty();
}
