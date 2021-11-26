// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ItemSellingTile.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UItemSellingTile::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemDisplay = Cast<UImage>(GetWidgetFromName(FName("ItemDisplay")));
	ItemName = Cast<UTextBlock>(GetWidgetFromName(FName("ItemName")));
	ItemDescription = Cast<UTextBlock>(GetWidgetFromName(FName("ItemDescription")));
	ItemTileButton = Cast<UButton>(GetWidgetFromName(FName("ItemTileButton")));
}
