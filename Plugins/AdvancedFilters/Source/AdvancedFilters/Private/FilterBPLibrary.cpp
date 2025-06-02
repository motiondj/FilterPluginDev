#include "FilterBPLibrary.h"
#include "KalmanFilter.h"
#include "OneEuroFilter.h"
#include "Engine/World.h"

// Static member initialization
TMap<FString, UBaseFilterObject*> FFilterInstanceManager::FilterInstances;

// Performance tracking static members
TMap<FString, FDateTime> UFilterBPLibrary::ProfileStartTimes;
TMap<FString, FFilterPerformanceData> UFilterBPLibrary::PerformanceData;

UBaseFilterObject* FFilterInstanceManager::GetOrCreateFilter(const FString& FilterID, EFilterType Type)
{
    // Check if filter already exists
    if (FilterInstances.Contains(FilterID))
    {
        return FilterInstances[FilterID];
    }

    // Create new filter based on type
    UBaseFilterObject* NewFilter = nullptr;

    switch (Type)
    {
    case EFilterType::Kalman:
        NewFilter = NewObject<UKalmanFilter>();
        break;

    case EFilterType::OneEuro:
        NewFilter = NewObject<UOneEuroFilter>();
        break;
    }

    if (NewFilter)
    {
        NewFilter->AddToRoot(); // Prevent garbage collection
        FilterInstances.Add(FilterID, NewFilter);
    }

    return NewFilter;
}

void FFilterInstanceManager::CleanupFilters()
{
    for (auto& Pair : FilterInstances)
    {
        if (Pair.Value)
        {
            Pair.Value->RemoveFromRoot();
        }
    }
    FilterInstances.Empty();
}

// ========== 3-Node System Implementation ==========

UBaseFilterObject* UFilterBPLibrary::CreateFilter(EFilterType FilterType)
{
    UBaseFilterObject* NewFilter = nullptr;

    switch (FilterType)
    {
    case EFilterType::Kalman:
        NewFilter = NewObject<UKalmanFilter>();
        UE_LOG(LogTemp, Log, TEXT("Created new Kalman Filter"));
        break;

    case EFilterType::OneEuro:
        NewFilter = NewObject<UOneEuroFilter>();
        UE_LOG(LogTemp, Log, TEXT("Created new One Euro Filter"));
        break;
    }

    return NewFilter;
}

bool UFilterBPLibrary::InitializeFilter(UBaseFilterObject* Filter, EFilterPreset Preset)
{
    if (!Filter)
    {
        UE_LOG(LogTemp, Warning, TEXT("InitializeFilter: Filter is null"));
        return false;
    }

    Filter->Initialize(Preset);
    return true;
}

float UFilterBPLibrary::UpdateFilterFloat(UBaseFilterObject* Filter, float RawValue)
{
    if (!Filter)
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateFilterFloat: Filter is null, returning raw value"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateFilterFloat: Filter not initialized, initializing with Medium preset"));
        Filter->Initialize(EFilterPreset::Medium);
    }

    return Filter->UpdateEstimate(RawValue);
}

FVector UFilterBPLibrary::UpdateFilterVector(UBaseFilterObject* Filter, const FVector& RawValue)
{
    if (!Filter)
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateFilterVector: Filter is null, returning raw value"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        UE_LOG(LogTemp, Warning, TEXT("UpdateFilterVector: Filter not initialized, initializing with Medium preset"));
        Filter->Initialize(EFilterPreset::Medium);
    }

    return Filter->UpdateEstimateVector(RawValue);
}

// ========== One-Click Macro Functions Implementation ==========

float UFilterBPLibrary::KalmanFilterValue(float RawValue, EFilterPreset Preset, const FString& FilterID)
{
    FString FullID = FString::Printf(TEXT("Kalman_%s"), *FilterID);
    UBaseFilterObject* Filter = FFilterInstanceManager::GetOrCreateFilter(FullID, EFilterType::Kalman);

    if (!Filter)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create Kalman filter"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        Filter->Initialize(Preset);
    }

    return Filter->UpdateEstimate(RawValue);
}

FVector UFilterBPLibrary::KalmanFilterVector(const FVector& RawValue, EFilterPreset Preset, const FString& FilterID)
{
    FString FullID = FString::Printf(TEXT("KalmanVec_%s"), *FilterID);
    UBaseFilterObject* Filter = FFilterInstanceManager::GetOrCreateFilter(FullID, EFilterType::Kalman);

    if (!Filter)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create Kalman filter"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        Filter->Initialize(Preset);
    }

    return Filter->UpdateEstimateVector(RawValue);
}

