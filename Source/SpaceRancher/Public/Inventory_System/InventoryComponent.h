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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Slots per Row"), Category = "Inventory")
	int Columns = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Slots per Column"), Category = "Inventory")
	int Rows = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int ItemSlots = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FText InventoryName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, BlueprintGetter=GetInventoryOpen, AdvancedDisplay, Category = "Inventory")
	bool bInventoryOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, AdvancedDisplay, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", AdvancedDisplay)
	FVector2D WidgetPosition = FVector2D(700, 200);

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

	UFUNCTION(BlueprintGetter)
	bool GetInventoryOpen();

	UFUNCTION()
	bool SortInventory();

	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UUserWidget> InventoryWindowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay, Category = "Inventory")
	class UInventoryWindow* InventoryWindow;

	UPROPERTY()
	TArray<FItem_Struct> Items;

	UPROPERTY()
	class ACppPlayerController* PC;
};
