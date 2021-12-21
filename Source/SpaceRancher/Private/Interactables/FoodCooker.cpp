// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/FoodCooker.h"
#include "Components/WidgetComponent.h"
#include "Widgets/UI/FoodCookerTimer.h"
#include "Components/SpawnerComponent.h"
#include "Inventory_System/ItemBase.h"
#include "Characters/Main Character/MyCharacter.h"

AFoodCooker::AFoodCooker(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	CookerFrame = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CookerFrame"));
	CookerGrill = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CookerGrill"));
	CookerDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CookerDoor"));
	DoorTimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComponent"));
	TimerWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("TimerWidget"));
	SpawnerComponent = CreateDefaultSubobject<USpawnerComponent>(TEXT("SpawnerComponent"));
	
	CookerFrame->SetupAttachment(RootComponent);
	CookerDoor->SetupAttachment(CookerFrame);
	CookerGrill->SetupAttachment(CookerFrame);
	TimerWidget->SetupAttachment(CookerFrame);
	SpawnerComponent->SetupAttachment(CookerFrame);
}

void AFoodCooker::BeginPlay()
{
	Super::BeginPlay();

	PC = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	//Binding our float track to our UpdateTimelineComp Function's output
	UpdateFunctionFloat.BindDynamic(this, &AFoodCooker::UpdateTimelineComp);

	//If we have a float curve, bind it's graph to our update function
	if (DoorTimelineFloatCurve)
	{
		DoorTimelineComponent->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}

	CookerTimer = Cast<UFoodCookerTimer>(TimerWidget->GetWidget());
	check(CookerTimer);
}

void AFoodCooker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCooking)
	{
		CookedTime += DeltaTime;
		CookerTimer->UpdateTimer(CookingTime-CookedTime);
		if (CookedTime >= CookingTime)
		{
			EndCooking();
		}
	}
}

void AFoodCooker::Interact_Implementation()
{
	
}

bool AFoodCooker::ItemInteract_Implementation(FItem_Struct EquippedItem)
{
	if (EquippedItem.ItemClass == RequiredItem)
	{
		if (bDoorOpen)
		{
			QueueCooking();
			DoorTimelineComponent->Reverse();
			bDoorOpen = false;
		}
		else
		{
			if (bCookingQueued)
			{
				StartCooking();
			}
			else
			{
				DoorTimelineComponent->Play();
				bDoorOpen = true;
			}
		}
		return true;
	}
	return false;
}

void AFoodCooker::QueueCooking()
{
	bCookingQueued = true;
}

bool AFoodCooker::StartCooking()
{
	if (!bCooking)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Started cooking!"));
		CookedTime = 0.0f;
		bCooking = true;
		return true;
	}
	return false;
}

void AFoodCooker::EndCooking()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Finished cooking!"));
	bCookingQueued = false;
	bCooking = false;
	SpawnerComponent->Spawn();
}

void AFoodCooker::UpdateTimelineComp(const float Output)
{
	// Create and set our Door's new relative location based on the output from our Timeline Curve
	const FRotator DoorNewRotation = FRotator(0.0f, Output, 0.0f);
	CookerDoor->SetRelativeRotation(DoorNewRotation);
}
