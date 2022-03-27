// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ComputerHUDs/TradeTerminal/ItemSellingTile.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Widgets/ComputerHUDs/TradeTerminal/ItemStructTileView.h"

void UItemSellingTile::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemDisplay = Cast<UImage>(GetWidgetFromName(FName("ItemDisplay")));
	ItemName = Cast<UTextBlock>(GetWidgetFromName(FName("ItemName")));
	ItemDescription = Cast<UTextBlock>(GetWidgetFromName(FName("ItemDescription")));
	TileBorder = Cast<UBorder>(GetWidgetFromName(FName("Border")));
	CreditValue = Cast<UTextBlock>(GetWidgetFromName(FName("CreditValue")));
}

void UItemSellingTile::SetWidgets() const
{
	if (RepresentedItem)
	{
		const FItem_Struct Item_Struct = RepresentedItem->Item.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure;
		ItemDisplay->SetBrushFromTexture(Item_Struct.Thumbnail);
		ItemName->SetText(FText::FromString(Item_Struct.Name));
		ItemDescription->SetText(FText::FromString(Item_Struct.Details));
		CreditValue->SetText(FText::FromString(FString("Credit Value: ") + FString::FromInt(Item_Struct.CreditValue)));
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
