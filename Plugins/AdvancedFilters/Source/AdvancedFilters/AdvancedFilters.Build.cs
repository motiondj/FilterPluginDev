// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AdvancedFilters : ModuleRules
{
    public AdvancedFilters(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // 언리얼 엔진 5.5 이상 최적화 설정
        CppStandard = CppStandardVersion.Cpp17;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore"
            }
            );

        // 에디터에서만 필요한 모듈들
        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "UnrealEd",
                    "BlueprintGraph",
                    "ToolMenus",
                    "EditorSubsystem",
                    "DeveloperSettings",
                    "KismetCompiler",
                    "Kismet",
                    "KismetWidgets",
                    "PropertyEditor"
					// BlueprintEditorModule 제거 - 5.5에서는 사용하지 않음
				}
            );
        }


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}