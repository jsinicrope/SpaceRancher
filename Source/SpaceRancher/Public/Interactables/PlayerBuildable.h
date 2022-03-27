// Fill out your copyright notice in the Description page of Project Settings.
  
#pragma once
  
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "PlayerBuildable.generated.h"

class UImage;

USTRUCT()
struct SPACERANCHER_API FBuildableDisplayable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name = FName("Buildable");
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* DisplayImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description = FText::FromString("Enter a description for the Buildable");
};

USTRUCT(BlueprintType)
struct FBuildableItemChart : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AItemBase> Item;

	int GetTotalItemBasePrice()	const;
};


USTRUCT(BlueprintType)
struct FBuildablePriceStruct : public FTableRowBase
{
	GENERATED_BODY()
	
	/* The Credit price if this Object is bought without additional Resources
	 * This price is supposed to be substantially higher than that of the Resource costs combined
	 * TODO Automatically calculate this price based on the current market prices for the given materials */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RawCreditPrice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBuildableItemChart> RequiredItems;

	TArray<AItemBase*> GetRequiredItemsList() const;
};


UCLASS(Abstract)
class SPACERANCHER_API APlayerBuildable : public AActor
{
	GENERATED_BODY()

public:	
	APlayerBuildable();
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintGetter)
	const FBuildableDisplayable& GetDisplayStyle()	const { return Display; }
	
	UFUNCTION(BlueprintGetter)
	const FBuildablePriceStruct& GetCost()	const { return Cost; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetDisplayStyle)
	FBuildableDisplayable Display;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetCost)
	FBuildablePriceStruct Cost;
};
