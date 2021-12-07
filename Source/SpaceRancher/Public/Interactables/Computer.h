// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory_System/ItemBase.h"
#include "Computer.generated.h"

UCLASS()
class SPACERANCHER_API AComputer : public AActor
{
	GENERATED_BODY()
	
public:	
	AComputer(const FObjectInitializer &ObjectInitializer);
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	class AMyCharacter* PlayerCharacter;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Selling")
	TArray<TSubclassOf<AItemBase>> SellableItems;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* ComputerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Screen;

	UPROPERTY(BlueprintReadWrite)
	class UComputerMonitor* ScreenWidget;

	UFUNCTION(BlueprintCallable)
	void SetSellingItemTiles();
};