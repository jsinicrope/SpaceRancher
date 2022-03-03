#pragma once

#include "CoreMinimal.h"
#include "AI/NPC.h"
#include "RockSheep.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOnItemDestroyed);
DECLARE_DYNAMIC_DELEGATE(FOnItemSpawned);

UCLASS()
class SPACERANCHER_API ARockSheep : public ANPC
{
	GENERATED_BODY()
	
	friend class ARockSheepController;

public:
	ARockSheep();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ItemRespawnTime = 90.0f;

	UFUNCTION()
	void SetItemState(bool Collectible) const;

	UFUNCTION()
	void ItemDestroyed(AActor* Actor);

	UFUNCTION()
	bool SpawnItem();

private:
	UPROPERTY()
	float ItemTimeToRespawn = 0.0f;
};
