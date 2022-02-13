// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AI/AIState.h"
#include "AIControllable.generated.h"

UINTERFACE()
class UAIControllable : public UInterface
{
	GENERATED_BODY()
};

class SPACERANCHER_API IAIControllable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent)
	FAIPawnState GetAIPawnState();

	UFUNCTION(BlueprintNativeEvent)
	void SetAIPawnState(const FAIPawnState AIPawnState);
};
