// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/PlayerBuildable.h"

APlayerBuildable::APlayerBuildable()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerBuildable::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerBuildable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
