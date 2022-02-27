// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FHitResult;
struct FItem_Struct;
class UHUDSetting;
class UInventoryComponent;
#ifdef SPACERANCHER_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define SPACERANCHER_MyCharacter_generated_h

#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_SPARSE_DATA
#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_RPC_WRAPPERS \
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


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_EVENT_PARMS \
	struct MyCharacter_eventOnSelectedItemChanged_Parms \
	{ \
		FItem_Struct Item; \
	};


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_CALLBACK_WRAPPERS
#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AMyCharacter*>(this); }


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AMyCharacter*>(this); }


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_STANDARD_CONSTRUCTORS \
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


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_13_PROLOG \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_EVENT_PARMS


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_SPARSE_DATA \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_RPC_WRAPPERS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_CALLBACK_WRAPPERS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_INCLASS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_SPARSE_DATA \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_CALLBACK_WRAPPERS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_INCLASS_NO_PURE_DECLS \
	FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACERANCHER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
