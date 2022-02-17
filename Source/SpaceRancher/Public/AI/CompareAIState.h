// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "CompareAIState.generated.h"

enum class EAIBehaviorState : uint8;

/** Compares the current state of the AI to the one set and returns it's equality
 * May NOT be used with an AI not based on the NPC_Controller class
 * The underlying pawn must implement the IAIControllable Interface */
UCLASS()
class SPACERANCHER_API UCompareAIState final : public UBTDecorator
{
	GENERATED_BODY()
	
public:
	UCompareAIState();
	
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAIBehaviorState BehaviorState;
};
