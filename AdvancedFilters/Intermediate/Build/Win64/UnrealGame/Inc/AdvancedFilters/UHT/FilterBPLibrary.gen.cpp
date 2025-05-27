// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedFilters/Public/FilterBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFilterBPLibrary() {}

// Begin Cross Module References
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilterObject_NoRegister();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UFilterBPLibrary();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UFilterBPLibrary_NoRegister();
ADVANCEDFILTERS_API UEnum* Z_Construct_UEnum_AdvancedFilters_EFilterPreset();
ADVANCEDFILTERS_API UEnum* Z_Construct_UEnum_AdvancedFilters_EFilterType();
ADVANCEDFILTERS_API UScriptStruct* Z_Construct_UScriptStruct_FCustomFilterPreset();
ADVANCEDFILTERS_API UScriptStruct* Z_Construct_UScriptStruct_FFilterChainNode();
ADVANCEDFILTERS_API UScriptStruct* Z_Construct_UScriptStruct_FFilterInstanceManager();
ADVANCEDFILTERS_API UScriptStruct* Z_Construct_UScriptStruct_FFilterPerformanceData();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UPackage* Z_Construct_UPackage__Script_AdvancedFilters();
// End Cross Module References

// Begin Enum EFilterType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFilterType;
static UEnum* EFilterType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFilterType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFilterType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AdvancedFilters_EFilterType, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("EFilterType"));
	}
	return Z_Registration_Info_UEnum_EFilterType.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UEnum* StaticEnum<EFilterType>()
{
	return EFilterType_StaticEnum();
}
struct Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Filter type for creation\n * \xec\x83\x9d\xec\x84\xb1\xed\x95\xa0 \xed\x95\x84\xed\x84\xb0 \xec\x9c\xa0\xed\x98\x95\n */" },
		{ "Kalman.DisplayName", "Kalman Filter" },
		{ "Kalman.Name", "EFilterType::Kalman" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "OneEuro.DisplayName", "One Euro Filter" },
		{ "OneEuro.Name", "EFilterType::OneEuro" },
		{ "ToolTip", "Filter type for creation\n\xec\x83\x9d\xec\x84\xb1\xed\x95\xa0 \xed\x95\x84\xed\x84\xb0 \xec\x9c\xa0\xed\x98\x95" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFilterType::Kalman", (int64)EFilterType::Kalman },
		{ "EFilterType::OneEuro", (int64)EFilterType::OneEuro },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	"EFilterType",
	"EFilterType",
	Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AdvancedFilters_EFilterType()
{
	if (!Z_Registration_Info_UEnum_EFilterType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFilterType.InnerSingleton, Z_Construct_UEnum_AdvancedFilters_EFilterType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFilterType.InnerSingleton;
}
// End Enum EFilterType

// Begin ScriptStruct FCustomFilterPreset
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CustomFilterPreset;
class UScriptStruct* FCustomFilterPreset::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CustomFilterPreset.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CustomFilterPreset.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomFilterPreset, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("CustomFilterPreset"));
	}
	return Z_Registration_Info_UScriptStruct_CustomFilterPreset.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<FCustomFilterPreset>()
{
	return FCustomFilterPreset::StaticStruct();
}
struct Z_Construct_UScriptStruct_FCustomFilterPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Custom filter preset data\n * \xec\xbb\xa4\xec\x8a\xa4\xed\x85\x80 \xed\x95\x84\xed\x84\xb0 \xed\x94\x84\xeb\xa6\xac\xec\x85\x8b \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0\n */" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Custom filter preset data\n\xec\xbb\xa4\xec\x8a\xa4\xed\x85\x80 \xed\x95\x84\xed\x84\xb0 \xed\x94\x84\xeb\xa6\xac\xec\x85\x8b \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetName_MetaData[] = {
		{ "Category", "Filter Preset" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterType_MetaData[] = {
		{ "Category", "Filter Preset" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessNoise_MetaData[] = {
		{ "Category", "Kalman" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0001" },
		{ "Comment", "// Kalman filter parameters\n" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Kalman filter parameters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeasurementNoise_MetaData[] = {
		{ "Category", "Kalman" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.0001" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinCutoff_MetaData[] = {
		{ "Category", "OneEuro" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.001" },
		{ "Comment", "// One Euro filter parameters\n" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "One Euro filter parameters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Beta_MetaData[] = {
		{ "Category", "OneEuro" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DCutoff_MetaData[] = {
		{ "Category", "OneEuro" },
		{ "ClampMax", "10.0" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PresetName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessNoise;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MeasurementNoise;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinCutoff;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Beta;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DCutoff;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomFilterPreset>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_PresetName = { "PresetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, PresetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetName_MetaData), NewProp_PresetName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_FilterType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_FilterType = { "FilterType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, FilterType), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterType_MetaData), NewProp_FilterType_MetaData) }; // 3230867610
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_ProcessNoise = { "ProcessNoise", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, ProcessNoise), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessNoise_MetaData), NewProp_ProcessNoise_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_MeasurementNoise = { "MeasurementNoise", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, MeasurementNoise), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeasurementNoise_MetaData), NewProp_MeasurementNoise_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_MinCutoff = { "MinCutoff", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, MinCutoff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinCutoff_MetaData), NewProp_MinCutoff_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_Beta = { "Beta", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, Beta), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Beta_MetaData), NewProp_Beta_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_DCutoff = { "DCutoff", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCustomFilterPreset, DCutoff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DCutoff_MetaData), NewProp_DCutoff_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_PresetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_FilterType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_FilterType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_ProcessNoise,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_MeasurementNoise,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_MinCutoff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_Beta,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewProp_DCutoff,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	&NewStructOps,
	"CustomFilterPreset",
	Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::PropPointers),
	sizeof(FCustomFilterPreset),
	alignof(FCustomFilterPreset),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCustomFilterPreset()
{
	if (!Z_Registration_Info_UScriptStruct_CustomFilterPreset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CustomFilterPreset.InnerSingleton, Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_CustomFilterPreset.InnerSingleton;
}
// End ScriptStruct FCustomFilterPreset

// Begin ScriptStruct FFilterChainNode
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FilterChainNode;
class UScriptStruct* FFilterChainNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FilterChainNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FilterChainNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFilterChainNode, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("FilterChainNode"));
	}
	return Z_Registration_Info_UScriptStruct_FilterChainNode.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<FFilterChainNode>()
{
	return FFilterChainNode::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFilterChainNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Filter chain node\n * \xed\x95\x84\xed\x84\xb0 \xec\xb2\xb4\xec\x9d\xb8 \xeb\x85\xb8\xeb\x93\x9c\n */" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Filter chain node\n\xed\x95\x84\xed\x84\xb0 \xec\xb2\xb4\xec\x9d\xb8 \xeb\x85\xb8\xeb\x93\x9c" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "Category", "Filter Chain" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weight_MetaData[] = {
		{ "Category", "Filter Chain" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Weight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFilterChainNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FFilterChainNode_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterChainNode, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterChainNode_Statics::NewProp_Weight = { "Weight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterChainNode, Weight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weight_MetaData), NewProp_Weight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFilterChainNode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterChainNode_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterChainNode_Statics::NewProp_Weight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterChainNode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFilterChainNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	&NewStructOps,
	"FilterChainNode",
	Z_Construct_UScriptStruct_FFilterChainNode_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterChainNode_Statics::PropPointers),
	sizeof(FFilterChainNode),
	alignof(FFilterChainNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterChainNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFilterChainNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFilterChainNode()
{
	if (!Z_Registration_Info_UScriptStruct_FilterChainNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FilterChainNode.InnerSingleton, Z_Construct_UScriptStruct_FFilterChainNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FilterChainNode.InnerSingleton;
}
// End ScriptStruct FFilterChainNode

// Begin ScriptStruct FFilterPerformanceData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FilterPerformanceData;
class UScriptStruct* FFilterPerformanceData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FilterPerformanceData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FilterPerformanceData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFilterPerformanceData, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("FilterPerformanceData"));
	}
	return Z_Registration_Info_UScriptStruct_FilterPerformanceData.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<FFilterPerformanceData>()
{
	return FFilterPerformanceData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFilterPerformanceData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Filter performance data\n * \xed\x95\x84\xed\x84\xb0 \xec\x84\xb1\xeb\x8a\xa5 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0\n */" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Filter performance data\n\xed\x95\x84\xed\x84\xb0 \xec\x84\xb1\xeb\x8a\xa5 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageProcessingTime_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxProcessingTime_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateCount_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalProcessingTime_MetaData[] = {
		{ "Category", "Performance" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageProcessingTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxProcessingTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UpdateCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalProcessingTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFilterPerformanceData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_AverageProcessingTime = { "AverageProcessingTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterPerformanceData, AverageProcessingTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageProcessingTime_MetaData), NewProp_AverageProcessingTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_MaxProcessingTime = { "MaxProcessingTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterPerformanceData, MaxProcessingTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxProcessingTime_MetaData), NewProp_MaxProcessingTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_UpdateCount = { "UpdateCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterPerformanceData, UpdateCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateCount_MetaData), NewProp_UpdateCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_TotalProcessingTime = { "TotalProcessingTime", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFilterPerformanceData, TotalProcessingTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalProcessingTime_MetaData), NewProp_TotalProcessingTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_AverageProcessingTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_MaxProcessingTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_UpdateCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewProp_TotalProcessingTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	&NewStructOps,
	"FilterPerformanceData",
	Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::PropPointers),
	sizeof(FFilterPerformanceData),
	alignof(FFilterPerformanceData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFilterPerformanceData()
{
	if (!Z_Registration_Info_UScriptStruct_FilterPerformanceData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FilterPerformanceData.InnerSingleton, Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FilterPerformanceData.InnerSingleton;
}
// End ScriptStruct FFilterPerformanceData

// Begin ScriptStruct FFilterInstanceManager
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FilterInstanceManager;
class UScriptStruct* FFilterInstanceManager::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FilterInstanceManager.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FilterInstanceManager.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFilterInstanceManager, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("FilterInstanceManager"));
	}
	return Z_Registration_Info_UScriptStruct_FilterInstanceManager.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<FFilterInstanceManager>()
{
	return FFilterInstanceManager::StaticStruct();
}
struct Z_Construct_UScriptStruct_FFilterInstanceManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * Static filter instance manager\n * \xec\xa0\x95\xec\xa0\x81 \xed\x95\x84\xed\x84\xb0 \xec\x9d\xb8\xec\x8a\xa4\xed\x84\xb4\xec\x8a\xa4 \xea\xb4\x80\xeb\xa6\xac\xec\x9e\x90\n */" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Static filter instance manager\n\xec\xa0\x95\xec\xa0\x81 \xed\x95\x84\xed\x84\xb0 \xec\x9d\xb8\xec\x8a\xa4\xed\x84\xb4\xec\x8a\xa4 \xea\xb4\x80\xeb\xa6\xac\xec\x9e\x90" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFilterInstanceManager>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFilterInstanceManager_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	&NewStructOps,
	"FilterInstanceManager",
	nullptr,
	0,
	sizeof(FFilterInstanceManager),
	alignof(FFilterInstanceManager),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFilterInstanceManager_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFilterInstanceManager_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FFilterInstanceManager()
{
	if (!Z_Registration_Info_UScriptStruct_FilterInstanceManager.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FilterInstanceManager.InnerSingleton, Z_Construct_UScriptStruct_FFilterInstanceManager_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FilterInstanceManager.InnerSingleton;
}
// End ScriptStruct FFilterInstanceManager

// Begin Class UFilterBPLibrary Function ApplyCustomPreset
struct Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics
{
	struct FilterBPLibrary_eventApplyCustomPreset_Parms
	{
		UBaseFilterObject* Filter;
		FCustomFilterPreset Preset;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Custom Preset" },
		{ "DisplayName", "Apply Custom Preset" },
		{ "Keywords", "apply custom preset filter settings" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Apply a custom preset to a filter" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Preset;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventApplyCustomPreset_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventApplyCustomPreset_Parms, Preset), Z_Construct_UScriptStruct_FCustomFilterPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 1553149815
void Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FilterBPLibrary_eventApplyCustomPreset_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventApplyCustomPreset_Parms), &Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "ApplyCustomPreset", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::FilterBPLibrary_eventApplyCustomPreset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::FilterBPLibrary_eventApplyCustomPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execApplyCustomPreset)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_STRUCT_REF(FCustomFilterPreset,Z_Param_Out_Preset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFilterBPLibrary::ApplyCustomPreset(Z_Param_Filter,Z_Param_Out_Preset);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function ApplyCustomPreset

// Begin Class UFilterBPLibrary Function AutoTuneFilter
struct Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics
{
	struct FilterBPLibrary_eventAutoTuneFilter_Parms
	{
		UBaseFilterObject* Filter;
		TArray<float> RecentValues;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Advanced" },
		{ "DisplayName", "Auto Tune Filter" },
		{ "Keywords", "auto tune adjust filter noise" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Automatically tune filter based on detected noise level" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecentValues_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecentValues_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RecentValues;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventAutoTuneFilter_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_RecentValues_Inner = { "RecentValues", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_RecentValues = { "RecentValues", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventAutoTuneFilter_Parms, RecentValues), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecentValues_MetaData), NewProp_RecentValues_MetaData) };
void Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FilterBPLibrary_eventAutoTuneFilter_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventAutoTuneFilter_Parms), &Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_RecentValues_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_RecentValues,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "AutoTuneFilter", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::FilterBPLibrary_eventAutoTuneFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::FilterBPLibrary_eventAutoTuneFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execAutoTuneFilter)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_TARRAY_REF(float,Z_Param_Out_RecentValues);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFilterBPLibrary::AutoTuneFilter(Z_Param_Filter,Z_Param_Out_RecentValues);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function AutoTuneFilter

// Begin Class UFilterBPLibrary Function BlendFilterOutputs
struct Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics
{
	struct FilterBPLibrary_eventBlendFilterOutputs_Parms
	{
		TArray<UBaseFilterObject*> Filters;
		TArray<float> Weights;
		float RawValue;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Chain" },
		{ "DisplayName", "Blend Filter Outputs" },
		{ "Keywords", "blend mix combine filter outputs" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Blend outputs from multiple filters based on weights" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filters_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Weights_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Filters;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Weights_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Weights;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Filters_Inner = { "Filters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Filters = { "Filters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventBlendFilterOutputs_Parms, Filters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filters_MetaData), NewProp_Filters_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Weights_Inner = { "Weights", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Weights = { "Weights", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventBlendFilterOutputs_Parms, Weights), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Weights_MetaData), NewProp_Weights_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventBlendFilterOutputs_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventBlendFilterOutputs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Filters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Filters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Weights_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_Weights,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "BlendFilterOutputs", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::FilterBPLibrary_eventBlendFilterOutputs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::FilterBPLibrary_eventBlendFilterOutputs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execBlendFilterOutputs)
{
	P_GET_TARRAY_REF(UBaseFilterObject*,Z_Param_Out_Filters);
	P_GET_TARRAY_REF(float,Z_Param_Out_Weights);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::BlendFilterOutputs(Z_Param_Out_Filters,Z_Param_Out_Weights,Z_Param_RawValue);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function BlendFilterOutputs

// Begin Class UFilterBPLibrary Function CleanupAllFilters
struct Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Cleanup All Filters" },
		{ "Keywords", "cleanup clear all filters memory" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Cleanup all one-click filter instances to free memory" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "CleanupAllFilters", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execCleanupAllFilters)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UFilterBPLibrary::CleanupAllFilters();
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function CleanupAllFilters

// Begin Class UFilterBPLibrary Function CompareFilterOutputs
struct Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics
{
	struct FilterBPLibrary_eventCompareFilterOutputs_Parms
	{
		const UBaseFilterObject* Filter1;
		const UBaseFilterObject* Filter2;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Advanced" },
		{ "DisplayName", "Compare Filter Outputs" },
		{ "Keywords", "compare difference filter output" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Compare the difference between two filter outputs" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter1_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter2_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter2;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_Filter1 = { "Filter1", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCompareFilterOutputs_Parms, Filter1), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter1_MetaData), NewProp_Filter1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_Filter2 = { "Filter2", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCompareFilterOutputs_Parms, Filter2), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter2_MetaData), NewProp_Filter2_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCompareFilterOutputs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_Filter1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_Filter2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "CompareFilterOutputs", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::FilterBPLibrary_eventCompareFilterOutputs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::FilterBPLibrary_eventCompareFilterOutputs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execCompareFilterOutputs)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter1);
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter2);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::CompareFilterOutputs(Z_Param_Filter1,Z_Param_Filter2);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function CompareFilterOutputs

// Begin Class UFilterBPLibrary Function CreateCustomPreset
struct Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics
{
	struct FilterBPLibrary_eventCreateCustomPreset_Parms
	{
		FString PresetName;
		EFilterType FilterType;
		float Param1;
		float Param2;
		float Param3;
		FCustomFilterPreset ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Custom Preset" },
		{ "CPP_Default_Param3", "1.000000" },
		{ "DisplayName", "Create Custom Preset" },
		{ "Keywords", "create custom preset save filter settings" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Create a custom filter preset with specific parameters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PresetName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param1;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param2;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param3;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_PresetName = { "PresetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, PresetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetName_MetaData), NewProp_PresetName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_FilterType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_FilterType = { "FilterType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, FilterType), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param1 = { "Param1", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, Param1), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param2 = { "Param2", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, Param2), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param3 = { "Param3", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, Param3), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateCustomPreset_Parms, ReturnValue), Z_Construct_UScriptStruct_FCustomFilterPreset, METADATA_PARAMS(0, nullptr) }; // 1553149815
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_PresetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_FilterType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_FilterType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_Param3,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "CreateCustomPreset", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::FilterBPLibrary_eventCreateCustomPreset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::FilterBPLibrary_eventCreateCustomPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execCreateCustomPreset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PresetName);
	P_GET_ENUM(EFilterType,Z_Param_FilterType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param1);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param2);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param3);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCustomFilterPreset*)Z_Param__Result=UFilterBPLibrary::CreateCustomPreset(Z_Param_PresetName,EFilterType(Z_Param_FilterType),Z_Param_Param1,Z_Param_Param2,Z_Param_Param3);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function CreateCustomPreset

// Begin Class UFilterBPLibrary Function CreateFilter
struct Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics
{
	struct FilterBPLibrary_eventCreateFilter_Parms
	{
		EFilterType FilterType;
		UBaseFilterObject* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Core" },
		{ "DisplayName", "Create Filter" },
		{ "Keywords", "create make new filter kalman oneeuro" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Creates a new filter instance of the specified type" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_FilterType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_FilterType = { "FilterType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateFilter_Parms, FilterType), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateFilter_Parms, ReturnValue), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_FilterType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_FilterType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "CreateFilter", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::FilterBPLibrary_eventCreateFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::FilterBPLibrary_eventCreateFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_CreateFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_CreateFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execCreateFilter)
{
	P_GET_ENUM(EFilterType,Z_Param_FilterType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBaseFilterObject**)Z_Param__Result=UFilterBPLibrary::CreateFilter(EFilterType(Z_Param_FilterType));
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function CreateFilter

// Begin Class UFilterBPLibrary Function CreateFilterChain
struct Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics
{
	struct FilterBPLibrary_eventCreateFilterChain_Parms
	{
		TArray<EFilterType> FilterTypes;
		TArray<EFilterPreset> Presets;
		TArray<FFilterChainNode> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Chain" },
		{ "DisplayName", "Create Filter Chain" },
		{ "Keywords", "create chain multiple filters combine" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Create a chain of filters that process values sequentially" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Presets_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterTypes_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilterTypes;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Presets_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Presets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Presets;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes_Inner = { "FilterTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes = { "FilterTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateFilterChain_Parms, FilterTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterTypes_MetaData), NewProp_FilterTypes_MetaData) }; // 3230867610
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets_Inner = { "Presets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets = { "Presets", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateFilterChain_Parms, Presets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Presets_MetaData), NewProp_Presets_MetaData) }; // 90198315
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFilterChainNode, METADATA_PARAMS(0, nullptr) }; // 2649234700
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventCreateFilterChain_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2649234700
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_FilterTypes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_Presets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "CreateFilterChain", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::FilterBPLibrary_eventCreateFilterChain_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::FilterBPLibrary_eventCreateFilterChain_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execCreateFilterChain)
{
	P_GET_TARRAY_REF(EFilterType,Z_Param_Out_FilterTypes);
	P_GET_TARRAY_REF(EFilterPreset,Z_Param_Out_Presets);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FFilterChainNode>*)Z_Param__Result=UFilterBPLibrary::CreateFilterChain(Z_Param_Out_FilterTypes,Z_Param_Out_Presets);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function CreateFilterChain

// Begin Class UFilterBPLibrary Function EstimateFilterLatency
struct Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics
{
	struct FilterBPLibrary_eventEstimateFilterLatency_Parms
	{
		const UBaseFilterObject* Filter;
		EFilterPreset Preset;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Advanced" },
		{ "DisplayName", "Estimate Filter Latency" },
		{ "Keywords", "latency delay filter response time" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Estimate the latency/delay of the filter in frames" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventEstimateFilterLatency_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventEstimateFilterLatency_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventEstimateFilterLatency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "EstimateFilterLatency", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::FilterBPLibrary_eventEstimateFilterLatency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::FilterBPLibrary_eventEstimateFilterLatency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execEstimateFilterLatency)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UFilterBPLibrary::EstimateFilterLatency(Z_Param_Filter,EFilterPreset(Z_Param_Preset));
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function EstimateFilterLatency

// Begin Class UFilterBPLibrary Function GetCurrentValueFloat
struct Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics
{
	struct FilterBPLibrary_eventGetCurrentValueFloat_Parms
	{
		const UBaseFilterObject* Filter;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Get Current Value (Float)" },
		{ "Keywords", "get current filter value float" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get the current filtered float value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetCurrentValueFloat_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetCurrentValueFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetCurrentValueFloat", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::FilterBPLibrary_eventGetCurrentValueFloat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::FilterBPLibrary_eventGetCurrentValueFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetCurrentValueFloat)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::GetCurrentValueFloat(Z_Param_Filter);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetCurrentValueFloat

// Begin Class UFilterBPLibrary Function GetCurrentValueVector
struct Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics
{
	struct FilterBPLibrary_eventGetCurrentValueVector_Parms
	{
		const UBaseFilterObject* Filter;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Get Current Value (Vector)" },
		{ "Keywords", "get current filter value vector" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get the current filtered vector value" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetCurrentValueVector_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetCurrentValueVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetCurrentValueVector", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::FilterBPLibrary_eventGetCurrentValueVector_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::FilterBPLibrary_eventGetCurrentValueVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetCurrentValueVector)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UFilterBPLibrary::GetCurrentValueVector(Z_Param_Filter);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetCurrentValueVector

// Begin Class UFilterBPLibrary Function GetFilterDescription
struct Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics
{
	struct FilterBPLibrary_eventGetFilterDescription_Parms
	{
		EFilterType FilterType;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Recommendation" },
		{ "DisplayName", "Get Filter Description" },
		{ "Keywords", "filter description info help" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get a description of what the filter does" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_FilterType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_FilterType = { "FilterType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterDescription_Parms, FilterType), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_FilterType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_FilterType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetFilterDescription", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::FilterBPLibrary_eventGetFilterDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::FilterBPLibrary_eventGetFilterDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetFilterDescription)
{
	P_GET_ENUM(EFilterType,Z_Param_FilterType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFilterBPLibrary::GetFilterDescription(EFilterType(Z_Param_FilterType));
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetFilterDescription

// Begin Class UFilterBPLibrary Function GetFilterInstance
struct Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics
{
	struct FilterBPLibrary_eventGetFilterInstance_Parms
	{
		FString FilterID;
		UBaseFilterObject* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Get Filter Instance" },
		{ "Keywords", "get filter instance object id" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get a filter instance by its ID" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::NewProp_FilterID = { "FilterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterInstance_Parms, FilterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterID_MetaData), NewProp_FilterID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterInstance_Parms, ReturnValue), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::NewProp_FilterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetFilterInstance", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::FilterBPLibrary_eventGetFilterInstance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::FilterBPLibrary_eventGetFilterInstance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetFilterInstance)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBaseFilterObject**)Z_Param__Result=UFilterBPLibrary::GetFilterInstance(Z_Param_FilterID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetFilterInstance

// Begin Class UFilterBPLibrary Function GetFilterResponseCurve
struct Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics
{
	struct FilterBPLibrary_eventGetFilterResponseCurve_Parms
	{
		EFilterType FilterType;
		EFilterPreset Preset;
		int32 NumPoints;
		TArray<FVector2D> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Advanced Filters|Debug" },
		{ "CPP_Default_NumPoints", "100" },
		{ "DisplayName", "Get Filter Response Curve" },
		{ "Keywords", "debug draw curve response filter" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get points for drawing filter response curve" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_FilterType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FilterType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumPoints;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_FilterType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_FilterType = { "FilterType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterResponseCurve_Parms, FilterType), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterResponseCurve_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_NumPoints = { "NumPoints", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterResponseCurve_Parms, NumPoints), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterResponseCurve_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_FilterType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_FilterType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_NumPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetFilterResponseCurve", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::FilterBPLibrary_eventGetFilterResponseCurve_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::FilterBPLibrary_eventGetFilterResponseCurve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetFilterResponseCurve)
{
	P_GET_ENUM(EFilterType,Z_Param_FilterType);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_GET_PROPERTY(FIntProperty,Z_Param_NumPoints);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector2D>*)Z_Param__Result=UFilterBPLibrary::GetFilterResponseCurve(EFilterType(Z_Param_FilterType),EFilterPreset(Z_Param_Preset),Z_Param_NumPoints);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetFilterResponseCurve

// Begin Class UFilterBPLibrary Function GetFilterStatistics
struct Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics
{
	struct FilterBPLibrary_eventGetFilterStatistics_Parms
	{
		const UBaseFilterObject* Filter;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Debug" },
		{ "DisplayName", "Get Filter Statistics" },
		{ "Keywords", "debug stats statistics filter info" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get debug statistics about the filter performance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterStatistics_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetFilterStatistics_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetFilterStatistics", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::FilterBPLibrary_eventGetFilterStatistics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::FilterBPLibrary_eventGetFilterStatistics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetFilterStatistics)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFilterBPLibrary::GetFilterStatistics(Z_Param_Filter);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetFilterStatistics

// Begin Class UFilterBPLibrary Function GetPresetDescription
struct Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics
{
	struct FilterBPLibrary_eventGetPresetDescription_Parms
	{
		EFilterPreset Preset;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Recommendation" },
		{ "DisplayName", "Get Preset Description" },
		{ "Keywords", "preset description info help" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Get a description of what the preset does" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetPresetDescription_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventGetPresetDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "GetPresetDescription", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::FilterBPLibrary_eventGetPresetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::FilterBPLibrary_eventGetPresetDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execGetPresetDescription)
{
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFilterBPLibrary::GetPresetDescription(EFilterPreset(Z_Param_Preset));
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function GetPresetDescription

// Begin Class UFilterBPLibrary Function InitializeFilter
struct Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics
{
	struct FilterBPLibrary_eventInitializeFilter_Parms
	{
		UBaseFilterObject* Filter;
		EFilterPreset Preset;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Core" },
		{ "DisplayName", "Initialize Filter" },
		{ "Keywords", "init initialize setup filter preset" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Initialize the filter with a preset (Low/Medium/High)" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventInitializeFilter_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventInitializeFilter_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
void Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FilterBPLibrary_eventInitializeFilter_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventInitializeFilter_Parms), &Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "InitializeFilter", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::FilterBPLibrary_eventInitializeFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::FilterBPLibrary_eventInitializeFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execInitializeFilter)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFilterBPLibrary::InitializeFilter(Z_Param_Filter,EFilterPreset(Z_Param_Preset));
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function InitializeFilter

// Begin Class UFilterBPLibrary Function IsFilterInitialized
struct Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics
{
	struct FilterBPLibrary_eventIsFilterInitialized_Parms
	{
		const UBaseFilterObject* Filter;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Is Filter Initialized" },
		{ "Keywords", "check filter initialized ready" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Check if the filter has been initialized" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventIsFilterInitialized_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
void Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FilterBPLibrary_eventIsFilterInitialized_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventIsFilterInitialized_Parms), &Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "IsFilterInitialized", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::FilterBPLibrary_eventIsFilterInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::FilterBPLibrary_eventIsFilterInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execIsFilterInitialized)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFilterBPLibrary::IsFilterInitialized(Z_Param_Filter);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function IsFilterInitialized

// Begin Class UFilterBPLibrary Function KalmanFilterValue
struct Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics
{
	struct FilterBPLibrary_eventKalmanFilterValue_Parms
	{
		float RawValue;
		EFilterPreset Preset;
		FString FilterID;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One-Click" },
		{ "CPP_Default_FilterID", "Default" },
		{ "CPP_Default_Preset", "Medium" },
		{ "DisplayName", "Kalman Filter Value" },
		{ "Keywords", "kalman filter one click easy float" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Apply Kalman filter to a value with one node" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterID;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterValue_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterValue_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_FilterID = { "FilterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterValue_Parms, FilterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterID_MetaData), NewProp_FilterID_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_FilterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "KalmanFilterValue", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::FilterBPLibrary_eventKalmanFilterValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::FilterBPLibrary_eventKalmanFilterValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execKalmanFilterValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::KalmanFilterValue(Z_Param_RawValue,EFilterPreset(Z_Param_Preset),Z_Param_FilterID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function KalmanFilterValue

// Begin Class UFilterBPLibrary Function KalmanFilterVector
struct Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics
{
	struct FilterBPLibrary_eventKalmanFilterVector_Parms
	{
		FVector RawValue;
		EFilterPreset Preset;
		FString FilterID;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One-Click" },
		{ "CPP_Default_FilterID", "Default" },
		{ "CPP_Default_Preset", "Medium" },
		{ "DisplayName", "Kalman Filter Vector" },
		{ "Keywords", "kalman filter one click easy vector" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Apply Kalman filter to a vector with one node" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawValue_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterVector_Parms, RawValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawValue_MetaData), NewProp_RawValue_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterVector_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_FilterID = { "FilterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterVector_Parms, FilterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterID_MetaData), NewProp_FilterID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventKalmanFilterVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_FilterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "KalmanFilterVector", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::FilterBPLibrary_eventKalmanFilterVector_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::FilterBPLibrary_eventKalmanFilterVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execKalmanFilterVector)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_RawValue);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UFilterBPLibrary::KalmanFilterVector(Z_Param_Out_RawValue,EFilterPreset(Z_Param_Preset),Z_Param_FilterID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function KalmanFilterVector

// Begin Class UFilterBPLibrary Function OneEuroFilterValue
struct Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics
{
	struct FilterBPLibrary_eventOneEuroFilterValue_Parms
	{
		float RawValue;
		float DeltaTime;
		EFilterPreset Preset;
		FString FilterID;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One-Click" },
		{ "CPP_Default_FilterID", "Default" },
		{ "CPP_Default_Preset", "Medium" },
		{ "DisplayName", "One Euro Filter Value" },
		{ "Keywords", "oneeuro filter one click easy float" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Apply One Euro filter to a value with one node" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterID;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterValue_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterValue_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterValue_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_FilterID = { "FilterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterValue_Parms, FilterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterID_MetaData), NewProp_FilterID_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_FilterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "OneEuroFilterValue", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::FilterBPLibrary_eventOneEuroFilterValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::FilterBPLibrary_eventOneEuroFilterValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execOneEuroFilterValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::OneEuroFilterValue(Z_Param_RawValue,Z_Param_DeltaTime,EFilterPreset(Z_Param_Preset),Z_Param_FilterID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function OneEuroFilterValue

// Begin Class UFilterBPLibrary Function OneEuroFilterVector
struct Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics
{
	struct FilterBPLibrary_eventOneEuroFilterVector_Parms
	{
		FVector RawValue;
		float DeltaTime;
		EFilterPreset Preset;
		FString FilterID;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One-Click" },
		{ "CPP_Default_FilterID", "Default" },
		{ "CPP_Default_Preset", "Medium" },
		{ "DisplayName", "One Euro Filter Vector" },
		{ "Keywords", "oneeuro filter one click easy vector" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Apply One Euro filter to a vector with one node" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawValue_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Preset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilterID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterVector_Parms, RawValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawValue_MetaData), NewProp_RawValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterVector_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_Preset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterVector_Parms, Preset), Z_Construct_UEnum_AdvancedFilters_EFilterPreset, METADATA_PARAMS(0, nullptr) }; // 90198315
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_FilterID = { "FilterID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterVector_Parms, FilterID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterID_MetaData), NewProp_FilterID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventOneEuroFilterVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_Preset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_FilterID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "OneEuroFilterVector", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::FilterBPLibrary_eventOneEuroFilterVector_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::FilterBPLibrary_eventOneEuroFilterVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execOneEuroFilterVector)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_RawValue);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_GET_ENUM(EFilterPreset,Z_Param_Preset);
	P_GET_PROPERTY(FStrProperty,Z_Param_FilterID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UFilterBPLibrary::OneEuroFilterVector(Z_Param_Out_RawValue,Z_Param_DeltaTime,EFilterPreset(Z_Param_Preset),Z_Param_FilterID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function OneEuroFilterVector

// Begin Class UFilterBPLibrary Function PresetToString
struct Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics
{
	struct FilterBPLibrary_eventPresetToString_Parms
	{
		FCustomFilterPreset Preset;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Custom Preset" },
		{ "DisplayName", "Preset to String" },
		{ "Keywords", "save preset string serialize" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Convert a custom preset to a string for saving" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Preset;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventPresetToString_Parms, Preset), Z_Construct_UScriptStruct_FCustomFilterPreset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Preset_MetaData), NewProp_Preset_MetaData) }; // 1553149815
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventPresetToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::NewProp_Preset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "PresetToString", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::FilterBPLibrary_eventPresetToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::FilterBPLibrary_eventPresetToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_PresetToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_PresetToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execPresetToString)
{
	P_GET_STRUCT_REF(FCustomFilterPreset,Z_Param_Out_Preset);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFilterBPLibrary::PresetToString(Z_Param_Out_Preset);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function PresetToString

// Begin Class UFilterBPLibrary Function ProcessThroughChain
struct Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics
{
	struct FilterBPLibrary_eventProcessThroughChain_Parms
	{
		TArray<FFilterChainNode> FilterChain;
		float RawValue;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Chain" },
		{ "DisplayName", "Process Through Chain" },
		{ "Keywords", "process chain filter sequential" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Process a value through a chain of filters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilterChain_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FilterChain_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilterChain;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_FilterChain_Inner = { "FilterChain", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FFilterChainNode, METADATA_PARAMS(0, nullptr) }; // 2649234700
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_FilterChain = { "FilterChain", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProcessThroughChain_Parms, FilterChain), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilterChain_MetaData), NewProp_FilterChain_MetaData) }; // 2649234700
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProcessThroughChain_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProcessThroughChain_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_FilterChain_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_FilterChain,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "ProcessThroughChain", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::FilterBPLibrary_eventProcessThroughChain_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::FilterBPLibrary_eventProcessThroughChain_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execProcessThroughChain)
{
	P_GET_TARRAY_REF(FFilterChainNode,Z_Param_Out_FilterChain);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::ProcessThroughChain(Z_Param_Out_FilterChain,Z_Param_RawValue);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function ProcessThroughChain

// Begin Class UFilterBPLibrary Function ProfileFilterUpdate
struct Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics
{
	struct FilterBPLibrary_eventProfileFilterUpdate_Parms
	{
		UBaseFilterObject* Filter;
		float RawValue;
		FFilterPerformanceData OutPerformance;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Performance" },
		{ "DisplayName", "Profile Filter Update" },
		{ "Keywords", "measure time filter update performance" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Measure the time taken for a filter update" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutPerformance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProfileFilterUpdate_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProfileFilterUpdate_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_OutPerformance = { "OutPerformance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProfileFilterUpdate_Parms, OutPerformance), Z_Construct_UScriptStruct_FFilterPerformanceData, METADATA_PARAMS(0, nullptr) }; // 1086078593
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventProfileFilterUpdate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_OutPerformance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "ProfileFilterUpdate", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::FilterBPLibrary_eventProfileFilterUpdate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::FilterBPLibrary_eventProfileFilterUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execProfileFilterUpdate)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_GET_STRUCT_REF(FFilterPerformanceData,Z_Param_Out_OutPerformance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::ProfileFilterUpdate(Z_Param_Filter,Z_Param_RawValue,Z_Param_Out_OutPerformance);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function ProfileFilterUpdate

// Begin Class UFilterBPLibrary Function RecommendFilterType
struct Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics
{
	struct FilterBPLibrary_eventRecommendFilterType_Parms
	{
		bool bNeedsFastResponse;
		bool bNeedsPrecisePrediction;
		bool bIsVRARInput;
		bool bHasVariableFrameRate;
		EFilterType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Recommendation" },
		{ "DisplayName", "Recommend Filter Type" },
		{ "Keywords", "recommend suggest best filter type" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Recommends the best filter type based on your use case" },
	};
#endif // WITH_METADATA
	static void NewProp_bNeedsFastResponse_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNeedsFastResponse;
	static void NewProp_bNeedsPrecisePrediction_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNeedsPrecisePrediction;
	static void NewProp_bIsVRARInput_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVRARInput;
	static void NewProp_bHasVariableFrameRate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasVariableFrameRate;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsFastResponse_SetBit(void* Obj)
{
	((FilterBPLibrary_eventRecommendFilterType_Parms*)Obj)->bNeedsFastResponse = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsFastResponse = { "bNeedsFastResponse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventRecommendFilterType_Parms), &Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsFastResponse_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsPrecisePrediction_SetBit(void* Obj)
{
	((FilterBPLibrary_eventRecommendFilterType_Parms*)Obj)->bNeedsPrecisePrediction = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsPrecisePrediction = { "bNeedsPrecisePrediction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventRecommendFilterType_Parms), &Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsPrecisePrediction_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bIsVRARInput_SetBit(void* Obj)
{
	((FilterBPLibrary_eventRecommendFilterType_Parms*)Obj)->bIsVRARInput = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bIsVRARInput = { "bIsVRARInput", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventRecommendFilterType_Parms), &Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bIsVRARInput_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bHasVariableFrameRate_SetBit(void* Obj)
{
	((FilterBPLibrary_eventRecommendFilterType_Parms*)Obj)->bHasVariableFrameRate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bHasVariableFrameRate = { "bHasVariableFrameRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FilterBPLibrary_eventRecommendFilterType_Parms), &Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bHasVariableFrameRate_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventRecommendFilterType_Parms, ReturnValue), Z_Construct_UEnum_AdvancedFilters_EFilterType, METADATA_PARAMS(0, nullptr) }; // 3230867610
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsFastResponse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bNeedsPrecisePrediction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bIsVRARInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_bHasVariableFrameRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "RecommendFilterType", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::FilterBPLibrary_eventRecommendFilterType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::FilterBPLibrary_eventRecommendFilterType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execRecommendFilterType)
{
	P_GET_UBOOL(Z_Param_bNeedsFastResponse);
	P_GET_UBOOL(Z_Param_bNeedsPrecisePrediction);
	P_GET_UBOOL(Z_Param_bIsVRARInput);
	P_GET_UBOOL(Z_Param_bHasVariableFrameRate);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EFilterType*)Z_Param__Result=UFilterBPLibrary::RecommendFilterType(Z_Param_bNeedsFastResponse,Z_Param_bNeedsPrecisePrediction,Z_Param_bIsVRARInput,Z_Param_bHasVariableFrameRate);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function RecommendFilterType

// Begin Class UFilterBPLibrary Function ResetFilter
struct Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics
{
	struct FilterBPLibrary_eventResetFilter_Parms
	{
		UBaseFilterObject* Filter;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Utility" },
		{ "DisplayName", "Reset Filter" },
		{ "Keywords", "reset clear filter" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Reset the filter to its initial state" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventResetFilter_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::NewProp_Filter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "ResetFilter", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::FilterBPLibrary_eventResetFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::FilterBPLibrary_eventResetFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_ResetFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_ResetFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execResetFilter)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	UFilterBPLibrary::ResetFilter(Z_Param_Filter);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function ResetFilter

// Begin Class UFilterBPLibrary Function StartProfiling
struct Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics
{
	struct FilterBPLibrary_eventStartProfiling_Parms
	{
		FString ProfileID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Performance" },
		{ "DisplayName", "Start Profiling" },
		{ "Keywords", "start performance profiling measure" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Start measuring filter performance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProfileID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProfileID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::NewProp_ProfileID = { "ProfileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventStartProfiling_Parms, ProfileID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProfileID_MetaData), NewProp_ProfileID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::NewProp_ProfileID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "StartProfiling", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::FilterBPLibrary_eventStartProfiling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::FilterBPLibrary_eventStartProfiling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_StartProfiling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_StartProfiling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execStartProfiling)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ProfileID);
	P_FINISH;
	P_NATIVE_BEGIN;
	UFilterBPLibrary::StartProfiling(Z_Param_ProfileID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function StartProfiling

// Begin Class UFilterBPLibrary Function StopProfiling
struct Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics
{
	struct FilterBPLibrary_eventStopProfiling_Parms
	{
		FString ProfileID;
		FFilterPerformanceData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Performance" },
		{ "DisplayName", "Stop Profiling" },
		{ "Keywords", "stop performance profiling measure" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Stop measuring filter performance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProfileID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProfileID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::NewProp_ProfileID = { "ProfileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventStopProfiling_Parms, ProfileID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProfileID_MetaData), NewProp_ProfileID_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventStopProfiling_Parms, ReturnValue), Z_Construct_UScriptStruct_FFilterPerformanceData, METADATA_PARAMS(0, nullptr) }; // 1086078593
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::NewProp_ProfileID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "StopProfiling", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::FilterBPLibrary_eventStopProfiling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::FilterBPLibrary_eventStopProfiling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_StopProfiling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_StopProfiling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execStopProfiling)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ProfileID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FFilterPerformanceData*)Z_Param__Result=UFilterBPLibrary::StopProfiling(Z_Param_ProfileID);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function StopProfiling

// Begin Class UFilterBPLibrary Function StringToPreset
struct Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics
{
	struct FilterBPLibrary_eventStringToPreset_Parms
	{
		FString PresetString;
		FCustomFilterPreset ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Custom Preset" },
		{ "DisplayName", "String to Preset" },
		{ "Keywords", "load preset string deserialize" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Convert a string back to a custom preset" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PresetString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PresetString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::NewProp_PresetString = { "PresetString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventStringToPreset_Parms, PresetString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PresetString_MetaData), NewProp_PresetString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventStringToPreset_Parms, ReturnValue), Z_Construct_UScriptStruct_FCustomFilterPreset, METADATA_PARAMS(0, nullptr) }; // 1553149815
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::NewProp_PresetString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "StringToPreset", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::FilterBPLibrary_eventStringToPreset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::FilterBPLibrary_eventStringToPreset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_StringToPreset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_StringToPreset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execStringToPreset)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PresetString);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCustomFilterPreset*)Z_Param__Result=UFilterBPLibrary::StringToPreset(Z_Param_PresetString);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function StringToPreset

// Begin Class UFilterBPLibrary Function UpdateFilterFloat
struct Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics
{
	struct FilterBPLibrary_eventUpdateFilterFloat_Parms
	{
		UBaseFilterObject* Filter;
		float RawValue;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Core" },
		{ "DisplayName", "Update Filter (Float)" },
		{ "Keywords", "update filter value float" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Update the filter with a new measurement and get filtered result" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterFloat_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterFloat_Parms, RawValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "UpdateFilterFloat", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::FilterBPLibrary_eventUpdateFilterFloat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::FilterBPLibrary_eventUpdateFilterFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execUpdateFilterFloat)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RawValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFilterBPLibrary::UpdateFilterFloat(Z_Param_Filter,Z_Param_RawValue);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function UpdateFilterFloat

// Begin Class UFilterBPLibrary Function UpdateFilterVector
struct Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics
{
	struct FilterBPLibrary_eventUpdateFilterVector_Parms
	{
		UBaseFilterObject* Filter;
		FVector RawValue;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Core" },
		{ "DisplayName", "Update Filter (Vector)" },
		{ "Keywords", "update filter value vector" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Update the filter with a new vector measurement and get filtered result" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RawValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RawValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterVector_Parms, Filter), Z_Construct_UClass_UBaseFilterObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_RawValue = { "RawValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterVector_Parms, RawValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RawValue_MetaData), NewProp_RawValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FilterBPLibrary_eventUpdateFilterVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_RawValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFilterBPLibrary, nullptr, "UpdateFilterVector", nullptr, nullptr, Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::FilterBPLibrary_eventUpdateFilterVector_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::FilterBPLibrary_eventUpdateFilterVector_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFilterBPLibrary::execUpdateFilterVector)
{
	P_GET_OBJECT(UBaseFilterObject,Z_Param_Filter);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_RawValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UFilterBPLibrary::UpdateFilterVector(Z_Param_Filter,Z_Param_Out_RawValue);
	P_NATIVE_END;
}
// End Class UFilterBPLibrary Function UpdateFilterVector

// Begin Class UFilterBPLibrary
void UFilterBPLibrary::StaticRegisterNativesUFilterBPLibrary()
{
	UClass* Class = UFilterBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyCustomPreset", &UFilterBPLibrary::execApplyCustomPreset },
		{ "AutoTuneFilter", &UFilterBPLibrary::execAutoTuneFilter },
		{ "BlendFilterOutputs", &UFilterBPLibrary::execBlendFilterOutputs },
		{ "CleanupAllFilters", &UFilterBPLibrary::execCleanupAllFilters },
		{ "CompareFilterOutputs", &UFilterBPLibrary::execCompareFilterOutputs },
		{ "CreateCustomPreset", &UFilterBPLibrary::execCreateCustomPreset },
		{ "CreateFilter", &UFilterBPLibrary::execCreateFilter },
		{ "CreateFilterChain", &UFilterBPLibrary::execCreateFilterChain },
		{ "EstimateFilterLatency", &UFilterBPLibrary::execEstimateFilterLatency },
		{ "GetCurrentValueFloat", &UFilterBPLibrary::execGetCurrentValueFloat },
		{ "GetCurrentValueVector", &UFilterBPLibrary::execGetCurrentValueVector },
		{ "GetFilterDescription", &UFilterBPLibrary::execGetFilterDescription },
		{ "GetFilterInstance", &UFilterBPLibrary::execGetFilterInstance },
		{ "GetFilterResponseCurve", &UFilterBPLibrary::execGetFilterResponseCurve },
		{ "GetFilterStatistics", &UFilterBPLibrary::execGetFilterStatistics },
		{ "GetPresetDescription", &UFilterBPLibrary::execGetPresetDescription },
		{ "InitializeFilter", &UFilterBPLibrary::execInitializeFilter },
		{ "IsFilterInitialized", &UFilterBPLibrary::execIsFilterInitialized },
		{ "KalmanFilterValue", &UFilterBPLibrary::execKalmanFilterValue },
		{ "KalmanFilterVector", &UFilterBPLibrary::execKalmanFilterVector },
		{ "OneEuroFilterValue", &UFilterBPLibrary::execOneEuroFilterValue },
		{ "OneEuroFilterVector", &UFilterBPLibrary::execOneEuroFilterVector },
		{ "PresetToString", &UFilterBPLibrary::execPresetToString },
		{ "ProcessThroughChain", &UFilterBPLibrary::execProcessThroughChain },
		{ "ProfileFilterUpdate", &UFilterBPLibrary::execProfileFilterUpdate },
		{ "RecommendFilterType", &UFilterBPLibrary::execRecommendFilterType },
		{ "ResetFilter", &UFilterBPLibrary::execResetFilter },
		{ "StartProfiling", &UFilterBPLibrary::execStartProfiling },
		{ "StopProfiling", &UFilterBPLibrary::execStopProfiling },
		{ "StringToPreset", &UFilterBPLibrary::execStringToPreset },
		{ "UpdateFilterFloat", &UFilterBPLibrary::execUpdateFilterFloat },
		{ "UpdateFilterVector", &UFilterBPLibrary::execUpdateFilterVector },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFilterBPLibrary);
UClass* Z_Construct_UClass_UFilterBPLibrary_NoRegister()
{
	return UFilterBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UFilterBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Blueprint Function Library for Advanced Filters\n * \xea\xb3\xa0\xea\xb8\x89 \xed\x95\x84\xed\x84\xb0\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x95\xa8\xec\x88\x98 \xeb\x9d\xbc\xec\x9d\xb4\xeb\xb8\x8c\xeb\x9f\xac\xeb\xa6\xac\n */" },
		{ "IncludePath", "FilterBPLibrary.h" },
		{ "ModuleRelativePath", "Public/FilterBPLibrary.h" },
		{ "ToolTip", "Blueprint Function Library for Advanced Filters\n\xea\xb3\xa0\xea\xb8\x89 \xed\x95\x84\xed\x84\xb0\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x95\xa8\xec\x88\x98 \xeb\x9d\xbc\xec\x9d\xb4\xeb\xb8\x8c\xeb\x9f\xac\xeb\xa6\xac" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFilterBPLibrary_ApplyCustomPreset, "ApplyCustomPreset" }, // 2150608320
		{ &Z_Construct_UFunction_UFilterBPLibrary_AutoTuneFilter, "AutoTuneFilter" }, // 991322057
		{ &Z_Construct_UFunction_UFilterBPLibrary_BlendFilterOutputs, "BlendFilterOutputs" }, // 3392650232
		{ &Z_Construct_UFunction_UFilterBPLibrary_CleanupAllFilters, "CleanupAllFilters" }, // 1703017523
		{ &Z_Construct_UFunction_UFilterBPLibrary_CompareFilterOutputs, "CompareFilterOutputs" }, // 1732789124
		{ &Z_Construct_UFunction_UFilterBPLibrary_CreateCustomPreset, "CreateCustomPreset" }, // 2868755135
		{ &Z_Construct_UFunction_UFilterBPLibrary_CreateFilter, "CreateFilter" }, // 3344913376
		{ &Z_Construct_UFunction_UFilterBPLibrary_CreateFilterChain, "CreateFilterChain" }, // 396770126
		{ &Z_Construct_UFunction_UFilterBPLibrary_EstimateFilterLatency, "EstimateFilterLatency" }, // 3304815231
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueFloat, "GetCurrentValueFloat" }, // 95376793
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetCurrentValueVector, "GetCurrentValueVector" }, // 3305621671
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetFilterDescription, "GetFilterDescription" }, // 1183156137
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetFilterInstance, "GetFilterInstance" }, // 284773068
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetFilterResponseCurve, "GetFilterResponseCurve" }, // 1776166570
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetFilterStatistics, "GetFilterStatistics" }, // 3369106935
		{ &Z_Construct_UFunction_UFilterBPLibrary_GetPresetDescription, "GetPresetDescription" }, // 1619112799
		{ &Z_Construct_UFunction_UFilterBPLibrary_InitializeFilter, "InitializeFilter" }, // 3968843129
		{ &Z_Construct_UFunction_UFilterBPLibrary_IsFilterInitialized, "IsFilterInitialized" }, // 3034094936
		{ &Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterValue, "KalmanFilterValue" }, // 856791745
		{ &Z_Construct_UFunction_UFilterBPLibrary_KalmanFilterVector, "KalmanFilterVector" }, // 1878087637
		{ &Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterValue, "OneEuroFilterValue" }, // 959691650
		{ &Z_Construct_UFunction_UFilterBPLibrary_OneEuroFilterVector, "OneEuroFilterVector" }, // 2384244664
		{ &Z_Construct_UFunction_UFilterBPLibrary_PresetToString, "PresetToString" }, // 3823764866
		{ &Z_Construct_UFunction_UFilterBPLibrary_ProcessThroughChain, "ProcessThroughChain" }, // 4210708462
		{ &Z_Construct_UFunction_UFilterBPLibrary_ProfileFilterUpdate, "ProfileFilterUpdate" }, // 42227486
		{ &Z_Construct_UFunction_UFilterBPLibrary_RecommendFilterType, "RecommendFilterType" }, // 778112016
		{ &Z_Construct_UFunction_UFilterBPLibrary_ResetFilter, "ResetFilter" }, // 3419590280
		{ &Z_Construct_UFunction_UFilterBPLibrary_StartProfiling, "StartProfiling" }, // 2491166705
		{ &Z_Construct_UFunction_UFilterBPLibrary_StopProfiling, "StopProfiling" }, // 3770034760
		{ &Z_Construct_UFunction_UFilterBPLibrary_StringToPreset, "StringToPreset" }, // 927314976
		{ &Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterFloat, "UpdateFilterFloat" }, // 62371976
		{ &Z_Construct_UFunction_UFilterBPLibrary_UpdateFilterVector, "UpdateFilterVector" }, // 3205926456
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFilterBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UFilterBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFilterBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFilterBPLibrary_Statics::ClassParams = {
	&UFilterBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFilterBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UFilterBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFilterBPLibrary()
{
	if (!Z_Registration_Info_UClass_UFilterBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFilterBPLibrary.OuterSingleton, Z_Construct_UClass_UFilterBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFilterBPLibrary.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UClass* StaticClass<UFilterBPLibrary>()
{
	return UFilterBPLibrary::StaticClass();
}
UFilterBPLibrary::UFilterBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFilterBPLibrary);
UFilterBPLibrary::~UFilterBPLibrary() {}
// End Class UFilterBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFilterType_StaticEnum, TEXT("EFilterType"), &Z_Registration_Info_UEnum_EFilterType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3230867610U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCustomFilterPreset::StaticStruct, Z_Construct_UScriptStruct_FCustomFilterPreset_Statics::NewStructOps, TEXT("CustomFilterPreset"), &Z_Registration_Info_UScriptStruct_CustomFilterPreset, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCustomFilterPreset), 1553149815U) },
		{ FFilterChainNode::StaticStruct, Z_Construct_UScriptStruct_FFilterChainNode_Statics::NewStructOps, TEXT("FilterChainNode"), &Z_Registration_Info_UScriptStruct_FilterChainNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFilterChainNode), 2649234700U) },
		{ FFilterPerformanceData::StaticStruct, Z_Construct_UScriptStruct_FFilterPerformanceData_Statics::NewStructOps, TEXT("FilterPerformanceData"), &Z_Registration_Info_UScriptStruct_FilterPerformanceData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFilterPerformanceData), 1086078593U) },
		{ FFilterInstanceManager::StaticStruct, Z_Construct_UScriptStruct_FFilterInstanceManager_Statics::NewStructOps, TEXT("FilterInstanceManager"), &Z_Registration_Info_UScriptStruct_FilterInstanceManager, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFilterInstanceManager), 127526970U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFilterBPLibrary, UFilterBPLibrary::StaticClass, TEXT("UFilterBPLibrary"), &Z_Registration_Info_UClass_UFilterBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFilterBPLibrary), 2568164543U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_3404081813(TEXT("/Script/AdvancedFilters"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
