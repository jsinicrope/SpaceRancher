// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUDSetting.h"
#include "UI/Clock.h"
#include "Inventory_System/ItemPickUpWidget.h"

// Sets default values for this component's properties
UHUDSetting::UHUDSetting()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UHUDSetting::BeginPlay()
{
	Super::BeginPlay();

	if (InteractPopUpClass)
	{
		InteractPopUp = CreateWidget<UUserWidget>(GetWorld(), InteractPopUpClass);
	}

	if (ItemPickUpWidgetClass)
	{
		ItemPickUpWidget = CreateWidget<UItemPickUpWidget>(GetWorld(), ItemPickUpWidgetClass);
	}

	if (ClockWidgetClass)
	{
		ClockWidget = CreateWidget<UClock>(GetWorld(), ClockWidgetClass);
		ClockWidget->AddToViewport();
	}
}


// Called every frame
void UHUDSetting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

