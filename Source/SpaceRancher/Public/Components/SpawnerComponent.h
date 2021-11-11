// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACERANCHER_API USpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	USpawnerComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	TSubclassOf<AActor> Spawnable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Spawning")
	AActor* SpawnedObject;

public:
	UFUNCTION(BlueprintCallable)
	void SetSpawner(TSubclassOf<AActor> NewSpawnable);

	UFUNCTION(BlueprintCallable)
	AActor* Spawn();

	UFUNCTION(BlueprintCallable)
	bool DestroySpawned();
};
