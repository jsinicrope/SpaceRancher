// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HarvesterAffectable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHarvesterAffectable : public UInterface
{
	GENERATED_BODY()
};

// Add interface functions to this class. This is the class that will be inherited to implement this interface.
class SPACERANCHER_API IHarvesterAffectable
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintNativeEvent)
	void PrimaryAffect(TSubclassOf<class AHarvesterAttachmentBase> Attachment, float DeltaAffectedTime);
};
