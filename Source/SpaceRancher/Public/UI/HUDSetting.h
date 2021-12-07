// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
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
	TSubclassOf<class UUserWidget> MainHUDClass;
	
	UPROPERTY(BlueprintReadOnly)
	class UCMainHUD* MainHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemSelectionHUD> RadialMenuClass;

	UPROPERTY(BlueprintReadOnly)
	class UItemSelectionHUD* RadialMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> InteractPopUpClass;
	
	UPROPERTY()
	class UUserWidget* InteractPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UItemPickUpWidget> ItemPickUpWidgetClass;

	UPROPERTY()
	class UItemPickUpWidget* ItemPickUpWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UClock> ClockWidgetClass;

	UPROPERTY()
	class UClock* ClockWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> MiniMapClass;

	UPROPERTY()
	class UUserWidget* MiniMap;
	
	UPROPERTY()
	class UUserWidget* WidgetToRemove;

	UFUNCTION(BlueprintCallable)
	bool OpenRadialMenu();

	UFUNCTION(BlueprintCallable)
	void CloseRadialMenu();
};
