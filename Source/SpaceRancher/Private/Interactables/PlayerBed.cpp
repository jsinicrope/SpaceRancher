// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/PlayerBed.h"
#include "Kismet/GameplayStatics.h"

APlayerBed::APlayerBed()
{
	PrimaryActorTick.bCanEverTick = true;
}

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
}

void APlayerBed::Interact_Implementation()
{
	if (GameInstance->GameHour >= AllowSleepTime || GameInstance->GameHour < WakeUpTime)
	{
		GameInstance->AccelerateTime(WakeUpTime, 0, TimeAcceleration);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Can't sleep! Too early"));
	}
}
