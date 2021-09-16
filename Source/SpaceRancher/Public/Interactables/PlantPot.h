// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactables/Plant.h"
#include "Interactables/InteractInterface.h"
#include "PlantPot.generated.h"

UCLASS()
class SPACERANCHER_API APlantPot : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantPot();

	void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter")
	float Width = 236.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter")
	float Length = 236.0f;

	UFUNCTION(BlueprintCallable, Category = "Planter")
	FVector GetRandomPlantSpawnPoint();

	UFUNCTION(BlueprintCallable, Category = "Planter")
	void SpawnPlants(int AmountOfPlant);

	UFUNCTION(BlueprintCallable, Category = "Planter")
	void DestroyAllPlants();

	UFUNCTION(BlueprintCallable, Category = "Planter|Planting")
	bool SetNewPlant(class TSubclassOf<APlant> NewPlant, bool bSpawnPlants = false, int AmountOfPlants = 20);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter|Content")
	class TSubclassOf<APlant> Plant;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Planter|Content")
	class APlant* MainPlant;

	//Cast property to used Plant Class for use
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Planter|Content")
	TArray<AActor*> PlantedPlants;
};
