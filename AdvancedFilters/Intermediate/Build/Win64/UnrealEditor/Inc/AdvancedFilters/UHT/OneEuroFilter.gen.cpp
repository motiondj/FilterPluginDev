// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedFilters/Public/OneEuroFilter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOneEuroFilter() {}

// Begin Cross Module References
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilterObject();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UOneEuroFilter();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UOneEuroFilter_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
UPackage* Z_Construct_UPackage__Script_AdvancedFilters();
// End Cross Module References

// Begin Class UOneEuroFilter Function GetCurrentCutoff
struct Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics
{
	struct OneEuroFilter_eventGetCurrentCutoff_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "DisplayName", "Get Current Cutoff" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventGetCurrentCutoff_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "GetCurrentCutoff", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::OneEuroFilter_eventGetCurrentCutoff_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::OneEuroFilter_eventGetCurrentCutoff_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execGetCurrentCutoff)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentCutoff();
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function GetCurrentCutoff

// Begin Class UOneEuroFilter Function SetBeta
struct Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics
{
	struct OneEuroFilter_eventSetBeta_Parms
	{
		float NewBeta;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "DisplayName", "Set Beta" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewBeta;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::NewProp_NewBeta = { "NewBeta", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventSetBeta_Parms, NewBeta), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::NewProp_NewBeta,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "SetBeta", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::OneEuroFilter_eventSetBeta_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::OneEuroFilter_eventSetBeta_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_SetBeta()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_SetBeta_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execSetBeta)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewBeta);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBeta(Z_Param_NewBeta);
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function SetBeta

// Begin Class UOneEuroFilter Function SetDerivativeCutoff
struct Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics
{
	struct OneEuroFilter_eventSetDerivativeCutoff_Parms
	{
		float NewDCutoff;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "DisplayName", "Set Derivative Cutoff" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewDCutoff;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::NewProp_NewDCutoff = { "NewDCutoff", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventSetDerivativeCutoff_Parms, NewDCutoff), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::NewProp_NewDCutoff,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "SetDerivativeCutoff", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::OneEuroFilter_eventSetDerivativeCutoff_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::OneEuroFilter_eventSetDerivativeCutoff_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execSetDerivativeCutoff)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewDCutoff);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDerivativeCutoff(Z_Param_NewDCutoff);
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function SetDerivativeCutoff

