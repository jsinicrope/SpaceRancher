// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory_System/ItemStruct.h"
#include "ComputerMonitor.generated.h"

UCLASS()
class SPACERANCHER_API UComputerMonitor : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY()
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
	class UOverlay* SellingButtonsOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* SelectedAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* DecreaseSelectedAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* IncreaseSelectedAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class USizeBox* SellButtonBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* SellButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* SellButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UItemStructTileView* ActiveTile;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int SelectedSellAmount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int MaxAmount = 0;

	UPROPERTY()
	float TimeSinceSold = 0.0f;

	UFUNCTION()
	void SetAwaitingSelection() const;

	UFUNCTION()
	void SetSelectionSet() const;
	
	UFUNCTION()
	void UpdateSelectedAmountText();

	UFUNCTION()
	void IncreaseSelectedSellAmount();

	UFUNCTION()
	void DecreaseSelectedSellAmount();

	UFUNCTION()
	void UpdateMaxAmount();
	
	UFUNCTION(BlueprintCallable)
	void Sell();

	UFUNCTION(BlueprintCallable)
	void UpdateActiveTile(UObject* NewObject);

public:
	void SetPlayerCharacter(class AMyCharacter* PlayerCharacter) {PC = PlayerCharacter;}
	
	UFUNCTION(BlueprintCallable)
	void AddItemToList(FItem_Struct ItemStruct);
};
