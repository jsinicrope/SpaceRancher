// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RunAwayFromPlayer.h"
#include "GameFramework/Actor.h"
#include "AI/NPC_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type URunAwayFromPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	
	APawn* Enemy = Cast<APawn>(Blackboard->GetValueAsObject(TargetActor.SelectedKeyName));
	const auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	const FVector NewTargetPosition = GetRunAwayPoint(Enemy, ControlledPawn);

	Blackboard->SetValueAsVector(TargetPosition.SelectedKeyName, NewTargetPosition);

	const ACharacter* EntityCharacter = Cast<ACharacter>(ControlledPawn);
	EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunAwaySpeed;

	return EBTNodeResult::Succeeded;
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
	FVector RepresentedLocation = NewLocation;
	RepresentedLocation.Z = EntityLocation.Z;

	UKismetSystemLibrary::DrawDebugLine(GetWorld(), EntityLocation, RepresentedLocation, FColor::Blue, 1.0f, 12.3333f);
	return NewLocation;
}