float UFilterBPLibrary::OneEuroFilterValue(float RawValue, float DeltaTime, EFilterPreset Preset, const FString& FilterID)
{
    FString FullID = FString::Printf(TEXT("OneEuro_%s"), *FilterID);
    UBaseFilterObject* Filter = FFilterInstanceManager::GetOrCreateFilter(FullID, EFilterType::OneEuro);

    if (!Filter)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create One Euro filter"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        Filter->Initialize(Preset);
    }

    // Cast to OneEuroFilter to use delta time update
    UOneEuroFilter* OneEuroFilter = Cast<UOneEuroFilter>(Filter);
    if (OneEuroFilter)
    {
        return OneEuroFilter->UpdateEstimateWithDeltaTime(RawValue, DeltaTime);
    }

    return Filter->UpdateEstimate(RawValue);
}

FVector UFilterBPLibrary::OneEuroFilterVector(const FVector& RawValue, float DeltaTime, EFilterPreset Preset, const FString& FilterID)
{
    FString FullID = FString::Printf(TEXT("OneEuroVec_%s"), *FilterID);
    UBaseFilterObject* Filter = FFilterInstanceManager::GetOrCreateFilter(FullID, EFilterType::OneEuro);

    if (!Filter)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create One Euro filter"));
        return RawValue;
    }

    if (!Filter->IsInitialized())
    {
        Filter->Initialize(Preset);
    }

    // Cast to OneEuroFilter to use delta time update
    UOneEuroFilter* OneEuroFilter = Cast<UOneEuroFilter>(Filter);
    if (OneEuroFilter)
    {
        return OneEuroFilter->UpdateEstimateVectorWithDeltaTime(RawValue, DeltaTime);
    }

    return Filter->UpdateEstimateVector(RawValue);
}

// ========== Helper Functions Implementation ==========

void UFilterBPLibrary::ResetFilter(UBaseFilterObject* Filter)
{
    if (Filter)
    {
        Filter->Reset();
        UE_LOG(LogTemp, Log, TEXT("Filter reset to initial state"));
    }
}

float UFilterBPLibrary::GetCurrentValueFloat(const UBaseFilterObject* Filter)
{
    if (!Filter)
    {
        return 0.0f;
    }

    return Filter->GetCurrentEstimate();
}

FVector UFilterBPLibrary::GetCurrentValueVector(const UBaseFilterObject* Filter)
{
    if (!Filter)
    {
        return FVector::ZeroVector;
    }

    return Filter->GetCurrentEstimateVector();
}

bool UFilterBPLibrary::IsFilterInitialized(const UBaseFilterObject* Filter)
{
    if (!Filter)
    {
        return false;
    }

    return Filter->IsInitialized();
}

void UFilterBPLibrary::CleanupAllFilters()
{
    FFilterInstanceManager::CleanupFilters();
    UE_LOG(LogTemp, Log, TEXT("All one-click filter instances cleaned up"));
}

// ========== Filter Recommendation System Implementation ==========

EFilterType UFilterBPLibrary::RecommendFilterType(
    bool bNeedsFastResponse,
    bool bNeedsPrecisePrediction,
    bool bIsVRARInput,
    bool bHasVariableFrameRate)
{
    // VR/AR 입력이거나 빠른 반응이 필요한 경우 원유로필터 추천
    if (bIsVRARInput || (bNeedsFastResponse && !bNeedsPrecisePrediction))
    {
        UE_LOG(LogTemp, Log, TEXT("Recommending One Euro Filter: Fast response needed"));
        return EFilterType::OneEuro;
    }

    // 정밀한 예측이 필요하거나 가변 프레임레이트가 없는 경우 칼만 필터 추천
    if (bNeedsPrecisePrediction || !bHasVariableFrameRate)
    {
        UE_LOG(LogTemp, Log, TEXT("Recommending Kalman Filter: Precise prediction needed"));
        return EFilterType::Kalman;
    }

    // 기본값: 칼만 필터
    return EFilterType::Kalman;
}

