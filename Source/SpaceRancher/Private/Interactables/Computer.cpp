// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Computer.h"
#include "Components/WidgetComponent.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Widgets/ComputerHUDs/TradeTerminal/ComputerScreen.h"
#include "Widgets/ComputerHUDs/TradeTerminal/ComputerBuying.h"

AComputer::AComputer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ComputerMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("ComputerMesh"));
	Screen = CreateDefaultSubobject<UWidgetComponent>(TEXT("Screen"));
	SetRootComponent(ComputerMesh);
	Screen->SetupAttachment(ComputerMesh);
}

void AComputer::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ScreenWidget = Cast<UComputerScreen>(Screen->GetWidget());
	ScreenWidget->SetOwningComputer(this);
	ScreenWidget->SetSellingTabActive();

	ScreenWidget->BuyingTab->SetMaxStock(MaxBuyStock);
}

void AComputer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
