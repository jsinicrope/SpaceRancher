// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Plant.h"
#include "World/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(GetGameInstance());
	
	GameInstanceTimeStart = GameInstance->RealTimeMinutes;
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlantStateAgeMinutes = GameInstance->RealTimeMinutes - GameInstanceTimeStart;
}

void APlant::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Interacted with Plant"));
}

bool APlant::SwitchState()
{
	if (GrowState < GrowthStages)
	{
		GrowState++;
		PlantStateAgeMinutes = 0.0f;
		return true;
	}
	else
	{
		return false;
	}
}
