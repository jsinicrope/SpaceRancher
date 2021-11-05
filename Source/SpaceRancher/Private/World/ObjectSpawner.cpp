// Fill out your copyright notice in the Description page of Project Settings.

#include "World/ObjectSpawner.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

AObjectSpawner::AObjectSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	BoundingBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoundingBox"));
	AddOwnedComponent(BoundingBox);
}

void AObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (bSpawnOnBeginPlay)
	{
		BoundingBox->SetVisibility(false);
		SpawnActors(Amount);
	}
}

void AObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector AObjectSpawner::GetSpawnPoint()
{
	if (BoundingBox->GetStaticMesh() != nullptr)
	{
		FVector InOrigin;
		FVector InBoxExtent;
		float InSphereRadius;
		UKismetSystemLibrary::GetComponentBounds(BoundingBox, InOrigin, InBoxExtent, InSphereRadius);
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
	
	UE_LOG(LogTemp, Warning, TEXT("No Bounding Box Set on Object"));
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, FString("No Bounding Box Set on Object: ") + GetName());
	return FVector();
}

void AObjectSpawner::SpawnActors(int SpawnAmount)
{
	for (int i = 0; i < SpawnAmount; i++)
	{
		FVector SpawnPoint = GetSpawnPoint();
		FRotator ActorRotation(0.0f);
		if (bRandomRotation)
		{
			ActorRotation.Yaw += FMath::RandRange(0.0f, 360.0f); 
		}
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClass, SpawnPoint, ActorRotation, SpawnParams);
		SpawnedActors.Add(NewActor);
	}
}

void AObjectSpawner::DeleteAllActors()
{
	for (AActor* Actor : SpawnedActors)
	{
		Actor->Destroy();
	}
	SpawnedActors.Empty();
}
