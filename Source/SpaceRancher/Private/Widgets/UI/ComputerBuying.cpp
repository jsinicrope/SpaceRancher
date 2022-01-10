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
		const int Amount = SelectedAmount;
		for (int i = 0; i < Amount; i++)
		{
			if (PC->DeductCredits(ActiveTile->Item_Struct.CreditValue))
			{
				if (!PlayerCharacter->AddInventoryItem(ActiveTile->Item_Struct))
					break;
				SelectedAmount--;
				MaxAmount--;
			}
			else
			{
				TransferButtonText->SetText(FText::FromString("Not enough Credits available"));
				TimeSinceTransfer = 0.0f;
				return;
			}
		}
		TransferButtonText->SetText(FText::FromString("Bought!"));
		UpdateMaxAmount();
		UpdateSelectedAmountText();
		TimeSinceTransfer = 0.0f;
	}
}
