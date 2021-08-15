// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "ItemPickUpWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UItemPickUpWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* PickedUpItem;

public:
	virtual void NativeConstruct();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* ItemImage = NULL;
};
