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

void UFunds::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	AvailableFunds->SetText(FText::FromString(FString::FromInt(PC->GetCredits())));
}
