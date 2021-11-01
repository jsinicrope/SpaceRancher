// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HealthAndStaminaBar.h"
#include "Components/ProgressBar.h"
#include "Characters/Main Character/MyCharacter.h"

void UHealthAndStaminaBar::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	HealthBar = Cast<UProgressBar>(GetWidgetFromName(FName("HealthBar")));
	StaminaBar = Cast<UProgressBar>(GetWidgetFromName(FName("StaminaBar")));

	PC = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void UHealthAndStaminaBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateHealthBar();
	UpdateStaminaBar();
}

void UHealthAndStaminaBar::UpdateHealthBar() const
{
	const float Percent = PC->GetHealth() / PC->GetMaxHealth();
	HealthBar->SetPercent(Percent);
}

void UHealthAndStaminaBar::UpdateStaminaBar() const
{
	const float Percent = PC->GetStamina() / PC->GetMaxStamina();
	StaminaBar->SetPercent(Percent);
}
