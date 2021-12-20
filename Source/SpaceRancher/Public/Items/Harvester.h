// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Inventory_System/Equippable.h"
#include "Inventory_System/ItemBase.h"
#include "Harvester.generated.h"

UCLASS()
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
	float LaserRange = 750.0f;

	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetLaserActive)
	bool bLaserActive = false;

	UPROPERTY(BlueprintReadWrite)
	FVector BeamTarget;
	
public:
	UFUNCTION(BlueprintGetter)
	bool GetLaserActive() const	{return bLaserActive;}
	
	UFUNCTION(BlueprintCallable)
	bool ToggleLaser();
	
	UFUNCTION(BlueprintCallable)
	bool ActivateLaser();

	UFUNCTION(BlueprintCallable)
	bool DeactivateLaser();

	UFUNCTION(BlueprintCallable)
	void UpdateAimDirection();
};
