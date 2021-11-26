// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Computer.h"
#include "Components/WidgetComponent.h"

AComputer::AComputer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ComputerMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("ComputerMesh"));
	Screen = CreateDefaultSubobject<UWidgetComponent>(TEXT("Screen"));
	
	RootComponent = ComputerMesh;
}

void AComputer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
