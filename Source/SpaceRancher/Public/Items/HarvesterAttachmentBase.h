// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HarvesterAttachments.h"
#include "Inventory_System/ItemBase.h"
#include "HarvesterAttachmentBase.generated.h"

UCLASS()
class SPACERANCHER_API AHarvesterAttachmentBase : public AItemBase
{
	GENERATED_BODY()
	
public:
	AHarvesterAttachmentBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetAttachment_Struct, BlueprintReadWrite)
	FHarvesterAttachment_Struct Attachment_Struct;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintGetter)
	FHarvesterAttachment_Struct GetAttachment_Struct() const {return Attachment_Struct;}
};
