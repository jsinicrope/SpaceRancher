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

	PlayerInGameTime = InitialStartGameTime;
}

bool UMainGameInstance::Tick(float DeltaSeconds)
{
	if (!UGameplayStatics::IsGamePaused(GetWorld()))
	{
		PlayerInGameTime += (DeltaSeconds / 60.0f) * TimeScale;
		RealTimeMinutes += (DeltaSeconds / 60.0f) * TimeScale;

		if (PlayerInGameTime >= 30.0f)
		{
			PlayerInGameTime -= 30.0f;
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
	// Prepare for saving by emptying the old Serialized Data
	SaveGameData->Data.Empty();
	
	SaveGameData->InGameTime = PlayerInGameTime;

	//Save, then serialize PlayerCharacter
	SaveActors.Empty();
	
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), SaveActors);

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Savable Actors Found: ") + FString::FromInt(SaveActors.Num()));

	for (int i = 0; i < SaveActors.Num(); i++)
	{
		ISaveable::Execute_PreSaveActor(SaveActors[i]);
		FActorRecord ActorRecord(SaveActors[i]);
		FMemoryWriter MemoryWriter(ActorRecord.Data, true);
		FActorSaveArchive Ar(MemoryWriter, false);
		MemoryWriter.SetIsSaving(true);
		SaveActors[i]->Serialize(Ar);
		SaveGameData->Data.Add(ActorRecord);
		ISaveable::Execute_SaveActor(SaveActors[i]);
	}

	AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	PCharacter->SavePlayerCharacter();

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

		PlayerInGameTime = SaveGameData->InGameTime;

		//De-Serialize Actors
		SaveActors.Empty();
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), SaveActors);
		
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::FromInt(SaveActors.Num()));
		
		for (int i = 0; i < SaveActors.Num(); i++)
		{
			if (SaveGameData->Data[i].Name == SaveActors[i]->GetName())
			{
				ISaveable::Execute_PreLoadActor(SaveActors[i]);
				SaveActors[i]->SetActorTransform(SaveGameData->Data[i].Transform);
				FMemoryReader MemoryReader(SaveGameData->Data[i].Data, true);
				FActorSaveArchive Ar(MemoryReader, false);
				MemoryReader.SetIsLoading(true);
				SaveActors[i]->Serialize(Ar);
				ISaveable::Execute_LoadActor(SaveActors[i]);
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Actor deleted"));
			}
		}

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Game Loaded!"));
		return true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("No Save Game found"));
	return false;
}
