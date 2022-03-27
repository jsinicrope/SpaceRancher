// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawnableInfoTile.generated.h"

class UTextBlock;

UCLASS()
class SPACERANCHER_API USpawnableInfoTile : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	
	UFUNCTION(BlueprintCallable)
	void SetDescription(const FText& Text) const;
	void SetDescription(const FString& Text) const;

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* ItemDescription = nullptr;
};
