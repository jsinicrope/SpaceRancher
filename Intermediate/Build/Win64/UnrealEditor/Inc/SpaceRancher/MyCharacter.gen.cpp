// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpaceRancher/Public/Characters/Main Character/MyCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacter() {}
// Cross Module References
	SPACERANCHER_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
	SPACERANCHER_API UClass* Z_Construct_UClass_AMyCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_SpaceRancher();
	SPACERANCHER_API UScriptStruct* Z_Construct_UScriptStruct_FItem_Struct();
	SPACERANCHER_API UClass* Z_Construct_UClass_UHUDSetting_NoRegister();
	SPACERANCHER_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	SPACERANCHER_API UClass* Z_Construct_UClass_UMainGameInstance_NoRegister();
	SPACERANCHER_API UClass* Z_Construct_UClass_ACppPlayerController_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	UMG_API UClass* Z_Construct_UClass_UWidgetInteractionComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UChildActorComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMyCharacter::execCheckForInteractable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CheckForInteractable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetViewForwardVector)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetViewForwardVector();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetViewPoint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetViewPoint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execRemoveWidgetFromViewport)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveWidgetFromViewport();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetSelectedItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FItem_Struct*)Z_Param__Result=P_THIS->GetSelectedItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execCloseRadialMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseRadialMenu();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execOpenRadialMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenRadialMenu();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execToggleInventory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleInventory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execRemoveItemFromInventoryByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ItemName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FItem_Struct*)Z_Param__Result=P_THIS->RemoveItemFromInventoryByName(Z_Param_ItemName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execRemoveItemFromInventory)
	{
		P_GET_STRUCT_REF(FItem_Struct,Z_Param_Out_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FItem_Struct*)Z_Param__Result=P_THIS->RemoveItemFromInventory(Z_Param_Out_Item);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execRemoveItemFromInventoryFromPosition)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_column);
		P_GET_PROPERTY(FIntProperty,Z_Param_row);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FItem_Struct*)Z_Param__Result=P_THIS->RemoveItemFromInventoryFromPosition(Z_Param_column,Z_Param_row);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execAddItemToInventory)
	{
		P_GET_STRUCT_REF(FItem_Struct,Z_Param_Out_Item_Struct);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddItemToInventory(Z_Param_Out_Item_Struct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execLoadPlayerCharacter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadPlayerCharacter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execSavePlayerCharacter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SavePlayerCharacter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execLoadGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadGame();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execSaveGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveGame();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetIsPlayerDead)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsPlayerDead();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execRespawnPlayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RespawnPlayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execKillPlayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->KillPlayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execDamagePlayer)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DamagePlayer(Z_Param_Damage);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execPlayerInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayerInteract();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execPlayerStopSprint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayerStopSprint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execPlayerStartSprint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayerStartSprint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execZoomMiniMapOut)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZoomMiniMapOut();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execZoomMiniMapIn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZoomMiniMapIn();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execZoomMiniMap)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZoomMiniMap(Z_Param_Level);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetHUDController)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UHUDSetting**)Z_Param__Result=P_THIS->GetHUDController();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetInventoryComp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UInventoryComponent**)Z_Param__Result=P_THIS->GetInventoryComp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetMaxStamina)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxStamina();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetStamina)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetStamina();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetMaxHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxHealth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execGetHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetHealth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execOnSelectedItemChanged)
	{
		P_GET_STRUCT_REF(FItem_Struct,Z_Param_Out_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSelectedItemChanged_Implementation(Z_Param_Out_Item);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execUnEquipItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnEquipItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execUpdateSelectedItem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSelectedItem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execPrimaryActionReleased)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PrimaryActionReleased_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyCharacter::execPrimaryActionPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PrimaryActionPressed_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AMyCharacter_OnSelectedItemChanged = FName(TEXT("OnSelectedItemChanged"));
	void AMyCharacter::OnSelectedItemChanged(FItem_Struct& Item)
	{
		MyCharacter_eventOnSelectedItemChanged_Parms Parms;
		Parms.Item=Item;
		ProcessEvent(FindFunctionChecked(NAME_AMyCharacter_OnSelectedItemChanged),&Parms);
		Item=Parms.Item;
	}
	static FName NAME_AMyCharacter_PrimaryActionPressed = FName(TEXT("PrimaryActionPressed"));
	void AMyCharacter::PrimaryActionPressed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMyCharacter_PrimaryActionPressed),NULL);
	}
	static FName NAME_AMyCharacter_PrimaryActionReleased = FName(TEXT("PrimaryActionReleased"));
	void AMyCharacter::PrimaryActionReleased()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMyCharacter_PrimaryActionReleased),NULL);
	}
	void AMyCharacter::StaticRegisterNativesAMyCharacter()
	{
		UClass* Class = AMyCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItemToInventory", &AMyCharacter::execAddItemToInventory },
			{ "CheckForInteractable", &AMyCharacter::execCheckForInteractable },
			{ "CloseRadialMenu", &AMyCharacter::execCloseRadialMenu },
			{ "DamagePlayer", &AMyCharacter::execDamagePlayer },
			{ "GetHealth", &AMyCharacter::execGetHealth },
			{ "GetHUDController", &AMyCharacter::execGetHUDController },
			{ "GetInventoryComp", &AMyCharacter::execGetInventoryComp },
			{ "GetIsPlayerDead", &AMyCharacter::execGetIsPlayerDead },
			{ "GetMaxHealth", &AMyCharacter::execGetMaxHealth },
			{ "GetMaxStamina", &AMyCharacter::execGetMaxStamina },
			{ "GetSelectedItem", &AMyCharacter::execGetSelectedItem },
			{ "GetStamina", &AMyCharacter::execGetStamina },
			{ "GetViewForwardVector", &AMyCharacter::execGetViewForwardVector },
			{ "GetViewPoint", &AMyCharacter::execGetViewPoint },
			{ "KillPlayer", &AMyCharacter::execKillPlayer },
			{ "LoadGame", &AMyCharacter::execLoadGame },
			{ "LoadPlayerCharacter", &AMyCharacter::execLoadPlayerCharacter },
			{ "OnSelectedItemChanged", &AMyCharacter::execOnSelectedItemChanged },
			{ "OpenRadialMenu", &AMyCharacter::execOpenRadialMenu },
			{ "PlayerInteract", &AMyCharacter::execPlayerInteract },
			{ "PlayerStartSprint", &AMyCharacter::execPlayerStartSprint },
			{ "PlayerStopSprint", &AMyCharacter::execPlayerStopSprint },
			{ "PrimaryActionPressed", &AMyCharacter::execPrimaryActionPressed },
			{ "PrimaryActionReleased", &AMyCharacter::execPrimaryActionReleased },
			{ "RemoveItemFromInventory", &AMyCharacter::execRemoveItemFromInventory },
			{ "RemoveItemFromInventoryByName", &AMyCharacter::execRemoveItemFromInventoryByName },
			{ "RemoveItemFromInventoryFromPosition", &AMyCharacter::execRemoveItemFromInventoryFromPosition },
			{ "RemoveWidgetFromViewport", &AMyCharacter::execRemoveWidgetFromViewport },
			{ "RespawnPlayer", &AMyCharacter::execRespawnPlayer },
			{ "SaveGame", &AMyCharacter::execSaveGame },
			{ "SavePlayerCharacter", &AMyCharacter::execSavePlayerCharacter },
			{ "ToggleInventory", &AMyCharacter::execToggleInventory },
			{ "UnEquipItem", &AMyCharacter::execUnEquipItem },
			{ "UpdateSelectedItem", &AMyCharacter::execUpdateSelectedItem },
			{ "ZoomMiniMap", &AMyCharacter::execZoomMiniMap },
			{ "ZoomMiniMapIn", &AMyCharacter::execZoomMiniMapIn },
			{ "ZoomMiniMapOut", &AMyCharacter::execZoomMiniMapOut },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics
	{
		struct MyCharacter_eventAddItemToInventory_Parms
		{
			FItem_Struct Item_Struct;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Item_Struct;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_Item_Struct = { "Item_Struct", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventAddItemToInventory_Parms, Item_Struct), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyCharacter_eventAddItemToInventory_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacter_eventAddItemToInventory_Parms), &Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_Item_Struct,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "AddItemToInventory", nullptr, nullptr, sizeof(MyCharacter_eventAddItemToInventory_Parms), Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_AddItemToInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_AddItemToInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics
	{
		struct MyCharacter_eventCheckForInteractable_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyCharacter_eventCheckForInteractable_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacter_eventCheckForInteractable_Parms), &Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interaction" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "CheckForInteractable", nullptr, nullptr, sizeof(MyCharacter_eventCheckForInteractable_Parms), Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_CheckForInteractable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_CheckForInteractable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "ItemSelection" },
		{ "Comment", "// Closes the RadialMenu\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Closes the RadialMenu" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "CloseRadialMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_CloseRadialMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_CloseRadialMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics
	{
		struct MyCharacter_eventDamagePlayer_Parms
		{
			float Damage;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventDamagePlayer_Parms, Damage), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::NewProp_Damage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "DamagePlayer", nullptr, nullptr, sizeof(MyCharacter_eventDamagePlayer_Parms), Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_DamagePlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_DamagePlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetHealth_Statics
	{
		struct MyCharacter_eventGetHealth_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Health" },
		{ "Comment", "// Functions\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetHealth", nullptr, nullptr, sizeof(MyCharacter_eventGetHealth_Parms), Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics
	{
		struct MyCharacter_eventGetHUDController_Parms
		{
			UHUDSetting* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetHUDController_Parms, ReturnValue), Z_Construct_UClass_UHUDSetting_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetHUDController", nullptr, nullptr, sizeof(MyCharacter_eventGetHUDController_Parms), Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetHUDController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetHUDController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics
	{
		struct MyCharacter_eventGetInventoryComp_Parms
		{
			UInventoryComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetInventoryComp_Parms, ReturnValue), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetInventoryComp", nullptr, nullptr, sizeof(MyCharacter_eventGetInventoryComp_Parms), Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetInventoryComp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetInventoryComp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics
	{
		struct MyCharacter_eventGetIsPlayerDead_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyCharacter_eventGetIsPlayerDead_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyCharacter_eventGetIsPlayerDead_Parms), &Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetIsPlayerDead", nullptr, nullptr, sizeof(MyCharacter_eventGetIsPlayerDead_Parms), Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics
	{
		struct MyCharacter_eventGetMaxHealth_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetMaxHealth", nullptr, nullptr, sizeof(MyCharacter_eventGetMaxHealth_Parms), Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetMaxHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetMaxHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics
	{
		struct MyCharacter_eventGetMaxStamina_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetMaxStamina_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetMaxStamina", nullptr, nullptr, sizeof(MyCharacter_eventGetMaxStamina_Parms), Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetMaxStamina()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetMaxStamina_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics
	{
		struct MyCharacter_eventGetSelectedItem_Parms
		{
			FItem_Struct ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetSelectedItem_Parms, ReturnValue), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetSelectedItem", nullptr, nullptr, sizeof(MyCharacter_eventGetSelectedItem_Parms), Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetSelectedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetSelectedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetStamina_Statics
	{
		struct MyCharacter_eventGetStamina_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetStamina_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetStamina", nullptr, nullptr, sizeof(MyCharacter_eventGetStamina_Parms), Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetStamina()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetStamina_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics
	{
		struct MyCharacter_eventGetViewForwardVector_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetViewForwardVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetViewForwardVector", nullptr, nullptr, sizeof(MyCharacter_eventGetViewForwardVector_Parms), Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetViewForwardVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetViewForwardVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics
	{
		struct MyCharacter_eventGetViewPoint_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventGetViewPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "GetViewPoint", nullptr, nullptr, sizeof(MyCharacter_eventGetViewPoint_Parms), Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_GetViewPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_GetViewPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "KillPlayer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_KillPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_KillPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_LoadGame_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_LoadGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveGame" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_LoadGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "LoadGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_LoadGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_LoadGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_LoadGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_LoadGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveGame" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "LoadPlayerCharacter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Item;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventOnSelectedItemChanged_Parms, Item), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::NewProp_Item,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "OnSelectedItemChanged", nullptr, nullptr, sizeof(MyCharacter_eventOnSelectedItemChanged_Parms), Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08480C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "ItemSelection" },
		{ "Comment", "/** Opens the RadialMenu\n\x09 * Does not open the menu if other interactable widgets are active on screen */" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Opens the RadialMenu\nDoes not open the menu if other interactable widgets are active on screen" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "OpenRadialMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_OpenRadialMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_OpenRadialMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom Functions" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "PlayerInteract", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_PlayerInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_PlayerInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom Functions" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "PlayerStartSprint", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_PlayerStartSprint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_PlayerStartSprint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom Functions" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "PlayerStopSprint", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_PlayerStopSprint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_PlayerStopSprint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Functions\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Functions" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "PrimaryActionPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "PrimaryActionReleased", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics
	{
		struct MyCharacter_eventRemoveItemFromInventory_Parms
		{
			FItem_Struct Item;
			FItem_Struct ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Item;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventory_Parms, Item), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventory_Parms, ReturnValue), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "RemoveItemFromInventory", nullptr, nullptr, sizeof(MyCharacter_eventRemoveItemFromInventory_Parms), Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics
	{
		struct MyCharacter_eventRemoveItemFromInventoryByName_Parms
		{
			FString ItemName;
			FItem_Struct ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventoryByName_Parms, ItemName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventoryByName_Parms, ReturnValue), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::NewProp_ItemName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "RemoveItemFromInventoryByName", nullptr, nullptr, sizeof(MyCharacter_eventRemoveItemFromInventoryByName_Parms), Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics
	{
		struct MyCharacter_eventRemoveItemFromInventoryFromPosition_Parms
		{
			int32 column;
			int32 row;
			FItem_Struct ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_column;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_row;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_column = { "column", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventoryFromPosition_Parms, column), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_row = { "row", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventoryFromPosition_Parms, row), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventRemoveItemFromInventoryFromPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_column,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_row,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "RemoveItemFromInventoryFromPosition", nullptr, nullptr, sizeof(MyCharacter_eventRemoveItemFromInventoryFromPosition_Parms), Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics::Function_MetaDataParams[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "RemoveWidgetFromViewport", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "RespawnPlayer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_RespawnPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_RespawnPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_SaveGame_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_SaveGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveGame" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_SaveGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "SaveGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_SaveGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_SaveGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_SaveGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_SaveGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveGame" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "SavePlayerCharacter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "ToggleInventory", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_ToggleInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_ToggleInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "UnEquipItem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_UnEquipItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_UnEquipItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "UpdateSelectedItem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics
	{
		struct MyCharacter_eventZoomMiniMap_Parms
		{
			int32 Level;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Level;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::NewProp_Level_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyCharacter_eventZoomMiniMap_Parms, Level), METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::NewProp_Level_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::NewProp_Level_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::NewProp_Level,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "MiniMap" },
		{ "Comment", "// Zoom in or out of the MiniMap\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Zoom in or out of the MiniMap" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "ZoomMiniMap", nullptr, nullptr, sizeof(MyCharacter_eventZoomMiniMap_Parms), Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_ZoomMiniMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_ZoomMiniMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics::Function_MetaDataParams[] = {
		{ "Category", "MiniMap" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "ZoomMiniMapIn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics::Function_MetaDataParams[] = {
		{ "Category", "MiniMap" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyCharacter, nullptr, "ZoomMiniMapOut", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyCharacter_NoRegister()
	{
		return AMyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthRegenPerSecond_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthRegenPerSecond;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRegeneratedHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRegeneratedHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeToHealthRegen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeToHealthRegen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerDead_MetaData[];
#endif
		static void NewProp_bPlayerDead_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerDead;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDamaged_MetaData[];
#endif
		static void NewProp_bDamaged_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDamaged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaminaRegenPerSecond_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaRegenPerSecond;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaminaLossRunning_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StaminaLossRunning;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeToStaminaRegen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeToStaminaRegen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseTurnAtRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseTurnAtRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpAtRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpAtRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSprinting_MetaData[];
#endif
		static void NewProp_bSprinting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSprinting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentVelocity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentVelocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FallingTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FallingTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FallDamageFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FallDamageFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinFallDamageVelocity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinFallDamageVelocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCanHarvest_MetaData[];
#endif
		static void NewProp_bCanHarvest_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanHarvest;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bItemInRange_MetaData[];
#endif
		static void NewProp_bItemInRange_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bItemInRange;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InteractDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInteractableInRange_MetaData[];
#endif
		static void NewProp_bInteractableInRange_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInteractableInRange;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RespawnPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RespawnPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RespawnViewDirection_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RespawnViewDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInventoryOpen_MetaData[];
#endif
		static void NewProp_bInventoryOpen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInventoryOpen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bItemSelectionOpen_MetaData[];
#endif
		static void NewProp_bItemSelectionOpen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bItemSelectionOpen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedItem_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMiniMapSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultMiniMapSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultZoomLevel_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_DefaultZoomLevel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZoomLevel_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ZoomLevel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxZoomLevel_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxZoomLevel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZoomSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ZoomSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetToRemove_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetToRemove;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PC_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PC;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimerHandler_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TimerHandler;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ElapsedDamageTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedDamageTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ElapsedStaminaDrainTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ElapsedStaminaDrainTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthLastTick_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthLastTick;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpStartPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_JumpStartPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetInteractionComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetInteractionComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MiniMapCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MiniMapCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MiniMapCapture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MiniMapCapture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HeldItem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HeldItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HandItem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HandItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HUDController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDController;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SpaceRancher,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyCharacter_AddItemToInventory, "AddItemToInventory" }, // 2497367192
		{ &Z_Construct_UFunction_AMyCharacter_CheckForInteractable, "CheckForInteractable" }, // 786451081
		{ &Z_Construct_UFunction_AMyCharacter_CloseRadialMenu, "CloseRadialMenu" }, // 1215133628
		{ &Z_Construct_UFunction_AMyCharacter_DamagePlayer, "DamagePlayer" }, // 1072611392
		{ &Z_Construct_UFunction_AMyCharacter_GetHealth, "GetHealth" }, // 2176630474
		{ &Z_Construct_UFunction_AMyCharacter_GetHUDController, "GetHUDController" }, // 657435290
		{ &Z_Construct_UFunction_AMyCharacter_GetInventoryComp, "GetInventoryComp" }, // 3176147444
		{ &Z_Construct_UFunction_AMyCharacter_GetIsPlayerDead, "GetIsPlayerDead" }, // 1711621322
		{ &Z_Construct_UFunction_AMyCharacter_GetMaxHealth, "GetMaxHealth" }, // 230594925
		{ &Z_Construct_UFunction_AMyCharacter_GetMaxStamina, "GetMaxStamina" }, // 451992980
		{ &Z_Construct_UFunction_AMyCharacter_GetSelectedItem, "GetSelectedItem" }, // 3900058430
		{ &Z_Construct_UFunction_AMyCharacter_GetStamina, "GetStamina" }, // 950084552
		{ &Z_Construct_UFunction_AMyCharacter_GetViewForwardVector, "GetViewForwardVector" }, // 1928174150
		{ &Z_Construct_UFunction_AMyCharacter_GetViewPoint, "GetViewPoint" }, // 1271686848
		{ &Z_Construct_UFunction_AMyCharacter_KillPlayer, "KillPlayer" }, // 286801584
		{ &Z_Construct_UFunction_AMyCharacter_LoadGame, "LoadGame" }, // 472659649
		{ &Z_Construct_UFunction_AMyCharacter_LoadPlayerCharacter, "LoadPlayerCharacter" }, // 631528198
		{ &Z_Construct_UFunction_AMyCharacter_OnSelectedItemChanged, "OnSelectedItemChanged" }, // 4114401958
		{ &Z_Construct_UFunction_AMyCharacter_OpenRadialMenu, "OpenRadialMenu" }, // 4199420391
		{ &Z_Construct_UFunction_AMyCharacter_PlayerInteract, "PlayerInteract" }, // 1509151083
		{ &Z_Construct_UFunction_AMyCharacter_PlayerStartSprint, "PlayerStartSprint" }, // 215416479
		{ &Z_Construct_UFunction_AMyCharacter_PlayerStopSprint, "PlayerStopSprint" }, // 173474060
		{ &Z_Construct_UFunction_AMyCharacter_PrimaryActionPressed, "PrimaryActionPressed" }, // 3080335046
		{ &Z_Construct_UFunction_AMyCharacter_PrimaryActionReleased, "PrimaryActionReleased" }, // 2502493712
		{ &Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventory, "RemoveItemFromInventory" }, // 1331955064
		{ &Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryByName, "RemoveItemFromInventoryByName" }, // 3959265479
		{ &Z_Construct_UFunction_AMyCharacter_RemoveItemFromInventoryFromPosition, "RemoveItemFromInventoryFromPosition" }, // 3708749207
		{ &Z_Construct_UFunction_AMyCharacter_RemoveWidgetFromViewport, "RemoveWidgetFromViewport" }, // 506083104
		{ &Z_Construct_UFunction_AMyCharacter_RespawnPlayer, "RespawnPlayer" }, // 1838780855
		{ &Z_Construct_UFunction_AMyCharacter_SaveGame, "SaveGame" }, // 2500372366
		{ &Z_Construct_UFunction_AMyCharacter_SavePlayerCharacter, "SavePlayerCharacter" }, // 389760350
		{ &Z_Construct_UFunction_AMyCharacter_ToggleInventory, "ToggleInventory" }, // 3809195433
		{ &Z_Construct_UFunction_AMyCharacter_UnEquipItem, "UnEquipItem" }, // 2222884729
		{ &Z_Construct_UFunction_AMyCharacter_UpdateSelectedItem, "UpdateSelectedItem" }, // 2743363783
		{ &Z_Construct_UFunction_AMyCharacter_ZoomMiniMap, "ZoomMiniMap" }, // 1919235683
		{ &Z_Construct_UFunction_AMyCharacter_ZoomMiniMapIn, "ZoomMiniMapIn" }, // 3350794173
		{ &Z_Construct_UFunction_AMyCharacter_ZoomMiniMapOut, "ZoomMiniMapOut" }, // 3383763005
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Actor Tick Navigation" },
		{ "IncludePath", "Characters/Main Character/MyCharacter.h" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_Health_MetaData[] = {
		{ "BlueprintGetter", "GetHealth" },
		{ "Category", "Health" },
		{ "Comment", "// Health\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Health" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, Health), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "BlueprintGetter", "GetMaxHealth" },
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthRegenPerSecond_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthRegenPerSecond = { "HealthRegenPerSecond", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, HealthRegenPerSecond), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthRegenPerSecond_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthRegenPerSecond_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxRegeneratedHealth_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxRegeneratedHealth = { "MaxRegeneratedHealth", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MaxRegeneratedHealth), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxRegeneratedHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxRegeneratedHealth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToHealthRegen_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToHealthRegen = { "TimeToHealthRegen", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, TimeToHealthRegen), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToHealthRegen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToHealthRegen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead_MetaData[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bPlayerDead = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead = { "bPlayerDead", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged_MetaData[] = {
		{ "Category", "Health" },
		{ "Comment", "// Set to true if player is damaged\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Set to true if player is damaged" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bDamaged = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged = { "bDamaged", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_Stamina_MetaData[] = {
		{ "BlueprintGetter", "GetStamina" },
		{ "Category", "Stamina" },
		{ "Comment", "// Stamina\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Stamina" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, Stamina), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_Stamina_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_Stamina_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxStamina_MetaData[] = {
		{ "BlueprintGetter", "GetMaxStamina" },
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MaxStamina), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxStamina_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxStamina_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaRegenPerSecond_MetaData[] = {
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaRegenPerSecond = { "StaminaRegenPerSecond", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, StaminaRegenPerSecond), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaRegenPerSecond_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaRegenPerSecond_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaLossRunning_MetaData[] = {
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaLossRunning = { "StaminaLossRunning", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, StaminaLossRunning), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaLossRunning_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaLossRunning_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToStaminaRegen_MetaData[] = {
		{ "Category", "Stamina" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToStaminaRegen = { "TimeToStaminaRegen", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, TimeToStaminaRegen), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToStaminaRegen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToStaminaRegen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseTurnAtRate_MetaData[] = {
		{ "Category", "Movement" },
		{ "Comment", "// Movement\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Movement" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseTurnAtRate = { "BaseTurnAtRate", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, BaseTurnAtRate), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseTurnAtRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseTurnAtRate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseLookUpAtRate_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseLookUpAtRate = { "BaseLookUpAtRate", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, BaseLookUpAtRate), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseLookUpAtRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseLookUpAtRate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, WalkSpeed), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WalkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WalkSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, SprintSpeed), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SprintSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SprintSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bSprinting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting = { "bSprinting", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_CurrentVelocity_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_CurrentVelocity = { "CurrentVelocity", nullptr, (EPropertyFlags)0x0020080001000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, CurrentVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_CurrentVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_CurrentVelocity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallingTime_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallingTime = { "FallingTime", nullptr, (EPropertyFlags)0x0020080001000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, FallingTime), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallingTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallingTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallDamageFactor_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallDamageFactor = { "FallDamageFactor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, FallDamageFactor), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallDamageFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallDamageFactor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MinFallDamageVelocity_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MinFallDamageVelocity = { "MinFallDamageVelocity", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MinFallDamageVelocity), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MinFallDamageVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MinFallDamageVelocity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest_MetaData[] = {
		{ "Category", "Interaction" },
		{ "Comment", "// Interaction\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Interaction" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bCanHarvest = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest = { "bCanHarvest", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange_MetaData[] = {
		{ "Category", "Interaction" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bItemInRange = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange = { "bItemInRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_InteractDistance_MetaData[] = {
		{ "Category", "Interaction" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_InteractDistance = { "InteractDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, InteractDistance), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_InteractDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_InteractDistance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange_MetaData[] = {
		{ "Category", "Interaction" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bInteractableInRange = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange = { "bInteractableInRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnPoint_MetaData[] = {
		{ "Category", "Respawn" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnPoint = { "RespawnPoint", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, RespawnPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnViewDirection_MetaData[] = {
		{ "Category", "Respawn" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnViewDirection = { "RespawnViewDirection", nullptr, (EPropertyFlags)0x0020080001000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, RespawnViewDirection), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnViewDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnViewDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bInventoryOpen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen = { "bInventoryOpen", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen_MetaData[] = {
		{ "Category", "ItemSelection" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen_SetBit(void* Obj)
	{
		((AMyCharacter*)Obj)->bItemSelectionOpen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen = { "bItemSelectionOpen", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_SelectedItem_MetaData[] = {
		{ "Category", "ItemSelection" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_SelectedItem = { "SelectedItem", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, SelectedItem), Z_Construct_UScriptStruct_FItem_Struct, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SelectedItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SelectedItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMiniMapSize_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "Comment", "// MiniMap\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "MiniMap" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMiniMapSize = { "DefaultMiniMapSize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, DefaultMiniMapSize), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMiniMapSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMiniMapSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultZoomLevel_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultZoomLevel = { "DefaultZoomLevel", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, DefaultZoomLevel), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultZoomLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultZoomLevel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomLevel_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomLevel = { "ZoomLevel", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, ZoomLevel), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomLevel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxZoomLevel_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxZoomLevel = { "MaxZoomLevel", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MaxZoomLevel), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxZoomLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxZoomLevel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomSize_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "Comment", "// The amount the zoom changes\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "The amount the zoom changes" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomSize = { "ZoomSize", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, ZoomSize), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetToRemove_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetToRemove = { "WidgetToRemove", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, WidgetToRemove), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetToRemove_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetToRemove_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_GameInstance_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_GameInstance = { "GameInstance", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, GameInstance), Z_Construct_UClass_UMainGameInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_GameInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_GameInstance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_PC_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "Comment", "//Variables hidden in Editor\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Variables hidden in Editor" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_PC = { "PC", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, PC), Z_Construct_UClass_ACppPlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_PC_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_PC_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimerHandler_MetaData[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimerHandler = { "TimerHandler", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, TimerHandler), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimerHandler_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimerHandler_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedDamageTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedDamageTime = { "ElapsedDamageTime", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, ElapsedDamageTime), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedDamageTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedDamageTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedStaminaDrainTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedStaminaDrainTime = { "ElapsedStaminaDrainTime", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, ElapsedStaminaDrainTime), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedStaminaDrainTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedStaminaDrainTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthLastTick_MetaData[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthLastTick = { "HealthLastTick", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, HealthLastTick), METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthLastTick_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthLastTick_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpStartPoint_MetaData[] = {
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpStartPoint = { "JumpStartPoint", nullptr, (EPropertyFlags)0x0020080001000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, JumpStartPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpStartPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpStartPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_InventoryComp_MetaData[] = {
		{ "BlueprintGetter", "GetInventoryComp" },
		{ "Category", "Inventory" },
		{ "Comment", "// Components\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Components" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_InventoryComp = { "InventoryComp", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, InventoryComp), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_InventoryComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_InventoryComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetInteractionComponent_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetInteractionComponent = { "WidgetInteractionComponent", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, WidgetInteractionComponent), Z_Construct_UClass_UWidgetInteractionComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetInteractionComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetInteractionComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_PlayerCamera_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_PlayerCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_PlayerCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Category", "MyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCamera_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCamera = { "MiniMapCamera", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MiniMapCamera), Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCapture_MetaData[] = {
		{ "Category", "MiniMap" },
		{ "Comment", "// Mini Map\n" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
		{ "ToolTip", "Mini Map" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCapture = { "MiniMapCapture", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, MiniMapCapture), Z_Construct_UClass_ASceneCapture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCapture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCapture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_HeldItem_MetaData[] = {
		{ "Category", "Handheld" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_HeldItem = { "HeldItem", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, HeldItem), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HeldItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HeldItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_HandItem_MetaData[] = {
		{ "Category", "Handheld" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_HandItem = { "HandItem", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, HandItem), Z_Construct_UClass_UChildActorComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HandItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HandItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacter_Statics::NewProp_HUDController_MetaData[] = {
		{ "BlueprintGetter", "GetHUDController" },
		{ "Category", "HUD" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/Main Character/MyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp_HUDController = { "HUDController", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacter, HUDController), Z_Construct_UClass_UHUDSetting_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HUDController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::NewProp_HUDController_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_Health,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthRegenPerSecond,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxRegeneratedHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToHealthRegen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bPlayerDead,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bDamaged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_Stamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxStamina,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaRegenPerSecond,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_StaminaLossRunning,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimeToStaminaRegen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseTurnAtRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_BaseLookUpAtRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_WalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_SprintSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bSprinting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_CurrentVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallingTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_FallDamageFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MinFallDamageVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bCanHarvest,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemInRange,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_InteractDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInteractableInRange,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_RespawnViewDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bInventoryOpen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_bItemSelectionOpen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_SelectedItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultMiniMapSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_DefaultZoomLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MaxZoomLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ZoomSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetToRemove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_GameInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_PC,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_TimerHandler,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedDamageTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_ElapsedStaminaDrainTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_HealthLastTick,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_JumpStartPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_InventoryComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_WidgetInteractionComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_PlayerCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_SpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_MiniMapCapture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_HeldItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_HandItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp_HUDController,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacter_Statics::ClassParams = {
		&AMyCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UECodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyCharacter, 1582313888);
	template<> SPACERANCHER_API UClass* StaticClass<AMyCharacter>()
	{
		return AMyCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyCharacter(Z_Construct_UClass_AMyCharacter, &AMyCharacter::StaticClass, TEXT("/Script/SpaceRancher"), TEXT("AMyCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
