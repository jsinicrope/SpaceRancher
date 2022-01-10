// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Funds.generated.h"

UCLASS()
class SPACERANCHER_API UFunds : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	class UTextBlock* AvailableFunds;

	UPROPERTY(BlueprintReadOnly)
	class ACppPlayerController* PC;
};
