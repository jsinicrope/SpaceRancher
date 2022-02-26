// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HUDSetting.h"
#include "UI/ItemSelectionHUD.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "UI/HealthAndStaminaBar.h"
#include "UI/CMainHUD.h"
#include "UI/Clock.h"
#include "UI/Funds.h"

UHUDSetting::UHUDSetting()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHUDSetting::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<ACppPlayerController>(GetOwner()->GetInstigatorController());

	// No need to create widgets for simulating mode
	if (PlayerController)
	{
		if (MainHUDClass)
		{
			MainHUD = CreateWidget<UCMainHUD>(GetWorld(), MainHUDClass);
			MainHUD->AddToViewport(1);
		
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

		if (HealthAndStaminaBarClass)
		{
			HealthAndStaminaBar = CreateWidget<UHealthAndStaminaBar>(GetWorld(), HealthAndStaminaBarClass);
			HealthAndStaminaBar->AddToViewport(-1);
		}
		
		if (ClockWidgetClass)
		{
			ClockWidget = CreateWidget<UClock>(GetWorld(), ClockWidgetClass);
			ClockWidget->AddToViewport(-1);
		}

		if (MiniMapClass)
		{
			MiniMap = CreateWidget<UUserWidget>(GetWorld(), MiniMapClass);
			MiniMap->AddToViewport(-1);
		}

		if (RadialMenuClass)
		{
			RadialMenu = CreateWidget<UItemSelectionHUD>(GetWorld(), RadialMenuClass);
		}

		if (AvailableFundsClass)
		{
			AvailableFunds = CreateWidget<UFunds>(GetWorld(), AvailableFundsClass);
			AvailableFunds->AddToViewport();
		}
	}
}

void UHUDSetting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHUDSetting::ShowInteractPopUp()
{
	if (InteractPopUp && !InteractPopUp->IsInViewport())
	{
		InteractPopUp->AddToViewport();
	}
}

void UHUDSetting::HideInteractPopUp()
{
	if (InteractPopUp && InteractPopUp->IsInViewport())
	{
		InteractPopUp->RemoveFromViewport();
	}
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
