// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/GridPanel.h"
#include "Inventory_System/Item_Base.h"
#include "Components/Button.h"
#include "InventoryWindow.generated.h"

UCLASS()
class SPACERANCHER_API UInventoryWindow : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	
	UPROPERTY(BlueprintReadWrite)
	class UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;

	UPROPERTY()
	bool bWindowOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetUpInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetVariables(UInventoryComponent* InventoryComp, TSubclassOf<UUserWidget> InventorySlotWidgetClassIn);

	UFUNCTION()
	void ShowWindow();

	UFUNCTION()
	void CloseWindow();


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventorySlotWidget* InventorySlotWidget;

	UPROPERTY()
	FItem_Struct InventoryItem;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* InventoryTitle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UGridPanel* InventoryGrid;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* CloseInventoryButton;

	UPROPERTY()
	class ACppPlayerController* PC;

	UFUNCTION()
	void CloseInventory();

};
