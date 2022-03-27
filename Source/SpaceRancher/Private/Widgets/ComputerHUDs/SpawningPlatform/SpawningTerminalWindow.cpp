// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ComputerHUDs/SpawningPlatform//SpawningTerminalWindow.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/BuildableDisplayStruct.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnableMainTile.h"
#include "Components/ScrollBox.h"
#include "Interactables/SpawningArea.h"

void USpawningTerminalWindow::NativeOnInitialized()
{
	ItemsScrollBox = Cast<UScrollBox>(GetWidgetFromName(FName("ItemsScrollBox")));

	Super::NativeOnInitialized();
}

void USpawningTerminalWindow::AddItems(const TArray<UBuildableDisplayStruct*>& Items)
{
	for (UBuildableDisplayStruct* Item : Items)
	{
		USpawnableMainTile* Tile = CreateWidget<USpawnableMainTile>(GetWorld(), ListEntryMainTileClass);
		Tile->SetOwningTerminalWindow(this);
		Tile->SetListObject(Item);
		ItemsScrollBox->AddChild(Tile);
	}
}

bool USpawningTerminalWindow::RequestBuyWithCredits(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass) const
{
	return OwningTerminal->RequestBuyWithCredits(ItemPrice, BuildableClass);
}

bool USpawningTerminalWindow::RequestBuyWithMaterials(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass) const
{
	return OwningTerminal->RequestBuyWithMaterials(ItemPrice, BuildableClass);
}