FString UFilterBPLibrary::GetFilterDescription(EFilterType FilterType)
{
    switch (FilterType)
    {
    case EFilterType::Kalman:
        return TEXT("Kalman Filter: Best for precise state estimation and prediction. "
            "Provides smooth output with some latency. "
            "Ideal for: sensor data, AI movement, camera smoothing.");

    case EFilterType::OneEuro:
        return TEXT("One Euro Filter: Best for low-latency filtering with adaptive smoothing. "
            "Reduces jitter while maintaining responsiveness. "
            "Ideal for: VR/AR input, mouse movement, real-time interaction.");

    default:
        return TEXT("Unknown filter type");
    }
}

FString UFilterBPLibrary::GetPresetDescription(EFilterPreset Preset)
{
    switch (Preset)
    {
    case EFilterPreset::Low:
        return TEXT("Low: Minimal filtering, fastest response. "
            "Best when you need immediate reaction with slight noise acceptable.");

    case EFilterPreset::Medium:
        return TEXT("Medium: Balanced filtering and response. "
            "Good for most general use cases.");

    case EFilterPreset::High:
        return TEXT("High: Maximum filtering, smoothest output. "
            "Best when smooth motion is more important than immediate response.");

    default:
        return TEXT("Unknown preset");
    }
}

// ========== Advanced Features Implementation ==========

float UFilterBPLibrary::CompareFilterOutputs(
    const UBaseFilterObject* Filter1,
    const UBaseFilterObject* Filter2)
{
    if (!Filter1 || !Filter2)
    {
        return 0.0f;
    }

    float Value1 = Filter1->GetCurrentEstimate();
    float Value2 = Filter2->GetCurrentEstimate();

    return FMath::Abs(Value1 - Value2);
}

int32 UFilterBPLibrary::EstimateFilterLatency(
    const UBaseFilterObject* Filter,
    EFilterPreset Preset)
{
    if (!Filter)
    {
        return 0;
    }

    // 필터 유형과 프리셋에 따른 대략적인 지연 시간 (프레임 단위)
    bool bIsKalman = Filter->IsA<UKalmanFilter>();

    if (bIsKalman)
    {
        switch (Preset)
        {
        case EFilterPreset::Low:    return 2;   // ~2 frames
        case EFilterPreset::Medium: return 5;   // ~5 frames
        case EFilterPreset::High:   return 10;  // ~10 frames
        default: return 5;
        }
    }
    else // One Euro Filter
    {
        switch (Preset)
        {
        case EFilterPreset::Low:    return 0;   // ~0 frames (immediate)
        case EFilterPreset::Medium: return 1;   // ~1 frame
        case EFilterPreset::High:   return 3;   // ~3 frames
        default: return 1;
        }
    }
}

bool UFilterBPLibrary::AutoTuneFilter(
    UBaseFilterObject* Filter,
    const TArray<float>& RecentValues)
{
    if (!Filter || RecentValues.Num() < 10)
    {
        UE_LOG(LogTemp, Warning, TEXT("AutoTuneFilter: Need at least 10 recent values"));
        return false;
    }

    // Calculate noise level (standard deviation)
    float Mean = 0.0f;
    for (float Value : RecentValues)
    {
        Mean += Value;
    }
    Mean /= RecentValues.Num();

    float Variance = 0.0f;
    for (float Value : RecentValues)
    {
        float Diff = Value - Mean;
        Variance += Diff * Diff;
    }
    Variance /= RecentValues.Num();
    float StdDev = FMath::Sqrt(Variance);

    // Determine appropriate preset based on noise level
    EFilterPreset RecommendedPreset;
    if (StdDev < 0.1f)
    {
        RecommendedPreset = EFilterPreset::Low;
        UE_LOG(LogTemp, Log, TEXT("AutoTune: Low noise detected (%.3f), using Low preset"), StdDev);
    }
    else if (StdDev < 1.0f)
    {
        RecommendedPreset = EFilterPreset::Medium;
        UE_LOG(LogTemp, Log, TEXT("AutoTune: Medium noise detected (%.3f), using Medium preset"), StdDev);
    }
    else
    {
        RecommendedPreset = EFilterPreset::High;
        UE_LOG(LogTemp, Log, TEXT("AutoTune: High noise detected (%.3f), using High preset"), StdDev);
    }

    Filter->Initialize(RecommendedPreset);
    return true;
}

// ========== Debug Visualization Implementation ==========

