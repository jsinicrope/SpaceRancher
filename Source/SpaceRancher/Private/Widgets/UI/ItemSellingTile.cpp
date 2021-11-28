// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ItemSellingTile.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Widgets/ItemStructTileView.h"

void UItemSellingTile::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemDisplay = Cast<UImage>(GetWidgetFromName(FName("ItemDisplay")));
	ItemName = Cast<UTextBlock>(GetWidgetFromName(FName("ItemName")));
	ItemDescription = Cast<UTextBlock>(GetWidgetFromName(FName("ItemDescription")));
	TileBorder = Cast<UBorder>(GetWidgetFromName(FName("Border")));
}

void UItemSellingTile::SetWidgets() const
{
	if (RepresentedItem)
	{
		ItemDisplay->SetBrushFromTexture(RepresentedItem->Item_Struct.Thumbnail);
		ItemName->SetText(FText::FromString(RepresentedItem->Item_Struct.Name));
		ItemDescription->SetText(FText::FromString(RepresentedItem->Item_Struct.Details));
	}
}

void UItemSellingTile::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	RepresentedItem = Cast<UItemStructTileView>(ListItemObject);
	SetWidgets();
}

void UItemSellingTile::NativeOnItemSelectionChanged(bool bIsSelected)
{
	IUserObjectListEntry::NativeOnItemSelectionChanged(bIsSelected);
}

void UItemSellingTile::NativeOnItemExpansionChanged(bool bIsExpanded)
{
	IUserObjectListEntry::NativeOnItemExpansionChanged(bIsExpanded);
}

void UItemSellingTile::NativeOnEntryReleased()
{
	IUserObjectListEntry::NativeOnEntryReleased();
}
