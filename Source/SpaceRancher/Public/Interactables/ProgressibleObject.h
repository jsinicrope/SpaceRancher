// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactables/InteractInterface.h"
#include "World/Saves/Saveable.h"
#include "ProgressibleObject.generated.h"

UCLASS()
class SPACERANCHER_API AProgressableObject : public AActor, public IInteractInterface, public ISaveable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProgressableObject();

	virtual void Interact_Implementation() override;
	virtual void LoadActor_Implementation() override;
	virtual void PreLoadActor_Implementation() override;
	virtual void SaveActor_Implementation() override;
	virtual void PreSaveActor_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame)
	int RequiredAmount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* ItemThumbnail = nullptr;

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
	void SetWidget(UTexture2D* ItemTexture, FString NameOfItem = FString(""), int ItemAmount = -1);

	UFUNCTION(BlueprintCallable)
	bool ShowWidget();

	UFUNCTION(BlueprintCallable)
	void HideWidget();

	UFUNCTION(BlueprintNativeEvent)
	bool AdvanceStage();
};
