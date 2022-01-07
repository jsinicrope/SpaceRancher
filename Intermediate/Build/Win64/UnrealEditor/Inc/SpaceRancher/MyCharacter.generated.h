// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
struct FVector;
struct FItem_Struct;
class UHUDSetting;
class UInventoryComponent;
#ifdef SPACERANCHER_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define SPACERANCHER_MyCharacter_generated_h

#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_SPARSE_DATA
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_RPC_WRAPPERS \
	virtual void OnSelectedItemChanged_Implementation(FItem_Struct& Item); \
	virtual void PrimaryActionReleased_Implementation(); \
	virtual void PrimaryActionPressed_Implementation(); \
 \
	DECLARE_FUNCTION(execLineTraceFromView); \
	DECLARE_FUNCTION(execCheckForInteractable); \
	DECLARE_FUNCTION(execGetViewForwardVector); \
	DECLARE_FUNCTION(execGetViewPoint); \
	DECLARE_FUNCTION(execRemoveWidgetFromViewport); \
	DECLARE_FUNCTION(execGetSelectedItem); \
	DECLARE_FUNCTION(execCloseRadialMenu); \
	DECLARE_FUNCTION(execOpenRadialMenu); \
	DECLARE_FUNCTION(execToggleInventory); \
	DECLARE_FUNCTION(execRemoveInventoryItemByName); \
	DECLARE_FUNCTION(execRemoveInventoryItem); \
	DECLARE_FUNCTION(execAddInventoryItem); \
	DECLARE_FUNCTION(execLoad); \
	DECLARE_FUNCTION(execSave); \
	DECLARE_FUNCTION(execGetIsPlayerDead); \
	DECLARE_FUNCTION(execRespawnPlayer); \
	DECLARE_FUNCTION(execKillPlayer); \
	DECLARE_FUNCTION(execDamagePlayer); \
	DECLARE_FUNCTION(execPlayerInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint); \
	DECLARE_FUNCTION(execZoomMiniMapOut); \
	DECLARE_FUNCTION(execZoomMiniMapIn); \
	DECLARE_FUNCTION(execZoomMiniMap); \
	DECLARE_FUNCTION(execGetHUDController); \
	DECLARE_FUNCTION(execGetInventoryComp); \
	DECLARE_FUNCTION(execGetMaxStamina); \
	DECLARE_FUNCTION(execGetStamina); \
	DECLARE_FUNCTION(execGetMaxHealth); \
	DECLARE_FUNCTION(execGetHealth); \
	DECLARE_FUNCTION(execOnSelectedItemChanged); \
	DECLARE_FUNCTION(execUnEquipItem); \
	DECLARE_FUNCTION(execUpdateSelectedItem); \
	DECLARE_FUNCTION(execPrimaryActionReleased); \
	DECLARE_FUNCTION(execPrimaryActionPressed);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnSelectedItemChanged_Implementation(FItem_Struct& Item); \
	virtual void PrimaryActionReleased_Implementation(); \
	virtual void PrimaryActionPressed_Implementation(); \
 \
	DECLARE_FUNCTION(execLineTraceFromView); \
	DECLARE_FUNCTION(execCheckForInteractable); \
	DECLARE_FUNCTION(execGetViewForwardVector); \
	DECLARE_FUNCTION(execGetViewPoint); \
	DECLARE_FUNCTION(execRemoveWidgetFromViewport); \
	DECLARE_FUNCTION(execGetSelectedItem); \
	DECLARE_FUNCTION(execCloseRadialMenu); \
	DECLARE_FUNCTION(execOpenRadialMenu); \
	DECLARE_FUNCTION(execToggleInventory); \
	DECLARE_FUNCTION(execRemoveInventoryItemByName); \
	DECLARE_FUNCTION(execRemoveInventoryItem); \
	DECLARE_FUNCTION(execAddInventoryItem); \
	DECLARE_FUNCTION(execLoad); \
	DECLARE_FUNCTION(execSave); \
	DECLARE_FUNCTION(execGetIsPlayerDead); \
	DECLARE_FUNCTION(execRespawnPlayer); \
	DECLARE_FUNCTION(execKillPlayer); \
	DECLARE_FUNCTION(execDamagePlayer); \
	DECLARE_FUNCTION(execPlayerInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint); \
	DECLARE_FUNCTION(execZoomMiniMapOut); \
	DECLARE_FUNCTION(execZoomMiniMapIn); \
	DECLARE_FUNCTION(execZoomMiniMap); \
	DECLARE_FUNCTION(execGetHUDController); \
	DECLARE_FUNCTION(execGetInventoryComp); \
	DECLARE_FUNCTION(execGetMaxStamina); \
	DECLARE_FUNCTION(execGetStamina); \
	DECLARE_FUNCTION(execGetMaxHealth); \
	DECLARE_FUNCTION(execGetHealth); \
	DECLARE_FUNCTION(execOnSelectedItemChanged); \
	DECLARE_FUNCTION(execUnEquipItem); \
	DECLARE_FUNCTION(execUpdateSelectedItem); \
	DECLARE_FUNCTION(execPrimaryActionReleased); \
	DECLARE_FUNCTION(execPrimaryActionPressed);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_EVENT_PARMS \
	struct MyCharacter_eventOnSelectedItemChanged_Parms \
	{ \
		FItem_Struct Item; \
	};


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_CALLBACK_WRAPPERS
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(AMyCharacter, Health); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(AMyCharacter, MaxHealth); } \
	FORCEINLINE static uint32 __PPO__HealthRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, HealthRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__MaxRegeneratableHealth() { return STRUCT_OFFSET(AMyCharacter, MaxRegeneratableHealth); } \
	FORCEINLINE static uint32 __PPO__TimeToHealthRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToHealthRegen); } \
	FORCEINLINE static uint32 __PPO__bPlayerDead() { return STRUCT_OFFSET(AMyCharacter, bPlayerDead); } \
	FORCEINLINE static uint32 __PPO__bDamaged() { return STRUCT_OFFSET(AMyCharacter, bDamaged); } \
	FORCEINLINE static uint32 __PPO__Stamina() { return STRUCT_OFFSET(AMyCharacter, Stamina); } \
	FORCEINLINE static uint32 __PPO__MaxStamina() { return STRUCT_OFFSET(AMyCharacter, MaxStamina); } \
	FORCEINLINE static uint32 __PPO__StaminaRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, StaminaRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__StaminaLossRunning() { return STRUCT_OFFSET(AMyCharacter, StaminaLossRunning); } \
	FORCEINLINE static uint32 __PPO__TimeToStaminaRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToStaminaRegen); } \
	FORCEINLINE static uint32 __PPO__BaseTurnAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseTurnAtRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseLookUpAtRate); } \
	FORCEINLINE static uint32 __PPO__WalkSpeed() { return STRUCT_OFFSET(AMyCharacter, WalkSpeed); } \
	FORCEINLINE static uint32 __PPO__SprintSpeed() { return STRUCT_OFFSET(AMyCharacter, SprintSpeed); } \
	FORCEINLINE static uint32 __PPO__bSprinting() { return STRUCT_OFFSET(AMyCharacter, bSprinting); } \
	FORCEINLINE static uint32 __PPO__CurrentVelocity() { return STRUCT_OFFSET(AMyCharacter, CurrentVelocity); } \
	FORCEINLINE static uint32 __PPO__FallingTime() { return STRUCT_OFFSET(AMyCharacter, FallingTime); } \
	FORCEINLINE static uint32 __PPO__FallDamageFactor() { return STRUCT_OFFSET(AMyCharacter, FallDamageFactor); } \
	FORCEINLINE static uint32 __PPO__MinFallDamageVelocity() { return STRUCT_OFFSET(AMyCharacter, MinFallDamageVelocity); } \
	FORCEINLINE static uint32 __PPO__InteractDistance() { return STRUCT_OFFSET(AMyCharacter, InteractDistance); } \
	FORCEINLINE static uint32 __PPO__bInteractableInRange() { return STRUCT_OFFSET(AMyCharacter, bInteractableInRange); } \
	FORCEINLINE static uint32 __PPO__RespawnPoint() { return STRUCT_OFFSET(AMyCharacter, RespawnPoint); } \
	FORCEINLINE static uint32 __PPO__RespawnViewDirection() { return STRUCT_OFFSET(AMyCharacter, RespawnViewDirection); } \
	FORCEINLINE static uint32 __PPO__bInventoryOpen() { return STRUCT_OFFSET(AMyCharacter, bInventoryOpen); } \
	FORCEINLINE static uint32 __PPO__bItemSelectionOpen() { return STRUCT_OFFSET(AMyCharacter, bItemSelectionOpen); } \
	FORCEINLINE static uint32 __PPO__SelectedItem() { return STRUCT_OFFSET(AMyCharacter, SelectedItem); } \
	FORCEINLINE static uint32 __PPO__DefaultMiniMapSize() { return STRUCT_OFFSET(AMyCharacter, DefaultMiniMapSize); } \
	FORCEINLINE static uint32 __PPO__DefaultZoomLevel() { return STRUCT_OFFSET(AMyCharacter, DefaultZoomLevel); } \
	FORCEINLINE static uint32 __PPO__ZoomLevel() { return STRUCT_OFFSET(AMyCharacter, ZoomLevel); } \
	FORCEINLINE static uint32 __PPO__MaxZoomLevel() { return STRUCT_OFFSET(AMyCharacter, MaxZoomLevel); } \
	FORCEINLINE static uint32 __PPO__ZoomSize() { return STRUCT_OFFSET(AMyCharacter, ZoomSize); } \
	FORCEINLINE static uint32 __PPO__WidgetToRemove() { return STRUCT_OFFSET(AMyCharacter, WidgetToRemove); } \
	FORCEINLINE static uint32 __PPO__GameInstance() { return STRUCT_OFFSET(AMyCharacter, GameInstance); } \
	FORCEINLINE static uint32 __PPO__PC() { return STRUCT_OFFSET(AMyCharacter, PC); } \
	FORCEINLINE static uint32 __PPO__TimerHandler() { return STRUCT_OFFSET(AMyCharacter, TimerHandler); } \
	FORCEINLINE static uint32 __PPO__ElapsedDamageTime() { return STRUCT_OFFSET(AMyCharacter, ElapsedDamageTime); } \
	FORCEINLINE static uint32 __PPO__ElapsedStaminaDrainTime() { return STRUCT_OFFSET(AMyCharacter, ElapsedStaminaDrainTime); } \
	FORCEINLINE static uint32 __PPO__HealthLastTick() { return STRUCT_OFFSET(AMyCharacter, HealthLastTick); } \
	FORCEINLINE static uint32 __PPO__JumpStartPoint() { return STRUCT_OFFSET(AMyCharacter, JumpStartPoint); } \
	FORCEINLINE static uint32 __PPO__InventoryComp() { return STRUCT_OFFSET(AMyCharacter, InventoryComp); } \
	FORCEINLINE static uint32 __PPO__WidgetInteractionComponent() { return STRUCT_OFFSET(AMyCharacter, WidgetInteractionComponent); } \
	FORCEINLINE static uint32 __PPO__PlayerCamera() { return STRUCT_OFFSET(AMyCharacter, PlayerCamera); } \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AMyCharacter, SpringArm); } \
	FORCEINLINE static uint32 __PPO__MiniMapCamera() { return STRUCT_OFFSET(AMyCharacter, MiniMapCamera); } \
	FORCEINLINE static uint32 __PPO__MiniMapCapture() { return STRUCT_OFFSET(AMyCharacter, MiniMapCapture); } \
	FORCEINLINE static uint32 __PPO__HeldItem() { return STRUCT_OFFSET(AMyCharacter, HeldItem); } \
	FORCEINLINE static uint32 __PPO__HandItem() { return STRUCT_OFFSET(AMyCharacter, HandItem); } \
	FORCEINLINE static uint32 __PPO__HUDController() { return STRUCT_OFFSET(AMyCharacter, HUDController); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_PROLOG \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_EVENT_PARMS


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_RPC_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_CALLBACK_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_INCLASS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_CALLBACK_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_INCLASS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACERANCHER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
