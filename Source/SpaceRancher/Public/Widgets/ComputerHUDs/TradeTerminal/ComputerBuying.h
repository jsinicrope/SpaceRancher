// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComputerSelling.h"
#include "Blueprint/UserWidget.h"
#include "ComputerBuying.generated.h"

UCLASS()
class SPACERANCHER_API UComputerBuying : public UComputerSelling
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void SetMaxStock(const int MaxStock) { MaxAmount = MaxStock; };

protected:
	virtual void UpdateMaxAmount() override;
	virtual void Transfer() override;	
};
