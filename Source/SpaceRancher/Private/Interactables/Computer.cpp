// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Computer.h"
#include "Components/WidgetComponent.h"
#include "Widgets/UI/ComputerMonitor.h"
#include "Inventory_System/ItemStruct.h"
#include "Characters/Main Character/MyCharacter.h"

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

	PlayerCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ScreenWidget = Cast<UComputerMonitor>(Screen->GetWidget());
	ScreenWidget->SetPlayerCharacter(PlayerCharacter);
	
	SetSellingItemTiles();
}

void AComputer::SetSellingItemTiles()
{
	for (int i = 0; i < SellableItems.Num(); i++)
	{
		if (SellableItems[i])
		{
			ScreenWidget->AddItemToList(Cast<AItemBase>(SellableItems[i]->ClassDefaultObject)->Main_Item_Structure);
		}
	}
}

void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
