// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBuildable.h"
#include "Interfaces/Interactable.h"
#include "Characters/Main Character/MyCharacter.h"
#include "PlayerBed.generated.h"

UCLASS()
class SPACERANCHER_API APlayerBed : public APlayerBuildable, public IInteractInterface
{
	GENERATED_BODY()
	
public:
	APlayerBed();

	virtual void Interact_Implementation() override;

protected:
	virtual void BeginPlay() override;

	// Time that will be spooled forward to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	int WakeUpTime = 8;

	// Time from when on the player can interact with the bed to sleep
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	int AllowSleepTime = 23;

	UPROPERTY()
	bool bTimeAcceleration;

	UPROPERTY()
	float TimeToAccelerate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Sleep")
	float TimeAcceleration = 300.0f;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	UMainGameInstance* GameInstance;
};
