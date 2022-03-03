// Fill out your copyright notice in the Description page of Project Settings.

#include "World/MainGameInstance.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Characters/Main Character/MyCharacter.h"
#include "World/Saves/ActorSaveArchive.h"
#include "Kismet/GameplayStatics.h"
#include "World/Saves/MainSaveGame.h"

void UMainGameInstance::Init()
{
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UMainGameInstance::Tick));

	Super::Init();

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

void UMainGameInstance::SetTime(const int Hour, const int Minute)
{
	GameMinutes += (Hour - GameHour) * 60 + Minute - GameMinute;
}

void UMainGameInstance::AccelerateTime(const int Hour, const int Minute, const float Speed)
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
	if (UGameplayStatics::DoesSaveGameExist(SaveName, 0))
	{
		SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveName, 0));
		return SaveGameData->CheckComplete();
	}
	SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));
	return false;
}

bool UMainGameInstance::IsDay()
{
	return bIsDay = Sunrise.X * 60 + Sunrise.Y <= GameMinutes && GameMinutes <= Sunset.X * 60 + Sunset.Y ? 1 : 0;
}

void UMainGameInstance::NewSave(FString OldSave)
{
	SaveGameData = Cast<UMainSaveGame>(UGameplayStatics::CreateSaveGameObject(UMainSaveGame::StaticClass()));

	UGameplayStatics::DeleteGameInSlot(OldSave, 0);
}

void UMainGameInstance::SaveGame()
{
	GetSaveGame();
	SaveGameData->Data.Empty();
	
	SaveGameData->InGameTime = GameMinutes;

	// Save objects then save player character
	SaveActors.Empty();
	
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), SaveActors);

	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, FString("Savable Actors Found: ") + FString::FromInt(SaveActors.Num()));

	bool* bSerialize = new bool[SaveActors.Num()];
	for (size_t i = 0; i < SaveActors.Num(); i++)
	{
		bSerialize[i] = ISaveable::Execute_PreSaveActor(SaveActors[i]);
	}

	for (int i = 0; i < SaveActors.Num(); i++)
	{
		if (bSerialize[i])
		{
			ensureAlwaysMsgf(bSerialize, TEXT("bSerialize array garbage collected"));
			FActorRecord ActorRecord(SaveActors[i]);
			FMemoryWriter MemoryWriter(ActorRecord.Data, true);
			FActorSaveArchive Ar(MemoryWriter, false);
			MemoryWriter.SetIsSaving(true);
			SaveActors[i]->Serialize(Ar);
			SaveGameData->Data.Add(ActorRecord);
		}
	}

	for (AActor* Actor : SaveActors)
	{
		ISaveable::Execute_PostSaveActor(Actor);
	}

	AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	PCharacter->Save();

	FString SlotName = SaveName;
	if (UGameplayStatics::SaveGameToSlot(SaveGameData, SlotName, 0))
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Game Saved!"));
}

bool UMainGameInstance::LoadGame()
{
	if (GetSaveGame())
	{
		AMyCharacter* PCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		PCharacter->Load();
		
		GameMinutes = SaveGameData->InGameTime;

		// De-Serialize Actors
		UGameplayStatics::GetAllActorsWithInterface(GetWorld(), USaveable::StaticClass(), SaveActors);

		bool* bSerialize = new bool[SaveActors.Num()];
		for (size_t i = 0; i < SaveActors.Num(); i++)
		{
			bSerialize[i] = ISaveable::Execute_PreLoadActor(SaveActors[i]);
		}
		
		for (FActorRecord &ActorRecord : SaveGameData->Data)
		{
			bool bActorFound = false;
			int ActorIndex = -1;
			// Match the save data to the correct actor
			for (size_t i = 0; i < SaveActors.Num(); i++)
			{
				if (ActorRecord.Name == SaveActors[i]->GetName())
				{
					ActorIndex = i;
					SaveActor = SaveActors[i];
					bActorFound = true;
					break;
				}
			}
			
			if (bActorFound)
			{
				ensureAlways(ActorIndex != -1);
				if (bSerialize[ActorIndex])
				{
					SaveActor->SetActorTransform(ActorRecord.Transform);
					FMemoryReader MemoryReader(ActorRecord.Data, true);
					FActorSaveArchive Ar(MemoryReader, false);
					MemoryReader.SetIsLoading(true);
					SaveActor->Serialize(Ar);
				}
			}
			else
			{
				// Spawn Actor
				UClass* Class = ActorRecord.Class;
				const FTransform* Transform = &ActorRecord.Transform;
				FActorSpawnParameters SpawnParameters;
				// We can force spawn the actor, because we already know that the position is not being blocked
				SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AActor* SpawnedActor = GetWorld()->SpawnActor(Class, Transform, SpawnParameters);
				ActorRecord.Name = SpawnedActor->GetName();
				
				ISaveable::Execute_PreLoadActor(SpawnedActor);

				// De-Serialize it's data
				FMemoryReader MemoryReader(ActorRecord.Data, true);
				FActorSaveArchive Ar(MemoryReader, false);
				MemoryReader.SetIsLoading(true);
				SpawnedActor->Serialize(Ar);

				SaveActors.Add(SpawnedActor);
			}
			
			for (AActor* Actor : SaveActors)
			{
				ISaveable::Execute_PostLoadActor(Actor);
			}
		}

		// We have to save again to update the new names for spawned actors
		FString SlotName = SaveName;
		if (UGameplayStatics::SaveGameToSlot(SaveGameData, SlotName, 0))
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("Game Loaded!"));
		
		return true;
	}
	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, TEXT("No Save Game found"));
	return false;
}

void UMainGameInstance::DeleteActiveSave() const
{
	UGameplayStatics::DeleteGameInSlot(SaveName, 0);
}

void UMainGameInstance::LoadMainMenu() const
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenuLevel"));
}

void UMainGameInstance::UnPauseGame() const
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void UMainGameInstance::PauseGame() const
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}
