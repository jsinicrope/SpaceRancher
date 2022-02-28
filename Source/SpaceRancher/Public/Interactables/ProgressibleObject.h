// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "World/Saves/Saveable.h"
#include "ProgressibleObject.generated.h"

UCLASS()
class SPACERANCHER_API AProgressibleObject : public AActor, public IInteractInterface, public ISaveable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProgressibleObject();

	virtual void Interact_Implementation() override;
	virtual bool ItemInteract_Implementation(const FItem_Struct& EquippedItem) override;
	virtual void PostLoadActor_Implementation() override;
	virtual bool PreLoadActor_Implementation() override;
	virtual void PostSaveActor_Implementation() override;
	virtual bool PreSaveActor_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	int RequiredAmount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AItemBase> RequiredItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	int Stage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Stages = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> NeededItemPopUpClass;

	UPROPERTY()
	class UNeededItemPopUp* NeededItemWidget = nullptr;

	UPROPERTY()
	FTimerHandle TimerHandler;

	UPROPERTY()
	class AMyCharacter* PlayerCharacter;

	UFUNCTION(BlueprintCallable)
	void SetWidget(const int ItemAmount = -1);

	UFUNCTION(BlueprintCallable)
	bool ShowWidget();

	UFUNCTION(BlueprintCallable)
	void HideWidget();

	UFUNCTION(BlueprintNativeEvent)
	bool AdvanceStage();

	void IncrementStage();
};
