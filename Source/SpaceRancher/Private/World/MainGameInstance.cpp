// Fill out your copyright notice in the Description page of Project Settings.

#include "World/MainGameInstance.h"
#include "Characters/Main Character/MyCharacter.h"
#include "World/Saves/ActorSaveArchive.h"
#include "Kismet/GameplayStatics.h"
#include "World/Saves/MainSaveGame.h"

void UMainGameInstance::Init()
{

	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UMainGameInstance::Tick));

	Super::Init();

	GetSaveGame();

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

	//Save, then serialize PlayerCharacter
	AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	PCharacter->SavePlayerCharacter();

	FActorRecord PlayerRecord(PCharacter);
	FMemoryWriter MemoryWriterPlayer(PlayerRecord.Data);
	FActorSaveArchive PlayerAr(MemoryWriterPlayer, false);
	PCharacter->Serialize(PlayerAr);
	SaveGameData->PlayerCharacterData = PlayerRecord;

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), Actors);

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Saveable Actors Found: ") + FString::FromInt(Actors.Num()));

	for (int i = 0; i < Actors.Num(); i++)
	{
		FActorRecord ActorRecord(Actors[i]);
		FMemoryWriter MemoryWriter(ActorRecord.Data, true);
		FActorSaveArchive Ar(MemoryWriter, false);
		MemoryWriter.SetIsSaving(true);
		Actors[i]->Serialize(Ar);
		SaveGameData->Data.Add(ActorRecord);
		ISaveable::Execute_SaveActor(Actors[i]);
	}

	FString SlotName = SaveName;
	if (UGameplayStatics::SaveGameToSlot(SaveGameData, SlotName, 0))
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Game Saved!"));
}

bool UMainGameInstance::LoadGame()
{
	if (GetSaveGame())
	{
		AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		PCharacter->LoadPlayerCharacter();

		PlayerIngameTime = SaveGameData->IngameTime;

		//De-Serialize Actors
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), Actors);
		
		for (int i = 0; i < Actors.Num(); i++)
		{
			Actors[i]->SetActorTransform(SaveGameData->Data[i].Transform);

			FMemoryReader MemoryReader(SaveGameData->Data[i].Data);
			FActorSaveArchive Ar(MemoryReader, false);
			MemoryReader.SetIsLoading(true);
			Actors[i]->Serialize(Ar);
			ISaveable::Execute_LoadActor(Actors[i]);
		}

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Game Loaded!"));
		return true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("No Save Game found"));
	return false;
}
