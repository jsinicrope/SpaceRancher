// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnablePriceTile.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnablePriceTileSegment.h"
#include "Interactables/PlayerBuildable.h"
#include "Components/GridPanel.h"
#include "Components/Button.h"
#include "Items/ItemBase.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnableMainTile.h"

void USpawnablePriceTile::NativeConstruct()
{
	Super::NativeConstruct();
	
	CreditPriceWidget = Cast<USpawnablePriceTileSegment>(GetWidgetFromName(FName("CreditPriceWidget")));
	CreditPriceButton = Cast<UButton>(GetWidgetFromName(FName("CreditPriceButton")));
	MaterialsPriceButton = Cast<UButton>(GetWidgetFromName(FName("MaterialsPriceButton")));
	MaterialsGrid = Cast<UGridPanel>(GetWidgetFromName(FName("MaterialsGrid")));

	CreditPriceButton->OnPressed.AddDynamic(this, &USpawnablePriceTile::CreditPriceButtonPressed);
	MaterialsPriceButton->OnPressed.AddDynamic(this, &USpawnablePriceTile::MaterialsPriceButtonPressed);
}

void USpawnablePriceTile::SetPrice(const FBuildablePriceStruct& Items)
{
	RepresentedItemCost = Items;
	CreditPriceWidget->SetAmount(Items.RawCreditPrice);
	for (int i = 0; i < Items.RequiredItems.Num(); i++)
	{
		const FBuildableItemChart& Item = Items.RequiredItems[i];
		checkf(Item.Item, TEXT("Empty Property for PlayerBuildable Object on 'Items' property"));
		USpawnablePriceTileSegment* ItemWidget = CreateWidget<USpawnablePriceTileSegment>(GetWorld(), MaterialDisplayWidget);
		ItemWidget->SetContent(Item);
		MaterialsGrid->AddChildToGrid(ItemWidget, FMath::Floor(i / ItemPriceRows), i % ItemPriceRows);
	}
}

void USpawnablePriceTile::CreditPriceButtonPressed()
{
	OwningTile->RequestBuyWithCredits();
}

void USpawnablePriceTile::MaterialsPriceButtonPressed()
{
	OwningTile->RequestBuyWithMaterials();
}
