// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/PlayerBed.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerBed::APlayerBed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WakeUpTime = 10.0f;
	AllowSleepTime = 23.0f;
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
}

void APlayerBed::Interact_Implementation()
{
	if ((GameInstance->GameHour >= AllowSleepTime) || (GameInstance->GameHour < WakeUpTime))
	{
		GameInstance->AccelerateTime(WakeUpTime, 0, TimeAcceleration);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Can't sleep! Too early"));
	}
}
