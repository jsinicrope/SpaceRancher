// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/ProgressibleObject.h"
#include "UI/NeededItemPopUp.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AProgressibleObject::AProgressibleObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AProgressibleObject::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (NeededItemPopUpClass != nullptr)
	{
		NeededItemWidget = CreateWidget<UNeededItemPopUp>(GetWorld(), NeededItemPopUpClass);
		SetWidget(ItemThumbnail, ItemName, RequiredAmount);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Missing property 'NeededItemPopUpClass' on object: ") + UKismetSystemLibrary::GetObjectName(this));
	}
}

void AProgressibleObject::Interact_Implementation()
{
	for (int i = 0; i < RequiredAmount; i++)
	{
		FItem_Struct AcquiredItem = PlayerCharacter->RemoveItemFromInventoryByName(ItemName);
		if (AcquiredItem.bIsValidItem)
		{
			RequiredAmount--;
			if (RequiredAmount == 0)
			{
				AdvanceStage();
			}
		}
		else
		{
			SetWidget(ItemThumbnail, ItemName, RequiredAmount);
			ShowWidget();
			GetWorldTimerManager().SetTimer(TimerHandler, this, &AProgressibleObject::HideWidget, 2.0f, false, 2.0f);
		}
	}
}

void AProgressibleObject::SetWidget(UTexture2D* ItemTexture, FString NameOfItem, int ItemAmount)
{
	ItemThumbnail = ItemTexture;
	ItemName = NameOfItem;

	if (ItemAmount != -1)
	{
		RequiredAmount = ItemAmount;
	}
	NeededItemWidget->ItemImage->SetBrushFromTexture(ItemTexture);

	NeededItemWidget->SetTextAmount(ItemAmount, NameOfItem);
}

bool AProgressibleObject::ShowWidget()
{
	if (!NeededItemWidget->IsInViewport())
	{
		NeededItemWidget->AddToViewport();
		return true;
	}
	return false;
}

void AProgressibleObject::HideWidget()
{
	GetWorldTimerManager().ClearTimer(TimerHandler);
	NeededItemWidget->RemoveFromViewport();
}

bool AProgressibleObject::AdvanceStage_Implementation()
{
	if (Stage < Stages)
	{
		Stage++;
		return true;
	}
	return false;
}
