// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdvancedFilters/Public/KalmanFilter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKalmanFilter() {}

// Begin Cross Module References
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UBaseFilterObject();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UKalmanFilter();
ADVANCEDFILTERS_API UClass* Z_Construct_UClass_UKalmanFilter_NoRegister();
UPackage* Z_Construct_UPackage__Script_AdvancedFilters();
// End Cross Module References

// Begin Class UKalmanFilter Function GetErrorCovariance
struct Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics
{
	struct KalmanFilter_eventGetErrorCovariance_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Kalman" },
		{ "DisplayName", "Get Error Covariance" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KalmanFilter_eventGetErrorCovariance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKalmanFilter, nullptr, "GetErrorCovariance", nullptr, nullptr, Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::KalmanFilter_eventGetErrorCovariance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::KalmanFilter_eventGetErrorCovariance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UKalmanFilter::execGetErrorCovariance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetErrorCovariance();
	P_NATIVE_END;
}
// End Class UKalmanFilter Function GetErrorCovariance

// Begin Class UKalmanFilter Function GetKalmanGain
struct Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics
{
	struct KalmanFilter_eventGetKalmanGain_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Kalman" },
		{ "DisplayName", "Get Kalman Gain" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KalmanFilter_eventGetKalmanGain_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKalmanFilter, nullptr, "GetKalmanGain", nullptr, nullptr, Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::KalmanFilter_eventGetKalmanGain_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::KalmanFilter_eventGetKalmanGain_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UKalmanFilter_GetKalmanGain()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKalmanFilter_GetKalmanGain_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UKalmanFilter::execGetKalmanGain)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetKalmanGain();
	P_NATIVE_END;
}
// End Class UKalmanFilter Function GetKalmanGain

// Begin Class UKalmanFilter Function SetMeasurementNoise
struct Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics
{
	struct KalmanFilter_eventSetMeasurementNoise_Parms
	{
		float NewR;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Kalman" },
		{ "DisplayName", "Set Measurement Noise" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewR;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::NewProp_NewR = { "NewR", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KalmanFilter_eventSetMeasurementNoise_Parms, NewR), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::NewProp_NewR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKalmanFilter, nullptr, "SetMeasurementNoise", nullptr, nullptr, Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::KalmanFilter_eventSetMeasurementNoise_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::KalmanFilter_eventSetMeasurementNoise_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UKalmanFilter::execSetMeasurementNoise)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewR);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMeasurementNoise(Z_Param_NewR);
	P_NATIVE_END;
}
// End Class UKalmanFilter Function SetMeasurementNoise

// Begin Class UKalmanFilter Function SetProcessNoise
struct Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics
{
	struct KalmanFilter_eventSetProcessNoise_Parms
	{
		float NewQ;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Advanced Filters|Kalman" },
		{ "Comment", "// Blueprint exposed functions for advanced users\n" },
		{ "DisplayName", "Set Process Noise" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Blueprint exposed functions for advanced users" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewQ;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::NewProp_NewQ = { "NewQ", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(KalmanFilter_eventSetProcessNoise_Parms, NewQ), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::NewProp_NewQ,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKalmanFilter, nullptr, "SetProcessNoise", nullptr, nullptr, Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::KalmanFilter_eventSetProcessNoise_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::KalmanFilter_eventSetProcessNoise_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UKalmanFilter_SetProcessNoise()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKalmanFilter_SetProcessNoise_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UKalmanFilter::execSetProcessNoise)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewQ);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetProcessNoise(Z_Param_NewQ);
	P_NATIVE_END;
}
// End Class UKalmanFilter Function SetProcessNoise

// Begin Class UKalmanFilter
void UKalmanFilter::StaticRegisterNativesUKalmanFilter()
{
	UClass* Class = UKalmanFilter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetErrorCovariance", &UKalmanFilter::execGetErrorCovariance },
		{ "GetKalmanGain", &UKalmanFilter::execGetKalmanGain },
		{ "SetMeasurementNoise", &UKalmanFilter::execSetMeasurementNoise },
		{ "SetProcessNoise", &UKalmanFilter::execSetProcessNoise },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UKalmanFilter);
UClass* Z_Construct_UClass_UKalmanFilter_NoRegister()
{
	return UKalmanFilter::StaticClass();
}
struct Z_Construct_UClass_UKalmanFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Simple 1D Kalman Filter implementation\n * 1\xec\xb0\xa8\xec\x9b\x90 \xec\xb9\xbc\xeb\xa7\x8c \xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84\n */" },
		{ "IncludePath", "KalmanFilter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Simple 1D Kalman Filter implementation\n1\xec\xb0\xa8\xec\x9b\x90 \xec\xb9\xbc\xeb\xa7\x8c \xed\x95\x84\xed\x84\xb0 \xea\xb5\xac\xed\x98\x84" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Q_MetaData[] = {
		{ "Comment", "// Process noise covariance\n" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Process noise covariance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_R_MetaData[] = {
		{ "Comment", "// Measurement noise covariance  \n" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Measurement noise covariance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_P_MetaData[] = {
		{ "Comment", "// Estimation error covariance\n" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Estimation error covariance" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_K_MetaData[] = {
		{ "Comment", "// Kalman gain\n" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "Kalman gain" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_P_X_MetaData[] = {
		{ "Comment", "// For vector filtering - \xea\xb0\x81 \xec\xb6\x95\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xea\xb0\x9c\xeb\xb3\x84 \xec\xb9\xbc\xeb\xa7\x8c \xed\x95\x84\xed\x84\xb0 \xec\x83\x81\xed\x83\x9c\n" },
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
		{ "ToolTip", "For vector filtering - \xea\xb0\x81 \xec\xb6\x95\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xea\xb0\x9c\xeb\xb3\x84 \xec\xb9\xbc\xeb\xa7\x8c \xed\x95\x84\xed\x84\xb0 \xec\x83\x81\xed\x83\x9c" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_P_Y_MetaData[] = {
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_P_Z_MetaData[] = {
		{ "ModuleRelativePath", "Public/KalmanFilter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Q;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_R;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_P;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_K;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_P_X;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_P_Y;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_P_Z;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UKalmanFilter_GetErrorCovariance, "GetErrorCovariance" }, // 1004440744
		{ &Z_Construct_UFunction_UKalmanFilter_GetKalmanGain, "GetKalmanGain" }, // 1353449806
		{ &Z_Construct_UFunction_UKalmanFilter_SetMeasurementNoise, "SetMeasurementNoise" }, // 2238258828
		{ &Z_Construct_UFunction_UKalmanFilter_SetProcessNoise, "SetProcessNoise" }, // 3918422000
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKalmanFilter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_Q = { "Q", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, Q), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Q_MetaData), NewProp_Q_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_R = { "R", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, R), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_R_MetaData), NewProp_R_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P = { "P", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, P), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_P_MetaData), NewProp_P_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_K = { "K", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, K), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_K_MetaData), NewProp_K_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_X = { "P_X", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, P_X), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_P_X_MetaData), NewProp_P_X_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_Y = { "P_Y", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, P_Y), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_P_Y_MetaData), NewProp_P_Y_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_Z = { "P_Z", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKalmanFilter, P_Z), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_P_Z_MetaData), NewProp_P_Z_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UKalmanFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_Q,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_R,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_K,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_X,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_Y,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKalmanFilter_Statics::NewProp_P_Z,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKalmanFilter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UKalmanFilter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBaseFilterObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AdvancedFilters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKalmanFilter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UKalmanFilter_Statics::ClassParams = {
	&UKalmanFilter::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UKalmanFilter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UKalmanFilter_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKalmanFilter_Statics::Class_MetaDataParams), Z_Construct_UClass_UKalmanFilter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UKalmanFilter()
{
	if (!Z_Registration_Info_UClass_UKalmanFilter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UKalmanFilter.OuterSingleton, Z_Construct_UClass_UKalmanFilter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UKalmanFilter.OuterSingleton;
}
template<> ADVANCEDFILTERS_API UClass* StaticClass<UKalmanFilter>()
{
	return UKalmanFilter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UKalmanFilter);
UKalmanFilter::~UKalmanFilter() {}
// End Class UKalmanFilter

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UKalmanFilter, UKalmanFilter::StaticClass, TEXT("UKalmanFilter"), &Z_Registration_Info_UClass_UKalmanFilter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKalmanFilter), 2736424959U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_375238047(TEXT("/Script/AdvancedFilters"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
