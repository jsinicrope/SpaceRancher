// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Computer.h"
#include "Components/WidgetComponent.h"
#include "Widgets/UI/Computer_ItemSelling.h"
#include "Inventory_System/ItemStruct.h"

AComputer::AComputer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ComputerMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("ComputerMesh"));
	Screen = CreateDefaultSubobject<UWidgetComponent>(TEXT("Screen"));
	
	ComputerMesh->SetupAttachment(RootComponent);
	Screen->SetupAttachment(ComputerMesh);
}

void AComputer::BeginPlay()
{
	Super::BeginPlay();

	ScreenWidget = Cast<UComputer_ItemSelling>(Screen->GetWidget());
    	
	SetSellingItemTiles();
}

void AComputer::SetSellingItemTiles()
{
	for (int i = 0; i < SellableItems.Num(); i++)
	{
		ScreenWidget->AddItemToList(SellableItems[i]);
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("Item added to widget"));
	}
}

void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
