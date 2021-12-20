// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Equippable.generated.h"

UINTERFACE(MinimalAPI)
class UEquippable : public UInterface
{
	GENERATED_BODY()
};

class SPACERANCHER_API IEquippable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Called when the item gets selected through the item selection menu
	UFUNCTION(BlueprintNativeEvent)
	void Selected();

	// Called when the item isn't selected anymore
	UFUNCTION(BlueprintNativeEvent)
	void DeSelect();
	
	// Called when the item is used
	UFUNCTION(BlueprintNativeEvent)
	void Activated();

	// Called when the item is stopped being used
	UFUNCTION(BlueprintNativeEvent)
	void Deactivated();
};
