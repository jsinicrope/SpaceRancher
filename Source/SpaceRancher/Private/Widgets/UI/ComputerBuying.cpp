// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ComputerBuying.h"
#include "Components/TextBlock.h"
#include "Widgets/ItemStructTileView.h"
#include "Characters/Main Character/MyCharacter.h"

void UComputerBuying::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UComputerBuying::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateSelectedAmountText();

	TimeSinceTransfer += InDeltaTime;
	if (TimeSinceTransfer >= 2.0f)
	{
		TransferButtonText->SetText(FText::FromString("Buy"));
	}
}

void UComputerBuying::UpdateMaxAmount()
{
	
}

void UComputerBuying::Transfer()
{
	if (SelectedAmount > 0)
	{
		for (int i = 0; i < SelectedAmount; i++)
		{
			PC->AddItemToInventory(ActiveTile->Item_Struct);
		}
		MaxAmount -= SelectedAmount;
		TransferButtonText->SetText(FText::FromString("Bought!"));
		TimeSinceTransfer = 0.0f;
		UpdateMaxAmount();
		SelectedAmount = 0;
		UpdateSelectedAmountText();
	}
}
