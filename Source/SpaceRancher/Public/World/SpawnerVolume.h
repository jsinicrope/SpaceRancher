// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Saves/Saveable.h"
#include "SpawnerVolume.generated.h"


UENUM(BlueprintType, meta=(DisplayName="SpawnState"))
enum class ESpawnState : uint8
{
	Random			UMETA(DisplayName="Random"),
	Centered		UMETA(DisplayName="Centered"),
	Rastered		UMETA(DisplayName="Rastered")
};


UCLASS(HideCategories=(Collision, HLOD, LOD, Navigation, WorldPartition, Cooking, Actor), NotBlueprintable)
class SPACERANCHER_API ASpawnerVolume : public AVolume, public ISaveable
{
	GENERATED_BODY()

public:
	ASpawnerVolume();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginDestroy() override;

	virtual bool PreSaveActor_Implementation() override;
	virtual bool PreLoadActor_Implementation() override;
	virtual void PostSaveActor_Implementation() override;
	virtual void PostLoadActor_Implementation() override;

	void SetCanRespawn(const bool bValue);
	
protected:
	// Actors

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors")
	bool bUseActors = true;
	
	// Classes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(DisplayThumbnail="true", AllowAbstract="false"))
	TArray<TSubclassOf<AActor>> ActorClasses;
	
	// Variational properties for actors
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float ActorsMinScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.1f, ClampMax=10.0f))
	float ActorsMaxScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float ActorsRandomXRotation = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Actors", meta=(ClampMin=0.0f, ClampMax=360.0f))
	float ActorsRandomYRotation = 0.0f;

	
	// AI Entities

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|AI Entities")
	bool bUseAIEntities = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|AI Entities", meta=(DisplayThumbnail="true"))
	TArray<TSubclassOf<APawn>> AIEntityClasses;

	
	// Meshes

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes")
	bool bUseMeshes = true;
	
	// Meshes to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Meshes", meta=(DisplayThumbnail="true"))
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
	TArray<AActor*> SpawnedActors;

	UPROPERTY()
	TArray<APawn*> SpawnedAI;
	
	UPROPERTY()
	TArray<class ASpawnerMeshInstance*> InstancedMeshes;

	UPROPERTY(SaveGame)
	int SpawnedObjects = 0;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Respawn")
	bool bCanRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Respawn")
	float TimeToRespawn = 60.0f;

	// The amount of actors to respawn every time respawn is called
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Respawn")
	int AmountToRespawn = 1;

	UPROPERTY(SaveGame)
	float TimeSinceRespawn = 0.0f;

	// The maximum number of items still active before they can be respawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner|Respawn")
	int MaxNumberBeforeRespawn = 2;

	// Saving
	UPROPERTY(SaveGame)
	int SpawnedObjectsLastSave = Population;
	
	UFUNCTION()
	bool LineTraceToGround(FVector &NewPoint, FRotator &OutRotation) const;
	
	// Gets spawn points from random points in the volume
	UFUNCTION(BlueprintCallable, Category="Spawner")
	void GetRandomSpawnPoints(int Amount);

	// Gets spawn points from random points distributed spherically around the center of the volume
	UFUNCTION(BlueprintCallable)
	void GetSphereCenteredSpawnPoints(int Amount);

	// Gets spawn points from points in a raster of the volume
	UFUNCTION(BlueprintCallable)
	void GetRasteredSpawnPoints();

	// Returns true if Mesh Instances could be successfully initialized or already are
	UFUNCTION()
	bool PrepareMeshInstancing();

	UFUNCTION()
	AActor* SpawnActor(FVector SpawnPoint, FRotator Rotation);

	UFUNCTION()
	APawn* SpawnAIEntity(FVector SpawnPoint, FRotator Rotation);
	
	UFUNCTION()
	void SpawnMesh(FVector SpawnPoint, FRotator Rotation);
	
	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void SpawnObjects();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void AddObjects();
	
	void AddObjects(int Amount);

	UFUNCTION()
	void VerifyActiveActors();

	UFUNCTION(BlueprintCallable, Category="Spawner")
	void DeleteLastAddedActor();

	UFUNCTION(BlueprintCallable, Category="Spawner")
	void DeleteLastAddedMesh();

	UFUNCTION(BlueprintCallable, CallInEditor, Category="Spawner")
	void DeleteAllObjects();
};
