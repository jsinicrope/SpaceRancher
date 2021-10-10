// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
};
