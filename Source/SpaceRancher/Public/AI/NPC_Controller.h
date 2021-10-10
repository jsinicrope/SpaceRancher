// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "NPC_Controller.generated.h"

UCLASS()
class SPACERANCHER_API ANPC_Controller : public AAIController
{
	GENERATED_BODY()

public:

    ANPC_Controller(const FObjectInitializer& ObjectInitializer);

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UBehaviorTree* BehaviorTree;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
    class UAIPerceptionComponent* AIPerceptionComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AISightRadius = 3000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AISightAge = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AILosesSightRadius = AISightRadius + 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AIFieldOfView = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAISenseConfig_Sight* SightConfig;
	

	UFUNCTION()
	void OnPawnDetected(AActor* UpdatedActor, FAIStimulus Stimulus);
};
