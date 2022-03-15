// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ComputerHUDs/SpawningPlatform//SpawningTerminalWindow.h"
#include "Components/TileView.h"

void USpawningTerminalWindow::NativeConstruct()
{
	Super::NativeConstruct();

	TileView = Cast<UTileView>(GetWidgetFromName(FName("TileView")));
}
