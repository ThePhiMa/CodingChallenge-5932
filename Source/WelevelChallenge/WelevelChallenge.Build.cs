// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WelevelChallenge : ModuleRules
{
	public WelevelChallenge(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
