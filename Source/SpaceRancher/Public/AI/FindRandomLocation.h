// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindRandomLocation.generated.h"

UCLASS()
class SPACERANCHER_API UFindRandomLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 150.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector TargetPosition;
};
