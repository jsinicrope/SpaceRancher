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
	UFUNCTION(BlueprintNativeEvent)
	void SaveActor();
	
	UFUNCTION(BlueprintNativeEvent)
	void PreSaveActor();
	
	UFUNCTION(BlueprintNativeEvent)
	void LoadActor();

	UFUNCTION(BlueprintNativeEvent)
	void PreLoadActor();
};
