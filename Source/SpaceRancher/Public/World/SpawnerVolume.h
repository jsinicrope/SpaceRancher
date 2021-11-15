// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "SpawnerVolume.generated.h"

UENUM(BlueprintType, meta=(DisplayName="SpawnState"))
enum class ESpawnState : uint8
{
	Random			UMETA(DisplayName="Random"),
	Centered		UMETA(DisplayName="Centered"),
	Rastered		UMETA(DisplayName="Rastered")
};

UCLASS()
class SPACERANCHER_API ASpawnerVolume : public AVolume
{
	GENERATED_BODY()

public:
	ASpawnerVolume();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginDestroy() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(DisplayThumbnail="true"))
	TArray<TSubclassOf<AActor>> ActorClasses;
	
	UPROPERTY()
	TArray<AActor*> SpawnedActors;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	ESpawnState SpawnState;
	
	// The amount of objects to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(EditCondition="SpawnState!=ESpawnState::Rastered"))
	int Population = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(EditCondition="SpawnState==ESpawnState::Centered"))
	float CenterDensity = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(EditCondition="SpawnState==ESpawnState::Centered"))
	bool bRandomCenterDensity = true;
	
	// If the spawned actor should be randomly rotated around its z axis
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bRandomRotation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(EditCondition="SpawnState==ESpawnState::Rastered"))
	FIntPoint RasterLayout = FIntPoint(3, 3);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(ClampMin=0.1f, ClampMax=1.0f, EditCondiotion="SpawnState==ESpawnState::Rastered"))
	float BoxRasterScaling = 1.0f;

	/** Whether the objects will be  spawned on an object any distance
	 * under the bounding box, or if they should spawn at the bounding
	 * box floor if no other object was hit							*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Spawner")
	bool bBoundingBoxIsLowest = false;
	
	UPROPERTY()
	TArray<FVector> SpawnPoints;

	/** whether the actors should be spawned on BeginPlay;
	 * or if they will be spawned at another time      */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bSpawnOnBeginPlay = false;

	UFUNCTION()
	bool LineTraceToGround(FVector &NewPoint) const;
	
	// Gets spawn points from random points in the volume
	UFUNCTION(BlueprintCallable, Category="Spawner")
	void GetRandomSpawnPoints();

	// Gets spawn points from random points distributed spherically around the center of the volume
	UFUNCTION(BlueprintCallable)
	void GetSphereCenteredSpawnPoints();

	// Gets spawn points from points in a raster of the volume
	UFUNCTION(BlueprintCallable)
	void GetRasteredSpawnPoints();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void SpawnActors();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void DeleteAllActors();
};
