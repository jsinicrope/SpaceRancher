// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/HarvesterAffectable.h"
#include "Inventory_System/ItemBase.h"
#include "AffectableItemBase.generated.h"

enum class EHarvesterAttachmentType : uint8;

UCLASS()
class SPACERANCHER_API AAffectableItemBase : public AItemBase, public IHarvesterAffectable
{
	GENERATED_BODY()

public:
	AAffectableItemBase();
	
	virtual void PrimaryAffect_Implementation(AHarvester* Effector, float DeltaAffectedTime) override;
	virtual void EndPrimaryAffect_Implementation(AHarvester* Effector) override;
	
	bool PrimaryAffectImpl(AHarvester* Effector, float DeltaAffectedTime);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* NiagaraComponent;

	UPROPERTY(BlueprintReadOnly)
	float AffectedTime = 0.0f;

	// The time required to harvest the plant
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RequiredAffectTime = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	bool bAffected;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHarvesterAttachmentType RequiredAttachment;

	void SetNiagaraComponentValues(const FVector &AttractionPoint, const FVector &HitPoint);
};
