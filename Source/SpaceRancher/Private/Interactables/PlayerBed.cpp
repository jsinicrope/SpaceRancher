// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/PlayerBed.h"

// Sets default values
APlayerBed::APlayerBed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WakeUpTime = 10.0f;
}

// Called when the game starts or when spawned
void APlayerBed::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerBed::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Bed was Interacted with"));
}
