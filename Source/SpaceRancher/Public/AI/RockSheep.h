#pragma once

#include "CoreMinimal.h"
#include "AI/NPC.h"
#include "Interfaces/Interactable.h"
#include "Items/ItemBase.h"
#include "RockSheep.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnItemDestroyed);
DECLARE_DYNAMIC_DELEGATE(FOnItemSpawned);

UCLASS()
class SPACERANCHER_API ARockSheep : public ANPC, public IInteractInterface
{
	GENERATED_BODY()
	
	friend class ARockSheepController;

public:
	ARockSheep();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(const FItem_Struct& EquippedItem) override;

	FOnItemDestroyed OnItemDestroyed;
	FOnItemSpawned OnItemSpawned;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* GemSpawnerComponent;
	
	UPROPERTY()
	UChildActorComponent* GemSpawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> BackAttachment;

	UPROPERTY(BlueprintReadOnly)
	class AGem* Item;

	UPROPERTY(EditAnywhere, SaveGame, BlueprintReadWrite)
	float ItemRespawnTime = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AItemBase>> TamingItems;

	/* Currently only used to determine the amount of TamingItems needed to tame */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="1"))
	int TamingDifficulty = 2;

	UFUNCTION()
	void SetItemState(bool Collectible) const;

	UFUNCTION()
	void ItemDestroyed(AActor* Actor);

	UFUNCTION()
	bool SpawnItem();

	UFUNCTION(BlueprintCallable)
	void SetAIControllerState(const EAIBehaviorState& NewState) const;

private:
	UPROPERTY()
	float ItemTimeToRespawn = 0.0f;
};
