// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Attackable.h"
#include "NPC.generated.h"

UCLASS()
class SPACERANCHER_API ANPC : public ACharacter, public IAttackable
{
	GENERATED_BODY()

public:
	ANPC();
	
	bool WasKilled_Implementation() override { return bNPCAlive; }
	void Damage_Implementation(float Damage) override { DamageActor(Damage); }
	ACharacter* GetCharacter_Implementation() override { return this; }
	

protected:
	virtual void BeginPlay() override;

	// Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter="GetHealth", Category="Health")
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxRegeneratedHealth = Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float HealthRegenPerSecond = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float TimeToHealthRegen = 10.0f;

	UPROPERTY()
	float HealthLastTick = Health;

	UPROPERTY(BlueprintReadOnly, Category="Health", meta=(DisplayName="Is NPC Alive"))
	bool bNPCAlive = true;

	// Stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float MaxStamina = 100.0f;

	UPROPERTY()
	float ElapsedDamageTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float StaminaRegenPerSecond = 10.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float StaminaLossRunning = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float TimeToStaminaRegen = 3.0f;

	UPROPERTY()
	float ElapsedStaminaDrainTime = 0.0f;

	// Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float WalkSpeed = 250.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SprintSpeed = 400.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bSprinting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Movement")
	float FallingTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float FallDamageFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MinFallDamageVelocity;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintGetter)
	float GetHealth();
	
	UFUNCTION(BlueprintCallable)
	void StartSprint();

	UFUNCTION(BlueprintCallable)
	void StopSprint();

	UFUNCTION(BlueprintCallable)
	void KillPlayer();

	UFUNCTION(BlueprintCallable)
	void DamageActor(float Damage);
};
