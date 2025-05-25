#include "OneEuroFilter.h"
#include "Engine/World.h"

UOneEuroFilter::UOneEuroFilter()
{
    // Default values already set in header
}

void UOneEuroFilter::Initialize(EFilterPreset Preset)
{
    // 프리셋에 따른 파라미터 설정
    switch (Preset)
    {
    case EFilterPreset::Low:
        // Minimal filtering, fastest response
        MinCutoff = 1.0f;
        Beta = 0.001f;
        DCutoff = 1.0f;
        break;

    case EFilterPreset::Medium:
        // Balanced filtering
        MinCutoff = 0.5f;
        Beta = 0.007f;
        DCutoff = 1.0f;
        break;

    case EFilterPreset::High:
        // Strong filtering, smoothest output
        MinCutoff = 0.1f;
        Beta = 0.01f;
        DCutoff = 1.0f;
        break;
    }

    bIsInitialized = true;

    UE_LOG(LogTemp, Log, TEXT("One Euro Filter initialized with preset: %s"),
        *UEnum::GetValueAsString(Preset));
}

void UOneEuroFilter::Reset()
{
    Super::Reset();

    // Reset all filter states
    bFirstUpdate = true;
    bFirstVectorUpdate = true;
    PreviousValue = 0.0f;
    PreviousFilteredValue = 0.0f;
    PreviousDerivative = 0.0f;
    PreviousTime = 0.0f;
    PreviousVectorValue = FVector::ZeroVector;
    PreviousFilteredVectorValue = FVector::ZeroVector;
    PreviousVectorDerivative = FVector::ZeroVector;
}

float UOneEuroFilter::UpdateEstimate(float Measurement)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("One Euro Filter not initialized! Using raw measurement."));
        CurrentEstimate = Measurement;
        return Measurement;
    }

    // Use default delta time (assuming 60 FPS)
    const float DefaultDeltaTime = 1.0f / 60.0f;
    return UpdateEstimateWithDeltaTime(Measurement, DefaultDeltaTime);
}

float UOneEuroFilter::UpdateEstimateWithDeltaTime(float Measurement, float DeltaTime)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("One Euro Filter not initialized! Using raw measurement."));
        CurrentEstimate = Measurement;
        return Measurement;
    }

    // Clamp delta time to prevent instability
    DeltaTime = FMath::Max(0.001f, DeltaTime);

    CurrentEstimate = ProcessValue(Measurement, DeltaTime);
    return CurrentEstimate;
}

FVector UOneEuroFilter::UpdateEstimateVector(const FVector& Measurement)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("One Euro Filter not initialized! Using raw measurement."));
        CurrentEstimateVector = Measurement;
        return Measurement;
    }

    // Use default delta time (assuming 60 FPS)
    const float DefaultDeltaTime = 1.0f / 60.0f;
    return UpdateEstimateVectorWithDeltaTime(Measurement, DefaultDeltaTime);
}

FVector UOneEuroFilter::UpdateEstimateVectorWithDeltaTime(const FVector& Measurement, float DeltaTime)
{
    if (!bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("One Euro Filter not initialized! Using raw measurement."));
        CurrentEstimateVector = Measurement;
        return Measurement;
    }

    // FVector 컴포넌트를 float로 변환하여 처리
    float MeasX = static_cast<float>(Measurement.X);
    float MeasY = static_cast<float>(Measurement.Y);
    float MeasZ = static_cast<float>(Measurement.Z);

    float PrevX = static_cast<float>(PreviousVectorValue.X);
    float PrevY = static_cast<float>(PreviousVectorValue.Y);
    float PrevZ = static_cast<float>(PreviousVectorValue.Z);

    float PrevFilteredX = static_cast<float>(PreviousFilteredVectorValue.X);
    float PrevFilteredY = static_cast<float>(PreviousFilteredVectorValue.Y);
    float PrevFilteredZ = static_cast<float>(PreviousFilteredVectorValue.Z);

    float PrevDerivX = static_cast<float>(PreviousVectorDerivative.X);
    float PrevDerivY = static_cast<float>(PreviousVectorDerivative.Y);
    float PrevDerivZ = static_cast<float>(PreviousVectorDerivative.Z);

    // Process each axis independently
    float FilteredX = ProcessSingleAxis(MeasX, PrevX, PrevFilteredX, PrevDerivX, bFirstVectorUpdate, DeltaTime);
    float FilteredY = ProcessSingleAxis(MeasY, PrevY, PrevFilteredY, PrevDerivY, bFirstVectorUpdate, DeltaTime);
    float FilteredZ = ProcessSingleAxis(MeasZ, PrevZ, PrevFilteredZ, PrevDerivZ, bFirstVectorUpdate, DeltaTime);

    // 상태 업데이트
    PreviousVectorValue.X = PrevX;
    PreviousVectorValue.Y = PrevY;
    PreviousVectorValue.Z = PrevZ;

    PreviousFilteredVectorValue.X = PrevFilteredX;
    PreviousFilteredVectorValue.Y = PrevFilteredY;
    PreviousFilteredVectorValue.Z = PrevFilteredZ;

    PreviousVectorDerivative.X = PrevDerivX;
    PreviousVectorDerivative.Y = PrevDerivY;
    PreviousVectorDerivative.Z = PrevDerivZ;

    CurrentEstimateVector = FVector(FilteredX, FilteredY, FilteredZ);
    bFirstVectorUpdate = false;

    return CurrentEstimateVector;
}

