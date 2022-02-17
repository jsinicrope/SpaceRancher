// Fill out your copyright notice in the Description page of Project Settings.

#include "World/Saves/MainSaveGame.h"

UMainSaveGame::UMainSaveGame()
{
	InGameTime = 10.0f;
}

bool UMainSaveGame::CheckComplete() const
{
	return !(Player_Inventory_Array_Columns.IsEmpty() || PlayerCharacterData.Data.IsEmpty() || Data.IsEmpty());
}
