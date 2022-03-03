// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/AffectableItemBase.h"
#include "Interfaces/Equippable.h"
#include "Items/Harvester.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"

AAffectableItemBase::AAffectableItemBase()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(StaticMesh);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponentDissolving"));
	NiagaraComponent->SetupAttachment(StaticMesh);
	NiagaraComponent->SetAutoActivate(false);
	NiagaraComponent->Deactivate();
}

void AAffectableItemBase::BeginPlay()
{
	Super::BeginPlay();
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
			
			if (bOnlyDestructible) { Destroy(); }
			
			else
			{
				if (bInventoryAddable)
				{
					if (PC->GetPlayerCharacter()->AddInventoryItem(Main_Item_Structure)) { Destroy(); }
				}
			}
		}
		return true;
	}
	return false;
}

bool AAffectableItemBase::Collect_Implementation(bool bAddToInventory)
{
	bool ItemAdded = false;
	if (bAddToInventory && bInventoryAddable && RequiredAttachment == EHarvesterAttachmentType::None)
	{
		ItemAdded = PC->GetPlayerCharacter()->AddInventoryItem(Main_Item_Structure);
	}
	if (ItemAdded || !bAddToInventory)
	{
		this->Destroy();
		return true;
	}
	return false;
}

void AAffectableItemBase::SetNiagaraComponentValues(const FVector& AttractionPoint, const FVector& HitPoint)
{
	NiagaraComponent->Activate();
	bAffected = true;
	NiagaraComponent->SetVariableVec3(FName("AttractionPoint"), AttractionPoint);
	NiagaraComponent->SetVariableVec3(FName("HitPoint"), HitPoint);
	NiagaraComponent->SetVariableVec3(FName("ActorScale"), GetActorScale3D());
	NiagaraComponent->SetVariableQuat(FName("ActorRotation"), GetActorRotation().Quaternion());
}
