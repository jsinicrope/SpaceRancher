// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GetRunAwayFromPlayerPoint.h"
#include "GameFramework/Actor.h"
#include "AI/NPC_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

UGetRunAwayFromPlayerPoint::UGetRunAwayFromPlayerPoint()
{
	MaxRadius = 5000.0f;
	NewDistanceFactor = 1.2f;
	RunAwaySpeed = 450.0f;
	bReachedNewPosition = false;
}

EBTNodeResult::Type UGetRunAwayFromPlayerPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Started Custom Script"));
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	FVector EntityPosition = ControlledPawn->GetActorLocation();
	FVector PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector TargetPosition = Blackboard->GetValueAsVector(TargetVector.SelectedKeyName);

	if (Blackboard->GetValueAsBool(HasPosition.SelectedKeyName))
	{
		float Current_Distance = sqrt(pow((TargetPosition.X - EntityPosition.X), 2.0f) + pow((TargetPosition.Y - EntityPosition.Y), 2.0f));

		if (Current_Distance <= 50.0f)
		{
			FVector NewTargetPosition = UGetRunAwayFromPlayerPoint::GetRunAwayPoint(EntityPosition, PlayerPosition, NewDistanceFactor);

			Blackboard->SetValueAsVector(TargetVector.SelectedKeyName, NewTargetPosition);

			ACharacter* EntityCharacter = Cast<ACharacter>(ControlledPawn);
			EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunAwaySpeed;
		}

		AAIController* EntityController = Cast<AAIController>(ControlledPawn->GetController());
		EntityController->MoveToLocation(TargetPosition);

		return EBTNodeResult::Succeeded;
	}

	else
	{
		FVector NewTargetPosition = UGetRunAwayFromPlayerPoint::GetRunAwayPoint(EntityPosition, PlayerPosition, NewDistanceFactor);

		Blackboard->SetValueAsVector(TargetVector.SelectedKeyName, NewTargetPosition);

		ACharacter* EntityCharacter = Cast<ACharacter>(ControlledPawn);
		EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunAwaySpeed;

		AAIController* EntityController = Cast<AAIController>(ControlledPawn->GetController());
		EntityController->MoveToLocation(NewTargetPosition);

		Blackboard->SetValueAsBool(HasPosition.SelectedKeyName, true);

		return EBTNodeResult::Succeeded;
	}
	
}

FVector UGetRunAwayFromPlayerPoint::GetRunAwayPoint(FVector Entity, FVector Player, float fMaxNewDistanceFactor)
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	if (!NavSys)
		return FVector();

	FNavLocation Result;

	float Current_Distance = sqrt(pow((Entity.X - Player.X), 2.0f) + pow((Entity.Y - Player.Y), 2.0f));

	if (NavSys->GetRandomReachablePointInRadius(Entity, (Current_Distance * fMaxNewDistanceFactor * 2), Result))
	{
		FVector NewPosition = Result.Location;

		float NewDistance = sqrt(pow((NewPosition.X - Player.X), 2.0f) + pow((NewPosition.Y - Player.Y), 2.0f));

		if (NewDistance >= (Current_Distance * fMaxNewDistanceFactor))
		{
			return NewPosition;
		}
		else
		{
			fMaxNewDistanceFactor += 0.01f;
			return GetRunAwayPoint(Entity, Player, fMaxNewDistanceFactor);
		}
	}
	return FVector();
}
