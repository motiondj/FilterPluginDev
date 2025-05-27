// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OneEuroFilter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVANCEDFILTERS_OneEuroFilter_generated_h
#error "OneEuroFilter.generated.h already included, missing '#pragma once' in OneEuroFilter.h"
#endif
#define ADVANCEDFILTERS_OneEuroFilter_generated_h

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentCutoff); \
	DECLARE_FUNCTION(execSetDerivativeCutoff); \
	DECLARE_FUNCTION(execSetBeta); \
	DECLARE_FUNCTION(execSetMinCutoff); \
	DECLARE_FUNCTION(execUpdateEstimateVectorWithDeltaTime); \
	DECLARE_FUNCTION(execUpdateEstimateWithDeltaTime);


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOneEuroFilter(); \
	friend struct Z_Construct_UClass_UOneEuroFilter_Statics; \
public: \
	DECLARE_CLASS(UOneEuroFilter, UBaseFilterObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedFilters"), NO_API) \
	DECLARE_SERIALIZER(UOneEuroFilter)


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOneEuroFilter(UOneEuroFilter&&); \
	UOneEuroFilter(const UOneEuroFilter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOneEuroFilter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOneEuroFilter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOneEuroFilter) \
	NO_API virtual ~UOneEuroFilter();


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_20_PROLOG
#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDFILTERS_API UClass* StaticClass<class UOneEuroFilter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_OneEuroFilter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
