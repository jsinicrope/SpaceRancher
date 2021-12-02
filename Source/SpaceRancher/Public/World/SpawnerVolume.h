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


UCLASS(HideCategories=(Collision, HLOD, Navigation))
class SPACERANCHER_API ASpawnerVolume : public AVolume
{
	GENERATED_BODY()

public:
	ASpawnerVolume();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginDestroy() override;
	
protected:
	// Actors
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors")
	bool bUseActors = true;
	
	// Classes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(DisplayThumbnail="true", EditCondition="Meshes.Num() <= 0"))
	TArray<TSubclassOf<AActor>> ActorClasses;

	// Variational properties for meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float ActorsMinScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float ActorsMaxScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float ActorsRandomXRotation = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float ActorsRandomYRotation = 0.0f;

	// Meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes")
	bool bUseMeshes = true;
	
	// Meshes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(DisplayThumbnail="true", EditCondition="ActorClasses.Num() <= 0"))
	TArray<UStaticMesh*> Meshes;

	// Variational properties for meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float MeshesMinScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float MeshesMaxScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float MeshesRandomXRotation = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float MeshesRandomYRotation = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bAlignToGround = false;
	
	UPROPERTY()
	TArray<class ASpawnerMeshInstance*> InstancedMeshes;
	
	UPROPERTY()
	TArray<AActor*> SpawnedActors;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	ESpawnState SpawnState;
	
	// The amount of objects to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner", meta=(EditCondition="SpawnState!=ESpawnState::Rastered"))
	int Population = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Centered", meta=(EditCondition="SpawnState==ESpawnState::Centered"))
	float InnerRing = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Centered", meta=(EditCondition="SpawnState==ESpawnState::Centered"))
	float OuterRing = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Centered", meta=(EditCondition="SpawnState==ESpawnState::Centered"))
	bool bRandomCenterDensity = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Centered", meta=(ClampMin = 0.0f, EditCondition="SpawnState==ESpawnState::Centered && !bRandomCenterDensity"))
	float CenterDensity = 2.0f;
	
	// If the spawned actor should be randomly rotated around its z axis
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bRandomRotation = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Rastered", meta=(EditCondition="SpawnState==ESpawnState::Rastered"))
	FIntPoint RasterLayout = FIntPoint(3, 3);

	// How much of the volumes size should be used
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Rastered", meta=(ClampMin=0.1f, ClampMax=1.0f, EditCondition="SpawnState==ESpawnState::Rastered"))
	float BoxRasterScaling = 1.0f;

	/** Whether the objects will be  spawned on an object any distance
	 * under the bounding box, or if they should spawn at the bounding
	 * box floor if no other object was hit							*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bBoundingBoxIsLowest = true;
	
	UPROPERTY()
	TArray<FVector> SpawnPoints;

	UPROPERTY()
	TArray<FRotator> SpawnRotation;

	/** whether the actors should be spawned on BeginPlay;
	 * or if they will be spawned at another time      */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	bool bSpawnOnBeginPlay = false;
	
	UFUNCTION()
	bool LineTraceToGround(FVector &NewPoint, FRotator &OutRotation) const;
	
	// Gets spawn points from random points in the volume
	UFUNCTION(BlueprintCallable, Category="Spawner")
	void GetRandomSpawnPoints();

	// Gets spawn points from random points distributed spherically around the center of the volume
	UFUNCTION(BlueprintCallable)
	void GetSphereCenteredSpawnPoints();

	// Gets spawn points from points in a raster of the volume
	UFUNCTION(BlueprintCallable)
	void GetRasteredSpawnPoints();

	// Returns true if Mesh Instances could be successfully initialized or already are
	UFUNCTION()
	bool PrepareMeshInstancing();

	UFUNCTION()
	AActor* SpawnActor(FVector SpawnPoint, FRotator Rotation);

	UFUNCTION()
	void SpawnMesh(FVector SpawnPoint, FRotator Rotation);
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void SpawnActors();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void AddActors();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void DeleteAllActors();
};
