// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Clock.h"
#include "Components/TextBlock.h"
#include "World/MainGameInstance.h"

void UClock::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	GameInstance = Cast<UMainGameInstance>(GetGameInstance());
	TextBlockTime = Cast<UTextBlock>(GetWidgetFromName(FName("TextBlockTime")));
}

void UClock::UpdateClock()
{
	ClockTimeTotalMinutes = (int)(GameInstance->PlayerIngameTime * GameInstance->RealToGameTimeFactor);
	ClockTimeMinutes = ClockTimeTotalMinutes % 60;
	ClockTimeHour = ClockTimeTotalMinutes / 60;

	MinutesString = FString::FromInt(ClockTimeMinutes);

	if (ClockTimeMinutes < 10)
		MinutesString = FString("0") + FString::FromInt(ClockTimeMinutes);

	StringTime = FString::FromInt(ClockTimeHour) + FString(":") + MinutesString;
}
