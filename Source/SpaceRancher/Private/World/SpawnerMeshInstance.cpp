// Fill out your copyright notice in the Description page of Project Settings.

#include "World/SpawnerMeshInstance.h"

ASpawnerMeshInstance::ASpawnerMeshInstance()
{
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMeshComponent"));
	RootComponent = InstancedStaticMeshComponent;
}
