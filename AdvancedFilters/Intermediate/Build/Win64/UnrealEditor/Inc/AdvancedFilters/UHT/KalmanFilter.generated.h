// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "KalmanFilter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVANCEDFILTERS_KalmanFilter_generated_h
#error "KalmanFilter.generated.h already included, missing '#pragma once' in KalmanFilter.h"
#endif
#define ADVANCEDFILTERS_KalmanFilter_generated_h

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetErrorCovariance); \
	DECLARE_FUNCTION(execGetKalmanGain); \
	DECLARE_FUNCTION(execSetMeasurementNoise); \
	DECLARE_FUNCTION(execSetProcessNoise);


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUKalmanFilter(); \
	friend struct Z_Construct_UClass_UKalmanFilter_Statics; \
public: \
	DECLARE_CLASS(UKalmanFilter, UBaseFilterObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedFilters"), NO_API) \
	DECLARE_SERIALIZER(UKalmanFilter)


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UKalmanFilter(UKalmanFilter&&); \
	UKalmanFilter(const UKalmanFilter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UKalmanFilter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UKalmanFilter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UKalmanFilter) \
	NO_API virtual ~UKalmanFilter();


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_11_PROLOG
#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDFILTERS_API UClass* StaticClass<class UKalmanFilter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_KalmanFilter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
