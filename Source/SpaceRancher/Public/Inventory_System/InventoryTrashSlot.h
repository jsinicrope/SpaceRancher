// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "Blueprint/UserWidget.h"
#include "InventoryTrashSlot.generated.h"

UCLASS()
class SPACERANCHER_API UInventoryTrashSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlock = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* ImageThumbnail = nullptr;

	UPROPERTY()
	class UInventoryWindow* InventoryWindow;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	FItem_Struct SlotContent;

protected:
	UPROPERTY()
	float TimeToReset = 0.75f;
	
	UFUNCTION(BlueprintCallable)
	void ResetSlot();
};
