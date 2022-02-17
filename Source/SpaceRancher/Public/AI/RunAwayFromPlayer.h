// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "RunAwayFromPlayer.generated.h"

UCLASS()
class SPACERANCHER_API URunAwayFromPlayer final : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION(BlueprintCallable)
	FVector GetRunAwayPoint(APawn* Enemy, APawn* Entity) const;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetActor;
	
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetPosition;

	UPROPERTY(EditAnywhere)
	float RunAwaySpeed = 450.0f;

	UPROPERTY(EditAnywhere)
	float MinNewDistance = 500.0f;

	UPROPERTY(EditAnywhere)
	float MaxNewDistance = 1000.0f;

	UPROPERTY(EditAnywhere)
	float DirectionalNoiseDeg = 35.0f;
};
