// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryWindow.h"
#include "Components/ActorComponent.h"
#include "Inventory_System/Item_Base.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemRows
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItem_Struct> Row_Items;

	FItemRows(int NewRows = 5);
};


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACERANCHER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UInventoryComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int Rows = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int Columns = 4;

	/** The amount of slots in the inventory
	 * Fill Rows and columns until the desired amount is reached
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int ItemSlots = 20;
	
	// The represented name of the inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FText InventoryName;

	// If the inventory is open or not
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, BlueprintGetter=GetInventoryOpen, AdvancedDisplay, Category = "Inventory")
	bool bInventoryOpen = false;

	// true if Inventory should be sorted automatically, false if sorting is handled by a widget button
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	bool bAutoSort = false;

	// The inventory array itself, TODO: Blueprint default set items
	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, AdvancedDisplay, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

    // The position the widget is spawned at when opened
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", AdvancedDisplay)
	FVector2D WidgetPosition = FVector2D(700, 200);

	UFUNCTION(BlueprintGetter)
	UInventoryWindow* GetInventoryWindow() const {return InventoryWindow;}

	/* Add Item to the inventory
	 * returns true if successful, else false
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(FItem_Struct Item_Struct, int Row = 0, int Column = 0);

	/** Returns and removes an item from the inventory at given position
	 * return an invalid item if no item is at given position
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromPosition(int Row, int Column);

	// Returns and removes first item that matches the given item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItem(FItem_Struct Item);

	// Returns and removes first item that matches the given item name
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemByName(FString ItemName);

	// Call to toggle inventory state (open/closed)
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	UFUNCTION(BlueprintGetter)
	bool GetInventoryOpen();

	// Sorts inventory, does not update visual
	UFUNCTION()
	bool SortInventory();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UUserWidget> InventoryWindowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UUserWidget> InventorySlotWidgetClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, BlueprintGetter=GetInventoryWindow, AdvancedDisplay, Category = "Inventory")
	class UInventoryWindow* InventoryWindow;

	UPROPERTY()
	TArray<FItem_Struct> Items;

	UPROPERTY()
	class ACppPlayerController* PC;
};
