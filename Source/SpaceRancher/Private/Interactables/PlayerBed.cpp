// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/PlayerBed.h"

// Sets default values
APlayerBed::APlayerBed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WakeUpTime = 10.0f;
	TimeAcceleration = 750.0f;
}

// Called when the game starts or when spawned
void APlayerBed::BeginPlay()
{
	Super::BeginPlay();

	this->SetActorTickEnabled(false);

	GameInstance = Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
}

// Called every frame
void APlayerBed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTimeAcceleration)
	{
		TimeToAccelerate -= (DeltaTime / 60.0f) * GameInstance->TimeScale;

		if (TimeToAccelerate <= 0.0f)
		{
			bTimeAcceleration = false;
			this->SetActorTickEnabled(false);
			GameInstance->TimeScale = 1.0f;
		}
	}

}

void APlayerBed::Interact_Implementation()
{
	TimeToAccelerate = (30.0f + WakeUpTime) - GameInstance->PlayerIngameTime;
	GameInstance->TimeScale = TimeAcceleration;
	bTimeAcceleration = true;
	this->SetActorTickEnabled(true);
}
