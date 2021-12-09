// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory_System/ItemBase.h"
#include "Inventory_System/ItemStruct.h"
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
	class AMyCharacter* PC;
	
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

	UPROPERTY(BlueprintReadOnly)
	int SelectedAmount = 0;

	UPROPERTY(BlueprintReadOnly)
	int MaxAmount = 0;

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

	UFUNCTION(BlueprintCallable)
	virtual void Transfer() {}

	UFUNCTION(BlueprintCallable)
	virtual void UpdateActiveTile(UObject* NewObject);

	UFUNCTION(BlueprintCallable)
	virtual void AddItemToList(FItem_Struct ItemStruct);

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetTiles(TArray<TSubclassOf<AItemBase>> Items);
};
