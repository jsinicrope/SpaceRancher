// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/ProgressibleObject.h"
#include "UI/NeededItemPopUp.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AProgressableObject::AProgressableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AProgressableObject::BeginPlay()
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

void AProgressableObject::Interact_Implementation()
{
	if (RequiredAmount == 0)
	{
		AdvanceStage();
	}
	
	for (int i = 0; i < RequiredAmount; i++)
	{
		const FItem_Struct AcquiredItem = PlayerCharacter->RemoveItemFromInventoryByName(ItemName);
		if (AcquiredItem.bValidItem)
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
			GetWorldTimerManager().SetTimer(TimerHandler, this, &AProgressableObject::HideWidget, 2.0f, false, 2.0f);
		}
	}
}

void AProgressableObject::PreLoadActor_Implementation()
{
	
}

void AProgressableObject::LoadActor_Implementation()
{
	
}

void AProgressableObject::PreSaveActor_Implementation()
{
	
}

void AProgressableObject::SaveActor_Implementation()
{
	
}

void AProgressableObject::SetWidget(UTexture2D* ItemTexture, FString NameOfItem, int ItemAmount)
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

bool AProgressableObject::ShowWidget()
{
	if (!NeededItemWidget->IsInViewport())
	{
		NeededItemWidget->AddToViewport();
		return true;
	}
	return false;
}

void AProgressableObject::HideWidget()
{
	GetWorldTimerManager().ClearTimer(TimerHandler);
	NeededItemWidget->RemoveFromViewport();
}

bool AProgressableObject::AdvanceStage_Implementation()
{
	if (Stage < Stages)
	{
		Stage++;
		return true;
	}
	return false;
}
