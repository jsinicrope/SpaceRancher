// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "SpawnerVolume.generated.h"

UCLASS()
class SPACERANCHER_API ASpawnerVolume : public AVolume
{
	GENERATED_BODY()

	ASpawnerVolume();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> SpawnedActors;
	
	UFUNCTION(BlueprintCallable)
	FVector GetSpawnPoint();

	// The amount of objects to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount = 3;

	// If the spawned actor should be randomly rotated around its z axis
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRandomRotation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClass;

	/** whether the actors should be spawned on BeginPlay;
	 * or if they will be spawned at another time
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSpawnOnBeginPlay = true;

	UFUNCTION(BlueprintCallable)
	void SpawnActors(int SpawnAmount);

	UFUNCTION(BlueprintCallable)
	void DeleteAllActors();
};
