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
	UPROPERTY()
	APlayerController* PC;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UCanvasPanel* CanvasPanel = nullptr;

	UPROPERTY()
	int ActiveInteractableWidgets;

	UPROPERTY()
	TArray<UWidget*> InteractableWidgets;

	UPROPERTY()
	int ActiveInventoryWidgets;

	UPROPERTY()
	TArray<UWidget*> InventoryWidgets;

public:
	UFUNCTION(BlueprintCallable)
	UCanvasPanelSlot* AddToCanvas(UWidget* Widget);

	UFUNCTION()
	UCanvasPanelSlot* AddInteractableWidgetToCanvas(UWidget* Widget);

	UFUNCTION()
	UCanvasPanelSlot* AddInventoryWidgetToCanvas(UWidget* Widget);

	UFUNCTION()
	int GetInteractableWidgets() const { return ActiveInteractableWidgets; }

	// Only use if widgets can't be added to the MainHUD container
	UFUNCTION()
	void AddInteractableWidgetInternal(UWidget* Widget);

	UFUNCTION()
	void SetInputWidgetMode(bool bWidgetFocus) const;

	UFUNCTION()
	void RemoveInteractableWidgetFromCanvas(UWidget* Widget);

	UFUNCTION()
	void RemoveInventoryWidgetFromCanvas(UWidget* Widget);

	UFUNCTION()
	void RemoveAllInteractableWidgets();

	UFUNCTION()
	void RemoveAllInventoryWidgets();
};
