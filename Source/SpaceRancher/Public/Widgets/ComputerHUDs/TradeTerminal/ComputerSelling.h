// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ComputerHUDs/TradeTerminal/TradingTab.h"
#include "ComputerSelling.generated.h"

UCLASS()
class SPACERANCHER_API UComputerSelling : public UTradingTab
{
	GENERATED_BODY()

public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	virtual void Transfer() override;
};
