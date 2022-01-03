// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FTProject : ModuleRules
{
	public FTProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
