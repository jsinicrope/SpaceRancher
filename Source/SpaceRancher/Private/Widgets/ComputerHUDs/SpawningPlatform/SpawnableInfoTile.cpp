// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnableInfoTile.h"
#include "Components/TextBlock.h"

void USpawnableInfoTile::NativeOnInitialized()
{
	ItemDescription = Cast<UTextBlock>(GetWidgetFromName(FName("ItemDescription")));

	Super::NativeOnInitialized();
}

void USpawnableInfoTile::SetDescription(const FText& Text) const
{
	ItemDescription->SetText(Text);
}

void USpawnableInfoTile::SetDescription(const FString& Text) const
{
	SetDescription(FText::FromString(Text));
}
