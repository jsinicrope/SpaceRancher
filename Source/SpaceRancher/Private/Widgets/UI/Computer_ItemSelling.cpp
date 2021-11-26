// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/Computer_ItemSelling.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/TileView.h"
#include "Components/Button.h"

void UComputer_ItemSelling::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemTiles = Cast<UTileView>(GetWidgetFromName(FName("ItemTiles")));
	DisplayedItemImage = Cast<UImage>(GetWidgetFromName(FName("DisplayedItemImage")));
	DisplayedItemName = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemName")));
	DisplayedItemInfo = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemInfo")));
	SelectedAmount = Cast<UTextBlock>(GetWidgetFromName(FName("SelectedAmount")));
	DecreaseSelectedAmount = Cast<UButton>(GetWidgetFromName(FName("DecreaseSelectedAmount")));
	IncreaseSelectedAmount = Cast<UButton>(GetWidgetFromName(FName("IncreaseSelectedAmount")));
	SellButton = Cast<UButton>(GetWidgetFromName(FName("SellButton")));
	SellButtonText = Cast<UTextBlock>(GetWidgetFromName(FName("SellButtonText")));
}
