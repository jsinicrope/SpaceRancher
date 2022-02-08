#pragma once

#include "CoreMinimal.h"
#include "AI/NPC.h"
#include "RockSheep.generated.h"

UCLASS()
class SPACERANCHER_API ARockSheep : public ANPC
{
	GENERATED_BODY()

public:
	ARockSheep();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* GemSpawnerComponent;
	
	UPROPERTY()
	class UChildActorComponent* GemSpawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> BackAttachment;

	UPROPERTY(BlueprintReadOnly)
	class AAffectableItemBase* Item;

	UFUNCTION()
	void SetItemState(bool Collectible) const;
};
