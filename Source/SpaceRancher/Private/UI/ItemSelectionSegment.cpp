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

inline void UItemSelectionSegment::SetLocalAngle()
{
	float MouseX, MouseY;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(MouseX, MouseY);
	const FVector TargetLocation = FVector(MouseX, MouseY, 0.0f);
	const FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(GetWorld()) / 2.0f;
	const float RotationY = UKismetMathLibrary::FindLookAtRotation(FVector(ViewportSize, 0.0f), TargetLocation).Yaw;
	LocalAngle = 1 - (RotationY + 180) / 360.0f;
}

inline float UItemSelectionSegment::DistToMenuCenter() const
{
	float MouseX, MouseY;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(MouseX, MouseY);
	const FVector2D MousePosition = FVector2D(MouseX, MouseY);
	const FVector2D ViewportCenter = UWidgetLayoutLibrary::GetViewportSize(GetWorld()) / 2.0f;
	
	const float MouseDistToCenter = FVector2D::Distance(MousePosition, ViewportCenter);
	
	return MouseDistToCenter / ViewportCenter.Size();
}

FVector2D UItemSelectionSegment::GetSegmentCenter()
{
	const float OuterRadius = MaterialInstance->K2_GetScalarParameterValue(FName("OuterRadius"));
	const float InnerRadius = MaterialInstance->K2_GetScalarParameterValue(FName("InnerRadius"));
	const float RotateDegrees = -(StartingPoint + RelativeEnd / 2) * 2 * PI + PI;
	const float VectorLength = (OuterRadius + InnerRadius) * 0.43f * GetDesiredSize().X;
	
	// Rotated vector point
	return FVector2D(VectorLength * cos(RotateDegrees), VectorLength * sin(RotateDegrees));
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
	RelativeEnd = End;
	MinValue = Min;
	MaxValue = Max;
	Name = SegmentName;
}

void UItemSelectionSegment::CreateStyle_Implementation()	{ }
