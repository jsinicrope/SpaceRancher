// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BehaviorTreeNodes/TaskNodes/MoveToRandomLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


UMoveToRandomLocation::UMoveToRandomLocation()
{
	bNotifyTick = true;
}

void UMoveToRandomLocation::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UMoveToRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Owner = OwnerComp.GetAIOwner();
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	if (!bHasPosition)
	{
		FNavLocation OutLocation;
		if (!NavSys || !NavSys->GetRandomReachablePointInRadius(Owner->GetPawn()->GetActorLocation(), Radius, OutLocation))
		{
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Navigation System Failed"));
			return EBTNodeResult::Failed;
		}
		TargetPosition = OutLocation.Location;
		bHasPosition = true;
	}

	Cast<ACharacter>(Owner->GetPawn())->GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
	Owner->MoveToLocation(TargetPosition);

	const float Distance = FVector::Dist(TargetPosition, Owner->GetPawn()->GetActorLocation());
	if (Distance <= AcceptableRadius + 85.2f)
	{
		bHasPosition = false;
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::InProgress;
}
