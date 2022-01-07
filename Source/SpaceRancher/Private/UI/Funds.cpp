// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Funds.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Components/TextBlock.h"

void UFunds::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	AvailableFunds = Cast<UTextBlock>(GetWidgetFromName(FName("AvailableFunds")));
	PC = Cast<ACppPlayerController>(GetWorld()->GetFirstPlayerController());
}

void UFunds::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	AvailableFunds->SetText(FText::FromString(FString::FromInt(PC->GetCredits())));
}
