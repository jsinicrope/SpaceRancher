// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CompareAIState.h"
#include "AI/AIState.h"
#include "AI/NPC_Controller.h"


UCompareAIState::UCompareAIState()
{
	
}

bool UCompareAIState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	ANPC_Controller* AIController = static_cast<ANPC_Controller*>(OwnerComp.GetAIOwner());
	const FAIControllerState ControllerState = AIController->GetAIControllerState();
	return ControllerState.BehaviorState == BehaviorState;
}
