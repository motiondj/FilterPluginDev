// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BaseFilter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADVANCEDFILTERS_BaseFilter_generated_h
#error "BaseFilter.generated.h already included, missing '#pragma once' in BaseFilter.h"
#endif
#define ADVANCEDFILTERS_BaseFilter_generated_h

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDFILTERS_API UBaseFilter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBaseFilter(UBaseFilter&&); \
	UBaseFilter(const UBaseFilter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDFILTERS_API, UBaseFilter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBaseFilter); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBaseFilter) \
	ADVANCEDFILTERS_API virtual ~UBaseFilter();


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUBaseFilter(); \
	friend struct Z_Construct_UClass_UBaseFilter_Statics; \
public: \
	DECLARE_CLASS(UBaseFilter, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AdvancedFilters"), ADVANCEDFILTERS_API) \
	DECLARE_SERIALIZER(UBaseFilter)


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_GENERATED_UINTERFACE_BODY() \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IBaseFilter() {} \
public: \
	typedef UBaseFilter UClassType; \
	typedef IBaseFilter ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_26_PROLOG
#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_29_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDFILTERS_API UClass* StaticClass<class UBaseFilter>();

#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsInitialized);


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBaseFilterObject(); \
	friend struct Z_Construct_UClass_UBaseFilterObject_Statics; \
public: \
	DECLARE_CLASS(UBaseFilterObject, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/AdvancedFilters"), NO_API) \
	DECLARE_SERIALIZER(UBaseFilterObject) \
	virtual UObject* _getUObject() const override { return const_cast<UBaseFilterObject*>(this); }


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBaseFilterObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBaseFilterObject(UBaseFilterObject&&); \
	UBaseFilterObject(const UBaseFilterObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBaseFilterObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBaseFilterObject); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBaseFilterObject) \
	NO_API virtual ~UBaseFilterObject();


#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_78_PROLOG
#define FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h_81_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDFILTERS_API UClass* StaticClass<class UBaseFilterObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_AdvancedFilters_Source_AdvancedFilters_Public_BaseFilter_h


#define FOREACH_ENUM_EFILTERPRESET(op) \
	op(EFilterPreset::Low) \
	op(EFilterPreset::Medium) \
	op(EFilterPreset::High) 

enum class EFilterPreset : uint8;
template<> struct TIsUEnumClass<EFilterPreset> { enum { Value = true }; };
template<> ADVANCEDFILTERS_API UEnum* StaticEnum<EFilterPreset>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
