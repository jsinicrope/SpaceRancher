// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemSelectionHUD.generated.h"

UCLASS()
class SPACERANCHER_API UItemSelectionHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UOverlay* RadialOverlay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemSelectionSegment> SegmentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> PiePieces;

public:
	UFUNCTION(BlueprintCallable)
	void CreateStandardWidget();
};
