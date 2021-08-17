// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory_System/Item_Base.h"
#include "InventoryComponent.generated.h"


USTRUCT(BlueprintType)
struct FItemRows
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItem_Struct> Row_Items;

	FItemRows(int rows = 5);
};


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACERANCHER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Columns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(FItem_Struct Item_Struct, int row = 0, int column = 0);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemClosestPosition(int row, int column);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItem(FItem_Struct Item);

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
