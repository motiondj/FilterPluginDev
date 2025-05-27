#include "KalmanFilter.h"

UKalmanFilter::UKalmanFilter()
{
    // Default values already set in header
}

void UKalmanFilter::Initialize(EFilterPreset Preset)
{
    // 프리셋에 따른 파라미터 설정
    switch (Preset)
    {
    case EFilterPreset::Low:
        // Fast response, less filtering
        Q = 0.1f;
        R = 0.01f;
        break;

    case EFilterPreset::Medium:
        // Balanced
        Q = 0.01f;
        R = 0.1f;
        break;

    case EFilterPreset::High:
        // Smooth output, more filtering
        Q = 0.001f;
        R = 1.0f;
        break;
    }

    // Initialize error covariance
    P = 1.0f;
    P_X = 1.0f;
    P_Y = 1.0f;
    P_Z = 1.0f;

    bIsInitialized = true;

    UE_LOG(LogTemp, Log, TEXT("Kalman Filter initialized with preset: %s"),
        *UEnum::GetValueAsString(Preset));
}

void UKalmanFilter::Reset()
{
    Super::Reset();

    // Reset all filter states
    P = 1.0f;
    P_X = 1.0f;
    P_Y = 1.0f;
    P_Z = 1.0f;
    K = 0.0f;
}

float UKalmanFilter::UpdateEstimate(float Measurement)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("Kalman Filter not initialized! Using raw measurement."));
        CurrentEstimate = Measurement;
        return Measurement;
    }

    // Prediction step
    // In this simple model, prediction = current estimate
    // P = P + Q (prediction error covariance)
    P = P + Q;

    // Update step
    // Calculate Kalman gain
    K = P / (P + R);

    // Update estimate with measurement
    CurrentEstimate = CurrentEstimate + K * (Measurement - CurrentEstimate);

    // Update error covariance
    P = (1.0f - K) * P;

    return CurrentEstimate;
}

FVector UKalmanFilter::UpdateEstimateVector(const FVector& Measurement)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("Kalman Filter not initialized! Using raw measurement."));
        CurrentEstimateVector = Measurement;
        return Measurement;
    }

    // Update each axis independently
    CurrentEstimateVector.X = UpdateSingleAxis(Measurement.X, P_X, CurrentEstimateVector.X);
    CurrentEstimateVector.Y = UpdateSingleAxis(Measurement.Y, P_Y, CurrentEstimateVector.Y);
    CurrentEstimateVector.Z = UpdateSingleAxis(Measurement.Z, P_Z, CurrentEstimateVector.Z);

    return CurrentEstimateVector;
}

float UKalmanFilter::UpdateSingleAxis(float Measurement, float& EstimateError, float CurrentValue)
{
    // Prediction step
    EstimateError = EstimateError + Q;

    // Update step
    float AxisGain = EstimateError / (EstimateError + R);
    float NewEstimate = CurrentValue + AxisGain * (Measurement - CurrentValue);
    EstimateError = (1.0f - AxisGain) * EstimateError;

    return NewEstimate;
}

void UKalmanFilter::SetProcessNoise(float NewQ)
{
    Q = FMath::Max(0.0001f, NewQ);  // Ensure positive value
    UE_LOG(LogTemp, Log, TEXT("Kalman Filter process noise set to: %f"), Q);
}

void UKalmanFilter::SetMeasurementNoise(float NewR)
{
    R = FMath::Max(0.0001f, NewR);  // Ensure positive value
    UE_LOG(LogTemp, Log, TEXT("Kalman Filter measurement noise set to: %f"), R);
}