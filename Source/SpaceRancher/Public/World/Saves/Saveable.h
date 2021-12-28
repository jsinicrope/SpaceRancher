// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Saveable.generated.h"

UINTERFACE()
class USaveable : public UInterface
{
	GENERATED_BODY()
};

class ISaveable
{
	GENERATED_BODY()

public:
	/** Called before any saving on the actor takes place
	 * @return true if the actor should be automatically serialized */
	UFUNCTION(BlueprintNativeEvent)
	bool PreSaveActor();

	/** Called before any loading on the actor takes place
	 * @return true if the actor should be automatically serialized
	 * @note This might not be called if the actor has not spawned yet */
	UFUNCTION(BlueprintNativeEvent)
	bool PreLoadActor();

	// Called after the actor has been saved
	UFUNCTION(BlueprintNativeEvent)
	void PostSaveActor();

	// Called after the actor has been successfully spawned and loaded
	UFUNCTION(BlueprintNativeEvent)
	void PostLoadActor();
};
