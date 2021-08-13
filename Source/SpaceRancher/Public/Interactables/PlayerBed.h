// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactables/InteractInterface.h"
#include "Characters/Main Character/MyCharacter.h"
#include "PlayerBed.generated.h"

UCLASS()
class SPACERANCHER_API APlayerBed : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBed();

	void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	float WakeUpTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	float AllowSleepTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	bool bTimeAcceleration;

	UPROPERTY()
	float TimeToAccelerate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sleep")
	float TimeAcceleration;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	UMainGameInstance* GameInstance;
};
