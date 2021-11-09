// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CMainHUD.h"
#include "Blueprint/DragDropOperation.h"
#include "Components/CanvasPanelSlot.h"
#include "UI/WidgetDragOperation.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UCMainHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CanvasPanel = Cast<UCanvasPanel>(GetWidgetFromName(FName("CanvasPanel")));
}

bool UCMainHUD::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (InOperation->Tag.Equals(FString("Not draggable")))
	{
		return false;
	}
	
	const UWidgetDragOperation* InOp = Cast<UWidgetDragOperation>(InOperation);
	const FVector2D WidgetOffset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
	const FVector2D WidgetPosition = WidgetOffset - InOp->DragOffset;
	
	UCanvasPanelSlot* NewSlot = AddToCanvas(InOperation->DefaultDragVisual);
	NewSlot->SetAutoSize(true);
	NewSlot->SetPosition(WidgetPosition);
	return true;
}

UCanvasPanelSlot* UCMainHUD::AddToCanvas(UWidget* Widget)
{
	return CanvasPanel->AddChildToCanvas(Widget);
}

UCanvasPanelSlot* UCMainHUD::AddInteractableWidgetToCanvas(UWidget* Widget)
{
	ActiveInteractableWidgets++;
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PC);
	PC->bShowMouseCursor = true;
	InteractableWidgets.Add(Widget);
	return AddToCanvas(Widget);
}

UCanvasPanelSlot* UCMainHUD::AddInventoryWidgetToCanvas(UWidget* Widget)
{
	ActiveInventoryWidgets++;
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PC);
	PC->bShowMouseCursor = true;
	InventoryWidgets.Add(Widget);
	return AddToCanvas(Widget);
}

void UCMainHUD::RemoveInteractableWidgetFromCanvas(UWidget* Widget)
{
	Widget->RemoveFromParent();
	InteractableWidgets.RemoveSingle(Widget);
	ActiveInteractableWidgets--;
	if (ActiveInteractableWidgets <= 0)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
	}
}

void UCMainHUD::RemoveInventoryWidgetFromCanvas(UWidget* Widget)
{
	Widget->RemoveFromParent();
	InventoryWidgets.RemoveSingle(Widget);
	ActiveInventoryWidgets--;
	if (ActiveInventoryWidgets <= 0)
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		PC->bShowMouseCursor = false;
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
	}
}

void UCMainHUD::RemoveAllInteractableWidgets()
{
	const int InteractableWidgetsLength = InteractableWidgets.Num(); 
	for (int i = 0; i<InteractableWidgetsLength; i++)
	{
		if (InteractableWidgets[i])
		{
			RemoveInteractableWidgetFromCanvas(InteractableWidgets[i]);
		}
	}
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->bShowMouseCursor = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
}

void UCMainHUD::RemoveAllInventoryWidgets()
{
	const int InvLength = InventoryWidgets.Num();
	for (int i = 0; i<InvLength; i++)
	{
		if (InventoryWidgets[i])
		{
			RemoveInventoryWidgetFromCanvas(InventoryWidgets[i]);
		}
	}
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	PC->bShowMouseCursor = false;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PC);
}
