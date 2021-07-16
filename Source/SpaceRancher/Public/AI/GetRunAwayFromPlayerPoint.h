// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GetRunAwayFromPlayerPoint.generated.h"

/**
 * 
 */
UCLASS()
class SPACERANCHER_API UGetRunAwayFromPlayerPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UGetRunAwayFromPlayerPoint();

	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION(BlueprintCallable)
	FVector GetRunAwayPoint(FVector Entity, FVector Player, float fMinNewDistanceFactor);

	UPROPERTY(EditAnywhere)
	float MaxRadius = 5000.0f;

	UPROPERTY(EditAnywhere)
	float NewDistanceFactor;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetVector;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector HasPosition;

	UPROPERTY(EditAnywhere)
	float RunAwaySpeed;

	bool bReachedNewPosition;

private:
	float MinNewDistanceFactor;
};
