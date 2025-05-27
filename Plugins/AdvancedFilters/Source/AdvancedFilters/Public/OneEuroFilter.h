#pragma once

#include "CoreMinimal.h"
#include "BaseFilter.h"
#include "Math/UnrealMathUtility.h"  // PI 상수를 위해 추가
#include "OneEuroFilter.generated.h"

// PI 상수 정의 (언리얼 엔진에서는 UE_PI 사용)
#ifndef PI
#define PI UE_PI
#endif

/**
 * One Euro Filter implementation for low-latency filtering
 * 저지연 필터링을 위한 원유로필터 구현
 *
 * Based on: "1€ Filter: A Simple Speed-based Low-pass Filter for Noisy Input"
 * by Géry Casiez, Nicolas Roussel, and Daniel Vogel
 */
UCLASS(BlueprintType, Blueprintable)
class ADVANCEDFILTERS_API UOneEuroFilter : public UBaseFilterObject
{
    GENERATED_BODY()

private:
    // Filter parameters
    UPROPERTY()
    float MinCutoff = 1.0f;  // Minimum cutoff frequency (Hz)

    UPROPERTY()
    float Beta = 0.007f;     // Cutoff slope - higher = more aggressive filtering

    UPROPERTY()
    float DCutoff = 1.0f;    // Derivative cutoff frequency

    // Internal state for float filtering
    UPROPERTY()
    float PreviousValue = 0.0f;

    UPROPERTY()
    float PreviousFilteredValue = 0.0f;

    UPROPERTY()
    float PreviousDerivative = 0.0f;

    UPROPERTY()
    float PreviousTime = 0.0f;

    UPROPERTY()
    bool bFirstUpdate = true;

    // Internal state for vector filtering - 각 축별 상태
    UPROPERTY()
    FVector PreviousVectorValue = FVector::ZeroVector;

    UPROPERTY()
    FVector PreviousFilteredVectorValue = FVector::ZeroVector;

    UPROPERTY()
    FVector PreviousVectorDerivative = FVector::ZeroVector;

    UPROPERTY()
    bool bFirstVectorUpdate = true;

public:
    UOneEuroFilter();

    // IBaseFilter interface implementation
    virtual void Initialize(EFilterPreset Preset) override;
    virtual void Reset() override;
    virtual float UpdateEstimate(float Measurement) override;
    virtual FVector UpdateEstimateVector(const FVector& Measurement) override;

    // One Euro specific update with delta time
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Update With Delta Time"))
    float UpdateEstimateWithDeltaTime(float Measurement, float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Update Vector With Delta Time"))
    FVector UpdateEstimateVectorWithDeltaTime(const FVector& Measurement, float DeltaTime);

    // Advanced parameter control for experienced users
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Set Min Cutoff"))
    void SetMinCutoff(float NewMinCutoff);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Set Beta"))
    void SetBeta(float NewBeta);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Set Derivative Cutoff"))
    void SetDerivativeCutoff(float NewDCutoff);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One Euro", meta = (DisplayName = "Get Current Cutoff"))
    float GetCurrentCutoff() const;

protected:
    // Low-pass filter implementation
    float LowPassFilter(float Value, float PreviousFilteredValue, float Alpha);

    // Calculate alpha from cutoff frequency
    float CalculateAlpha(float Cutoff, float DeltaTime);

    // Process single value with explicit delta time
    float ProcessValue(float Value, float DeltaTime);

    // Process single axis for vector
    float ProcessSingleAxis(float Value, float& PrevValue, float& PrevFiltered,
        float& PrevDerivative, bool& bFirst, float DeltaTime);
};