// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/ItemSelectionSegment.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Button.h"
#include "Kismet/KismetMathLibrary.h"

void UItemSelectionSegment::NativeConstruct()
{
	Super::NativeConstruct();
}

void UItemSelectionSegment::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UItemSelectionSegment::SetLocalAngle()
{
	float MouseX, MouseY;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(MouseX, MouseY);
	const FVector TargetLocation = FVector(MouseX, MouseY, 0.0f);
	const FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(GetWorld()) / 2.0f;
	const float RotationY = UKismetMathLibrary::FindLookAtRotation(FVector(ViewportSize, 0.0f), TargetLocation).Yaw;
	LocalAngle = 1 - (RotationY + 180) / 360.0f;
}

float UItemSelectionSegment::DistToMenuCenter()
{
	float MouseX, MouseY;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(MouseX, MouseY);
	const FVector2D MousePosition = FVector2D(MouseX, MouseY);
	const FVector2D ViewportCenter = UWidgetLayoutLibrary::GetViewportSize(GetWorld()) / 2.0f;
	
	const float MouseDistToCenter = FVector2D::Distance(MousePosition, ViewportCenter);
	
	return MouseDistToCenter / ViewportCenter.Size();
}

bool UItemSelectionSegment::IsMouseOver()
{
	SetLocalAngle();
	const float Dist = DistToMenuCenter();
	if (MaxInteractionDistance >= Dist && Dist >= MinInteractionDistance &&
		MaxValue - (StartingPoint - MinValue) >= LocalAngle && LocalAngle >= StartingPoint)
	{
		return true;
	}
	return false;
}

void UItemSelectionSegment::SetVariables(float Start, float End, float Min, float Max, FName SegmentName)
{
	StartingPoint = Start;
	EndPoint = End;
	MinValue = Min;
	MaxValue = Max;
	Name = SegmentName;
}

void UItemSelectionSegment::CreateStyle_Implementation()	{ }
