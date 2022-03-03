// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/BehaviorTreeNodes/TaskNodes/RunAwayFromPlayer.h"
#include "NavigationSystem.h"
#include "GameFramework/Actor.h"
#include "AI/NPC_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"


URunAwayFromPlayer::URunAwayFromPlayer()
{
	bNotifyTick = true;
}

void URunAwayFromPlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type URunAwayFromPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	APawn* Enemy = Cast<APawn>(Blackboard->GetValueAsObject(TargetActor.SelectedKeyName));
	AAIController* EntityController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = EntityController->GetPawn();
	const ACharacter* EntityCharacter = Cast<ACharacter>(ControlledPawn);
	const FVector EntityPosition = EntityCharacter->GetActorLocation();

	TargetPosition = TargetPosition.IsZero() ? GetRunAwayPoint(Enemy, ControlledPawn) : TargetPosition;

	const float Distance = FVector::Distance(EntityPosition, TargetPosition);
	if (Distance <= AcceptableRadius + 25.0f)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		TargetPosition = FVector::ZeroVector;
		return EBTNodeResult::Succeeded;
	}

	// Fail Task if there is no valid location to escape to
	if (EntityController->MoveToLocation(TargetPosition) == EPathFollowingRequestResult::Type::Failed)
	{
		TargetPosition = FVector::ZeroVector;
		FinishLatentTask(OwnerComp,EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}
	
	EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunAwaySpeed;
	return EBTNodeResult::InProgress;
}

FVector URunAwayFromPlayer::GetRunAwayPoint(APawn* Enemy, APawn* Entity) const
{
	const FVector PlayerLocation = Enemy->GetActorLocation();
	const FVector EntityLocation = Entity->GetActorLocation();
	const float XLocationDelta = PlayerLocation.X - EntityLocation.X;
	const float YLocationDelta = PlayerLocation.Y - EntityLocation.Y;
	
	// Get rotation from radians
	const float Rotation = FMath::RadiansToDegrees(FMath::Atan2(YLocationDelta, XLocationDelta)) - (180.0f + FMath::RandRange(-DirectionalNoiseDeg, DirectionalNoiseDeg));
	
	// Add noise for more random run direction
	const FRotator RunDirection(0, Rotation, 0);
	const float RunAwayDistance = FMath::RandRange(MinNewDistance, MaxNewDistance);
	FVector NewLocation = UKismetMathLibrary::GetForwardVector(RunDirection) * RunAwayDistance;
	
	NewLocation += EntityLocation;
	
	// Debugging line
#if WITH_EDITOR
	FVector RepresentedLocation = NewLocation;
	RepresentedLocation.Z = EntityLocation.Z;

	UKismetSystemLibrary::DrawDebugLine(GetWorld(), EntityLocation, RepresentedLocation, FColor::Blue, 1.0f, 12.3333f);
#endif
	return NewLocation;
}
