// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/AttackPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Actor.h"

UAttackPlayer::UAttackPlayer(const FObjectInitializer& objectInitializer)  : Super(objectInitializer)
{
	bNotifyTick = true;
}

EBTNodeResult::Type UAttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Player = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (Player->bIsPlayerDead())
	{
		return EBTNodeResult::Succeeded;
	}
	
	FVector PlayerLocation = Player->GetActorLocation();
	AAIController* EntityController = OwnerComp.GetAIOwner();
	FVector EntityLocation = EntityController->GetPawn()->GetActorLocation();
	const float Distance = FVector::Dist(PlayerLocation, EntityLocation);
	ACharacter* EntityCharacter = Cast<ACharacter>(EntityController->GetPawn());

	if (Distance >= AttackRange)
	{
		EntityController->MoveToLocation(PlayerLocation);
		EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
	else
	{
		if (TimeSinceLastAttack >= AttackSpeed)
		{
			Player->DamagePlayer(Damage);
			TimeSinceLastAttack = 0.0f;

			if (Player->bIsPlayerDead())
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::InProgress;
}

void UAttackPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	TimeSinceLastAttack += DeltaSeconds;

	ExecuteTask(OwnerComp, NodeMemory);
}
