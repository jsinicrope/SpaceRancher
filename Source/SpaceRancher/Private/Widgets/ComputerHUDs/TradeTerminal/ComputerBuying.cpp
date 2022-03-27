// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ComputerHUDs/TradeTerminal/ComputerBuying.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Widgets/ComputerHUDs/TradeTerminal/ItemStructTileView.h"
#include "Characters/Main Character/MyCharacter.h"

void UComputerBuying::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UComputerBuying::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	TimeSinceTransfer += InDeltaTime;
	if (TimeSinceTransfer >= 2.0f)
	{
		TransferButtonText->SetText(FText::FromString("Buy"));
	}
}

void UComputerBuying::UpdateMaxAmount()
{
	MaxAmount = ActiveTile->Item.StockAmount;
}

void UComputerBuying::Transfer()
{
	if (SelectedAmount > 0)
	{
		const int Amount = SelectedAmount;
		for (int i = 0; i < Amount; i++)
		{
			if (PC->DeductCredits(ActiveTile->Item.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure.CreditValue))
			{
				if (!PlayerCharacter->AddInventoryItem(ActiveTile->Item.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure))
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
