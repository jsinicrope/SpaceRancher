// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/FindRandomLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const AAIController* Owner = OwnerComp.GetAIOwner();
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	
	FNavLocation OutLocation;
	if (!NavSys || !NavSys->GetRandomReachablePointInRadius(Owner->GetPawn()->GetActorLocation(), Radius, OutLocation))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Navigation System Failed"));
		return EBTNodeResult::Failed;
	}

	Cast<ACharacter>(Owner->GetPawn())->GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TargetPosition.SelectedKeyName, OutLocation.Location);
	return EBTNodeResult::Succeeded;
}
