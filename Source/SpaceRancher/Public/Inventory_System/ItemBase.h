// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory_System/ItemStruct.h"
#include "Interactables/InteractInterface.h"
#include "World/Saves/Saveable.h"
#include "ItemBase.generated.h"

UCLASS()
class SPACERANCHER_API AItemBase : public AActor, public IInteractInterface, public ISaveable
{
	GENERATED_BODY()
	
public:
	AItemBase();

	virtual void BeginPlay() override;

	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(FItem_Struct EquippedItem) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem_Struct Main_Item_Structure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCollectible = true;

	// A required item to harvest the plant. Empty if none is needed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plant")
	FName RequiredItem = FName("");

	UFUNCTION(BlueprintCallable)
	bool CollectItem(bool bAddToInventory = true);

private:
	UPROPERTY()
	class AMyCharacter* PC;
};
