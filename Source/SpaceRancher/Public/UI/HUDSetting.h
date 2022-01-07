// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "Inventory_System/ItemStruct.h"
#include "HUDSetting.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACERANCHER_API UHUDSetting : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHUDSetting();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	class ACppPlayerController* PlayerController;
	
	//Widgets
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MainHUDClass;
	
	UPROPERTY(BlueprintReadOnly)
	class UCMainHUD* MainHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemSelectionHUD> RadialMenuClass;

	UPROPERTY(BlueprintReadOnly)
	UItemSelectionHUD* RadialMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InteractPopUpClass;
	
	UPROPERTY()
	UUserWidget* InteractPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemPickUpWidget> ItemPickUpWidgetClass;

	UPROPERTY()
	UItemPickUpWidget* ItemPickUpWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UHealthAndStaminaBar> HealthAndStaminaBarClass;

	UPROPERTY()
	UHealthAndStaminaBar* HealthAndStaminaBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UClock> ClockWidgetClass;

	UPROPERTY()
	UClock* ClockWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MiniMapClass;

	UPROPERTY()
	UUserWidget* MiniMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UFunds> AvailableFundsClass;
	
	UPROPERTY()
	UFunds* AvailableFunds;
	
	UPROPERTY()
	UUserWidget* WidgetToRemove;

	UFUNCTION(BlueprintCallable)
	void ShowInteractPopUp();

	UFUNCTION(BlueprintCallable)
	void HideInteractPopUp();
	
	UFUNCTION(BlueprintCallable)
	bool OpenRadialMenu(TArray<FItem_Struct> &Selectables);

	UFUNCTION(BlueprintCallable)
	void CloseRadialMenu();
};
