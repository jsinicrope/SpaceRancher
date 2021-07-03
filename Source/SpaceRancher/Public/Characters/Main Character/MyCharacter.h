// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UCharacterMovementComponent;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	bool bSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float StaminaLossRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float StaminaBaseRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float TimeToHealthRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float TimeToStaminaRegen;

	//Variables hidden in Engine
	float ElapsedDamageTime;
	float ElapsedStaminaDrainTime;
	float HealthLastTick;
	class UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();


	//Functions
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStartSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStopSprint();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
