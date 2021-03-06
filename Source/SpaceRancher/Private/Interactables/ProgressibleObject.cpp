// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/ProgressibleObject.h"
#include "UI/NeededItemPopUp.h"
#include "Components/Image.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Items/ItemBase.h"
#include "Kismet/KismetSystemLibrary.h"

AProgressibleObject::AProgressibleObject()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AProgressibleObject::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (NeededItemPopUpClass != nullptr)
	{
		NeededItemWidget = CreateWidget<UNeededItemPopUp>(GetWorld(), NeededItemPopUpClass);
		SetWidget(RequiredAmount);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Missing property 'NeededItemPopUpClass' on object: ") + UKismetSystemLibrary::GetObjectName(this));
	}
}

void AProgressibleObject::Interact_Implementation()
{
	if (RequiredAmount == 0)
	{
		AdvanceStage();
	}
	
	for (int i = 0; i < RequiredAmount; i++)
	{
		const FItem_Struct AcquiredItem = PlayerCharacter->RemoveInventoryItemByName(RequiredItem.GetDefaultObject()->Main_Item_Structure.Name);
		if (AcquiredItem.bValidItem)
		{
			RequiredAmount--;
			if (RequiredAmount == 0)
			{
				IncrementStage();
			}
		}
		else
		{
			SetWidget(RequiredAmount);
			ShowWidget();
			GetWorldTimerManager().SetTimer(TimerHandler, this, &AProgressibleObject::HideWidget, 2.0f, false, 2.0f);
		}
	}
}

bool AProgressibleObject::ItemInteract_Implementation(const FItem_Struct& EquippedItem)
{
	if (RequiredAmount == 0)
	{
		IncrementStage();
	}
	
	if (EquippedItem.ItemClass == RequiredItem)
	{
		RequiredAmount--;
		if (RequiredAmount == 0)
		{
			IncrementStage();
		}
	}
	SetWidget(RequiredAmount);
	ShowWidget();
	GetWorldTimerManager().SetTimer(TimerHandler, this, &AProgressibleObject::HideWidget, 2.0f, false, 2.0f);
	
	return true;
}

bool AProgressibleObject::PreLoadActor_Implementation()
{
	return true;
}

void AProgressibleObject::PostLoadActor_Implementation()
{
	
}

bool AProgressibleObject::PreSaveActor_Implementation()
{
	return true;
}

void AProgressibleObject::PostSaveActor_Implementation()
{
	
}

void AProgressibleObject::SetWidget(const int ItemAmount)
{;
	if (ItemAmount != -1)
	{
		RequiredAmount = ItemAmount;
	}
	NeededItemWidget->ItemImage->SetBrushFromTexture(RequiredItem.GetDefaultObject()->Main_Item_Structure.Thumbnail);

	NeededItemWidget->SetTextAmount(ItemAmount, RequiredItem.GetDefaultObject()->Main_Item_Structure.Name);
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

void AProgressibleObject::IncrementStage()
{
	if (Stage < Stages)
	{
		Stage++;
	}
}

bool AProgressibleObject::AdvanceStage_Implementation()
{
	return false;
}
