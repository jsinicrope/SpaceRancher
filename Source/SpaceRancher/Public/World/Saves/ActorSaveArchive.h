// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

struct FActorSaveArchive : public FObjectAndNameAsStringProxyArchive
{
	FActorSaveArchive(FArchive& InInnerArchive, bool bInLoadIfFails) : FObjectAndNameAsStringProxyArchive(InInnerArchive, bInLoadIfFails)
	{
		ArIsSaveGame = true;
	}
};
