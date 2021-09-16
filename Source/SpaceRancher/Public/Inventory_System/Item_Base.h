// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory_System/Item_Struct.h"
#include "Interactables/InteractInterface.h"
#include "Item_Base.generated.h"

UCLASS()
class SPACERANCHER_API AItem_Base : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_Base();

	virtual void BeginPlay() override;

	virtual void Interact_Implementation() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItem_Struct Main_Item_Structure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCollectible = false;

	UFUNCTION(BlueprintCallable)
	bool CollectItem(bool bAddToInventory = true);

	UPROPERTY()
	class AMyCharacter* PC;
};
