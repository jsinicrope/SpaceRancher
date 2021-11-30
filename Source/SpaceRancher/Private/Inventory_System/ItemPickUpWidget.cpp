// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/ItemPickUpWidget.h"

#include "Components/TextBlock.h"

void UItemPickUpWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Item Widget called"));
	}
}

void UItemPickUpWidget::UpdateWidget(UTexture2D* ItemImage, const FString ItemName) const
{
	PickedUpItem->SetBrushFromTexture(ItemImage);
	PickedUpItemName->SetText(FText::FromString(ItemName));
}
