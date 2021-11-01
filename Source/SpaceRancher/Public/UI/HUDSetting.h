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
	// Sets default values for this component's properties
	UHUDSetting();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Widgets
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> MainHUDClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCMainHUD* MainHUD;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> InteractPopUpClass;
	
	UPROPERTY()
	class UUserWidget* InteractPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> ItemPickUpWidgetClass;

	UPROPERTY()
	class UItemPickUpWidget* ItemPickUpWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> ClockWidgetClass;

	UPROPERTY()
	class UClock* ClockWidget;
	
	UPROPERTY()
	class UUserWidget* WidgetToRemove;
};
