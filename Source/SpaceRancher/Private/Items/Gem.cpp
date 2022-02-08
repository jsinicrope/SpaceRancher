// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Gem.h"


AGem::AGem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
