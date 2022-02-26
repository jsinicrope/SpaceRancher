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
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UFUNCTION(BlueprintCallable)
	FVector GetRunAwayPoint(APawn* Enemy, APawn* Entity) const;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetActor;
	
	FVector TargetPosition = FVector::ZeroVector;

	/** The Maximum Speed the NPC Pawn will move away at
	 * NOTE: The Speed is not reset to it's default at the end of execution */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunAwaySpeed = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinNewDistance = 750.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxNewDistance = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DirectionalNoiseDeg = 35.0f;

	/** The Radius in which to consider Actor to have reached it's destination */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AcceptableRadius = 20.0f;
};
