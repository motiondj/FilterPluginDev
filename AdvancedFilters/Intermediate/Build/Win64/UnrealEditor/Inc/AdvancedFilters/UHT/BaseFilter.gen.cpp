// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedFilters/Public/BaseFilter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseFilter() {}

// Begin Cross Module References
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilter();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilter_NoRegister();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilterObject();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilterObject_NoRegister();
ADVANCEDFILTERS_API UEnum* Z_Construct_UEnum_AdvancedFilters_EFilterPreset();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
UPackage* Z_Construct_UPackage__Script_AdvancedFilters();
// End Cross Module References

// Begin Enum EFilterPreset
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFilterPreset;
static UEnum* EFilterPreset_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFilterPreset.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFilterPreset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_AdvancedFilters_EFilterPreset, (UObject*)Z_Construct_UPackage__Script_AdvancedFilters(), TEXT("EFilterPreset"));
	}
	return Z_Registration_Info_UEnum_EFilterPreset.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UEnum* StaticEnum<EFilterPreset>()
{
	return EFilterPreset_StaticEnum();
}
struct Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Filter strength presets for easy configuration\n * \xed\x95\x84\xed\x84\xb0 \xea\xb0\x95\xeb\x8f\x84 \xed\x94\x84\xeb\xa6\xac\xec\x85\x8b - \xec\xb4\x88\xeb\xb3\xb4\xec\x9e\x90\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xea\xb0\x84\xed\x8e\xb8 \xec\x84\xa4\xec\xa0\x95\n */" },
		{ "High.DisplayName", "High (Smooth)" },
		{ "High.Name", "EFilterPreset::High" },
		{ "Low.DisplayName", "Low (Fast Response)" },
		{ "Low.Name", "EFilterPreset::Low" },
		{ "Medium.DisplayName", "Medium (Balanced)" },
		{ "Medium.Name", "EFilterPreset::Medium" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
		{ "ToolTip", "Filter strength presets for easy configuration\n\xed\x95\x84\xed\x84\xb0 \xea\xb0\x95\xeb\x8f\x84 \xed\x94\x84\xeb\xa6\xac\xec\x85\x8b - \xec\xb4\x88\xeb\xb3\xb4\xec\x9e\x90\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xea\xb0\x84\xed\x8e\xb8 \xec\x84\xa4\xec\xa0\x95" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFilterPreset::Low", (int64)EFilterPreset::Low },
		{ "EFilterPreset::Medium", (int64)EFilterPreset::Medium },
		{ "EFilterPreset::High", (int64)EFilterPreset::High },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_AdvancedFilters,
	nullptr,
	"EFilterPreset",
	"EFilterPreset",
	Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::Enum_MetaDataParams), Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_AdvancedFilters_EFilterPreset()
{
	if (!Z_Registration_Info_UEnum_EFilterPreset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFilterPreset.InnerSingleton, Z_Construct_UEnum_AdvancedFilters_EFilterPreset_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFilterPreset.InnerSingleton;
}
// End Enum EFilterPreset

// Begin Interface UBaseFilter
void UBaseFilter::StaticRegisterNativesUBaseFilter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBaseFilter);
UClass* Z_Construct_UClass_UBaseFilter_NoRegister()
{
	return UBaseFilter::StaticClass();
}
struct Z_Construct_UClass_UBaseFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IBaseFilter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBaseFilter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBaseFilter_Statics::ClassParams = {
	&UBaseFilter::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilter_Statics::Class_MetaDataParams), Z_Construct_UClass_UBaseFilter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBaseFilter()
{
	if (!Z_Registration_Info_UClass_UBaseFilter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBaseFilter.OuterSingleton, Z_Construct_UClass_UBaseFilter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBaseFilter.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UClass* StaticClass<UBaseFilter>()
{
	return UBaseFilter::StaticClass();
}
UBaseFilter::UBaseFilter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBaseFilter);
UBaseFilter::~UBaseFilter() {}
// End Interface UBaseFilter

// Begin Class UBaseFilterObject Function IsInitialized
struct Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics
{
	struct BaseFilterObject_eventIsInitialized_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters" },
		{ "Comment", "// Blueprint callable functions\n" },
		{ "DisplayName", "Is Initialized" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
		{ "ToolTip", "Blueprint callable functions" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BaseFilterObject_eventIsInitialized_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BaseFilterObject_eventIsInitialized_Parms), &Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBaseFilterObject, nullptr, "IsInitialized", nullptr, nullptr, Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::BaseFilterObject_eventIsInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::BaseFilterObject_eventIsInitialized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBaseFilterObject_IsInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBaseFilterObject_IsInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBaseFilterObject::execIsInitialized)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInitialized();
	P_NATIVE_END;
}
// End Class UBaseFilterObject Function IsInitialized

// Begin Class UBaseFilterObject
void UBaseFilterObject::StaticRegisterNativesUBaseFilterObject()
{
	UClass* Class = UBaseFilterObject::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "IsInitialized", &UBaseFilterObject::execIsInitialized },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBaseFilterObject);
UClass* Z_Construct_UClass_UBaseFilterObject_NoRegister()
{
	return UBaseFilterObject::StaticClass();
}
struct Z_Construct_UClass_UBaseFilterObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Base class for filter implementations\n * \xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84\xec\x9d\x84 \xec\x9c\x84\xed\x95\x9c \xea\xb8\xb0\xeb\xb3\xb8 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n */" },
		{ "IncludePath", "BaseFilter.h" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
		{ "ToolTip", "Base class for filter implementations\n\xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84\xec\x9d\x84 \xec\x9c\x84\xed\x95\x9c \xea\xb8\xb0\xeb\xb3\xb8 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentEstimate_MetaData[] = {
		{ "Category", "Filter State" },
		{ "Comment", "// Current filter state\n" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
		{ "ToolTip", "Current filter state" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentEstimateVector_MetaData[] = {
		{ "Category", "Filter State" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsInitialized_MetaData[] = {
		{ "Category", "Filter State" },
		{ "Comment", "// Filter initialized flag\n" },
		{ "ModuleRelativePath", "Public/BaseFilter.h" },
		{ "ToolTip", "Filter initialized flag" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentEstimate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentEstimateVector;
	static void NewProp_bIsInitialized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsInitialized;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBaseFilterObject_IsInitialized, "IsInitialized" }, // 2748607804
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBaseFilterObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_CurrentEstimate = { "CurrentEstimate", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBaseFilterObject, CurrentEstimate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentEstimate_MetaData), NewProp_CurrentEstimate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_CurrentEstimateVector = { "CurrentEstimateVector", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBaseFilterObject, CurrentEstimateVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentEstimateVector_MetaData), NewProp_CurrentEstimateVector_MetaData) };
void Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_bIsInitialized_SetBit(void* Obj)
{
	((UBaseFilterObject*)Obj)->bIsInitialized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_bIsInitialized = { "bIsInitialized", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBaseFilterObject), &Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_bIsInitialized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsInitialized_MetaData), NewProp_bIsInitialized_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBaseFilterObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_CurrentEstimate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_CurrentEstimateVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBaseFilterObject_Statics::NewProp_bIsInitialized,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilterObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBaseFilterObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilterObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UBaseFilterObject_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UBaseFilter_NoRegister, (int32)VTABLE_OFFSET(UBaseFilterObject, IBaseFilter), false },  // 2105561073
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBaseFilterObject_Statics::ClassParams = {
	&UBaseFilterObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UBaseFilterObject_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilterObject_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x001000A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBaseFilterObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UBaseFilterObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBaseFilterObject()
{
	if (!Z_Registration_Info_UClass_UBaseFilterObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBaseFilterObject.OuterSingleton, Z_Construct_UClass_UBaseFilterObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBaseFilterObject.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UClass* StaticClass<UBaseFilterObject>()
{
	return UBaseFilterObject::StaticClass();
}
UBaseFilterObject::UBaseFilterObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBaseFilterObject);
UBaseFilterObject::~UBaseFilterObject() {}
// End Class UBaseFilterObject

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFilterPreset_StaticEnum, TEXT("EFilterPreset"), &Z_Registration_Info_UEnum_EFilterPreset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 90198315U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBaseFilter, UBaseFilter::StaticClass, TEXT("UBaseFilter"), &Z_Registration_Info_UClass_UBaseFilter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBaseFilter), 2105561073U) },
		{ Z_Construct_UClass_UBaseFilterObject, UBaseFilterObject::StaticClass, TEXT("UBaseFilterObject"), &Z_Registration_Info_UClass_UBaseFilterObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBaseFilterObject), 1021066702U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_2345633607(TEXT("/Script/AdvancedFilters"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
