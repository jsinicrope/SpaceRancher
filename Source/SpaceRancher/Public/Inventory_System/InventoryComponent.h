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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int ItemSlots = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FText InventoryName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, BlueprintGetter=GetInventoryOpen, AdvancedDisplay, Category = "Inventory")
	bool bInventoryOpen = false;

	// true if Inventory should be sorted automatically, false if sorting is handled by a widget button
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAutoSort = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, EditFixedSize, AdvancedDisplay, Category = "Inventory")
	TArray<FItemRows> Inventory_Array_Columns;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", AdvancedDisplay)
	FVector2D WidgetPosition = FVector2D(700, 200);

	UFUNCTION(BlueprintGetter)
	UInventoryWindow* GetInventoryWindow() const {return InventoryWindow;}

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(FItem_Struct Item_Struct, int Row = 0, int Column = 0);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemClosestPosition(int Row, int Column);

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
