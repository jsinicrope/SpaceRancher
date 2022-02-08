// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/AttackPlayer.h"
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
	Enemy = Cast<ACharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("TargetActor")));
	if (!Enemy || !Enemy->GetClass()->ImplementsInterface(UAttackable::StaticClass()))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("TargetActor"), nullptr);
		return EBTNodeResult::Aborted;
	}
	
	if (IAttackable::Execute_WasKilled(Enemy))
	{
		return EBTNodeResult::Succeeded;
	}
	
	const FVector PlayerLocation = IAttackable::Execute_GetCharacter(Enemy)->GetActorLocation();
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
			IAttackable::Execute_Damage(Enemy, Damage);
			TimeSinceLastAttack = 0.0f;

			if (IAttackable::Execute_WasKilled(Enemy))
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}

	if (bFailOnLowHealth)
	{
		ANPC* Entity = Cast<ANPC>(EntityController->GetPawn());

		const float EntityHealth = Entity->GetHealth();
		
		if (EntityHealth <= EntityHealth * PercentLowHealth)
		{
			return EBTNodeResult::Failed;
		}
	}
	
	UKismetSystemLibrary::DrawDebugLine(GetWorld(), EntityLocation, FVector(PlayerLocation.X, PlayerLocation.Y, EntityLocation.Z), FColor::Red, 0.1f, 6.0f);
	return EBTNodeResult::InProgress;
}

void UAttackPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	TimeSinceLastAttack += DeltaSeconds;

	ExecuteTask(OwnerComp, NodeMemory);
}
