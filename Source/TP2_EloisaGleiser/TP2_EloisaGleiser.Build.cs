// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP2_EloisaGleiser : ModuleRules
{
	public TP2_EloisaGleiser(ReadOnlyTargetRules Target) : base(Target)
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
			"TP2_EloisaGleiser",
			"TP2_EloisaGleiser/Variant_Platforming",
			"TP2_EloisaGleiser/Variant_Platforming/Animation",
			"TP2_EloisaGleiser/Variant_Combat",
			"TP2_EloisaGleiser/Variant_Combat/AI",
			"TP2_EloisaGleiser/Variant_Combat/Animation",
			"TP2_EloisaGleiser/Variant_Combat/Gameplay",
			"TP2_EloisaGleiser/Variant_Combat/Interfaces",
			"TP2_EloisaGleiser/Variant_Combat/UI",
			"TP2_EloisaGleiser/Variant_SideScrolling",
			"TP2_EloisaGleiser/Variant_SideScrolling/AI",
			"TP2_EloisaGleiser/Variant_SideScrolling/Gameplay",
			"TP2_EloisaGleiser/Variant_SideScrolling/Interfaces",
			"TP2_EloisaGleiser/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
