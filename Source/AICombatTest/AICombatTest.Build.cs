// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AICombatTest : ModuleRules
{
	public AICombatTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
