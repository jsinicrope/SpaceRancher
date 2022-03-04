// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBuildable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "SpawningArea.generated.h"

UCLASS()
class SPACERANCHER_API ASpawningArea : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	ASpawningArea();
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation() override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BasePlate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Terminal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APlayerBuildable>> Buildables;

	UPROPERTY(BlueprintReadOnly)
	APlayerBuildable* BuiltObject;

	UFUNCTION(BlueprintCallable)
	void Spawn();

	UFUNCTION(BlueprintCallable)
	void Destruct();
};
