// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/SpawningArea.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/BuildableDisplayStruct.h"

ASpawningArea::ASpawningArea()
{
	PrimaryActorTick.bCanEverTick = true;

	BasePlate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BasePlate"));
	RootComponent = BasePlate;
	
	Terminal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Terminal"));
	Terminal->SetupAttachment(RootComponent);

	Screen = CreateDefaultSubobject<UWidgetComponent>(FName("Screen"));
	Screen->SetupAttachment(Terminal);
}

void ASpawningArea::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetCharacter());
	ScreenWidget = Cast<USpawningTerminalWindow>(Screen->GetWidget());
	ensureAlwaysMsgf(ScreenWidget, TEXT("An invalid Widget was set as the display for %s"), *GetName());
	UpdateScreenWidgets();
}

void ASpawningArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASpawningArea::RequestBuyWithCredits(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass)
{
	if (!CanSpawn()) return false;
	
	ACppPlayerController* PC = Cast<ACppPlayerController>(PlayerCharacter->GetController());
	if (PC->DeductCredits(ItemPrice.RawCreditPrice))
	{
		Spawn(BuildableClass);
		return true;
	}
	return false;
}

bool ASpawningArea::RequestBuyWithMaterials(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass)
{
	if (!CanSpawn()) return false;
	
	bool bSucceeded;
	PlayerCharacter->GetInventoryComp()->RemoveItems(ItemPrice.GetRequiredItemsList(), bSucceeded);
	if (bSucceeded)
	{
		Spawn(BuildableClass);
		return true;
	}
	return false;
}

void ASpawningArea::UpdateScreenWidgets()
{
	ScreenWidget->SetOwningTerminal(this);
	
	TArray<UBuildableDisplayStruct*> BuildablesStructs;
	for (const TSubclassOf<APlayerBuildable>& Buildable : Buildables)
	{
		UBuildableDisplayStruct* DisplayStruct = NewObject<UBuildableDisplayStruct>();
		DisplayStruct->Cost = Buildable->GetDefaultObject<APlayerBuildable>()->GetCost();
		DisplayStruct->DisplayStyle = Buildable->GetDefaultObject<APlayerBuildable>()->GetDisplayStyle();
		DisplayStruct->BuildableClass = Buildable;
		BuildablesStructs.Add(DisplayStruct);
	}

	ScreenWidget->AddItems(BuildablesStructs);
}

void ASpawningArea::Spawn(const TSubclassOf<APlayerBuildable>& BuildableClass)
{
	if (BuiltObject)
		return;
	BuiltObject = GetWorld()->SpawnActor<APlayerBuildable>(BuildableClass, GetActorLocation(), GetActorRotation());
	BasePlate->SetVisibility(false);
	BasePlate->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ASpawningArea::Destruct()
{
	if (BuiltObject)
	{
		BuiltObject->Destroy();
		BuiltObject = nullptr;
	}
	BasePlate->SetVisibility(true);
	BasePlate->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
