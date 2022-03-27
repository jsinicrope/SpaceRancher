// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnablePriceTileSegment.h"
#include "Interactables/PlayerBuildable.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Items/ItemBase.h"

void USpawnablePriceTileSegment::NativeConstruct()
{
	Super::NativeConstruct();
	
	ItemThumbnail = Cast<UImage>(GetWidgetFromName(FName("ItemThumbnail")));
	AmountText = Cast<UTextBlock>(GetWidgetFromName(FName("AmountText")));
}

void USpawnablePriceTileSegment::SetContent(const FBuildableItemChart& ItemChart) const
{
	ItemThumbnail->SetBrushFromTexture(ItemChart.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure.Thumbnail);
	AmountText->SetText(FText::FromString(FString::FromInt(ItemChart.Amount)));
}

void USpawnablePriceTileSegment::SetAmount(const int ItemAmount) const
{
	AmountText->SetText(FText::FromString(FString::FromInt(ItemAmount)));
}
