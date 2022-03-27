// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interactables/PlayerBuildable.h"
#include "SpawnablePriceTile.generated.h"

class UButton;
class UGridPanel;
class USpawnableMainTile;
class USpawnablePriceTileSegment;

UCLASS()
class SPACERANCHER_API USpawnablePriceTile final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void SetPrice(const FBuildablePriceStruct& Items);

	UFUNCTION(BlueprintSetter)
	void SetOwningTile(USpawnableMainTile* Owner) { OwningTile = Owner; }

protected:
	// This should be set to whatever image is used to display credits
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	USpawnablePriceTileSegment* CreditPriceWidget;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* CreditPriceButton;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* MaterialsPriceButton;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UGridPanel* MaterialsGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemPriceRows = 2;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<USpawnablePriceTileSegment> MaterialDisplayWidget;

	UPROPERTY(BlueprintReadOnly)
	FBuildablePriceStruct RepresentedItemCost;

	UPROPERTY(BlueprintSetter=SetOwningTile)
	USpawnableMainTile* OwningTile;

	UFUNCTION()
	void CreditPriceButtonPressed();
	
	UFUNCTION()
	void MaterialsPriceButtonPressed();
};
