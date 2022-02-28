// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BehaviorTreeNodes/TaskNodes/HarvestResource.h"

void UHarvestResource::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UHarvestResource::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return EBTNodeResult::Succeeded;
}
