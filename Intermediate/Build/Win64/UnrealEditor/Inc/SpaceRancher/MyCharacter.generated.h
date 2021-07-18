// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPACERANCHER_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define SPACERANCHER_MyCharacter_generated_h

#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_SPARSE_DATA
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInteract); \
	DECLARE_FUNCTION(execPlayerStopSprint); \
	DECLARE_FUNCTION(execPlayerStartSprint);


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_STANDARD_CONSTRUCTORS \
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


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BaseTurnAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseTurnAtRate); } \
	FORCEINLINE static uint32 __PPO__BaseLookUpAtRate() { return STRUCT_OFFSET(AMyCharacter, BaseLookUpAtRate); } \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(AMyCharacter, Health); } \
	FORCEINLINE static uint32 __PPO__Stamina() { return STRUCT_OFFSET(AMyCharacter, Stamina); } \
	FORCEINLINE static uint32 __PPO__HealthRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, HealthRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__bDamaged() { return STRUCT_OFFSET(AMyCharacter, bDamaged); } \
	FORCEINLINE static uint32 __PPO__WalkSpeed() { return STRUCT_OFFSET(AMyCharacter, WalkSpeed); } \
	FORCEINLINE static uint32 __PPO__SprintSpeed() { return STRUCT_OFFSET(AMyCharacter, SprintSpeed); } \
	FORCEINLINE static uint32 __PPO__bSprinting() { return STRUCT_OFFSET(AMyCharacter, bSprinting); } \
	FORCEINLINE static uint32 __PPO__StaminaLossRunning() { return STRUCT_OFFSET(AMyCharacter, StaminaLossRunning); } \
	FORCEINLINE static uint32 __PPO__StaminaBaseRegen() { return STRUCT_OFFSET(AMyCharacter, StaminaBaseRegen); } \
	FORCEINLINE static uint32 __PPO__TimeToHealthRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToHealthRegen); } \
	FORCEINLINE static uint32 __PPO__TimeToStaminaRegen() { return STRUCT_OFFSET(AMyCharacter, TimeToStaminaRegen); } \
	FORCEINLINE static uint32 __PPO__bCanHarvest() { return STRUCT_OFFSET(AMyCharacter, bCanHarvest); } \
	FORCEINLINE static uint32 __PPO__bItemInRange() { return STRUCT_OFFSET(AMyCharacter, bItemInRange); } \
	FORCEINLINE static uint32 __PPO__InteractDistance() { return STRUCT_OFFSET(AMyCharacter, InteractDistance); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_11_PROLOG
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_RPC_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_INCLASS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_INCLASS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACERANCHER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
