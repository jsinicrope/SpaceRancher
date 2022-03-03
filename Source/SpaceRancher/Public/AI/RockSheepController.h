// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/NPC_Controller.h"
#include "RockSheepController.generated.h"

UCLASS()
class SPACERANCHER_API ARockSheepController : public ANPC_Controller
{
	GENERATED_BODY()

public:
	ARockSheepController(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	class ARockSheep* UnderlyingPawn;

	/* Called when the Underlying RockSheep's item is attached */
	UFUNCTION()
	void OnItemAttached();

	UFUNCTION()
	/* Called when the Underlying RockSheep's item is removed */
	void OnItemRemoved();
};
