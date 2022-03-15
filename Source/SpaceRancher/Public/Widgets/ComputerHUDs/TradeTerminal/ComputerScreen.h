// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ComputerScreen.generated.h"

UCLASS()
class SPACERANCHER_API UComputerScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* SellTabButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* BuyTabButton;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UWidgetSwitcher* WidgetSwitcher;
	
	UPROPERTY(BlueprintReadOnly)
	class AMyCharacter* PC;

	UPROPERTY(BlueprintReadOnly)
	class AComputer* OwningComputer;

public:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UComputerSelling* SellingTab;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UComputerBuying* BuyingTab;

	UFUNCTION()
	void SetSellingTabActive();
	
	UFUNCTION()
	void SetBuyingTabActive();
	
	void SetOwningComputer(class AComputer* Computer) {OwningComputer = Computer;}

	UFUNCTION(BlueprintGetter)
	class AComputer* GetOwningComputer() const { return OwningComputer; }
};
