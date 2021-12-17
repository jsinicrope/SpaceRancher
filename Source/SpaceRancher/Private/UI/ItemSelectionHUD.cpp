// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/ItemSelectionHUD.h"
#include "Components/Overlay.h"
#include "UI/ItemSelectionSegment.h"

void UItemSelectionHUD::NativeConstruct()
{
	Super::NativeConstruct();

	RadialOverlay = Cast<UOverlay>(GetWidgetFromName(FName("RadialOverlay")));
}

void UItemSelectionHUD::CreateStandardWidget(TArray<FItem_Struct> &Selectables)
{
	RadialOverlay->ClearChildren();
	PiePieces = Selectables;
	const int Amount = PiePieces.Num();
	for (int i = 0; i < Amount; i++)
	{
		const float MinValue = static_cast<float>(i) / Amount;
		const float MaxValue = (i + 1.0f) * (1.0f / Amount);
		const float StartingPoint = MinValue + 0.01f;
		const float EndPoint = 1.0f / Amount - 0.02f;
		UItemSelectionSegment* Segment = CreateWidget<UItemSelectionSegment>(GetWorld()->GetFirstPlayerController(), SegmentClass);
		const FItem_Struct Item = PiePieces[i];
		Segment->SetVariables(StartingPoint, EndPoint, MinValue, MaxValue, FName(Item.Name));
		Segment->CreateStyle();
		Segment->SetItem(Item);
		
		RadialOverlay->AddChild(Segment);
	}
}

FItem_Struct UItemSelectionHUD::GetSelectedItem()
{
	const int Amount = PiePieces.Num();
	for (int i = 0; i < Amount; i++)
	{
		const UItemSelectionSegment* Segment = static_cast<UItemSelectionSegment*>(RadialOverlay->GetChildAt(i));
		if (Segment->bSelected)
		{
			return Segment->GetItem();
		}
	}
	return FItem_Struct();
}
