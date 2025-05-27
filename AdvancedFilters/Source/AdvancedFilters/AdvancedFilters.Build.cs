// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AdvancedFilters : ModuleRules
{
    public AdvancedFilters(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // Public dependencies - 블루프린트 라이브러리에 필요한 기본 모듈들
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        // Private dependencies - 플러그인 내부에서만 사용하는 모듈들
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // 기본 엔진 기능
                "Projects",
                "InputCore",
                "RenderCore",
                "RHI"
            }
        );

        // 에디터 전용 기능들 (에디터에서만 로드)
        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "UnrealEd",
                    "BlueprintGraph",
                    "KismetCompiler",
                    "ToolMenus",
                    "Slate",
                    "SlateCore",
                    "EditorStyle",
                    "EditorWidgets"
                }
            );
        }

        // 언리얼 엔진 5.5 호환성을 위한 추가 설정
        if (Target.Version.MajorVersion >= 5)
        {
            // 5.5에서 사용 가능한 모듈들만 추가
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "DeveloperSettings"
                }
            );
        }

        // 최적화 설정 - 런타임 플러그인에 적합하게 수정
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        // 빌드 설정
        bUseUnity = true;

        // C++ 표준 버전 (언리얼 5.5 호환)
        CppStandard = CppStandardVersion.Cpp17;

        // 추가 컴파일러 정의
        PublicDefinitions.Add("WITH_ADVANCED_FILTERS=1");
    }
}