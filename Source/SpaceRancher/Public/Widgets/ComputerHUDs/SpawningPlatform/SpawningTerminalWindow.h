// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawningTerminalWindow.generated.h"

class ASpawningArea;
class APlayerBuildable;
struct FBuildablePriceStruct;

UCLASS()
class SPACERANCHER_API USpawningTerminalWindow final : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void AddItems(const TArray<class UBuildableDisplayStruct*>& Items);

	UFUNCTION(BlueprintSetter)
	void SetOwningTerminal(ASpawningArea* Owner) { OwningTerminal = Owner; }

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithCredits(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass) const;

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithMaterials(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass) const;
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UScrollBox* ItemsScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USpawnableMainTile> ListEntryMainTileClass;

	UPROPERTY(BlueprintSetter=SetOwningTerminal)
	ASpawningArea* OwningTerminal;
};
