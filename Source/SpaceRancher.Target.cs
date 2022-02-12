// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class SpaceRancherTarget : TargetRules
{
	public SpaceRancherTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		// Use for debugging Shipping Builds
		// Requires UE Source installation
		// if (Configuration == UnrealTargetConfiguration.Shipping)
		// {
		//	BuildEnvironment = TargetBuildEnvironment.Unique;
		//	bUseChecksInShipping = true;
		//	bUseLoggingInShipping = true;
		// }
		
		
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SpaceRancher" } );
	}
}
