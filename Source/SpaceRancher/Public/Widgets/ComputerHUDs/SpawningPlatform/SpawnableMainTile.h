// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildableDisplayStruct.h"
#include "Blueprint/UserWidget.h"
#include "SpawnableMainTile.generated.h"

class UBorder;
class UButton;
class UImage;
class UTextBlock;
class UMenuAnchor;
class USpawningTerminalWindow;

UCLASS(Abstract)
class SPACERANCHER_API USpawnableMainTile final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	void SetListObject(UBuildableDisplayStruct* Object);

	UFUNCTION(BlueprintSetter)
	void SetOwningTerminalWindow(USpawningTerminalWindow* Owner) { OwningTerminalWindow = Owner; }

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithCredits() const;

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithMaterials() const;
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UBorder* BackgroundBorder;
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UImage* Image;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* Name;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* DetailsPanelButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* PricePanelButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UMenuAnchor* DetailsPanelAnchor;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UMenuAnchor* PricePanelAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBuildableDisplayStruct* RepresentedBuildable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USpawnablePriceTile> PriceTileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USpawnableInfoTile> InfoTileClass;

	UPROPERTY(BlueprintSetter=SetOwningTerminalWindow)
	USpawningTerminalWindow* OwningTerminalWindow;
	
	UFUNCTION()
	void UpdateWidget() const;

	UFUNCTION()
	void ToggleDetailsPanel();

	UFUNCTION()
	void TogglePricePanel();
	UFUNCTION()
	UUserWidget* GetDetailsPanel();

	UFUNCTION()
	UUserWidget* GetPricePanel();
};
