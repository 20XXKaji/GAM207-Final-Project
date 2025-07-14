// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Final_Project_PartI : ModuleRules
{
	public Final_Project_PartI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
