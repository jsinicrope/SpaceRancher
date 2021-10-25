// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FItem_Struct;
#ifdef SPACERANCHER_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define SPACERANCHER_MyCharacter_generated_h

#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_SPARSE_DATA
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCheckForInteractable); \
	DECLARE_FUNCTION(execRemoveWidgetFromViewport); \
	DECLARE_FUNCTION(execToggleInventory); \
	DECLARE_FUNCTION(execRemoveItemFromInventoryByName); \
	DECLARE_FUNCTION(execRemoveItemFromInventory); \
	DECLARE_FUNCTION(execRemoveItemFromInventoryClosestPosition); \
	DECLARE_FUNCTION(execAddItemToInventory); \
	DECLARE_FUNCTION(execLoadPlayerCharacter); \
	DECLARE_FUNCTION(execSavePlayerCharacter); \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execSaveGame); \
	DECLARE_FUNCTION(execbIsPlayerDead); \
	DECLARE_FUNCTION(execRespawnPlayer); \
	DECLARE_FUNCTION(execKillPlayer); \
	DECLARE_FUNCTION(execDamagePlayer); \
	DECLARE_FUNCTION(execPlayerInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCheckForInteractable); \
	DECLARE_FUNCTION(execRemoveWidgetFromViewport); \
	DECLARE_FUNCTION(execToggleInventory); \
	DECLARE_FUNCTION(execRemoveItemFromInventoryByName); \
	DECLARE_FUNCTION(execRemoveItemFromInventory); \
	DECLARE_FUNCTION(execRemoveItemFromInventoryClosestPosition); \
	DECLARE_FUNCTION(execAddItemToInventory); \
	DECLARE_FUNCTION(execLoadPlayerCharacter); \
	DECLARE_FUNCTION(execSavePlayerCharacter); \
	DECLARE_FUNCTION(execLoadGame); \
	DECLARE_FUNCTION(execSaveGame); \
	DECLARE_FUNCTION(execbIsPlayerDead); \
	DECLARE_FUNCTION(execRespawnPlayer); \
	DECLARE_FUNCTION(execKillPlayer); \
	DECLARE_FUNCTION(execDamagePlayer); \
	DECLARE_FUNCTION(execPlayerInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AMyCharacter*>(this); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AMyCharacter*>(this); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
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


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BaseTurnAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseTurnAtRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseLookUpAtRate); } \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(AMyCharacter, Health); } \
	FORCEINLINE static uint32 __PPO__maxHealth() { return STRUCT_OFFSET(AMyCharacter, maxHealth); } \
	FORCEINLINE static uint32 __PPO__MaxRegeneratedHealth() { return STRUCT_OFFSET(AMyCharacter, MaxRegeneratedHealth); } \
	FORCEINLINE static uint32 __PPO__bPlayerDead() { return STRUCT_OFFSET(AMyCharacter, bPlayerDead); } \
	FORCEINLINE static uint32 __PPO__maxStamina() { return STRUCT_OFFSET(AMyCharacter, maxStamina); } \
	FORCEINLINE static uint32 __PPO__Stamina() { return STRUCT_OFFSET(AMyCharacter, Stamina); } \
	FORCEINLINE static uint32 __PPO__HealthRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, HealthRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__bDamaged() { return STRUCT_OFFSET(AMyCharacter, bDamaged); } \
	FORCEINLINE static uint32 __PPO__WalkSpeed() { return STRUCT_OFFSET(AMyCharacter, WalkSpeed); } \
	FORCEINLINE static uint32 __PPO__SprintSpeed() { return STRUCT_OFFSET(AMyCharacter, SprintSpeed); } \
	FORCEINLINE static uint32 __PPO__bSprinting() { return STRUCT_OFFSET(AMyCharacter, bSprinting); } \
	FORCEINLINE static uint32 __PPO__CurrentVelocity() { return STRUCT_OFFSET(AMyCharacter, CurrentVelocity); } \
	FORCEINLINE static uint32 __PPO__StaminaLossRunning() { return STRUCT_OFFSET(AMyCharacter, StaminaLossRunning); } \
	FORCEINLINE static uint32 __PPO__StaminaRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, StaminaRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__TimeToHealthRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToHealthRegen); } \
	FORCEINLINE static uint32 __PPO__TimeToStaminaRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToStaminaRegen); } \
	FORCEINLINE static uint32 __PPO__FallingTime() { return STRUCT_OFFSET(AMyCharacter, FallingTime); } \
	FORCEINLINE static uint32 __PPO__FallDamageFactor() { return STRUCT_OFFSET(AMyCharacter, FallDamageFactor); } \
	FORCEINLINE static uint32 __PPO__MinFallDamageVelocity() { return STRUCT_OFFSET(AMyCharacter, MinFallDamageVelocity); } \
	FORCEINLINE static uint32 __PPO__bCanHarvest() { return STRUCT_OFFSET(AMyCharacter, bCanHarvest); } \
	FORCEINLINE static uint32 __PPO__bItemInRange() { return STRUCT_OFFSET(AMyCharacter, bItemInRange); } \
	FORCEINLINE static uint32 __PPO__InteractDistance() { return STRUCT_OFFSET(AMyCharacter, InteractDistance); } \
	FORCEINLINE static uint32 __PPO__bInteractableInRange() { return STRUCT_OFFSET(AMyCharacter, bInteractableInRange); } \
	FORCEINLINE static uint32 __PPO__RespawnPoint() { return STRUCT_OFFSET(AMyCharacter, RespawnPoint); } \
	FORCEINLINE static uint32 __PPO__RespawnViewDirection() { return STRUCT_OFFSET(AMyCharacter, RespawnViewDirection); } \
	FORCEINLINE static uint32 __PPO__InteractPopUpClass() { return STRUCT_OFFSET(AMyCharacter, InteractPopUpClass); } \
	FORCEINLINE static uint32 __PPO__InteractPopUp() { return STRUCT_OFFSET(AMyCharacter, InteractPopUp); } \
	FORCEINLINE static uint32 __PPO__ItemPickUpWidgetClass() { return STRUCT_OFFSET(AMyCharacter, ItemPickUpWidgetClass); } \
	FORCEINLINE static uint32 __PPO__ItemPickUpWidget() { return STRUCT_OFFSET(AMyCharacter, ItemPickUpWidget); } \
	FORCEINLINE static uint32 __PPO__WidgetToRemove() { return STRUCT_OFFSET(AMyCharacter, WidgetToRemove); } \
	FORCEINLINE static uint32 __PPO__ClockWidgetClass() { return STRUCT_OFFSET(AMyCharacter, ClockWidgetClass); } \
	FORCEINLINE static uint32 __PPO__ClockWidget() { return STRUCT_OFFSET(AMyCharacter, ClockWidget); } \
	FORCEINLINE static uint32 __PPO__GameInstance() { return STRUCT_OFFSET(AMyCharacter, GameInstance); } \
	FORCEINLINE static uint32 __PPO__PC() { return STRUCT_OFFSET(AMyCharacter, PC); } \
	FORCEINLINE static uint32 __PPO__TimerHandler() { return STRUCT_OFFSET(AMyCharacter, TimerHandler); } \
	FORCEINLINE static uint32 __PPO__ElapsedDamageTime() { return STRUCT_OFFSET(AMyCharacter, ElapsedDamageTime); } \
	FORCEINLINE static uint32 __PPO__ElapsedStaminaDrainTime() { return STRUCT_OFFSET(AMyCharacter, ElapsedStaminaDrainTime); } \
	FORCEINLINE static uint32 __PPO__HealthLastTick() { return STRUCT_OFFSET(AMyCharacter, HealthLastTick); } \
	FORCEINLINE static uint32 __PPO__JumpStartPoint() { return STRUCT_OFFSET(AMyCharacter, JumpStartPoint); } \
	FORCEINLINE static uint32 __PPO__InventoryComp() { return STRUCT_OFFSET(AMyCharacter, InventoryComp); } \
	FORCEINLINE static uint32 __PPO__bInventoryOpen() { return STRUCT_OFFSET(AMyCharacter, bInventoryOpen); } \
	FORCEINLINE static uint32 __PPO__MainHUD() { return STRUCT_OFFSET(AMyCharacter, MainHUD); } \
	FORCEINLINE static uint32 __PPO__PlayerCamera() { return STRUCT_OFFSET(AMyCharacter, PlayerCamera); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_17_PROLOG
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_RPC_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_INCLASS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACERANCHER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
