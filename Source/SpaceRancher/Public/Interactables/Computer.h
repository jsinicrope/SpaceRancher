// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Selling")
	TArray<struct FItem_Struct> SellableItems;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* ComputerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Screen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UComputerMonitor* ScreenWidget;

	UFUNCTION(BlueprintCallable)
	void SetSellingItemTiles();
};
