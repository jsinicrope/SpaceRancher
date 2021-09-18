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
	int Columns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Rows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText InventoryName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bInventoryOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InventoryWindowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;

	UPROPERTY(VisibleAnywhere)
	class ACppPlayerController* PC;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(FItem_Struct Item_Struct, int row = 0, int column = 0);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemClosestPosition(int row, int column);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItem(FItem_Struct Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemByName(FString ItemName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventoryWindow* InventoryWindow;
};
