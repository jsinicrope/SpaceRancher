// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/RockSheepController.h"
#include "AI/RockSheep.h"

ARockSheepController::ARockSheepController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AIControllerState.BehaviorState = EAIBehaviorState::Passive;
}

void ARockSheepController::BeginPlay()
{
	Super::BeginPlay();
}

void ARockSheepController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ARockSheepController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UnderlyingPawn = static_cast<ARockSheep*>(InPawn);
	ensure(UnderlyingPawn);
	UnderlyingPawn->OnItemDestroyed.BindDynamic(this, &ARockSheepController::OnItemRemoved);
	UnderlyingPawn->OnItemSpawned.BindDynamic(this, &ARockSheepController::OnItemAttached);

	UnderlyingPawn->SpawnItem();
}

void ARockSheepController::OnUnPossess()
{
	Super::OnUnPossess();
	
	UnderlyingPawn = nullptr;
}

void ARockSheepController::OnItemAttached()
{
	AIControllerState.BehaviorState = EAIBehaviorState::Aggressive;
}

void ARockSheepController::OnItemRemoved()
{
	AIControllerState.BehaviorState = EAIBehaviorState::Passive;
}
