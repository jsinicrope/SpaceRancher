// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"
#include "World/MainGameInstance.h"
#include "Inventory_System/InventoryComponent.h"
#include "Engine/EngineTypes.h"
#include "Inventory_System/ItemPickUpWidget.h"
#include "MyCharacter.generated.h"

class UCharacterMovementComponent;

UCLASS()
class SPACERANCHER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Variables

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Custom Variables")
	float BaseTurnAtRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float BaseLookUpAtRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, BlueprintGetter=GetHealth, Category="Health")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetMaxHealth, Category="Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxRegeneratedHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool bPlayerDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetMaxStamina, Category="Stamina")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, BlueprintGetter=GetStamina, Category="Stamina")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float HealthRegenPerSecond;

	// Set to true if player is damaged
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	bool bDamaged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Movement")
	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float StaminaLossRunning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float StaminaRegenPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Health")
	float TimeToHealthRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Health")
	float TimeToStaminaRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Movement")
	float FallingTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float FallDamageFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MinFallDamageVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bCanHarvest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bItemInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bInteractableInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Respawn")
	FVector RespawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Respawn")
	FRotator RespawnViewDirection;

	//Widgets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	TSubclassOf<class UUserWidget> InteractPopUpClass;

	UPROPERTY(VisibleAnywhere)
	class UUserWidget* InteractPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSubclassOf<class UUserWidget> ItemPickUpWidgetClass;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	class UItemPickUpWidget* ItemPickUpWidget;

	UPROPERTY()
	class UUserWidget* WidgetToRemove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clock")
	TSubclassOf<class UUserWidget> ClockWidgetClass;

	UPROPERTY(VisibleAnywhere)
	class UClock* ClockWidget;

	UPROPERTY(BlueprintReadOnly)
	UMainGameInstance* GameInstance;

	//Variables hidden in Editor
	UPROPERTY()
	class ACppPlayerController* PC;
	
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetInventoryComp, Category="Inventory")
	class UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	bool bInventoryOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetHUDController, Category="HUD")
	class UHUDSetting* HUDController;

	UPROPERTY()
	class UCameraComponent* PlayerCamera;

public:
	//Functions
	UFUNCTION(BlueprintGetter, Category="Health")
	float GetHealth() const {return Health;}

	UFUNCTION(BlueprintGetter, Category="Health")
	float GetMaxHealth()const {return MaxHealth;}

	UFUNCTION(BlueprintGetter, Category="Stamina")
	float GetStamina() const {return Stamina;}

	UFUNCTION(BlueprintGetter, Category="Stamina")
	float GetMaxStamina() const {return MaxStamina;}

	UFUNCTION(BlueprintGetter, Category="Inventory")
	UInventoryComponent* GetInventoryComp() const {return InventoryComp;}

	UFUNCTION(BlueprintCallable, Category="HUD")
	class UHUDSetting* GetHUDController() const {return HUDController;}
	
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStartSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStopSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerInteract();

	UFUNCTION(BlueprintCallable, Category="Health")
	void DamagePlayer(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void KillPlayer();

	UFUNCTION(BlueprintCallable, Category="Spawn")
	void RespawnPlayer();

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool bIsPlayerDead();

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
	FItem_Struct RemoveItemFromInventoryFromPosition(int column, int row);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromInventory(FItem_Struct Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveItemFromInventoryByName(FString ItemName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void RemoveWidgetFromViewport();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool CheckForInteractable();

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUpAtRate(float Value);
	void TurnAtRate(float Value);
};
