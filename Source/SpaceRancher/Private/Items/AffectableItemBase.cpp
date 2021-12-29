// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/AffectableItemBase.h"
#include "Inventory_System/Equippable.h"
#include "Items/Harvester.h"

AAffectableItemBase::AAffectableItemBase()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(StaticMesh);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponentDissolving"));
	NiagaraComponent->SetupAttachment(StaticMesh);
	NiagaraComponent->SetAutoActivate(false);
}

void AAffectableItemBase::PrimaryAffect_Implementation(AHarvester* Effector, float DeltaAffectedTime)
{
	PrimaryAffectImpl(Effector, DeltaAffectedTime);
}

void AAffectableItemBase::EndPrimaryAffect_Implementation(AHarvester* Effector)
{
	NiagaraComponent->Deactivate();
}

bool AAffectableItemBase::PrimaryAffectImpl(AHarvester* Effector, float DeltaAffectedTime)
{
	if (RequiredAttachment == EHarvesterAttachmentType::None || Effector->GetAttachmentType() == RequiredAttachment)
	{
		SetNiagaraComponentValues(Effector->GetLaserStartPos(), Effector->GetLaserTargetPos());
		AffectedTime += DeltaAffectedTime;
		if (AffectedTime >= RequiredAffectTime)
		{
			Execute_EndPrimaryAffect(this, Effector);
			Effector->SetCollectDeactivated(true);
			IEquippable::Execute_Deactivated(Effector);
			AffectedTime = 0.0f;
			if (bOnlyDestructible)
				Destroy();
			else
				Collect();
		}
		return true;
	}
	return false;
}

void AAffectableItemBase::SetNiagaraComponentValues(const FVector& AttractionPoint, const FVector& HitPoint)
{
	NiagaraComponent->Activate();
	bAffected = true;
	NiagaraComponent->SetVariableVec3(FName("AttractionPoint"), AttractionPoint - NiagaraComponent->GetComponentLocation());
	NiagaraComponent->SetVariableVec3(FName("HitPoint"), HitPoint - NiagaraComponent->GetComponentLocation());
}
