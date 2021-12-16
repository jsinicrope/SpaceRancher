// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemSelectionSegment.generated.h"

UCLASS()
class SPACERANCHER_API UItemSelectionSegment : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* SelectionButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* MaterialInstance;
	
	UPROPERTY(BlueprintReadOnly)
	class UItemSelectionHUD* SelectionHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin=0.0f, ClampMax=1.0f))
	float MinInteractionDistance = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin=0.0f, ClampMax=1.0f))
	float MaxInteractionDistance = 0.43f;

	UFUNCTION()
	inline void SetLocalAngle();

	// @Returns the absolute normalized distance to the menus center
	UFUNCTION()
	inline float DistToMenuCenter() const;

	UFUNCTION(BlueprintCallable)
	FVector2D GetSegmentCenter();

	// @Return true if the mouse is in interaction distance with this segment
	UFUNCTION(BlueprintCallable)
	bool IsMouseOver();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LocalAngle = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float StartingPoint = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float RelativeEnd = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float MinValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float MaxValue = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	FName Name;
	
	UFUNCTION()
	void SetVariables(float Start, float End, float Min, float Max, FName SegmentName);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CreateStyle();
};
