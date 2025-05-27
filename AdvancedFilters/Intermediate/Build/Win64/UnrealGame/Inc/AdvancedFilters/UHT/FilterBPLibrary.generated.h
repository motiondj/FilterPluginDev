// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FilterBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBaseFilterObject;
enum class EFilterPreset : uint8;
enum class EFilterType : uint8;
struct FCustomFilterPreset;
struct FFilterChainNode;
struct FFilterPerformanceData;
#ifdef ADVANCEDFILTERS_FilterBPLibrary_generated_h
#error "FilterBPLibrary.generated.h already included, missing '#pragma once' in FilterBPLibrary.h"
#endif
#define ADVANCEDFILTERS_FilterBPLibrary_generated_h

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_27_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCustomFilterPreset_Statics; \
	ADVANCEDFILTERS_API static class UScriptStruct* StaticStruct();


template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<struct FCustomFilterPreset>();

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_64_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFilterChainNode_Statics; \
	ADVANCEDFILTERS_API static class UScriptStruct* StaticStruct();


template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<struct FFilterChainNode>();

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_84_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFilterPerformanceData_Statics; \
	ADVANCEDFILTERS_API static class UScriptStruct* StaticStruct();


template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<struct FFilterPerformanceData>();

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_122_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFilterInstanceManager_Statics; \
	ADVANCEDFILTERS_API static class UScriptStruct* StaticStruct();


template<> ADVANCEDFILTERS_API UScriptStruct* StaticStruct<struct FFilterInstanceManager>();

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetFilterInstance); \
	DECLARE_FUNCTION(execProfileFilterUpdate); \
	DECLARE_FUNCTION(execStopProfiling); \
	DECLARE_FUNCTION(execStartProfiling); \
	DECLARE_FUNCTION(execStringToPreset); \
	DECLARE_FUNCTION(execPresetToString); \
	DECLARE_FUNCTION(execApplyCustomPreset); \
	DECLARE_FUNCTION(execCreateCustomPreset); \
	DECLARE_FUNCTION(execBlendFilterOutputs); \
	DECLARE_FUNCTION(execProcessThroughChain); \
	DECLARE_FUNCTION(execCreateFilterChain); \
	DECLARE_FUNCTION(execGetFilterResponseCurve); \
	DECLARE_FUNCTION(execGetFilterStatistics); \
	DECLARE_FUNCTION(execAutoTuneFilter); \
	DECLARE_FUNCTION(execEstimateFilterLatency); \
	DECLARE_FUNCTION(execCompareFilterOutputs); \
	DECLARE_FUNCTION(execGetPresetDescription); \
	DECLARE_FUNCTION(execGetFilterDescription); \
	DECLARE_FUNCTION(execRecommendFilterType); \
	DECLARE_FUNCTION(execCleanupAllFilters); \
	DECLARE_FUNCTION(execIsFilterInitialized); \
	DECLARE_FUNCTION(execGetCurrentValueVector); \
	DECLARE_FUNCTION(execGetCurrentValueFloat); \
	DECLARE_FUNCTION(execResetFilter); \
	DECLARE_FUNCTION(execOneEuroFilterVector); \
	DECLARE_FUNCTION(execOneEuroFilterValue); \
	DECLARE_FUNCTION(execKalmanFilterVector); \
	DECLARE_FUNCTION(execKalmanFilterValue); \
	DECLARE_FUNCTION(execUpdateFilterVector); \
	DECLARE_FUNCTION(execUpdateFilterFloat); \
	DECLARE_FUNCTION(execInitializeFilter); \
	DECLARE_FUNCTION(execCreateFilter);


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFilterBPLibrary(); \
	friend struct Z_Construct_UClass_UFilterBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFilterBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedFilters"), NO_API) \
	DECLARE_SERIALIZER(UFilterBPLibrary)


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFilterBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFilterBPLibrary(UFilterBPLibrary&&); \
	UFilterBPLibrary(const UFilterBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFilterBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFilterBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFilterBPLibrary) \
	NO_API virtual ~UFilterBPLibrary();


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_135_PROLOG
#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h_138_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDFILTERS_API UClass* StaticClass<class UFilterBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_FilterBPLibrary_h


#define FOREACH_ENUM_EFILTERTYPE(op) \
	op(EFilterType::Kalman) \
	op(EFilterType::OneEuro) 

enum class EFilterType : uint8;
template<> struct TIsUEnumClass<EFilterType> { enum { Value = true }; };
template<> ADVANCEDFILTERS_API UEnum* StaticEnum<EFilterType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
