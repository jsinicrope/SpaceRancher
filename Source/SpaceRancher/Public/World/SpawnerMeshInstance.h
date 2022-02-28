// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SpawnerMeshInstance.generated.h"

UCLASS(NotBlueprintable)
class SPACERANCHER_API ASpawnerMeshInstance : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ASpawnerMeshInstance();
	
	UPROPERTY()
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;
};
