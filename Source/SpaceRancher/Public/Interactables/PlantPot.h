// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactables/Plant.h"
#include "Interactables/InteractInterface.h"
#include "World/Saves/Saveable.h"
#include "PlantPot.generated.h"

UENUM(BlueprintType, meta=(DisplayName="SpawnState"))
enum class EPlantSpawnState : uint8
{
	Random			UMETA(DisplayName="Random"),
	Rastered		UMETA(DisplayName="Rastered")
};


UCLASS()
class SPACERANCHER_API APlantPot : public AActor, public IInteractInterface, public ISaveable
{
	GENERATED_BODY()
	
public:	
	APlantPot();

	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(FItem_Struct &EquippedItem) override;
	virtual void LoadActor_Implementation() override;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter")
	float Width = 236.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter")
	float Length = 236.0f;

	// The z offset given to plants when spawned. Use if plants are clipping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Planter")
	float ZOffset = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter|Planting")
	int PlantsToSpawn = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Planter")
	EPlantSpawnState SpawnState;

	// How much of the volumes size should be used
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Planter", meta=(ClampMin=0.1f, ClampMax=1.0f, EditCondition="SpawnState==EPlantSpawnState::Rastered"))
	float BoxRasterScaling = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Planter", meta=(EditCondition="SpawnState==EPlantSpawnState::Rastered"))
	FIntPoint RasterLayout = FIntPoint(3, 3);

	UPROPERTY()
	TArray<FVector> RasteredSpawnPoints;

	UFUNCTION(BlueprintCallable, Category = "Planter")
	FVector GetRandomPlantSpawnPoint();

	UFUNCTION(BlueprintCallable, Category = "Planter")
	void GetRasteredPlantSpawnPoints();

	UFUNCTION(CallInEditor, Category = "Planter")
	void Spawn();

	UFUNCTION(BlueprintCallable, Category = "Planter")
	void SpawnPlants(int AmountOfPlant);

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Planter")
	void DestroyAllPlants();

	UFUNCTION(BlueprintCallable, Category = "Planter|Planting")
	bool SetNewPlant(class APlant* NewPlant, bool bSpawnPlants = false, int AmountOfPlants = 20);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter|Content", meta=(DisplayThumbnail="true"))
	class TSubclassOf<APlant> DefaultPlant;

	UPROPERTY(BlueprintReadOnly, Category = "Planter|Content")
	class APlant* Plant;

	//Cast property to used Plant Class for use
	UPROPERTY(BlueprintReadOnly, Category = "Planter|Content")
	TArray<AActor*> PlantedPlants;
};
