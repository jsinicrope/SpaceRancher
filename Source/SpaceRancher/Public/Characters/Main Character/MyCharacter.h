// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class SPACERANCHER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float HealthRegenPerSecond;

	// Set to true if player is damaged
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	bool bDamaged;

	//Variables hidden in Engine
	float ElapsedDamageTime;
	float HealthLastTick;


	//Functions


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
