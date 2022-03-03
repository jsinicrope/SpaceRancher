// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HarvesterAttachments.h"
#include "Items/ItemBase.h"
#include "HarvesterAttachmentBase.generated.h"

UCLASS()
class SPACERANCHER_API AHarvesterAttachmentBase : public AItemBase
{
	GENERATED_BODY()
	
public:
	AHarvesterAttachmentBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetAttachmentType, BlueprintReadWrite)
	EHarvesterAttachmentType AttachmentType;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintGetter)
	EHarvesterAttachmentType GetAttachmentType() const {return AttachmentType;}
};
