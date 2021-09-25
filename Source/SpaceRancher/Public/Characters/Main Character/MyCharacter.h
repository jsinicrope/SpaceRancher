// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactables/InteractInterface.h"
#include "Blueprint/UserWidget.h"
#include "World/MainGameInstance.h"
#include "Inventory_System/InventoryComponent.h"
#include "Engine/EngineTypes.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "TimerManager.h"
#include "MyCharacter.generated.h"

class UCharacterMovementComponent;

UCLASS()
class SPACERANCHER_API AMyCharacter : public ACharacter, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Interact_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float BaseTurnAtRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float BaseLookUpAtRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float maxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float maxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float HealthRegenPerSecond;

	// Set to true if player is damaged
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	bool bDamaged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	bool bSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float StaminaLossRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float StaminaBaseRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	float TimeToHealthRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	float TimeToStaminaRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	float FallingTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float FallDamageFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	float MinFallDamageVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bCanHarvest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bItemInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bInteractableInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	FVector RespawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category = "Custom Variables")
	FRotator RespawnViewDirection;

	//Widgets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Variables")
	TSubclassOf<class UUserWidget> InteractPopUpClass;

	UPROPERTY(VisibleAnywhere)
	class UUserWidget* InteractPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<class UUserWidget> ItemPickUpWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	bool bInventoryOpen;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	class UItemPickUpWidget* ItemPickUpWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	class UUserWidget* WidgetToRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock")
	TSubclassOf<class UUserWidget> ClockWidgetClass;

	UPROPERTY(VisibleAnywhere)
	class UClock* ClockWidget;

	UPROPERTY(BlueprintReadOnly)
	UMainGameInstance* GameInstance;

	//Variables hidden in Editor
	class ACppPlayerController* PC;
	class UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

	UPROPERTY(SaveGame)
	FTimerHandle TimerHandler;

	UPROPERTY(SaveGame)
	float ElapsedDamageTime;

	UPROPERTY(SaveGame)
	float ElapsedStaminaDrainTime;

	UPROPERTY(SaveGame)
	float HealthLastTick;

	UPROPERTY(SaveGame)
	FVector JumpStartPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	class UInventoryComponent* InventoryComp;

	UPROPERTY()
	class UCameraComponent* PlayerCamera;

public:
	//Functions
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStartSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStopSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerInteract();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void KillPlayer();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SaveGame();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void LoadGame();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SavePlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void LoadPlayerCharacter();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemToInventory(FItem_Struct Item_Struct);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromInventoryClosestPosition(int column, int row);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromInventory(FItem_Struct Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromInventoryByName(FString ItemName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void RemoveWidgetFromViewport();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool CheckForInteractables();

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUpAtRate(float Value);
	void TurnAtRate(float Value);
};
