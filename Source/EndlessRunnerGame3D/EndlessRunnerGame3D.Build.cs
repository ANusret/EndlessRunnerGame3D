// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EndlessRunnerGame3D : ModuleRules
{
	public EndlessRunnerGame3D(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
