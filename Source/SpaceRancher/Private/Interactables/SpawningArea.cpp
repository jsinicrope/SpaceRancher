// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/SpawningArea.h"

#include "Characters/Main Character/CppPlayerController.h"

ASpawningArea::ASpawningArea()
{
	PrimaryActorTick.bCanEverTick = true;

	BasePlate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasePlate"));
	RootComponent = BasePlate;
	
	Terminal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Terminal"));
	Terminal->SetupAttachment(RootComponent);

	BasePlate->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASpawningArea::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawningArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawningArea::Interact_Implementation()
{
	const int Price = Buildables[0].GetDefaultObject()->GetCost().RawCreditPrice;
	if (Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController())->DeductCredits(Price))
		Spawn();
}

void ASpawningArea::Spawn()
{
	BuiltObject = GetWorld()->SpawnActor<APlayerBuildable>(Buildables[0], GetActorLocation(), GetActorRotation());
	BasePlate->SetVisibility(false);
}

void ASpawningArea::Destruct()
{
	if (BuiltObject)
	{
		BuiltObject->Destroy();
		BuiltObject = nullptr;
	}
	BasePlate->SetVisibility(true);
}
