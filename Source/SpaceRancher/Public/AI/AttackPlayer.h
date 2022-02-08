// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AttackPlayer.generated.h"

UCLASS()
class SPACERANCHER_API UAttackPlayer : public UBTTaskNode
{
	GENERATED_BODY()

	inline virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	UAttackPlayer(const FObjectInitializer& objectInitializer);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackRange = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackSpeed = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bFailOnLowHealth = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0", ClampMax="1", EditCondition="bFailOnLowHealth"))
	float PercentLowHealth;
	
private:
	UPROPERTY()
	ACharacter* Enemy = nullptr;

	UPROPERTY()
	float TimeSinceLastAttack = AttackSpeed;
};