float UOneEuroFilter::ProcessValue(float Value, float DeltaTime)
{
    if (bFirstUpdate)
    {
        PreviousValue = Value;
        PreviousFilteredValue = Value;
        PreviousDerivative = 0.0f;
        bFirstUpdate = false;
        return Value;
    }

    // Calculate derivative (speed of change)
    float Derivative = (Value - PreviousValue) / DeltaTime;

    // Filter the derivative
    float AlphaD = CalculateAlpha(DCutoff, DeltaTime);
    float FilteredDerivative = LowPassFilter(Derivative, PreviousDerivative, AlphaD);

    // Calculate adaptive cutoff frequency based on speed
    float Speed = FMath::Abs(FilteredDerivative);
    float Cutoff = MinCutoff + Beta * Speed;

    // Filter the value
    float Alpha = CalculateAlpha(Cutoff, DeltaTime);
    float FilteredValue = LowPassFilter(Value, PreviousFilteredValue, Alpha);

    // Update state
    PreviousValue = Value;
    PreviousFilteredValue = FilteredValue;
    PreviousDerivative = FilteredDerivative;

    return FilteredValue;
}

float UOneEuroFilter::ProcessSingleAxis(float Value, float& PrevValue, float& PrevFiltered,
    float& PrevDerivative, bool& bFirst, float DeltaTime)
{
    if (bFirst)
    {
        PrevValue = Value;
        PrevFiltered = Value;
        PrevDerivative = 0.0f;
        return Value;
    }

    // Calculate derivative
    float Derivative = (Value - PrevValue) / DeltaTime;

    // Filter the derivative
    float AlphaD = CalculateAlpha(DCutoff, DeltaTime);
    float FilteredDerivative = LowPassFilter(Derivative, PrevDerivative, AlphaD);

    // Calculate adaptive cutoff
    float Speed = FMath::Abs(FilteredDerivative);
    float Cutoff = MinCutoff + Beta * Speed;

    // Filter the value
    float Alpha = CalculateAlpha(Cutoff, DeltaTime);
    float FilteredValue = LowPassFilter(Value, PrevFiltered, Alpha);

    // Update state
    PrevValue = Value;
    PrevFiltered = FilteredValue;
    PrevDerivative = FilteredDerivative;

    return FilteredValue;
}

float UOneEuroFilter::LowPassFilter(float Value, float PrevFilteredValue, float Alpha)
{
    // 파라미터 이름 변경하여 멤버 변수와의 충돌 방지
    return Alpha * Value + (1.0f - Alpha) * PrevFilteredValue;
}

float UOneEuroFilter::CalculateAlpha(float Cutoff, float DeltaTime)
{
    float Tau = 1.0f / (2.0f * PI * Cutoff);
    return DeltaTime / (DeltaTime + Tau);
}

void UOneEuroFilter::SetMinCutoff(float NewMinCutoff)
{
    MinCutoff = FMath::Max(0.001f, NewMinCutoff);
    UE_LOG(LogTemp, Log, TEXT("One Euro Filter min cutoff set to: %f"), MinCutoff);
}

void UOneEuroFilter::SetBeta(float NewBeta)
{
    Beta = FMath::Max(0.0f, NewBeta);
    UE_LOG(LogTemp, Log, TEXT("One Euro Filter beta set to: %f"), Beta);
}

void UOneEuroFilter::SetDerivativeCutoff(float NewDCutoff)
{
    DCutoff = FMath::Max(0.001f, NewDCutoff);
    UE_LOG(LogTemp, Log, TEXT("One Euro Filter derivative cutoff set to: %f"), DCutoff);
}

float UOneEuroFilter::GetCurrentCutoff() const
{
    // Return the last calculated cutoff (based on speed)
    float Speed = FMath::Abs(PreviousDerivative);
    return MinCutoff + Beta * Speed;
}