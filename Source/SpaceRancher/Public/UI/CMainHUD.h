// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "CMainHUD.generated.h"

UCLASS()
class SPACERANCHER_API UCMainHUD : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UCanvasPanel* CanvasPanel = nullptr;

	UPROPERTY()
	int ActiveInteractableWidgets;

	UPROPERTY()
	TArray<UWidget*> InteractableWidgets;

public:
	UFUNCTION(BlueprintCallable)
	UCanvasPanelSlot* AddToCanvas(UWidget* Widget);

	UFUNCTION()
	UCanvasPanelSlot* AddInteractableWidgetToCanvas(UWidget* Widget);

	UFUNCTION()
	void RemoveInteractableWidgetFromCanvas(UWidget* Widget);

	UFUNCTION()
	void RemoveAllInteractableWidgets();
};
