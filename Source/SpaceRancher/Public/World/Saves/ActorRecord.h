// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorRecord.generated.h"

USTRUCT()
struct FActorRecord
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FString Name = FString("");

	UPROPERTY()
	UClass* Class = nullptr;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	TArray<uint8> Data;

	FActorRecord(AActor* Actor = nullptr)
	{
		if (Actor != nullptr)
		{
			Name = Actor->GetName();
			Class = Actor->GetClass();
			Transform = Actor->GetTransform();
		}
	}
};
