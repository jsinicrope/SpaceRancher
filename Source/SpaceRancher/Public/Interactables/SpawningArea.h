// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBuildable.h"
#include "GameFramework/Actor.h"
#include "Widgets/ComputerHUDs/SpawningPlatform/SpawningTerminalWindow.h"
#include "SpawningArea.generated.h"

UCLASS()
class SPACERANCHER_API ASpawningArea final : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawningArea();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithCredits(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass);

	UFUNCTION(BlueprintCallable)
	bool RequestBuyWithMaterials(FBuildablePriceStruct& ItemPrice, TSubclassOf<APlayerBuildable>& BuildableClass);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BasePlate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Terminal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UWidgetComponent* Screen;

	UPROPERTY(BlueprintReadWrite)
	USpawningTerminalWindow* ScreenWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<APlayerBuildable>> Buildables;

	UPROPERTY(BlueprintReadOnly)
	APlayerBuildable* BuiltObject;

	UPROPERTY(BlueprintReadOnly)
	class AMyCharacter* PlayerCharacter;
	
	UFUNCTION()
	void UpdateScreenWidgets();

	/** Whether an object can be spawned
	 * If something is already spawned, nothing else can be spawned */
	UFUNCTION(BlueprintCallable)
	bool CanSpawn() const { return !BuiltObject; }
	
	// Spawns the passed Object
	UFUNCTION(BlueprintCallable)
	void Spawn(const TSubclassOf<APlayerBuildable>& BuildableClass);

	// Destroys the currently built object
	UFUNCTION(BlueprintCallable)
	void Destruct();
};
