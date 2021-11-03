// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CMainHUD.h"
#include "Blueprint/DragDropOperation.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/WidgetDragOperation.h"

void UCMainHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CanvasPanel = Cast<UCanvasPanel>(GetWidgetFromName(FName("CanvasPanel")));
}

bool UCMainHUD::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	const FVector2D WidgetOffset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
	const FVector2D WidgetPosition = WidgetOffset - Cast<UWidgetDragOperation>(InOperation)->DragOffset;
	
	UCanvasPanelSlot* NewSlot = AddToCanvas(InOperation->DefaultDragVisual);
	NewSlot->SetAutoSize(true);
	NewSlot->SetPosition(WidgetPosition);
	return true;
}

UCanvasPanelSlot* UCMainHUD::AddToCanvas(UWidget* Widget)
{
	return CanvasPanel->AddChildToCanvas(Widget);
}
