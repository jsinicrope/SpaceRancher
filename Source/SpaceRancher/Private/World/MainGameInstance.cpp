// Fill out your copyright notice in the Description page of Project Settings.


#include "World/MainGameInstance.h"

void UMainGameInstance::Init()
{
	Super::Init();

	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Save Game Loaded from File!"));
	}
	else
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("New Save Game created!"));
	}
}
