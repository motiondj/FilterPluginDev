#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "UObject/Interface.h"
#include "Engine/EngineTypes.h"
#include "BaseFilter.generated.h"

/**
 * Filter strength presets for easy configuration
 * 필터 강도 프리셋 - 초보자를 위한 간편 설정
 */
UENUM(BlueprintType)
enum class EFilterPreset : uint8
{
    Low         UMETA(DisplayName = "Low (Fast Response)"),
    Medium      UMETA(DisplayName = "Medium (Balanced)"),
    High        UMETA(DisplayName = "High (Smooth)")
};

/**
 * Base interface for all filter types
 * 모든 필터의 기본 인터페이스
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UBaseFilter : public UInterface
{
    GENERATED_BODY()
};

class ADVANCEDFILTERS_API IBaseFilter
{
    GENERATED_BODY()

public:
    /**
     * Initialize filter with preset
     * 프리셋으로 필터 초기화
     */
    virtual void Initialize(EFilterPreset Preset) = 0;

    /**
     * Reset filter to initial state
     * 필터를 초기 상태로 리셋
     */
    virtual void Reset() = 0;

    /**
     * Update filter with new measurement (Float)
     * 새로운 측정값으로 필터 업데이트 (Float)
     */
    virtual float UpdateEstimate(float Measurement) = 0;

    /**
     * Update filter with new measurement (Vector)
     * 새로운 측정값으로 필터 업데이트 (Vector)
     */
    virtual FVector UpdateEstimateVector(const FVector& Measurement) = 0;

    /**
     * Get current filter state
     * 현재 필터 상태 가져오기
     */
    virtual float GetCurrentEstimate() const = 0;

    /**
     * Get current filter state (Vector)
     * 현재 필터 상태 가져오기 (Vector)
     */
    virtual FVector GetCurrentEstimateVector() const = 0;
};

/**
 * Base class for filter implementations
 * 필터 구현을 위한 기본 클래스
 */
UCLASS(Abstract, BlueprintType)
class ADVANCEDFILTERS_API UBaseFilterObject : public UObject, public IBaseFilter
{
    GENERATED_BODY()

protected:
    // Current filter state
    UPROPERTY(BlueprintReadOnly, Category = "Filter State")
    float CurrentEstimate = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category = "Filter State")
    FVector CurrentEstimateVector = FVector::ZeroVector;

    // Filter initialized flag
    UPROPERTY(BlueprintReadOnly, Category = "Filter State")
    bool bIsInitialized = false;

public:
    // IBaseFilter interface implementation
    virtual void Initialize(EFilterPreset Preset) override PURE_VIRTUAL(UBaseFilterObject::Initialize, );
    virtual void Reset() override;
    virtual float UpdateEstimate(float Measurement) override PURE_VIRTUAL(UBaseFilterObject::UpdateEstimate, return 0.0f;);
    virtual FVector UpdateEstimateVector(const FVector& Measurement) override PURE_VIRTUAL(UBaseFilterObject::UpdateEstimateVector, return FVector::ZeroVector;);
    virtual float GetCurrentEstimate() const override { return CurrentEstimate; }
    virtual FVector GetCurrentEstimateVector() const override { return CurrentEstimateVector; }

    // Blueprint callable functions
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters", meta = (DisplayName = "Is Initialized"))
    bool IsInitialized() const { return bIsInitialized; }
};