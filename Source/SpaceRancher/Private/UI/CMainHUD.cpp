// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CMainHUD.h"

void UCMainHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CanvasPanel = Cast<UCanvasPanel>(GetWidgetFromName(FName("CanvasPanel")));
}

UCanvasPanelSlot* UCMainHUD::AddToCanvas(UWidget* Widget)
{
	return CanvasPanel->AddChildToCanvas(Widget);
}
