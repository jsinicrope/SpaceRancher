// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryWindow.h"
#include "Components/ActorComponent.h"
#include "Items/ItemBase.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemRows
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItem_Struct> Row_Items;

	explicit FItemRows(const int NewRows = 5);
};


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SPACERANCHER_API UInventoryComponent final : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UInventoryComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int Rows = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int Columns = 5;

	/** The amount of slots in the inventory
	 * Fill Rows and columns until the desired amount is reached */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin=0), Category = "Inventory")
	int ItemSlots = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Inventory")
	TArray<TSubclassOf<AItemBase>> DefaultItems;
	
	// The represented name of the inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FText InventoryName;

	// true if Inventory should be sorted automatically, false if sorting is handled by a widget button
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	bool bAutoSort = false;

	// The inventory array itself
	UPROPERTY(BlueprintReadWrite, EditFixedSize, AdvancedDisplay, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

	// The position the widget is spawned at when opened
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", AdvancedDisplay)
	FVector2D WidgetPosition = FVector2D(600, 225);

	UFUNCTION(BlueprintGetter)
	UInventoryWindow* GetInventoryWindow() const {return InventoryWindow;}

	/* Add Item to the inventory
	 * returns true if successful, else false */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(AItemBase* Item, const int Row = 0, const int Column = 0);
	
	bool AddItem(const FItem_Struct &Item_Struct, int Row = 0, int Column = 0);

	/* Adds all items given to the inventory if possible
	 * Doesn't add any if they don't fit */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItems(const TArray<FItem_Struct>& Item_Structs);

	bool AddItems(const TArray<AItemBase*>& Items);
	bool AddItems(const TArray<TSubclassOf<AItemBase>>& Items);

	bool AddItemByIndex(const FItem_Struct &Item_Struct, const int Index);
	
	/* Adds a given Item and removes one if necessary
	 * * @return The Removed Item */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct ForceAddItem(const AItemBase* Item, const int Row = -1, const int Column = -1);

	/* Adds an item to the first free position
	 * Adds the item to the first inventory slot if no other is free
	 * @return The Removed Item */
	FItem_Struct ForceAddItem(const FItem_Struct& Item);

	/* Adds an item at the given position and removes currently at that slot
	* @return The Removed Item */
	FItem_Struct ForceAddItem(const FItem_Struct& Item, const int Row, const int Column); 

	/** Returns and removes an item from the inventory at given position
	 * return an invalid item if no item is at given position */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemByIndex(const int Row, const int Column);

	FItem_Struct RemoveItemByIndex(const int Index);

	// Returns and removes first item that matches the given item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItem(const FItem_Struct& Item);

	/* Removes an instance for every items given
	 * Doesn't remove any if it can't remove all items in the list */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FItem_Struct> RemoveItems(const TArray<FString>& ItemNames, bool& bSucceeded);

	TArray<FItem_Struct> RemoveItems(const TArray<FItem_Struct>& Items, bool& bSucceeded);
	TArray<FItem_Struct> RemoveItems(const TArray<AItemBase*>& Items, bool& bSucceeded);
	TArray<FItem_Struct> RemoveItems(const TArray<TSubclassOf<AItemBase>>& Items, bool& bSucceeded);

	// Returns and removes first item that matches the given item name
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemByName(const FString ItemName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct Emplace(FItem_Struct& OutItem, FItem_Struct& InItem);

	// Call to toggle inventory state (open/closed)
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void OpenInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void CloseInventory();

	// Toggles Inventory and that of the player
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventoryWithPlayerInventory();

	UFUNCTION(BlueprintGetter)
	bool GetInventoryOpen();

	// Updates the visual representation of the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateInventory() const;

	// Sorts the inventory lexicographically
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool SortInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int GetOccurrences(const FString ItemName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FItem_Struct> GetUniqueSelectables();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool Contains(const FItem_Struct &Item);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UInventoryWindow> InventoryWindowClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<UInventorySlotWidget> InventorySlotWidgetClass;
	
	UPROPERTY(BlueprintReadOnly, BlueprintGetter=GetInventoryWindow, AdvancedDisplay, Category = "Inventory")
	UInventoryWindow* InventoryWindow;

	// If the inventory is open or not
	UPROPERTY(BlueprintReadOnly, BlueprintGetter=GetInventoryOpen, AdvancedDisplay, Category = "Inventory")
	bool bInventoryOpen = false;

	UPROPERTY()
	ACppPlayerController* PC;

	UPROPERTY()
	class AMyCharacter* Player;
};
