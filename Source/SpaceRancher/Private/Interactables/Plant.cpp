// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactables/Plant.h"
#include "Items/Harvester.h"
#include "World/MainGameInstance.h"
#include "Kismet/GameplayStatics.h"

APlant::APlant()
{
	PrimaryActorTick.bCanEverTick = true;

	bIsCollectible = bCanBeHarvested;
	
	if (StateMeshes.Num() > 0)
	{
		StaticMesh->SetStaticMesh(StateMeshes[0]);
	}
}

void APlant::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UMainGameInstance>(GetGameInstance());
	ensureMsgf(NiagaraComponent->GetAsset(), TEXT("No Niagara system set for Plant dissolve effect"));
	if (StateMeshes.Num() > GrowthState - 1)
	{
		StaticMesh->SetStaticMesh(StateMeshes[GrowthState - 1]);
	}
}

void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlantStateAgeMinutes += GameInstance->GetIsDay() ? DeltaTime : DeltaTime * NightGrowthSpeed;
	
	if (PlantStateAgeMinutes >= TimePerStage * 60.0f)
	{
		GrowPlant();
	}
}

void APlant::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Interacted with Plant"));
	if (RequiredAttachment == EHarvesterAttachmentType::None)
	{
		Collect();
	}
}

bool APlant::ItemInteract_Implementation(FItem_Struct EquippedItem)
{
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Interacted with Plant"));
	return false;
}

bool APlant::PrimaryAffectImpl(AHarvester* Effector, float DeltaAffectedTime)
{
	if (IsCurrentlyCollectible() && (RequiredAttachment == EHarvesterAttachmentType::None || Effector->GetAttachmentType() == RequiredAttachment))
	{
		SetNiagaraComponentValues(Effector->GetLaserStartPos(), Effector->GetLaserTargetPos());
		AffectedTime += DeltaAffectedTime;
		if (AffectedTime >= RequiredAffectTime)
		{
			Execute_EndPrimaryAffect(this, Effector);
			Effector->SetCollectDeactivated(true);
			IEquippable::Execute_Deactivated(Effector);
			if (!Collect())
				AffectedTime = 0.0f;
		}
		return true;
	}
	return false;
}

bool APlant::PreSaveActor_Implementation()
{
	return Super::PreSaveActor_Implementation();
}

bool APlant::PreLoadActor_Implementation()
{
	return Super::PreLoadActor_Implementation();
}

void APlant::PostLoadActor_Implementation()
{
	
}

void APlant::PostSaveActor_Implementation()
{
	
}

bool APlant::GrowPlant()
{
	if (GrowthState < GrowthStages)
	{
		GrowthState++;
		PlantStateAgeMinutes = 0.0f;
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Plant grew"));
		if (StateMeshes.Num() > GrowthState - 1)
		{
			StaticMesh->SetStaticMesh(StateMeshes[GrowthState - 1]);
		}
		return true;
	}
	
	return false;
}

bool APlant::IsCurrentlyCollectible()
{
	return GrowthState >= MinHarvestableState && GrowthState <= MaxHarvestableState;
}

bool APlant::Collect(bool bAddToInventory)
{
	if (GrowthState >= MinHarvestableState && GrowthState <= MaxHarvestableState)
	{
		return Super::Collect(bAddToInventory);
	}
	return false;
}

bool APlant::WaterPlant()
{
	GrowPlant();
	return true;
}
