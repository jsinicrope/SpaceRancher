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
	SetTime(InitialStartGameTime.X, InitialStartGameTime.Y);
}

bool UMainGameInstance::Tick(float DeltaSeconds)
{
	DeltaSeconds *= TimeScale;
	if (!UGameplayStatics::IsGamePaused(GetWorld()))
	{
		// Update Time related values
		GameMinutes += (DeltaSeconds / 60.0f) * REAL_TO_GAME_TIME_FACTOR;
		GameHour = GameMinutes / 60;
		GameMinute = static_cast<int>(GameMinutes) % 60;
		RealTimeMinutes += DeltaSeconds / 100.0f;
		
		if (GameMinutes >= 24 * 60)
		{
			GameMinutes -= 24 * 60;
		}

		bIsDay = Sunrise.X * 60 + Sunrise.Y <= GameMinutes && GameMinutes <= Sunset.X * 60 + Sunset.Y ? 1 : 0;

		// Handle Time Acceleration
		if (bTimeAcceleration)
		{
			TimeToAccelerate -= DeltaSeconds / 60.0f * REAL_TO_GAME_TIME_FACTOR;

			if (TimeToAccelerate <= 0.0f)
			{
				bTimeAcceleration = false;
				TimeScale = 1.0f;
			}
		}
	}
	
	return true;
}

void UMainGameInstance::SetTime(int Hour, int Minute)
{
	GameMinutes += (Hour - GameHour) * 60 + Minute - GameMinute;
}

void UMainGameInstance::AccelerateTime(int Hour, int Minute, float Speed)
{
	int MinutesToSkip;
	const int CurrentGameMinutes = GameHour * 60 + GameMinute;
	const int TargetGameMinutes = Hour * 60 + Minute;

	if (CurrentGameMinutes > TargetGameMinutes)
	{
		MinutesToSkip = 24 * 60 - CurrentGameMinutes;
		MinutesToSkip += TargetGameMinutes;
	}
	else
	{
		MinutesToSkip = TargetGameMinutes - CurrentGameMinutes;
	}
	
	TimeToAccelerate = MinutesToSkip;
	bTimeAcceleration = true;
	TimeScale = Speed;
}

bool UMainGameInstance::GetSaveGame()
{
	const FString SlotName = SaveName;
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

	UGameplayStatics::DeleteGameInSlot(OldSave, 0);
}

void UMainGameInstance::SaveGame()
{
	GetSaveGame();
	// Prepare for saving by emptying the old Serialized Data
	SaveGameData->Data.Empty();
	
	SaveGameData->InGameTime = GameMinutes;

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

		GameMinutes = SaveGameData->InGameTime;

		//De-Serialize Actors
		SaveActors.Empty();
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), SaveActors);
		
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::FromInt(SaveActors.Num()));
		
		for (int i = 0; i < SaveGameData->Data.Num(); i++)
		{
			for (int j = i; j < SaveActors.Num(); j++)
			{
				if (SaveGameData->Data[i].Name == SaveActors[j]->GetName())
				{
					ISaveable::Execute_PreLoadActor(SaveActors[i]);
					SaveActors[i]->SetActorTransform(SaveGameData->Data[i].Transform);
					FMemoryReader MemoryReader(SaveGameData->Data[i].Data, true);
					FActorSaveArchive Ar(MemoryReader, false);
					MemoryReader.SetIsLoading(true);
					SaveActors[i]->Serialize(Ar);
					ISaveable::Execute_LoadActor(SaveActors[i]);
					break;
				}
			}
		}

		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Game Loaded!"));
		return true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("No Save Game found"));
	return false;
}
