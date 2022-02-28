// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BehaviorTreeNodes/TaskNodes/AttackPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Actor.h"
#include "AI/NPC.h"
#include "Kismet/KismetSystemLibrary.h"

UAttackPlayer::UAttackPlayer(const FObjectInitializer& ObjectInitializer)  : Super(ObjectInitializer)
{
	bNotifyTick = true;
}

EBTNodeResult::Type UAttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Enemy = Cast<ACharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetActor.SelectedKeyName));
	if (!Enemy || !Enemy->GetClass()->ImplementsInterface(UAttackable::StaticClass()))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetActor.SelectedKeyName, nullptr);
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(CanSeeTarget.SelectedKeyName, false);
		FinishLatentAbort(OwnerComp);
		return EBTNodeResult::Aborted;
	}
	
	const FVector PlayerLocation = Enemy->GetActorLocation();
	AAIController* EntityController = OwnerComp.GetAIOwner();
	const FVector EntityLocation = EntityController->GetPawn()->GetActorLocation();
	const float Distance = FVector::Dist(PlayerLocation, EntityLocation);
	const ACharacter* EntityCharacter = Cast<ACharacter>(EntityController->GetPawn());

	if (Distance >= AttackRange)
	{
		EntityController->MoveToLocation(PlayerLocation);
		EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
	else
	{
		if (TimeSinceLastAttack >= AttackSpeed)
		{
			TimeSinceLastAttack = 0.0f;
			if (IAttackable::Execute_Damage(Enemy, Damage))
			{
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(CanSeeTarget.SelectedKeyName, false);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	if (bFailOnLowHealth)
	{
		const ANPC* Entity = Cast<ANPC>(EntityController->GetPawn());

		const float EntityHealth = Entity->GetHealth();
		
		if (EntityHealth <= EntityHealth * LowHealthPercentage)
		{
			FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
			return EBTNodeResult::Failed;
		}
	}
	
	UKismetSystemLibrary::DrawDebugLine(GetWorld(), EntityLocation, FVector(PlayerLocation.X, PlayerLocation.Y, EntityLocation.Z), FColor::Red, 0.1f, 6.0f);
	return EBTNodeResult::InProgress;
}

void UAttackPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	TimeSinceLastAttack += DeltaSeconds;
	ExecuteTask(OwnerComp, NodeMemory);
}
