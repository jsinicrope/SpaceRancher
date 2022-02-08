// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Attackable.generated.h"

UINTERFACE()
class UAttackable : public UInterface
{
	GENERATED_BODY()
};

class SPACERANCHER_API IAttackable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent)
	bool WasKilled();

	UFUNCTION(BlueprintNativeEvent)
	void Damage(float Damage);

	UFUNCTION(BlueprintNativeEvent)
	ACharacter* GetCharacter();
};
