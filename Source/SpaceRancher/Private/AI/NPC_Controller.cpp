// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/NPC_Controller.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ANPC_Controller::ANPC_Controller(const FObjectInitializer& ObjectInitializer)
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SetPerceptionComponent(*AIPerceptionComponent);

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILosesSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent->SetDominantSense(*SightConfig->GetSenseImplementation());
	AIPerceptionComponent->ConfigureSense(*SightConfig);
}

void ANPC_Controller::BeginPlay()
{
	Super::BeginPlay();
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ANPC_Controller::OnPawnDetected);
	if (BehaviorTree != nullptr)
	{
		RunBehaviorTree(Cast<UBehaviorTree>(BehaviorTree));
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("BehaviorTree started"));
	}
	AIPerceptionComponent->Activate();
}

void ANPC_Controller::OnPawnDetected(AActor* UpdatedActor, struct FAIStimulus Stimulus)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Blue, FString("Player seen!"));
	GetBlackboardComponent()->SetValueAsBool(FName("CanSeePlayer"), Stimulus.WasSuccessfullySensed());
}
