// Fill out your copyright notice in the Description page of Project Settings.

// ReSharper disable CppMemberFunctionMayBeConst

#include "Widgets/ComputerHUDs/SpawningPlatform//SpawnableMainTile.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnablePriceTile.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawnableInfoTile.h"
#include "Components/MenuAnchor.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawningTerminalWindow.h"


void USpawnableMainTile::NativeOnInitialized()
{
	BackgroundBorder = Cast<UBorder>(GetWidgetFromName(FName("BackgroundBorder")));
	Image = Cast<UImage>(GetWidgetFromName(FName("Image")));
	Name = Cast<UTextBlock>(GetWidgetFromName(FName("Name")));
	DetailsPanelButton = Cast<UButton>(GetWidgetFromName(FName("DetailsPanelButton")));
	PricePanelButton = Cast<UButton>(GetWidgetFromName(FName("PricePanelButton")));
	DetailsPanelAnchor = Cast<UMenuAnchor>(GetWidgetFromName(FName("DetailsPanelAnchor")));
	PricePanelAnchor = Cast<UMenuAnchor>(GetWidgetFromName(FName("PricePanelAnchor")));

	DetailsPanelButton->OnPressed.AddDynamic(this, &USpawnableMainTile::ToggleDetailsPanel);
	PricePanelButton->OnPressed.AddDynamic(this, &USpawnableMainTile::TogglePricePanel);
	DetailsPanelAnchor->OnGetUserMenuContentEvent.BindDynamic(this, &USpawnableMainTile::GetDetailsPanel);
	PricePanelAnchor->OnGetUserMenuContentEvent.BindDynamic(this, &USpawnableMainTile::GetPricePanel);
	
	Super::NativeOnInitialized();
}

void USpawnableMainTile::SetListObject(UBuildableDisplayStruct* Object)
{
	RepresentedBuildable = Object;
	UpdateWidget();
}

bool USpawnableMainTile::RequestBuyWithCredits() const
{
	return OwningTerminalWindow->RequestBuyWithCredits(RepresentedBuildable->Cost, RepresentedBuildable->BuildableClass);
}

bool USpawnableMainTile::RequestBuyWithMaterials() const
{
	return OwningTerminalWindow->RequestBuyWithMaterials(RepresentedBuildable->Cost, RepresentedBuildable->BuildableClass);
}

void USpawnableMainTile::UpdateWidget() const
{
	Name->SetText(FText::FromName(RepresentedBuildable->DisplayStyle.Name));
	Image->SetBrushFromTexture(RepresentedBuildable->DisplayStyle.DisplayImage);
}

void USpawnableMainTile::ToggleDetailsPanel()
{
	if (PricePanelAnchor->IsOpen())
		PricePanelAnchor->Close();
	DetailsPanelAnchor->ToggleOpen(false);
}

void USpawnableMainTile::TogglePricePanel()
{
	if (DetailsPanelAnchor->IsOpen())
		DetailsPanelAnchor->Close();
	PricePanelAnchor->ToggleOpen(false);
}

UUserWidget* USpawnableMainTile::GetDetailsPanel()
{
	USpawnableInfoTile* Widget =  CreateWidget<USpawnableInfoTile>(GetWorld(), InfoTileClass);
	Widget->SetDescription(RepresentedBuildable->DisplayStyle.Description);
	return Widget;
}

UUserWidget* USpawnableMainTile::GetPricePanel()
{
	USpawnablePriceTile* Widget = CreateWidget<USpawnablePriceTile>(GetWorld(), PriceTileClass);
	Widget->SetPrice(RepresentedBuildable->Cost);
	Widget->SetOwningTile(this);
	return Widget;
}
