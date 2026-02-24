// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FleeTheDungeon : ModuleRules
{
	public FleeTheDungeon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FleeTheDungeon",
			"FleeTheDungeon/Variant_Horror",
			"FleeTheDungeon/Variant_Horror/UI",
			"FleeTheDungeon/Variant_Shooter",
			"FleeTheDungeon/Variant_Shooter/AI",
			"FleeTheDungeon/Variant_Shooter/UI",
			"FleeTheDungeon/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
