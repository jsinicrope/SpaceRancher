// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GetRunAwayFromPlayerPoint.generated.h"

UCLASS()
class SPACERANCHER_API UGetRunAwayFromPlayerPoint : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UGetRunAwayFromPlayerPoint();

	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION(BlueprintCallable)
	FVector GetRunAwayPoint(APawn* Entity);

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetVector;

	UPROPERTY(EditAnywhere)
	float RunAwaySpeed = 450.0f;

	UPROPERTY(EditAnywhere)
	float MinNewDistance = 500.0f;

	UPROPERTY(EditAnywhere)
	float MaxNewDistance = 1000.0f;

	UPROPERTY(EditAnywhere)
	float DirectionalNoiseDeg = 35.0f;
};
