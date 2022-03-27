// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Items/HarvesterAttachmentBase.h"
#include "Interfaces/Equippable.h"
#include "Items/ItemBase.h"
#include "Harvester.generated.h"

enum class EHarvesterAttachmentType : uint8;

UCLASS(Abstract, HideCategories=(Input))
class SPACERANCHER_API AHarvester : public AItemBase, public IEquippable
{
	GENERATED_BODY()
	
public:
	AHarvester();
	virtual void Tick(float DeltaTime) override;

	virtual void Selected_Implementation() override;
	virtual void Activated_Implementation() override;
	virtual void Deactivated_Implementation() override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* LaserHolder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UNiagaraComponent* LaserBeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* AttachmentHolder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Attachment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear)
	TSubclassOf<AHarvesterAttachmentBase> ActiveAttachment;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LaserRange = 750.0f;

	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetLaserStartPos)
	FVector LaserStart;

	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetLaserTargetPos)
	FVector LaserTarget;

	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetLaserActive)
	bool bLaserActive = false;

	UPROPERTY(BlueprintReadWrite)
	FVector BeamTarget;

	UPROPERTY()
	AActor* HitActor = nullptr;

	UPROPERTY()
	AActor* LastAffectedActor = nullptr;

	UPROPERTY(BlueprintSetter=SetCollectDeactivated)
	bool bCollectDeactivated = false;
	
public:
	UFUNCTION(BlueprintGetter)
	EHarvesterAttachmentType GetAttachmentType() const { return Cast<AHarvesterAttachmentBase>(ActiveAttachment->GetDefaultObject())->GetAttachmentType();}
	
	UFUNCTION(BlueprintGetter)
	bool GetLaserActive() const	{return bLaserActive;}

	UFUNCTION(BlueprintSetter)
	void SetCollectDeactivated(const bool Value) {bCollectDeactivated = Value;}

	UFUNCTION(BlueprintCallable)
	AActor* GetHitActor();

	UFUNCTION(BlueprintGetter)
	FVector GetLaserStartPos() const {return LaserStart;}

	UFUNCTION(BlueprintGetter)
	FVector GetLaserTargetPos() const {return LaserTarget;}
	
	UFUNCTION(BlueprintCallable)
	bool ToggleLaser();
	
	UFUNCTION(BlueprintCallable)
	bool ActivateLaser();

	UFUNCTION(BlueprintCallable)
	bool DeactivateLaser();

	UFUNCTION(BlueprintCallable)
	void UpdateAimDirection();
};
