// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "HarvestResource.generated.h"

UCLASS()
class SPACERANCHER_API UHarvestResource : public UBTTaskNode
{
	GENERATED_BODY()

	// inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
