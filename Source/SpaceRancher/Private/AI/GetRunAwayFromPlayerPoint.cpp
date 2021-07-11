// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/GetRunAwayFromPlayerPoint.h"
#include "GameFramework/Actor.h"
#include "AI/NPC_Controller.h"
#include "Kismet/GameplayStatics.h"


EBTNodeResult::Type UGetRunAwayFromPlayerPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Started Custom Script"));



	//Add Get Player Position Vector from Blackboard
	FVector PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	
	return EBTNodeResult::Succeeded;
	
}