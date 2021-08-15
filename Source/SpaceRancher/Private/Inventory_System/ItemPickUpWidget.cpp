// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_System/ItemPickUpWidget.h"

void UItemPickUpWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Item Widget called"));
	}

	if (ItemImage != NULL)
		PickedUpItem->SetBrushFromTexture(ItemImage);
}
