// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AdvancedFilters : ModuleRules
{
    public AdvancedFilters(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // Public dependencies - �������Ʈ ���̺귯���� �ʿ��� �⺻ ����
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        // Private dependencies - �÷����� ���ο����� ����ϴ� ����
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // �⺻ ���� ���
                "Projects",
                "InputCore",
                "RenderCore",
                "RHI"
            }
        );

        // ������ ���� ��ɵ� (�����Ϳ����� �ε�)
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

        // �𸮾� ���� 5.5 ȣȯ���� ���� �߰� ����
        if (Target.Version.MajorVersion >= 5)
        {
            // 5.5���� ��� ������ ���鸸 �߰�
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "DeveloperSettings"
                }
            );
        }

        // ����ȭ ���� - ��Ÿ�� �÷����ο� �����ϰ� ����
        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        // ���� ����
        bUseUnity = true;

        // C++ ǥ�� ���� (�𸮾� 5.5 ȣȯ)
        CppStandard = CppStandardVersion.Cpp17;

        // �߰� �����Ϸ� ����
        PublicDefinitions.Add("WITH_ADVANCED_FILTERS=1");
    }
}