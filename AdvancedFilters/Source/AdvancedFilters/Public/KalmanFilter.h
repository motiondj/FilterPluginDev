#pragma once

#include "CoreMinimal.h"
#include "BaseFilter.h"
#include "KalmanFilter.generated.h"

/**
 * Simple 1D Kalman Filter implementation
 * 1차원 칼만 필터 구현
 */
UCLASS(BlueprintType, Blueprintable)
class ADVANCEDFILTERS_API UKalmanFilter : public UBaseFilterObject
{
    GENERATED_BODY()

private:
    // Process noise covariance
    UPROPERTY()
    float Q = 0.01f;

    // Measurement noise covariance  
    UPROPERTY()
    float R = 0.1f;

    // Estimation error covariance
    UPROPERTY()
    float P = 1.0f;

    // Kalman gain
    UPROPERTY()
    float K = 0.0f;

    // For vector filtering - 각 축에 대한 개별 칼만 필터 상태
    UPROPERTY()
    float P_X = 1.0f;

    UPROPERTY()
    float P_Y = 1.0f;

    UPROPERTY()
    float P_Z = 1.0f;

public:
    UKalmanFilter();

    // IBaseFilter interface implementation
    virtual void Initialize(EFilterPreset Preset) override;
    virtual void Reset() override;
    virtual float UpdateEstimate(float Measurement) override;
    virtual FVector UpdateEstimateVector(const FVector& Measurement) override;

    // Blueprint exposed functions for advanced users
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Kalman", meta = (DisplayName = "Set Process Noise"))
    void SetProcessNoise(float NewQ);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Kalman", meta = (DisplayName = "Set Measurement Noise"))
    void SetMeasurementNoise(float NewR);

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Kalman", meta = (DisplayName = "Get Kalman Gain"))
    float GetKalmanGain() const { return K; }

    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Kalman", meta = (DisplayName = "Get Error Covariance"))
    float GetErrorCovariance() const { return P; }

protected:
    // Helper function to update single axis
    float UpdateSingleAxis(float Measurement, float& EstimateError, float CurrentValue);
};