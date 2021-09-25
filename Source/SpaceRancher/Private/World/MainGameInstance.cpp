// Fill out your copyright notice in the Description page of Project Settings.

#include "World/MainGameInstance.h"
#include "Characters/Main Character/MyCharacter.h"
#include "World/Saves/ActorSaveArchive.h"

void UMainGameInstance::Init()
{

	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UMainGameInstance::Tick));

	Super::Init();

	if (SaveName.IsEmpty())
		SaveName = GetWorld()->GetMapName();

	FString SlotName = SaveName;
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	}
	else
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
	}

	PlayerIngameTime = InitialStartGameTime;
}

bool UMainGameInstance::Tick(float DeltaSeconds)
{
	if (!UGameplayStatics::IsGamePaused(GetWorld()))
	{
		PlayerIngameTime += (DeltaSeconds / 60.0f) * TimeScale;
		RealTimeMinutes += (DeltaSeconds / 60.0f) * TimeScale;

		if (PlayerIngameTime >= 30.0f)
		{
			PlayerIngameTime -= 30.0f;
		}
	}
	return true;
}

bool UMainGameInstance::GetSaveGame()
{
	if (SaveName.IsEmpty())
		SaveName = GetWorld()->GetMapName();

	FString SlotName = SaveName;
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
		return true;
	}
	else
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
		return false;
	}
}

void UMainGameInstance::NewSave(FString OldSave)
{
	SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));

	FString SlotName = OldSave;
	UGameplayStatics::DeleteGameInSlot(SlotName, 0);
}

void UMainGameInstance::SaveGame()
{
	GetSaveGame();
	SaveGameData->IngameTime = PlayerIngameTime;

	AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

	//Serialize
	FActorRecord ActorRecord(PCharacter);
	FMemoryWriter MemoryWriter(ActorRecord.Data);
	FActorSaveArchive Ar(MemoryWriter, false);
	PCharacter->Serialize(Ar);

	SaveGameData->Data = ActorRecord;
}

bool UMainGameInstance::LoadGame()
{
	if (GetSaveGame())
	{
		PlayerIngameTime = SaveGameData->IngameTime;
		return true;
	}
	return false;
}
