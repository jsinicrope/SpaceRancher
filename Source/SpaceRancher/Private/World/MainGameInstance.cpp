// Fill out your copyright notice in the Description page of Project Settings.


#include "World/MainGameInstance.h"

void UMainGameInstance::Init()
{
	Super::Init();

	FString CurrentMapName = GetWorld()->GetMapName();
	FString SlotName = SaveSlotName + CurrentMapName;
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, SlotName);

	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Save Game Loaded from File!"));
	}
	else
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("New Save Game created!"));
	}
}
