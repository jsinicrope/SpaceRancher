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

#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_SPARSE_DATA
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_RPC_WRAPPERS
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpaceRancher"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_STANDARD_CONSTRUCTORS \
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


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(AMyCharacter, Health); } \
	FORCEINLINE static uint32 __PPO__Stamina() { return STRUCT_OFFSET(AMyCharacter, Stamina); } \
	FORCEINLINE static uint32 __PPO__HealthRegenPerSecond() { return STRUCT_OFFSET(AMyCharacter, HealthRegenPerSecond); } \
	FORCEINLINE static uint32 __PPO__bDamaged() { return STRUCT_OFFSET(AMyCharacter, bDamaged); }


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_9_PROLOG
#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_RPC_WRAPPERS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_INCLASS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_SPARSE_DATA \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
	SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPACERANCHER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SpaceRancher_Source_SpaceRancher_Public_Characters_Main_Character_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
