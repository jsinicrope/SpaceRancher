// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ComputerHUDs/SpawningPlatform//SpawnableTile.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"

void USpawnableTile::NativeConstruct()
{
	Super::NativeConstruct();

	Image = Cast<UImage>(GetWidgetFromName(FName("Image")));
	Name = Cast<UTextBlock>(GetWidgetFromName(FName("Name")));
	DetailsPanelButton = Cast<UButton>(GetWidgetFromName(FName("DetailsPanelButton")));
	PricePanelButton = Cast<UButton>(GetWidgetFromName(FName("PricePanelButton")));
}

void USpawnableTile::NativeOnItemSelectionChanged(bool bIsSelected)
{
	IUserObjectListEntry::NativeOnItemSelectionChanged(bIsSelected);
}

void USpawnableTile::NativeOnItemExpansionChanged(bool bIsExpanded)
{
	IUserObjectListEntry::NativeOnItemExpansionChanged(bIsExpanded);
}

void USpawnableTile::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
}
