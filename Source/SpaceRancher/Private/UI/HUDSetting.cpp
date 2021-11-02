// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUDSetting.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/Clock.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "UI/CMainHUD.h"

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

	if (MainHUDClass)
	{
		MainHUD = CreateWidget<UCMainHUD>(GetWorld(), MainHUDClass);
		MainHUD->AddToViewport();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("No MainHUD set"));
		UE_LOG(LogTemp, Warning, TEXT("No MainHUD set in UHUDSettings"));
	}
	
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
		ensure(MainHUD);
		MainHUD->AddToCanvas(ClockWidget)->SetPosition(ClockWidget->Position);
	}
}

// Called every frame
void UHUDSetting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