FString UFilterBPLibrary::GetFilterStatistics(const UBaseFilterObject* Filter)
{
    if (!Filter)
    {
        return TEXT("Filter is null");
    }

    FString Stats;
    Stats += FString::Printf(TEXT("Filter Type: %s\n"),
        Filter->IsA<UKalmanFilter>() ? TEXT("Kalman") : TEXT("One Euro"));
    Stats += FString::Printf(TEXT("Initialized: %s\n"),
        Filter->IsInitialized() ? TEXT("Yes") : TEXT("No"));
    Stats += FString::Printf(TEXT("Current Value: %.3f\n"),
        Filter->GetCurrentEstimate());
    Stats += FString::Printf(TEXT("Current Vector: (%.2f, %.2f, %.2f)\n"),
        Filter->GetCurrentEstimateVector().X,
        Filter->GetCurrentEstimateVector().Y,
        Filter->GetCurrentEstimateVector().Z);

    // Add filter-specific stats
    if (UKalmanFilter* KalmanFilter = Cast<UKalmanFilter>(const_cast<UBaseFilterObject*>(Filter)))
    {
        Stats += FString::Printf(TEXT("Kalman Gain: %.3f\n"), KalmanFilter->GetKalmanGain());
        Stats += FString::Printf(TEXT("Error Covariance: %.3f\n"), KalmanFilter->GetErrorCovariance());
    }
    else if (UOneEuroFilter* OneEuroFilter = Cast<UOneEuroFilter>(const_cast<UBaseFilterObject*>(Filter)))
    {
        Stats += FString::Printf(TEXT("Current Cutoff: %.3f Hz\n"), OneEuroFilter->GetCurrentCutoff());
    }

    return Stats;
}

TArray<FVector2D> UFilterBPLibrary::GetFilterResponseCurve(
    EFilterType FilterType,
    EFilterPreset Preset,
    int32 NumPoints)
{
    TArray<FVector2D> Curve;
    Curve.Reserve(NumPoints);

    // Create temporary filter
    UBaseFilterObject* TempFilter = nullptr;
    if (FilterType == EFilterType::Kalman)
    {
        TempFilter = NewObject<UKalmanFilter>();
    }
    else
    {
        TempFilter = NewObject<UOneEuroFilter>();
    }

    if (!TempFilter)
    {
        return Curve;
    }

    TempFilter->Initialize(Preset);

    // Generate step response
    for (int32 i = 0; i < NumPoints; i++)
    {
        float InputValue = (i < NumPoints / 2) ? 0.0f : 1.0f;  // Step input
        float OutputValue = TempFilter->UpdateEstimate(InputValue);

        float X = (float)i / (float)(NumPoints - 1);
        Curve.Add(FVector2D(X, OutputValue));
    }

    return Curve;
}

// ========== Filter Chain System Implementation ==========

