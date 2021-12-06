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

	UFUNCTION(BlueprintCallable)
	inline void SetLocalAngle();

	// Returns the absolute normalized distance to the menus center
	UFUNCTION(BlueprintCallable)
	inline float DistToMenuCenter();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LocalAngle = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float StartingPoint = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="true"))
	float EndPoint = 0.2f;

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
