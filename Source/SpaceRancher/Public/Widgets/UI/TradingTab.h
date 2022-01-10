// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory_System/ItemBase.h"
#include "Inventory_System/ItemStruct.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "TradingTab.generated.h"

UCLASS()
class SPACERANCHER_API UTradingTab : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class UComputerScreen* OwningScreen;

protected:
	UPROPERTY(BlueprintReadOnly)
	class AMyCharacter* PlayerCharacter;

	UPROPERTY(BlueprintReadOnly)
	class ACppPlayerController* PC;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTileView* ItemTiles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UImage* DisplayedItemImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* DisplayedItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* DisplayedItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UOverlay* ButtonsOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* SelectedTransferAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* DecreaseSelectedAmountButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* IncreaseSelectedAmountButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class USizeBox* TransferButtonBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* TransferButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* TransferButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UItemStructTileView* ActiveTile;

	// Selected amount to sell of the currently selected item
	UPROPERTY(BlueprintReadOnly)
	int SelectedAmount = 0;

	// The max selectable amount for the currently selected item
	UPROPERTY(BlueprintReadOnly)
	int MaxAmount = 0;

	/** The time since the Displayed state button (TransferButtonText) was changed
	 * Used for changing the text back to it's intended state after the user has interacted with the button */
	UPROPERTY()
	float TimeSinceTransfer = 0.0f;

	UFUNCTION()
	virtual void SetAwaitingSelection() const;

	UFUNCTION()
	virtual void SetSelectionSet() const;
	
	UFUNCTION()
	virtual void UpdateSelectedAmountText();

	UFUNCTION()
	virtual void IncreaseSelectedAmount();

	UFUNCTION()
	virtual void DecreaseSelectedAmount();

	UFUNCTION()
	virtual void UpdateMaxAmount();

	// A virtual function implemented in it's respective subclasses
	UFUNCTION(BlueprintCallable)
	virtual void Transfer() {}

	// Updates the representation for whatever item is selected
	UFUNCTION(BlueprintCallable)
	virtual void UpdateActiveTile(UObject* NewObject);

	/** Adds an item to the list of items that can be selected
	 * Function does NOT call UpdateActiveTile, this has to be done manually */
	UFUNCTION(BlueprintCallable)
	virtual void AddItemToList(FItem_Struct ItemStruct);

public:
	// Called when the object is finished initializing and adds and sets all tiles to a list of given items that should be represented
	UFUNCTION(BlueprintCallable)
	virtual void SetTiles(TArray<TSubclassOf<AItemBase>> Items);
};
