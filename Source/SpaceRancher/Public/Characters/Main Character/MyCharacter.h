// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "World/MainGameInstance.h"
#include "Inventory_System/InventoryComponent.h"
#include "Engine/EngineTypes.h"
#include "Interfaces/Attackable.h"
#include "MyCharacter.generated.h"

UCLASS(HideCategories=("Actor Tick"))
class SPACERANCHER_API AMyCharacter : public ACharacter, public IAttackable
{
	GENERATED_BODY()

public:
	AMyCharacter();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	// Health

	// The actual current health of the character
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetHealth, SaveGame, Category="Health")
	float Health = 100.0f;

	// The maximum health of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetMaxHealth, Category="Health")
	float MaxHealth = 100.0f;

	// How much health is regenerated every second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float HealthRegenRate = 10.0f;

	// How much health can be regenerated through the HealthRegenRate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
	float MaxRegeneratableHealth = 100.0f;

	// Time before health gets regenerated after the player gets damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Health")
	float TimeToHealthRegen = 3.0f;

	/** Whether the player is dead
	 * Internal use only recommended */
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	bool bPlayerDead = false;

	// Set to true if player is damaged 
	UPROPERTY(BlueprintReadOnly, Category="Health")
	bool bDamaged = false;

	// Stamina

	// The actual current health of the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetStamina, SaveGame, Category="Stamina")
	float Stamina = 100.0f;

	// The maximum amount of stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetMaxStamina, Category="Stamina")
	float MaxStamina = 100.0f;

	// How much Stamina is regenerated every second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float StaminaRegenRate = 20.0f;

	// How much stamina can be regenerated through the StaminaRegenRate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float StaminaLossRunning = 50.0f;

	// Time before stamina gets regenerated after the player used stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Stamina")
	float TimeToStaminaRegen = 2.0f;
	
	// Movement

	// The horizontal look turn rate speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float BaseTurnAtRate = 45.0f;

	// The vertical look turn rate speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float BaseLookUpAtRate = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float WalkSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float SprintSpeed = 1000.0f;
	
	/** True when the player is actively sprinting
	 * When this is true, stamina will be drained at the StaminaLossRunning rate*/
	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bSprinting = false;

	UPROPERTY(BlueprintReadOnly, SaveGame, Category="Movement")
	FVector CurrentVelocity;

	/** The time since the player started falling
	 * Used to calculate fall damage */
	UPROPERTY(BlueprintReadOnly, SaveGame, Category="Movement")
	float FallingTime = 0.0f;

	// The amount of fall damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float FallDamageFactor = 2.0f;

	// The minimum speed which the character has to be, before it gets damaged
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MinFallDamageVelocity = 5.0f;

	// Interaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractDistance = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Respawn")
	FVector RespawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Respawn")
	FRotator RespawnViewDirection;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
	bool bInventoryOpen = false;

	UPROPERTY(BlueprintReadOnly, Category="ItemSelection")
	bool bItemSelectionOpen = false;

	// The item that is currently selected from the radial menu
	UPROPERTY(BlueprintReadOnly, Category="ItemSelection")
	FItem_Struct SelectedItem;

	// MiniMap
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MiniMap")
	float DefaultMiniMapSize = 1024.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MiniMap")
	int DefaultZoomLevel = 2;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MiniMap")
	int ZoomLevel = DefaultZoomLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MiniMap")
	int MaxZoomLevel = 3;

	// The amount the zoom changes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MiniMap")
	float ZoomSize = 512.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="MiniMap")
	bool bMiniMapActive = true;

	UPROPERTY()
	UUserWidget* WidgetToRemove;

	UPROPERTY(BlueprintReadOnly)
	UMainGameInstance* GameInstance;

	//Variables hidden in Editor
	UPROPERTY(BlueprintReadOnly)
	ACppPlayerController* PC;

	// INTERNAL use only; Used for RemoveWidgetFromViewport
	UPROPERTY(SaveGame)
	FTimerHandle TimerHandler;

	UPROPERTY(SaveGame)
	float ElapsedDamageTime = 0.0f;

	UPROPERTY(SaveGame)
	float ElapsedStaminaDrainTime = 0.0f;

	UPROPERTY(SaveGame)
	float HealthLastTick = 100.0f;

	UPROPERTY(SaveGame)
	FVector JumpStartPoint;
	
	// Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetInventoryComp, Category="Inventory")
	UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UWidgetInteractionComponent* WidgetInteractionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* PlayerCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MiniMap")
	UChildActorComponent* MiniMapCamera;

	// Mini Map
	UPROPERTY(BlueprintReadOnly, Category="MiniMap")
	class ASceneCapture2D* MiniMapCapture;

	UPROPERTY(BlueprintReadWrite, Category="Handheld")
	AActor* HeldItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Handheld")
	UChildActorComponent* HandItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter=GetHUDController, Category="HUD")
	UHUDSetting* HUDController;

	// Functions
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PrimaryActionPressed();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void PrimaryActionReleased();
	
	UFUNCTION()
	void UpdateSelectedItem();

	UFUNCTION()
	void UnEquipItem();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnSelectedItemChanged(FItem_Struct &Item);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual bool Damage_Implementation(float Damage) override { return DamagePlayer(Damage); }
	virtual UClass* GetCharacter_Implementation() override { return GetClass(); }
	
public:
	// Functions
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
	UHUDSetting* GetHUDController() const {return HUDController;}
	
	// Zoom in or out of the MiniMap
	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void ZoomMiniMap(const int Level);

	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void ZoomMiniMapIn();

	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void ZoomMiniMapOut();

	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void DeactivateMiniMap();

	UFUNCTION(BlueprintCallable, Category="MiniMap")
	void ActivateMiniMap();
	
	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStartSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerStopSprint();

	UFUNCTION(BlueprintCallable, Category = "Custom Functions")
	void PlayerInteract();

	UFUNCTION(BlueprintCallable, Category="Health")
	bool DamagePlayer(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void KillPlayer();

	UFUNCTION(BlueprintCallable, Category="Spawn")
	void RespawnPlayer();

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool GetIsPlayerDead() const { return bPlayerDead; }

	/* Handles the saving of the character state
	 * Calling is handled from the MainGameInstance */
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Save();

	/** Handles the loading of the character state
	 * Calling is handled from the MainGameInstance */
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void Load();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddInventoryItem(FItem_Struct &Item_Struct);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveInventoryItem(const FItem_Struct &Item) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItem_Struct RemoveInventoryItemByName(FString ItemName) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

	/** Opens the RadialMenu
	 * Does not open the menu if other interactable widgets are active on screen */
	UFUNCTION(BlueprintCallable, Category="ItemSelection")
	void OpenRadialMenu();

	// Closes the RadialMenu
	UFUNCTION(BlueprintCallable, Category="ItemSelection")
	void CloseRadialMenu();

	// Returns the item currently selected in the radial menu
	UFUNCTION(BlueprintGetter)
	FItem_Struct GetSelectedItem() const	{return SelectedItem;}

	UFUNCTION(BlueprintCallable, Category = "UI")
	void RemoveWidgetFromViewport();

	/** Returns the position of the immediate viewpoint of the player
	 * Returns a null vector if the player is not looking at any object */
	UFUNCTION(BlueprintCallable)
	FVector GetViewPoint();

	UFUNCTION(BlueprintCallable)
	FVector GetViewForwardVector() const;

	// Returns true if an item with the IInteractInterface was hit
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool CheckForInteractable();
	
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	FHitResult LineTraceFromView(float Distance);

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookUpAtRate(float Value);
	void TurnAtRate(float Value);
};
