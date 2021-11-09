// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/UI/FoodCookerTimer.h"
#include "Kismet/KismetTextLibrary.h"

void UFoodCookerTimer::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UFoodCookerTimer::UpdateTimer(float RemainingTime) const
{
	int Minutes = FMath::Floor(RemainingTime / 60.0f);
	Minutes = Minutes >= 0 ? Minutes : 0;
	const FText TextMinutes = UKismetTextLibrary::Conv_IntToText(Minutes, false, true, 2);
	const FText Seconds = UKismetTextLibrary::Conv_IntToText(fmod(RemainingTime, 60.0f), false, true, 2);
	const FString NewDisplay = TextMinutes.ToString() + FString(":") + Seconds.ToString();
	Time->SetText(FText::FromString(NewDisplay));
}
