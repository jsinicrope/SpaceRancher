// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "WidgetDragOperation.generated.h"

UCLASS()
class SPACERANCHER_API UWidgetDragOperation : public UDragDropOperation
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	FVector2D DragOffset;

	UPROPERTY()
	UWidget* WidgetReference = nullptr;
};
