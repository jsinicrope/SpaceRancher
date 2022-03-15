// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpaceRancher_init() {}
	SPACERANCHER_API UFunction* Z_Construct_UDelegateFunction_SpaceRancher_OnItemDestroyed__DelegateSignature();
	SPACERANCHER_API UFunction* Z_Construct_UDelegateFunction_SpaceRancher_OnItemSpawned__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SpaceRancher;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SpaceRancher()
	{
		if (!Z_Registration_Info_UPackage__Script_SpaceRancher.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SpaceRancher_OnItemDestroyed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SpaceRancher_OnItemSpawned__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SpaceRancher",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x27770B6A,
				0x7CFD466F,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SpaceRancher.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SpaceRancher.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SpaceRancher(Z_Construct_UPackage__Script_SpaceRancher, TEXT("/Script/SpaceRancher"), Z_Registration_Info_UPackage__Script_SpaceRancher, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x27770B6A, 0x7CFD466F));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
