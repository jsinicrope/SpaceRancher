// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/ItemSelectionHUD.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Overlay.h"
#include "UI/ItemSelectionSegment.h"

void UItemSelectionHUD::CreateStandardWidget()
{
	RadialOverlay->ClearChildren();

	const int Amount = PiePieces.Num();
	for (int i = 0; i < Amount; i++)
	{
		const float MinValue = static_cast<float>(i) / Amount;
		const float MaxValue = (i + 1.0f) * (1.0f / Amount);
		const float StartingPoint = MinValue + 0.01f;
		const float EndPoint = 1.0f / Amount - 0.02f;
		const FName Name = PiePieces[i];
		UItemSelectionSegment* Segment = CreateWidget<UItemSelectionSegment>(GetWorld()->GetFirstPlayerController(), SegmentClass);
		Segment->SetVariables(StartingPoint, EndPoint, MinValue, MaxValue, Name);
		Segment->CreateStyle();
		
		RadialOverlay->AddChild(Segment);
	}
}
