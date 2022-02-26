// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseMenu.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "World/MainGameInstance.h"
	

void UPauseMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ResumeButton = Cast<UButton>(GetWidgetFromName(FName("ResumeButton")));
	SaveButton = Cast<UButton>(GetWidgetFromName(FName("SaveButton")));
	ExitButton = Cast<UButton>(GetWidgetFromName(FName("ExitButton")));

	ResumeButton->OnPressed.AddDynamic(this, &UPauseMenu::ResumeGame);
	SaveButton->OnPressed.AddDynamic(this, &UPauseMenu::SaveGame);
	ExitButton->OnPressed.AddDynamic(this, &UPauseMenu::ExitGame);
	
	GameInstance = Cast<UMainGameInstance>(GetGameInstance());
}

void UPauseMenu::ResumeGame()
{
	PlayerController = GetWorld()->GetFirstPlayerController();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GameInstance->UnPauseGame();
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
	this->RemoveFromParent();
}

void UPauseMenu::ExitGame()
{
	GameInstance->LoadMainMenu();
}

void UPauseMenu::SaveGame()
{
	GameInstance->SaveGame();
}
