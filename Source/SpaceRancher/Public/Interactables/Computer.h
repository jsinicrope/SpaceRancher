// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory_System/Item_Struct.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItem_Struct> SellableItems;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* ComputerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Screen;
};
