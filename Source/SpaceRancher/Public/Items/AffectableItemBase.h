// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Harvester.h"
#include "Interfaces/HarvesterAffectable.h"
#include "Inventory_System/ItemBase.h"
#include "AffectableItemBase.generated.h"

UCLASS()
class SPACERANCHER_API AAffectableItemBase : public AItemBase, public IHarvesterAffectable
{
	GENERATED_BODY()

public:
	AAffectableItemBase();

	virtual void BeginPlay() override;
	
	virtual void PrimaryAffect_Implementation(AHarvester* Effector, float DeltaAffectedTime) override final;
	virtual void EndPrimaryAffect_Implementation(AHarvester* Effector) override;

	// This function is called when the PrimaryAffect Interface function is called
	virtual bool PrimaryAffectImpl(AHarvester* Effector, float DeltaAffectedTime);
	virtual bool Collect_Implementation(bool bAddToInventory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* NiagaraComponent;

	UPROPERTY(BlueprintReadOnly, SaveGame)
	float AffectedTime = 0.0f;

	// The time required to harvest the plant
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RequiredAffectTime = 1.0f;

	UPROPERTY(BlueprintReadOnly)
	bool bAffected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHandCollectible = true;

	// Whether the actor gets collected when it's destroyed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOnlyDestructible;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EHarvesterAttachmentType RequiredAttachment;

	void SetNiagaraComponentValues(const FVector &AttractionPoint, const FVector &HitPoint);
};
