// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SpawnerComponent.h"

USpawnerComponent::USpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USpawnerComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void USpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USpawnerComponent::SetSpawner(TSubclassOf<AActor> NewSpawnable)
{
	if (NewSpawnable)
	{
		Spawnable = NewSpawnable;
	}
}

AActor* USpawnerComponent::Spawn()
{
	if (!Spawnable) { return nullptr; }
	
	const FVector SpawnLocation = GetComponentLocation();
	const FRotator SpawnRotation = GetComponentRotation();
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnedObject = GetWorld()->SpawnActor<AActor>(Spawnable, SpawnLocation, SpawnRotation, SpawnParameters);
	return SpawnedObject;
}

AActor* USpawnerComponent::Spawn(UClass* Object)
{
	if (Object)
		Spawnable = Object;
	return Spawn();
}

bool USpawnerComponent::DestroySpawned()
{
	if (SpawnedObject)
	{
		SpawnedObject->Destroy();
		return true;
	}
	return false;
}
