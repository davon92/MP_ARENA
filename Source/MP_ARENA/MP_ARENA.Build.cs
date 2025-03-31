// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MP_ARENA : ModuleRules
{
	public MP_ARENA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" ,
			"UMG", 
			"Slate", 
			"SlateCore"
		});
	}
}
