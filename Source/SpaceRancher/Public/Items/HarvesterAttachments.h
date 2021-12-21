// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory_System/ItemStruct.h"
#include "HarvesterAttachments.generated.h"

UENUM(BlueprintType, meta=(DisplayName="SpawnState"))
enum class EHarvesterAttachmentType : uint8
{
	None			UMETA("None"),
	General			UMETA(DisplayName="General"),
	Plants			UMETA(DisplayName="Plants"),
	Minerals		UMETA(DisplayName="Minerals"),
	Combat			UMETA(DisplayName="Combat")
};
