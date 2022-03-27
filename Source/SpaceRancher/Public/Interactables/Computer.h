// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/ItemBase.h"
#include "Computer.generated.h"

USTRUCT()
struct SPACERANCHER_API FTradeables : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AItemBase> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StockAmount;
};

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
	TArray<FTradeables> SellableItems;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetSellableItems, BlueprintReadWrite, Category="Buying")
	TArray<FTradeables> BuyableItems;

	UFUNCTION(BlueprintGetter)
	TArray<FTradeables> GetSellableItems() const	{ return SellableItems;}

	UFUNCTION(BlueprintGetter)
	TArray<FTradeables> GetBuyableItems() const	{ return BuyableItems;}


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ComputerMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetComponent* Screen;

	UPROPERTY(BlueprintReadWrite)
	class UComputerScreen* ScreenWidget;
};
