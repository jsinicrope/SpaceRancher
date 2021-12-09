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
	UPROPERTY(EditAnywhere, BlueprintGetter=GetSellableItems, BlueprintReadWrite, Category="Selling")
	TArray<TSubclassOf<AItemBase>> SellableItems;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetSellableItems, BlueprintReadWrite, Category="Buying")
	TArray<TSubclassOf<AItemBase>> BuyableItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buying")
	int MaxBuyStock = 12;

	UFUNCTION(BlueprintGetter)
	TArray<TSubclassOf<AItemBase>> GetSellableItems() const	{ return SellableItems;}

	UFUNCTION(BlueprintGetter)
	TArray<TSubclassOf<AItemBase>> GetBuyableItems() const	{ return BuyableItems;}


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* ComputerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Screen;

	UPROPERTY(BlueprintReadWrite)
	class UComputerScreen* ScreenWidget;
};
