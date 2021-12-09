// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ComputerScreen.h"
#include "Widgets/UI/ComputerSelling.h"
#include "Interactables/Computer.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
#include "Widgets/UI/ComputerBuying.h"
#include "Characters/Main Character/MyCharacter.h"

void UComputerScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	SellingTab = Cast<UComputerSelling>(GetWidgetFromName(FName("SellingTab")));
	BuyingTab = Cast<UComputerBuying>(GetWidgetFromName(FName("BuyingTab")));
	SellTabButton = Cast<UButton>(GetWidgetFromName(FName("SellTabButton")));
	BuyTabButton = Cast<UButton>(GetWidgetFromName(FName("BuyTabButton")));
	WidgetSwitcher = Cast<UWidgetSwitcher>(GetWidgetFromName(FName("WidgetSwitcher")));

	BuyTabButton->OnClicked.AddDynamic(this, &UComputerScreen::UComputerScreen::SetBuyingTabActive);
	SellTabButton->OnClicked.AddDynamic(this, &UComputerScreen::UComputerScreen::SetSellingTabActive);

	PC = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	SellingTab->OwningScreen = this;
	BuyingTab->OwningScreen = this;
}

void UComputerScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UComputerScreen::SetSellingTabActive()
{
	WidgetSwitcher->SetActiveWidgetIndex(0);
	SellingTab->SetTiles(OwningComputer->GetSellableItems());
}

void UComputerScreen::SetBuyingTabActive()
{
	WidgetSwitcher->SetActiveWidgetIndex(1);
	BuyingTab->SetTiles(OwningComputer->GetBuyableItems());
}
