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
			if (PC->DeductCredits(ActiveTile->Item_Struct.CreditValue))
			{
				PlayerCharacter->AddInventoryItem(ActiveTile->Item_Struct);
				MaxAmount -= SelectedAmount;
				TransferButtonText->SetText(FText::FromString("Bought!"));
				SelectedAmount = 0;
				UpdateMaxAmount();
				UpdateSelectedAmountText();
			}
			else
			{
				TransferButtonText->SetText(FText::FromString("Not enough Credits available"));
			}
		}
		TimeSinceTransfer = 0.0f;
	}
}
