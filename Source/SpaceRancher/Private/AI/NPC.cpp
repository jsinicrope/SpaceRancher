// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/NPC.h"
#include "GameFramework/CharacterMovementComponent.h"

ANPC::ANPC()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedDamageTime += DeltaTime;
	ElapsedStaminaDrainTime += DeltaTime;

	{
		if (HealthLastTick < Health)
			ElapsedDamageTime = 0.0f;

		HealthLastTick = Health;

		if ((ElapsedDamageTime >= TimeToHealthRegen) && (Health < MaxRegeneratedHealth))
		{
			Health = fmin(MaxHealth, Health + HealthRegenPerSecond * DeltaTime);
		}
	}
	
	// Drain Stamina if Sprinting and not in Air after 'TimeToStaminaRegen'
	{
		if (GetCharacterMovement()->IsMovingOnGround())
		{
			if (bSprinting)
			{
				Stamina -= StaminaLossRunning * DeltaTime;
				ElapsedStaminaDrainTime = 0.0f;
			}
			// Regen Stamina
			else if (ElapsedStaminaDrainTime >= TimeToStaminaRegen)
				Stamina = fmin(MaxStamina, Stamina + StaminaRegenPerSecond * DeltaTime);
		}
	}

	{
		if (Stamina <= 0)
			StopSprint();
	}

	// Check for Fall Damage
	{
		if (GetCharacterMovement()->IsFalling())
		{
			if (GetCharacterMovement()->GetLastUpdateVelocity().Z < 0.0f)
			{
				FallingTime += DeltaTime;
			}
		}

		if (!GetCharacterMovement()->IsFalling() && FallingTime > 0.0f)
		{
			// Calculate Landing Velocity
			// 2 * acceleration * delta time = velocity
			// 9.81 average gravity acceleration; should be same in engine
			const float FallSpeed = 9.81 * FallingTime;

			FallingTime = 0.0f;

			if (FallSpeed >= MinFallDamageVelocity)
			{
				Health -= (FallSpeed - MinFallDamageVelocity) * FallDamageFactor;
			}
		}
	}

	// Kill NPC if Health 0
	{
		if (Health <= 0.0f)
		{
			KillPlayer();
		}
		else
		{
			bNPCAlive = true;
		}
	}

}

float ANPC::GetHealth()
{
	return Health;
}

void ANPC::StartSprint()
{
	if (Stamina > 10 && GetCharacterMovement()->IsMovingOnGround())
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		bSprinting = true;
	}
}

void ANPC::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bSprinting = false;
}

void ANPC::KillPlayer()
{
	bNPCAlive = false;
}

void ANPC::DamageActor(float Damage)
{
	Health = FMath::Max(Health - Damage, 0.0f);

	if (Health <= 0.0f)
	{
		KillPlayer();
	}
}
