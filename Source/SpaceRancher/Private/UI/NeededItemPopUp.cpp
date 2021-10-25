// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/NeededItemPopUp.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UNeededItemPopUp::NativeOnInitialized()
{
	ItemImage = Cast<UImage>(GetWidgetFromName(FName("ItemImage")));
	AmountText = Cast<UTextBlock>(GetWidgetFromName(FName("AmountText")));
}

void UNeededItemPopUp::SetTextAmount(int Amount, FString ItemName)
{
	Quantity = Amount;
	if (ItemName.IsEmpty())
	{
		InText = FString("You need ") + FString::FromInt(Quantity);
	}
	else
	{
		InText = FString("You need ") + FString::FromInt(Quantity) + FString(" of ") + ItemName;
	}
	AmountText->SetText(FText::FromString(InText));
}