// Begin Class UOneEuroFilter Function SetMinCutoff
struct Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics
{
	struct OneEuroFilter_eventSetMinCutoff_Parms
	{
		float NewMinCutoff;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "Comment", "// Advanced parameter control for experienced users\n" },
		{ "DisplayName", "Set Min Cutoff" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Advanced parameter control for experienced users" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewMinCutoff;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::NewProp_NewMinCutoff = { "NewMinCutoff", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventSetMinCutoff_Parms, NewMinCutoff), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::NewProp_NewMinCutoff,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "SetMinCutoff", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::OneEuroFilter_eventSetMinCutoff_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::OneEuroFilter_eventSetMinCutoff_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execSetMinCutoff)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewMinCutoff);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinCutoff(Z_Param_NewMinCutoff);
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function SetMinCutoff

// Begin Class UOneEuroFilter Function UpdateEstimateVectorWithDeltaTime
struct Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics
{
	struct OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms
	{
		FVector Measurement;
		float DeltaTime;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "DisplayName", "Update Vector With Delta Time" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Measurement_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Measurement;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_Measurement = { "Measurement", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms, Measurement), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Measurement_MetaData), NewProp_Measurement_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_Measurement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "UpdateEstimateVectorWithDeltaTime", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::OneEuroFilter_eventUpdateEstimateVectorWithDeltaTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execUpdateEstimateVectorWithDeltaTime)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Measurement);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->UpdateEstimateVectorWithDeltaTime(Z_Param_Out_Measurement,Z_Param_DeltaTime);
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function UpdateEstimateVectorWithDeltaTime

// Begin Class UOneEuroFilter Function UpdateEstimateWithDeltaTime
struct Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics
{
	struct OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms
	{
		float Measurement;
		float DeltaTime;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|One Euro" },
		{ "Comment", "// One Euro specific update with delta time\n" },
		{ "DisplayName", "Update With Delta Time" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "One Euro specific update with delta time" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Measurement;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_Measurement = { "Measurement", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms, Measurement), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_Measurement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_DeltaTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOneEuroFilter, nullptr, "UpdateEstimateWithDeltaTime", nullptr, nullptr, Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::OneEuroFilter_eventUpdateEstimateWithDeltaTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOneEuroFilter::execUpdateEstimateWithDeltaTime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Measurement);
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->UpdateEstimateWithDeltaTime(Z_Param_Measurement,Z_Param_DeltaTime);
	P_NATIVE_END;
}
// End Class UOneEuroFilter Function UpdateEstimateWithDeltaTime

// Begin Class UOneEuroFilter
void UOneEuroFilter::StaticRegisterNativesUOneEuroFilter()
{
	UClass* Class = UOneEuroFilter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCurrentCutoff", &UOneEuroFilter::execGetCurrentCutoff },
		{ "SetBeta", &UOneEuroFilter::execSetBeta },
		{ "SetDerivativeCutoff", &UOneEuroFilter::execSetDerivativeCutoff },
		{ "SetMinCutoff", &UOneEuroFilter::execSetMinCutoff },
		{ "UpdateEstimateVectorWithDeltaTime", &UOneEuroFilter::execUpdateEstimateVectorWithDeltaTime },
		{ "UpdateEstimateWithDeltaTime", &UOneEuroFilter::execUpdateEstimateWithDeltaTime },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOneEuroFilter);
UClass* Z_Construct_UClass_UOneEuroFilter_NoRegister()
{
	return UOneEuroFilter::StaticClass();
}
struct Z_Construct_UClass_UOneEuroFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * One Euro Filter implementation for low-latency filtering\n * \xec\xa0\x80\xec\xa7\x80\xec\x97\xb0 \xed\x95\x84\xed\x84\xb0\xeb\xa7\x81\xec\x9d\x84 \xec\x9c\x84\xed\x95\x9c \xec\x9b\x90\xec\x9c\xa0\xeb\xa1\x9c\xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84\n *\n * Based on: \"1\xe2\x82\xac Filter: A Simple Speed-based Low-pass Filter for Noisy Input\"\n * by G\xc3\xa9ry Casiez, Nicolas Roussel, and Daniel Vogel\n */" },
		{ "IncludePath", "OneEuroFilter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "One Euro Filter implementation for low-latency filtering\n\xec\xa0\x80\xec\xa7\x80\xec\x97\xb0 \xed\x95\x84\xed\x84\xb0\xeb\xa7\x81\xec\x9d\x84 \xec\x9c\x84\xed\x95\x9c \xec\x9b\x90\xec\x9c\xa0\xeb\xa1\x9c\xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84\n\nBased on: \"1\xe2\x82\xac Filter: A Simple Speed-based Low-pass Filter for Noisy Input\"\nby G\xc3\xa9ry Casiez, Nicolas Roussel, and Daniel Vogel" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinCutoff_MetaData[] = {
		{ "Comment", "// Filter parameters\n" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Filter parameters" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Beta_MetaData[] = {
		{ "Comment", "// Minimum cutoff frequency (Hz)\n" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Minimum cutoff frequency (Hz)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DCutoff_MetaData[] = {
		{ "Comment", "// Cutoff slope - higher = more aggressive filtering\n" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Cutoff slope - higher = more aggressive filtering" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousValue_MetaData[] = {
		{ "Comment", "// Internal state for float filtering\n" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Internal state for float filtering" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousFilteredValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousDerivative_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFirstUpdate_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousVectorValue_MetaData[] = {
		{ "Comment", "// Internal state for vector filtering - \xea\xb0\x81 \xec\xb6\x95\xeb\xb3\x84 \xec\x83\x81\xed\x83\x9c\n" },
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
		{ "ToolTip", "Internal state for vector filtering - \xea\xb0\x81 \xec\xb6\x95\xeb\xb3\x84 \xec\x83\x81\xed\x83\x9c" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousFilteredVectorValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviousVectorDerivative_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bFirstVectorUpdate_MetaData[] = {
		{ "ModuleRelativePath", "Public/OneEuroFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinCutoff;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Beta;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DCutoff;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviousValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviousFilteredValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviousDerivative;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviousTime;
	static void NewProp_bFirstUpdate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFirstUpdate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousVectorValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousFilteredVectorValue;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PreviousVectorDerivative;
	static void NewProp_bFirstVectorUpdate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFirstVectorUpdate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOneEuroFilter_GetCurrentCutoff, "GetCurrentCutoff" }, // 1731371765
		{ &Z_Construct_UFunction_UOneEuroFilter_SetBeta, "SetBeta" }, // 810333363
		{ &Z_Construct_UFunction_UOneEuroFilter_SetDerivativeCutoff, "SetDerivativeCutoff" }, // 3295326416
		{ &Z_Construct_UFunction_UOneEuroFilter_SetMinCutoff, "SetMinCutoff" }, // 3738380228
		{ &Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateVectorWithDeltaTime, "UpdateEstimateVectorWithDeltaTime" }, // 1246694235
		{ &Z_Construct_UFunction_UOneEuroFilter_UpdateEstimateWithDeltaTime, "UpdateEstimateWithDeltaTime" }, // 1705875425
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOneEuroFilter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_MinCutoff = { "MinCutoff", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, MinCutoff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinCutoff_MetaData), NewProp_MinCutoff_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_Beta = { "Beta", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, Beta), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Beta_MetaData), NewProp_Beta_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_DCutoff = { "DCutoff", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, DCutoff), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DCutoff_MetaData), NewProp_DCutoff_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousValue = { "PreviousValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousValue_MetaData), NewProp_PreviousValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousFilteredValue = { "PreviousFilteredValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousFilteredValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousFilteredValue_MetaData), NewProp_PreviousFilteredValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousDerivative = { "PreviousDerivative", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousDerivative), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousDerivative_MetaData), NewProp_PreviousDerivative_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousTime = { "PreviousTime", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousTime_MetaData), NewProp_PreviousTime_MetaData) };
void Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstUpdate_SetBit(void* Obj)
{
	((UOneEuroFilter*)Obj)->bFirstUpdate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstUpdate = { "bFirstUpdate", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOneEuroFilter), &Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstUpdate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFirstUpdate_MetaData), NewProp_bFirstUpdate_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousVectorValue = { "PreviousVectorValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousVectorValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousVectorValue_MetaData), NewProp_PreviousVectorValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousFilteredVectorValue = { "PreviousFilteredVectorValue", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousFilteredVectorValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousFilteredVectorValue_MetaData), NewProp_PreviousFilteredVectorValue_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousVectorDerivative = { "PreviousVectorDerivative", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOneEuroFilter, PreviousVectorDerivative), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviousVectorDerivative_MetaData), NewProp_PreviousVectorDerivative_MetaData) };
void Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstVectorUpdate_SetBit(void* Obj)
{
	((UOneEuroFilter*)Obj)->bFirstVectorUpdate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstVectorUpdate = { "bFirstVectorUpdate", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOneEuroFilter), &Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstVectorUpdate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bFirstVectorUpdate_MetaData), NewProp_bFirstVectorUpdate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOneEuroFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_MinCutoff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_Beta,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_DCutoff,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousFilteredValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousDerivative,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstUpdate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousVectorValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousFilteredVectorValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_PreviousVectorDerivative,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOneEuroFilter_Statics::NewProp_bFirstVectorUpdate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOneEuroFilter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOneEuroFilter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBaseFilterObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOneEuroFilter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOneEuroFilter_Statics::ClassParams = {
	&UOneEuroFilter::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOneEuroFilter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOneEuroFilter_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOneEuroFilter_Statics::Class_MetaDataParams), Z_Construct_UClass_UOneEuroFilter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOneEuroFilter()
{
	if (!Z_Registration_Info_UClass_UOneEuroFilter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOneEuroFilter.OuterSingleton, Z_Construct_UClass_UOneEuroFilter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOneEuroFilter.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UClass* StaticClass<UOneEuroFilter>()
{
	return UOneEuroFilter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOneEuroFilter);
UOneEuroFilter::~UOneEuroFilter() {}
// End Class UOneEuroFilter

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOneEuroFilter, UOneEuroFilter::StaticClass, TEXT("UOneEuroFilter"), &Z_Registration_Info_UClass_UOneEuroFilter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOneEuroFilter), 1984257527U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_2078378145(TEXT("/Script/AdvancedFilters"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
