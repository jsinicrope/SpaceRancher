// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIState.h"
#include "Perception/AIPerceptionTypes.h"
#include "NPC_Controller.generated.h"

UCLASS()
class SPACERANCHER_API ANPC_Controller : public AAIController
{
	GENERATED_BODY()
	
public:
	ANPC_Controller(const FObjectInitializer& ObjectInitializer);
	
    virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	UFUNCTION(BlueprintCallable, BlueprintGetter)
	FAIControllerState GetAIControllerState();

	UFUNCTION(BlueprintCallable)
	void SetAIControllerState(FAIControllerState& NewState)	{ AIControllerState = NewState; }

	void SetAIControllerState(const EAIBehaviorState& NewState)	{ AIControllerState.BehaviorState = NewState; }
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
	UAIPerceptionComponent* AIPerceptionComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AISightRadius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AISightAge = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AILosesSightRadius = AISightRadius + 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AIFieldOfView = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAISenseConfig_Sight* SightConfig;

	// Called when a hostile Pawn was Detected
	UFUNCTION()
	void OnPawnDetected(AActor* UpdatedActor, const FAIStimulus Stimulus);

private:
	UPROPERTY(BlueprintGetter=GetAIControllerState, BlueprintSetter=SetAIControllerState)
	FAIControllerState AIControllerState;
};
