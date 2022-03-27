// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory_System/ItemStruct.h"
#include "Interfaces/Interactable.h"
#include "World/Saves/Saveable.h"
#include "ItemBase.generated.h"

UCLASS(Abstract)
class SPACERANCHER_API AItemBase : public AActor, public IInteractInterface, public ISaveable
{
	GENERATED_BODY()
	
public:
	AItemBase();

	virtual void BeginPlay() override;

	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(const FItem_Struct& EquippedItem) override;
	virtual bool PreSaveActor_Implementation() override;
	virtual bool PreLoadActor_Implementation() override;
	virtual void PostSaveActor_Implementation() override;
	virtual void PostLoadActor_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem_Struct Main_Item_Structure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bInventoryAddable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CurrentlyCollectible = true;

	// Optionally adds the Item to the players inventory, then destroys it if successful or if no adding was required
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Collect(bool bAddToInventory = true);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	class ACppPlayerController* PC;
};
