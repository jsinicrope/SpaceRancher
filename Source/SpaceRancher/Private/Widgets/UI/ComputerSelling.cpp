// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ComputerSelling.h"
#include "Components/TextBlock.h"
#include "Widgets/ItemStructTileView.h"
#include "Characters/Main Character/MyCharacter.h"

void UComputerSelling::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateSelectedAmountText();

	TimeSinceTransfer += InDeltaTime;
	if (TimeSinceTransfer >= 2.0f)
	{
		TransferButtonText->SetText(FText::FromString("Sell"));
	}
}

void UComputerSelling::Transfer()
{
	if (SelectedAmount > 0)
	{
		for (int i = 0; i < SelectedAmount; i++)
		{
			PC->AddCredits(ActiveTile->Item_Struct.CreditValue);
			PlayerCharacter->RemoveInventoryItemByName(ActiveTile->Item_Struct.Name);
		}
		TransferButtonText->SetText(FText::FromString("Sold!"));
		TimeSinceTransfer = 0.0f;
		UpdateMaxAmount();
		SelectedAmount = SelectedAmount <= MaxAmount ? SelectedAmount : 0;
		UpdateSelectedAmountText();
	}
}
