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

void UClock::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateClock();
}

void UClock::UpdateClock()
{
	MinutesString = FString::FromInt(GameInstance->GameMinute);

	if (GameInstance->GameMinute < 10)
		MinutesString = FString("0") + FString::FromInt(GameInstance->GameMinute);

	StringTime = FString::FromInt(GameInstance->GameHour) + FString(":") + MinutesString;
	const FText Text = FText::FromString(StringTime);
	SetTextBlock(Text);
}

void UClock::SetTextBlock(FText Text) const
{
	TextBlockTime->SetText(Text);
}
