// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/ComputerMonitor.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/TileView.h"
#include "Components/Button.h"
#include "Components/Overlay.h"
#include "Components/SizeBox.h"
#include "Inventory_System/ItemBase.h"
#include "Widgets/ItemStructTileView.h"
#include "Characters/Main Character/MyCharacter.h"

void UComputerMonitor::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	ItemTiles = Cast<UTileView>(GetWidgetFromName(FName("ItemTiles")));
	DisplayedItemImage = Cast<UImage>(GetWidgetFromName(FName("DisplayedItemImage")));
	DisplayedItemName = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemName")));
	DisplayedItemInfo = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemInfo")));
	SellingButtonsOverlay = Cast<UOverlay>(GetWidgetFromName(FName("SellingButtonsOverlay")));
	SelectedAmount = Cast<UTextBlock>(GetWidgetFromName(FName("SelectedAmount")));
	DecreaseSelectedAmount = Cast<UButton>(GetWidgetFromName(FName("DecreaseSelectedAmount")));
	IncreaseSelectedAmount = Cast<UButton>(GetWidgetFromName(FName("IncreaseSelectedAmount")));
	SellButtonBox = Cast<USizeBox>(GetWidgetFromName(FName("SellButtonBox")));
	SellButton = Cast<UButton>(GetWidgetFromName(FName("SellButton")));
	SellButtonText = Cast<UTextBlock>(GetWidgetFromName(FName("SellButtonText")));
	
	ItemTiles->OnItemSelectionChanged().AddUObject(this, &UComputerMonitor::UpdateActiveTile);
	IncreaseSelectedAmount->OnPressed.AddDynamic(this, &UComputerMonitor::IncreaseSelectedSellAmount);
	DecreaseSelectedAmount->OnPressed.AddDynamic(this, &UComputerMonitor::DecreaseSelectedSellAmount);
	SellButton->OnPressed.AddDynamic(this, &UComputerMonitor::Sell);

	SetAwaitingSelection();
}

void UComputerMonitor::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateSelectedAmountText();

	TimeSinceSold += InDeltaTime;
	if (TimeSinceSold >= 2.0f)
	{
		SellButtonText->SetText(FText::FromString("Sell"));
	}
}

void UComputerMonitor::SetAwaitingSelection() const
{
	DisplayedItemName->SetText(FText::FromString("Awaiting Selection"));
	DisplayedItemInfo->SetText(FText::FromString("Please select an item to proceed"));
	SellingButtonsOverlay->SetRenderOpacity(0.0f);
	SellButtonBox->SetRenderOpacity(0.0f);
}

void UComputerMonitor::SetSelectionSet() const
{
	SellingButtonsOverlay->SetRenderOpacity(1.0f);
	SellButtonBox->SetRenderOpacity(1.0f);
}

void UComputerMonitor::UpdateSelectedAmountText()
{
	UpdateMaxAmount();
	
	const FString SelectedAmountText = FString::FromInt(SelectedSellAmount) + FString(" / ") + FString::FromInt(MaxAmount);
	SelectedAmount->SetText(FText::FromString(SelectedAmountText));
}

void UComputerMonitor::IncreaseSelectedSellAmount()
{
	SelectedSellAmount = FMath::Min(SelectedSellAmount + 1, MaxAmount);
	UpdateSelectedAmountText();
}

void UComputerMonitor::DecreaseSelectedSellAmount()
{
	SelectedSellAmount = FMath::Max(SelectedSellAmount - 1, 0);
	UpdateSelectedAmountText();
}

void UComputerMonitor::UpdateMaxAmount()
{
	if (PC && ActiveTile)
	{
		MaxAmount = PC->GetInventoryComp()->GetNumMultipleItems(ActiveTile->Item_Struct.Name);
	}
}

void UComputerMonitor::Sell()
{
	if (SelectedSellAmount > 0)
	{
		for (int i = 0; i < SelectedSellAmount; i++)
		{
			PC->RemoveItemFromInventoryByName(ActiveTile->Item_Struct.Name);
		}
		SellButtonText->SetText(FText::FromString("Sold!"));
		TimeSinceSold = 0.0f;
		UpdateMaxAmount();
		SelectedSellAmount = SelectedSellAmount <= MaxAmount ? SelectedSellAmount : 0;
		UpdateSelectedAmountText();
	}
}

void UComputerMonitor::UpdateActiveTile(UObject* NewObject)
{
	SetSelectionSet();
	
	ActiveTile = Cast<UItemStructTileView>(NewObject);
	DisplayedItemImage->SetBrushFromTexture(ActiveTile->Item_Struct.Thumbnail);
	DisplayedItemName->SetText(FText::FromString(ActiveTile->Item_Struct.Name));
	DisplayedItemInfo->SetText(FText::FromString(ActiveTile->Item_Struct.Details));
	
	UpdateSelectedAmountText();
}

void UComputerMonitor::AddItemToList(FItem_Struct ItemStruct)
{
	UItemStructTileView* ItemObject = NewObject<UItemStructTileView>();
	ItemObject->Item_Struct = ItemStruct;
	ItemTiles->AddItem(ItemObject);
}
