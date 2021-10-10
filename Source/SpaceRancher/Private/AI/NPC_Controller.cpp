// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/NPC_Controller.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"

ANPC_Controller::ANPC_Controller(const FObjectInitializer& ObjectInitializer)
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	AddOwnedComponent(AIPerceptionComponent);
}

void ANPC_Controller::BeginPlay()
{
	Super::BeginPlay();
	if (BehaviorTree != nullptr)
	{
		RunBehaviorTree(Cast<UBehaviorTree>(BehaviorTree));
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("BehaviorTree started"));
	}
}
