// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AIState.generated.h"

UENUM(BlueprintType, meta=(DisplayName="BehaviourState"))
enum class EAIBehaviourState : uint8
{
	Passive			UMETA(DisplayName="Passive"),
	Aggressive		UMETA(DisplayName="Aggressive"),
	Alerted			UMETA(DisplayName="Alerted"),
	Scared			UMETA(DisplayName="Scared"),
	Annoyed			UMETA(DisplayName="Annoyed"),
	Friendly		UMETA(DisplayName="Friendly"),
	Tamed			UMETA(DisplayName="Tamed"),
	Mating			UMETA(DisplayName="Mating")
};

USTRUCT(BlueprintType)
struct SPACERANCHER_API FAIPawnState : public FTableRowBase
{
	GENERATED_BODY()

	// Health of the AI pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

	// Stamina of the AI pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Stamina;

	explicit FAIPawnState(const float Health = 100.0f, const float Stamina = 100.0f)
	{
		this->Health = Health;
		this->Stamina = Stamina;
	}
};

USTRUCT(BlueprintType)
struct SPACERANCHER_API FAIControllerState : public FTableRowBase
{
	GENERATED_BODY()

	// The State of the controlled pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAIPawnState PawnState;

	// BehaviourState of the AI Controller
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAIBehaviourState BehaviourState;

	explicit FAIControllerState(const FAIPawnState AIPawnState = FAIPawnState(), const EAIBehaviourState BehaviourState = EAIBehaviourState::Passive)
	{
		this->PawnState = AIPawnState;
		this->BehaviourState = BehaviourState;
	}
};
