// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Interfaces/Interactable.h"
#include "FoodCooker.generated.h"

UCLASS()
class SPACERANCHER_API AFoodCooker : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodCooker(const FObjectInitializer &ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(FItem_Struct EquippedItem) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CookerFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CookerGrill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CookerDoor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTimelineComponent* DoorTimelineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* TimerWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpawnerComponent* SpawnerComponent;

	UPROPERTY()
	class UFoodCookerTimer* CookerTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cooking")
	TSubclassOf<class AItemBase> RequiredItem = nullptr;

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, Category="Cooking")
	bool bDoorOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cooking")
	float CookingTime = 30.0f;

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, Category="Cooking")
	float CookedTime = 0.0f;

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, Category="Cooking")
	bool bCookingQueued = false;

	UPROPERTY(BlueprintReadOnly, AdvancedDisplay, Category="Cooking")
	bool bCooking = false;

	UPROPERTY()
	class AMyCharacter* PC;

	UFUNCTION(BlueprintCallable)
	void QueueCooking();
	
	UFUNCTION(BlueprintCallable)
	bool StartCooking();

	UFUNCTION(BlueprintCallable)
	void EndCooking();

public:
	// Variable to hold the Curve asset
	UPROPERTY(EditAnywhere)
	UCurveFloat* DoorTimelineFloatCurve;

private:
	//Float Track Signature to handle our update track event
	FOnTimelineFloat UpdateFunctionFloat;

	//Function which updates our Door's relative location with the timeline graph
	UFUNCTION()
	void UpdateTimelineComp(const float Output);
};
