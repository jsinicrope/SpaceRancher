// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUDSetting.h"
#include "UI/ItemSelectionHUD.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "UI/Clock.h"
#include "UI/CMainHUD.h"

UHUDSetting::UHUDSetting()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHUDSetting::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACppPlayerController>(GetOwner()->GetInstigatorController());
	
	if (MainHUDClass)
	{
		MainHUD = CreateWidget<UCMainHUD>(GetWorld(), MainHUDClass);
		MainHUD->AddToViewport(100);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("No MainHUD set"));
		UE_LOG(LogTemp, Warning, TEXT("No MainHUD set in UHUDSettings"));
	}

	ensureAlwaysMsgf(MainHUD, TEXT("MainHUD returns nullptr after creation in HUDSetting"));
	
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

	if (MiniMapClass)
	{
		MiniMap = CreateWidget<UUserWidget>(GetWorld(), MiniMapClass);
		MiniMap->AddToViewport();
	}

	if (RadialMenuClass)
	{
		RadialMenu = CreateWidget<UItemSelectionHUD>(GetWorld(), RadialMenuClass);
	}
}

void UHUDSetting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UHUDSetting::OpenRadialMenu(TArray<FItem_Struct> &Selectables)
{
	if (MainHUD->GetInteractableWidgets() < 1)
	{
		MainHUD->AddInteractableWidgetInternal(RadialMenu);
		MainHUD->SetInputWidgetMode(true);
		RadialMenu->AddToViewport();
		
		RadialMenu->CreateStandardWidget(Selectables);

		int ViewportX, ViewportY;
		PlayerController->GetViewportSize(ViewportX, ViewportY);
		PlayerController->SetMouseLocation(ViewportX / 2, ViewportY / 2);
		
		return true;
	}
	return false;
}

void UHUDSetting::CloseRadialMenu()
{
	MainHUD->RemoveInteractableWidgetFromCanvas(RadialMenu);
}
