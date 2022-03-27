// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/ComputerHUDs/TradeTerminal/TradingTab.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Widgets/ComputerHUDs/TradeTerminal/ItemStructTileView.h"
#include "Components/Button.h"
#include "Components/TileView.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"
#include "Components/SizeBox.h"
#include "Components/Image.h"

void UTradingTab::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ItemTiles = Cast<UTileView>(GetWidgetFromName(FName("ItemTiles")));
	DisplayedItemImage = Cast<UImage>(GetWidgetFromName(FName("DisplayedItemImage")));
	DisplayedItemName = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemName")));
	DisplayedItemInfo = Cast<UTextBlock>(GetWidgetFromName(FName("DisplayedItemInfo")));
	ButtonsOverlay = Cast<UOverlay>(GetWidgetFromName(FName("ButtonsOverlay")));
	SelectedTransferAmount = Cast<UTextBlock>(GetWidgetFromName(FName("SelectedTransferAmount")));
	DecreaseSelectedAmountButton = Cast<UButton>(GetWidgetFromName(FName("DecreaseSelectedAmountButton")));
	IncreaseSelectedAmountButton = Cast<UButton>(GetWidgetFromName(FName("IncreaseSelectedAmountButton")));
	TransferButtonBox = Cast<USizeBox>(GetWidgetFromName(FName("TransferButtonBox")));
	TransferButton = Cast<UButton>(GetWidgetFromName(FName("TransferButton")));
	TransferButtonText = Cast<UTextBlock>(GetWidgetFromName(FName("TransferButtonText")));
	
	ItemTiles->OnItemSelectionChanged().AddUObject(this, &UTradingTab::UpdateActiveTile);
	IncreaseSelectedAmountButton->OnPressed.AddDynamic(this, &UTradingTab::IncreaseSelectedAmount);
	DecreaseSelectedAmountButton->OnPressed.AddDynamic(this, &UTradingTab::DecreaseSelectedAmount);
	TransferButton->OnPressed.AddDynamic(this, &UTradingTab::Transfer);

	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());
	
	if (PC) { PlayerCharacter = Cast<AMyCharacter>(PC->GetPawn()); }
	
	SetAwaitingSelection();
}

void UTradingTab::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UTradingTab::SetAwaitingSelection() const
{
	DisplayedItemName->SetText(FText::FromString("Awaiting Selection"));
	DisplayedItemInfo->SetText(FText::FromString("Please select an item to proceed"));
	ButtonsOverlay->SetRenderOpacity(0.0f);
	TransferButtonBox->SetRenderOpacity(0.0f);
}

void UTradingTab::SetSelectionSet() const
{
	ButtonsOverlay->SetRenderOpacity(1.0f);
	TransferButtonBox->SetRenderOpacity(1.0f);
}

void UTradingTab::UpdateSelectedAmountText()
{
	UpdateMaxAmount();
	
	const FString SelectedAmountText = FString::FromInt(SelectedAmount) + FString(" / ") + FString::FromInt(MaxAmount);
	SelectedTransferAmount->SetText(FText::FromString(SelectedAmountText));
}

void UTradingTab::IncreaseSelectedAmount()
{
	SelectedAmount = FMath::Min(SelectedAmount + 1, MaxAmount);
	UpdateSelectedAmountText();
}

void UTradingTab::DecreaseSelectedAmount()
{
	SelectedAmount = FMath::Max(SelectedAmount - 1, 0);
	UpdateSelectedAmountText();
}

void UTradingTab::UpdateMaxAmount()
{
	if (PlayerCharacter && ActiveTile)
	{
		MaxAmount = PlayerCharacter->GetInventoryComp()->GetOccurrences(ActiveTile->Item.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure.Name);
	}
}

void UTradingTab::UpdateActiveTile(UObject* NewObject)
{
	SetSelectionSet();
	
	ActiveTile = Cast<UItemStructTileView>(NewObject);
	const FItem_Struct Item_Struct = ActiveTile->Item.Item->GetDefaultObject<AItemBase>()->Main_Item_Structure;
	DisplayedItemImage->SetBrushFromTexture(Item_Struct.Thumbnail);
	DisplayedItemName->SetText(FText::FromString(Item_Struct.Name));
	DisplayedItemInfo->SetText(FText::FromString(Item_Struct.Details));
	
	UpdateSelectedAmountText();
}

void UTradingTab::AddItemToList(FTradeables& ItemStruct)
{
	UItemStructTileView* ItemObject = NewObject<UItemStructTileView>();
	ItemObject->Item = ItemStruct;
	ItemTiles->AddItem(ItemObject);
}

void UTradingTab::SetTiles(TArray<FTradeables> Items)
{
	ItemTiles->ReleaseSlateResources(true);
	for (int i = 0; i < Items.Num(); i++)
	{
			AddItemToList(Items[i]);
	}
}
