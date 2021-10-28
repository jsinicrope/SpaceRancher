// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory_System/Item_Base.h"
#include "Interactables/InteractInterface.h"
#include "World/Saves/Saveable.h"
#include "Plant.generated.h"

UCLASS()
class SPACERANCHER_API APlant : public AItem_Base
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlant();

	virtual void Interact_Implementation() override;
	virtual void LoadActor_Implementation() override;
	virtual void SaveActor_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant")
	bool bCanBeHarvested = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Plant|Growth")
	int GrowState = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="MinutesPerStage"), Category = "Plant|Growth")
	float TimePerStage= 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	int GrowthStages = 3;

	/**The time the plant has spent in its current stage in minutes*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	float PlantStateAgeMinutes = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	float GrowFactor = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	int MinHarvestableState = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	int MaxHarvestableState = GrowthStages;

	/**
	* The thickness/radius of the bottom part of the stem
	* This is used when spawning it
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Properties")
	float BottomStemThickness = 10.0f;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant|Growth")
	TArray<UStaticMesh*> StateMeshes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UMainGameInstance* GameInstance;

public:
	UFUNCTION(BlueprintCallable, Category = "Plant|Growth")
	virtual bool GrowPlant();

	UFUNCTION(BlueprintCallable, Category = "Plant|Harvesting")
	bool PickupPlant();

	UFUNCTION(BlueprintCallable, Category = "Plant|Growth")
	bool WaterPlant();
};
