// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "ItemSellingTile.generated.h"

UCLASS()
class SPACERANCHER_API UItemSellingTile : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UImage* ItemDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UButton* ItemTileButton;
};
