// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inventory_System/ItemStruct.h"
#include "ItemSelectionHUD.generated.h"

UCLASS()
class SPACERANCHER_API UItemSelectionHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UOverlay* RadialOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemSelectionSegment> SegmentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItem_Struct> PiePieces;

public:
	UFUNCTION(BlueprintCallable)
	void CreateStandardWidget(TArray<FItem_Struct> &Selectables);

	UFUNCTION(BlueprintCallable)
	FItem_Struct GetSelectedItem();
};
