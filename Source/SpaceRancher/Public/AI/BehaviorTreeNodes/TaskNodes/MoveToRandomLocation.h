// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MoveToRandomLocation.generated.h"

UCLASS()
class SPACERANCHER_API UMoveToRandomLocation final : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UMoveToRandomLocation();
	
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 150.0f;

	/** The Radius in which to consider Actor to have reached it's destination */
	UPROPERTY(EditAnywhere)
	float AcceptableRadius = 20.0f;
	
	FVector TargetPosition = FVector::ZeroVector;
	bool bHasPosition = false;
};