TArray<FFilterChainNode> UFilterBPLibrary::CreateFilterChain(
    const TArray<EFilterType>& FilterTypes,
    const TArray<EFilterPreset>& Presets)
{
    TArray<FFilterChainNode> Chain;

    int32 Count = FMath::Min(FilterTypes.Num(), Presets.Num());
    for (int32 i = 0; i < Count; i++)
    {
        UBaseFilterObject* NewFilter = CreateFilter(FilterTypes[i]);
        if (NewFilter)
        {
            InitializeFilter(NewFilter, Presets[i]);

            FFilterChainNode Node;
            Node.Filter = NewFilter;
            Node.Weight = 1.0f / Count;  // Equal weights by default
            Chain.Add(Node);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("Created filter chain with %d filters"), Chain.Num());
    return Chain;
}

TArray<FFilterChainNode> UFilterBPLibrary::CreateFilterChainWithWeights(
    const TArray<EFilterType>& FilterTypes,
    const TArray<EFilterPreset>& Presets,
    const TArray<float>& BlendWeights)
{
    TArray<FFilterChainNode> Chain;

    int32 Count = FMath::Min(FilterTypes.Num(), Presets.Num());

    // 가중치 정규화 계산
    TArray<float> NormalizedWeights;
    if (BlendWeights.Num() >= Count && Count > 0)
    {
        // 사용자 제공 가중치 사용
        float TotalWeight = 0.0f;
        for (int32 i = 0; i < Count; i++)
        {
            TotalWeight += BlendWeights[i];
        }

        // 정규화 (총합이 1.0이 되도록)
        for (int32 i = 0; i < Count; i++)
        {
            float NormalizedWeight = (TotalWeight > 0.0f) ? (BlendWeights[i] / TotalWeight) : (1.0f / Count);
            NormalizedWeights.Add(NormalizedWeight);
        }

        UE_LOG(LogTemp, Log, TEXT("Using custom blend weights, total: %f"), TotalWeight);
    }
    else
    {
        // 기본 균등 가중치 사용
        for (int32 i = 0; i < Count; i++)
        {
            NormalizedWeights.Add(1.0f / Count);
        }

        UE_LOG(LogTemp, Log, TEXT("Using default equal weights"));
    }

    // 필터 체인 생성
    for (int32 i = 0; i < Count; i++)
    {
        UBaseFilterObject* NewFilter = CreateFilter(FilterTypes[i]);
        if (NewFilter)
        {
            InitializeFilter(NewFilter, Presets[i]);

            FFilterChainNode Node;
            Node.Filter = NewFilter;
            Node.Weight = NormalizedWeights[i];
            Chain.Add(Node);

            UE_LOG(LogTemp, Log, TEXT("Filter %d: Type=%d, Preset=%d, Weight=%f"),
                i, (int32)FilterTypes[i], (int32)Presets[i], NormalizedWeights[i]);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("Created filter chain with %d filters and custom weights"), Chain.Num());
    return Chain;
}

float UFilterBPLibrary::ProcessThroughChain(
    const TArray<FFilterChainNode>& FilterChain,
    float RawValue)
{
    float ProcessedValue = RawValue;

    for (const FFilterChainNode& Node : FilterChain)
    {
        if (Node.Filter && Node.Filter->IsInitialized())
        {
            ProcessedValue = Node.Filter->UpdateEstimate(ProcessedValue);
        }
    }

    return ProcessedValue;
}

float UFilterBPLibrary::BlendFilterOutputs(
    const TArray<UBaseFilterObject*>& Filters,
    const TArray<float>& Weights,
    float RawValue)
{
    if (Filters.Num() == 0 || Filters.Num() != Weights.Num())
    {
        return RawValue;
    }

    float BlendedValue = 0.0f;
    float TotalWeight = 0.0f;

    for (int32 i = 0; i < Filters.Num(); i++)
    {
        if (Filters[i] && Filters[i]->IsInitialized())
        {
            float FilteredValue = Filters[i]->UpdateEstimate(RawValue);
            BlendedValue += FilteredValue * Weights[i];
            TotalWeight += Weights[i];
        }
    }

    // Normalize by total weight
    if (TotalWeight > 0.0f)
    {
        BlendedValue /= TotalWeight;
    }
    else
    {
        BlendedValue = RawValue;
    }

    return BlendedValue;
}

// ========== Custom Preset System Implementation ==========

FCustomFilterPreset UFilterBPLibrary::CreateCustomPreset(
    const FString& PresetName,
    EFilterType FilterType,
    float ProcessNoiseOrMinCutoff,    // 변경된 이름
    float MeasurementNoiseOrBeta,     // 변경된 이름
    float DCutoff)
{
    FCustomFilterPreset Preset;
    Preset.PresetName = PresetName;
    Preset.FilterType = FilterType;

    if (FilterType == EFilterType::Kalman)
    {
        Preset.ProcessNoise = ProcessNoiseOrMinCutoff;      // 변경된 이름 사용
        Preset.MeasurementNoise = MeasurementNoiseOrBeta;   // 변경된 이름 사용
    }
    else // OneEuro
    {
        Preset.MinCutoff = ProcessNoiseOrMinCutoff;         // 변경된 이름 사용
        Preset.Beta = MeasurementNoiseOrBeta;               // 변경된 이름 사용
        Preset.DCutoff = DCutoff;
    }

    UE_LOG(LogTemp, Log, TEXT("Created custom preset: %s"), *PresetName);
    return Preset;
}

bool UFilterBPLibrary::ApplyCustomPreset(
    UBaseFilterObject* Filter,
    const FCustomFilterPreset& Preset)
{
    if (!Filter)
    {
        return false;
    }

    // Check filter type matches preset
    bool bIsKalman = Filter->IsA<UKalmanFilter>();
    bool bPresetIsKalman = (Preset.FilterType == EFilterType::Kalman);

    if (bIsKalman != bPresetIsKalman)
    {
        UE_LOG(LogTemp, Warning, TEXT("Filter type mismatch with preset"));
        return false;
    }

    if (bIsKalman)
    {
        UKalmanFilter* KalmanFilter = Cast<UKalmanFilter>(Filter);
        if (KalmanFilter)
        {
            KalmanFilter->SetProcessNoise(Preset.ProcessNoise);
            KalmanFilter->SetMeasurementNoise(Preset.MeasurementNoise);
            Filter->Initialize(EFilterPreset::Medium); // Initialize with base settings
            return true;
        }
    }
    else
    {
        UOneEuroFilter* OneEuroFilter = Cast<UOneEuroFilter>(Filter);
        if (OneEuroFilter)
        {
            OneEuroFilter->SetMinCutoff(Preset.MinCutoff);
            OneEuroFilter->SetBeta(Preset.Beta);
            OneEuroFilter->SetDerivativeCutoff(Preset.DCutoff);
            Filter->Initialize(EFilterPreset::Medium); // Initialize with base settings
            return true;
        }
    }

    return false;
}

FString UFilterBPLibrary::PresetToString(const FCustomFilterPreset& Preset)
{
    return FString::Printf(TEXT("%s|%d|%f|%f|%f|%f|%f"),
        *Preset.PresetName,
        (int32)Preset.FilterType,
        Preset.ProcessNoise,
        Preset.MeasurementNoise,
        Preset.MinCutoff,
        Preset.Beta,
        Preset.DCutoff);
}

FCustomFilterPreset UFilterBPLibrary::StringToPreset(const FString& PresetString)
{
    FCustomFilterPreset Preset;

    TArray<FString> Parts;
    PresetString.ParseIntoArray(Parts, TEXT("|"));

    if (Parts.Num() >= 7)
    {
        Preset.PresetName = Parts[0];
        Preset.FilterType = (EFilterType)FCString::Atoi(*Parts[1]);
        Preset.ProcessNoise = FCString::Atof(*Parts[2]);
        Preset.MeasurementNoise = FCString::Atof(*Parts[3]);
        Preset.MinCutoff = FCString::Atof(*Parts[4]);
        Preset.Beta = FCString::Atof(*Parts[5]);
        Preset.DCutoff = FCString::Atof(*Parts[6]);
    }

    return Preset;
}

// ========== Performance Profiling Implementation ==========

void UFilterBPLibrary::StartProfiling(const FString& ProfileID)
{
    ProfileStartTimes.Add(ProfileID, FDateTime::Now());

    if (!PerformanceData.Contains(ProfileID))
    {
        PerformanceData.Add(ProfileID, FFilterPerformanceData());
    }

    UE_LOG(LogTemp, Log, TEXT("Started profiling: %s"), *ProfileID);
}

FFilterPerformanceData UFilterBPLibrary::StopProfiling(const FString& ProfileID)
{
    FFilterPerformanceData Data;

    if (ProfileStartTimes.Contains(ProfileID))
    {
        FDateTime StartTime = ProfileStartTimes[ProfileID];
        FDateTime EndTime = FDateTime::Now();
        float ElapsedMs = (EndTime - StartTime).GetTotalMilliseconds();

        if (PerformanceData.Contains(ProfileID))
        {
            Data = PerformanceData[ProfileID];
            Data.RecordUpdate(ElapsedMs);
            PerformanceData[ProfileID] = Data;
        }

        ProfileStartTimes.Remove(ProfileID);
        UE_LOG(LogTemp, Log, TEXT("Stopped profiling %s: %.3f ms"), *ProfileID, ElapsedMs);
    }

    return Data;
}

float UFilterBPLibrary::ProfileFilterUpdate(
    UBaseFilterObject* Filter,
    float RawValue,
    FFilterPerformanceData& OutPerformance)
{
    if (!Filter)
    {
        return RawValue;
    }

    FDateTime StartTime = FDateTime::Now();
    float Result = Filter->UpdateEstimate(RawValue);
    FDateTime EndTime = FDateTime::Now();

    float ElapsedMs = (EndTime - StartTime).GetTotalMilliseconds();
    OutPerformance.RecordUpdate(ElapsedMs);

    return Result;
}

UBaseFilterObject* UFilterBPLibrary::GetFilterInstance(const FString& FilterID)
{
    // Check both Kalman and OneEuro instances
    FString KalmanID = FString::Printf(TEXT("Kalman_%s"), *FilterID);
    FString OneEuroID = FString::Printf(TEXT("OneEuro_%s"), *FilterID);

    if (FFilterInstanceManager::FilterInstances.Contains(KalmanID))
    {
        return FFilterInstanceManager::FilterInstances[KalmanID];
    }
    else if (FFilterInstanceManager::FilterInstances.Contains(OneEuroID))
    {
        return FFilterInstanceManager::FilterInstances[OneEuroID];
    }

    return nullptr;
}