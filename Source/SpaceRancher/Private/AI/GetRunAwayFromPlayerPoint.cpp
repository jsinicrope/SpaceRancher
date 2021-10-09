// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GetRunAwayFromPlayerPoint.h"
#include "GameFramework/Actor.h"
#include "AI/NPC_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

UGetRunAwayFromPlayerPoint::UGetRunAwayFromPlayerPoint()
{

}

EBTNodeResult::Type UGetRunAwayFromPlayerPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	FVector NewTargetPosition = UGetRunAwayFromPlayerPoint::GetRunAwayPoint(ControlledPawn);

	Blackboard->SetValueAsVector(TargetVector.SelectedKeyName, NewTargetPosition);

	ACharacter* EntityCharacter = Cast<ACharacter>(ControlledPawn);
	EntityCharacter->GetCharacterMovement()->MaxWalkSpeed = RunAwaySpeed;

	return EBTNodeResult::Succeeded;
}

FVector UGetRunAwayFromPlayerPoint::GetRunAwayPoint(APawn* Entity)
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!NavSys)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("No Nav mesh found"));
		return FVector();
	}

	FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector EntityLocation = Entity->GetActorLocation();
	float XLocationDelta = PlayerLocation.X - EntityLocation.X;
	float YLocationDelta = PlayerLocation.Y - EntityLocation.Y;
	// Get rotation from radians
	float Rotation = FMath::RadiansToDegrees(FMath::Atan2(YLocationDelta, XLocationDelta)) - (180.0f + FMath::RandRange(-DirectionalNoiseDeg, DirectionalNoiseDeg));

	// Add noise for more random run dirction
	float NewRunDirction = Rotation;
	FRotator RunDirection(0, Rotation, 0);
	float RunAwayDistance = FMath::RandRange(MinNewDistance, MaxNewDistance);
	FVector NewLocation = UKismetMathLibrary::GetForwardVector(RunDirection) * RunAwayDistance;

	// Debuging line
	FVector Start = EntityLocation;

	FVector ReprLocation = NewLocation;
	ReprLocation.Z = EntityLocation.Z;

	UKismetSystemLibrary::DrawDebugLine(GetWorld(), Start, ReprLocation, FColor::Blue, 1.0f, 12.3333f);
	return NewLocation;
}
