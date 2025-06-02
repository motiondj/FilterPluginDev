#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BaseFilter.h"
#include "Engine/Engine.h"
#include "FilterBPLibrary.generated.h"

/**
 * Filter type for creation
 * 생성할 필터 유형
 */
UENUM(BlueprintType)
enum class EFilterType : uint8
{
    Kalman      UMETA(DisplayName = "Kalman Filter"),
    OneEuro     UMETA(DisplayName = "One Euro Filter")
};

/**
 * Custom filter preset data
 * 커스텀 필터 프리셋 데이터
 */
USTRUCT(BlueprintType)
struct FCustomFilterPreset
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Filter Preset")
    FString PresetName = "Custom";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Filter Preset")
    EFilterType FilterType = EFilterType::Kalman;

    // Kalman filter parameters
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kalman", meta = (ClampMin = "0.0001", ClampMax = "1.0"))
    float ProcessNoise = 0.01f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kalman", meta = (ClampMin = "0.0001", ClampMax = "10.0"))
    float MeasurementNoise = 0.1f;

    // One Euro filter parameters
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneEuro", meta = (ClampMin = "0.001", ClampMax = "10.0"))
    float MinCutoff = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneEuro", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Beta = 0.007f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneEuro", meta = (ClampMin = "0.001", ClampMax = "10.0"))
    float DCutoff = 1.0f;

    FCustomFilterPreset()
    {
    }
};

/**
 * Filter chain node
 * 필터 체인 노드
 */
USTRUCT(BlueprintType)
struct FFilterChainNode
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Filter Chain")
    UBaseFilterObject* Filter = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Filter Chain", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Weight = 1.0f;

    FFilterChainNode()
    {
    }
};

/**
 * Filter performance data
 * 필터 성능 데이터
 */
USTRUCT(BlueprintType)
struct FFilterPerformanceData
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Performance")
    float AverageProcessingTime = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Performance")
    float MaxProcessingTime = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Performance")
    int32 UpdateCount = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Performance")
    float TotalProcessingTime = 0.0f;

    void RecordUpdate(float ProcessingTime)
    {
        UpdateCount++;
        TotalProcessingTime += ProcessingTime;
        AverageProcessingTime = TotalProcessingTime / UpdateCount;
        MaxProcessingTime = FMath::Max(MaxProcessingTime, ProcessingTime);
    }

    void Reset()
    {
        AverageProcessingTime = 0.0f;
        MaxProcessingTime = 0.0f;
        UpdateCount = 0;
        TotalProcessingTime = 0.0f;
    }
};

/**
 * Static filter instance manager
 * 정적 필터 인스턴스 관리자
 */
USTRUCT()
struct FFilterInstanceManager
{
    GENERATED_BODY()

    // Static filter instances for one-click filtering
    static TMap<FString, UBaseFilterObject*> FilterInstances;

    static UBaseFilterObject* GetOrCreateFilter(const FString& FilterID, EFilterType Type);
    static void CleanupFilters();
};

/**
 * Blueprint Function Library for Advanced Filters
 * 고급 필터를 위한 블루프린트 함수 라이브러리
 */
UCLASS()
class ADVANCEDFILTERS_API UFilterBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // ========== 3-Node System Functions ==========

    /**
     * Create a new filter instance
     * 새로운 필터 인스턴스 생성
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Core",
        meta = (DisplayName = "Create Filter",
            Keywords = "create make new filter kalman oneeuro",
            ToolTip = "Creates a new filter instance of the specified type"))
    static UBaseFilterObject* CreateFilter(EFilterType FilterType);

    /**
     * Initialize filter with preset
     * 프리셋으로 필터 초기화
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Core",
        meta = (DisplayName = "Initialize Filter",
            Keywords = "init initialize setup filter preset",
            ToolTip = "Initialize the filter with a preset (Low/Medium/High)"))
    static bool InitializeFilter(UBaseFilterObject* Filter, EFilterPreset Preset);

    /**
     * Update filter with new value
     * 새로운 값으로 필터 업데이트
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Core",
        meta = (DisplayName = "Update Filter (Float)",
            Keywords = "update filter value float",
            ToolTip = "Update the filter with a new measurement and get filtered result"))
    static float UpdateFilterFloat(UBaseFilterObject* Filter, float RawValue);

    /**
     * Update filter with new vector value
     * 새로운 벡터 값으로 필터 업데이트
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Core",
        meta = (DisplayName = "Update Filter (Vector)",
            Keywords = "update filter value vector",
            ToolTip = "Update the filter with a new vector measurement and get filtered result"))
    static FVector UpdateFilterVector(UBaseFilterObject* Filter, const FVector& RawValue);

    // ========== One-Click Macro Functions ==========

    /**
     * One-click Kalman filtering for float values
     * Float 값을 위한 원클릭 칼만 필터링
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One-Click",
        meta = (DisplayName = "Kalman Filter Value",
            Keywords = "kalman filter one click easy float",
            ToolTip = "Apply Kalman filter to a value with one node"))
    static float KalmanFilterValue(float RawValue,
        EFilterPreset Preset = EFilterPreset::Medium,
        const FString& FilterID = "Default");

    /**
     * One-click Kalman filtering for vector values
     * Vector 값을 위한 원클릭 칼만 필터링
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One-Click",
        meta = (DisplayName = "Kalman Filter Vector",
            Keywords = "kalman filter one click easy vector",
            ToolTip = "Apply Kalman filter to a vector with one node"))
    static FVector KalmanFilterVector(const FVector& RawValue,
        EFilterPreset Preset = EFilterPreset::Medium,
        const FString& FilterID = "Default");

    /**
     * One-click One Euro filtering for float values
     * Float 값을 위한 원클릭 원유로 필터링
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One-Click",
        meta = (DisplayName = "One Euro Filter Value",
            Keywords = "oneeuro filter one click easy float",
            ToolTip = "Apply One Euro filter to a value with one node"))
    static float OneEuroFilterValue(float RawValue,
        float DeltaTime,
        EFilterPreset Preset = EFilterPreset::Medium,
        const FString& FilterID = "Default");

    /**
     * One-click One Euro filtering for vector values
     * Vector 값을 위한 원클릭 원유로 필터링
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|One-Click",
        meta = (DisplayName = "One Euro Filter Vector",
            Keywords = "oneeuro filter one click easy vector",
            ToolTip = "Apply One Euro filter to a vector with one node"))
    static FVector OneEuroFilterVector(const FVector& RawValue,
        float DeltaTime,
        EFilterPreset Preset = EFilterPreset::Medium,
        const FString& FilterID = "Default");

    // ========== Helper Functions ==========

    /**
     * Reset a filter to initial state
     * 필터를 초기 상태로 리셋
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Reset Filter",
            Keywords = "reset clear filter",
            ToolTip = "Reset the filter to its initial state"))
    static void ResetFilter(UBaseFilterObject* Filter);

    /**
     * Get current filtered value
     * 현재 필터링된 값 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Get Current Value (Float)",
            Keywords = "get current filter value float",
            ToolTip = "Get the current filtered float value"))
    static float GetCurrentValueFloat(const UBaseFilterObject* Filter);

    /**
     * Get current filtered vector value
     * 현재 필터링된 벡터 값 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Get Current Value (Vector)",
            Keywords = "get current filter value vector",
            ToolTip = "Get the current filtered vector value"))
    static FVector GetCurrentValueVector(const UBaseFilterObject* Filter);

    /**
     * Check if filter is initialized
     * 필터 초기화 여부 확인
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Is Filter Initialized",
            Keywords = "check filter initialized ready",
            ToolTip = "Check if the filter has been initialized"))
    static bool IsFilterInitialized(const UBaseFilterObject* Filter);

    /**
     * Cleanup all static filter instances
     * 모든 정적 필터 인스턴스 정리
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Cleanup All Filters",
            Keywords = "cleanup clear all filters memory",
            ToolTip = "Cleanup all one-click filter instances to free memory"))
    static void CleanupAllFilters();

    // ========== Filter Recommendation System ==========

    /**
     * Recommend best filter type based on use case
     * 사용 사례에 따른 최적 필터 유형 추천
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Recommendation",
        meta = (DisplayName = "Recommend Filter Type",
            Keywords = "recommend suggest best filter type",
            ToolTip = "Recommends the best filter type based on your use case"))
    static EFilterType RecommendFilterType(
        bool bNeedsFastResponse,
        bool bNeedsPrecisePrediction,
        bool bIsVRARInput,
        bool bHasVariableFrameRate);

    /**
     * Get filter description
     * 필터 설명 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Recommendation",
        meta = (DisplayName = "Get Filter Description",
            Keywords = "filter description info help",
            ToolTip = "Get a description of what the filter does"))
    static FString GetFilterDescription(EFilterType FilterType);

    /**
     * Get preset description
     * 프리셋 설명 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Recommendation",
        meta = (DisplayName = "Get Preset Description",
            Keywords = "preset description info help",
            ToolTip = "Get a description of what the preset does"))
    static FString GetPresetDescription(EFilterPreset Preset);

    // ========== Advanced Features ==========

    /**
     * Compare two filter outputs
     * 두 필터 출력 비교
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Advanced",
        meta = (DisplayName = "Compare Filter Outputs",
            Keywords = "compare difference filter output",
            ToolTip = "Compare the difference between two filter outputs"))
    static float CompareFilterOutputs(
        const UBaseFilterObject* Filter1,
        const UBaseFilterObject* Filter2);

    /**
     * Calculate filter latency
     * 필터 지연 시간 계산
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Advanced",
        meta = (DisplayName = "Estimate Filter Latency",
            Keywords = "latency delay filter response time",
            ToolTip = "Estimate the latency/delay of the filter in frames"))
    static int32 EstimateFilterLatency(
        const UBaseFilterObject* Filter,
        EFilterPreset Preset);

    /**
     * Auto-tune filter based on noise level
     * 노이즈 레벨에 따른 필터 자동 조정
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Advanced",
        meta = (DisplayName = "Auto Tune Filter",
            Keywords = "auto tune adjust filter noise",
            ToolTip = "Automatically tune filter based on detected noise level"))
    static bool AutoTuneFilter(
        UBaseFilterObject* Filter,
        const TArray<float>& RecentValues);

    // ========== Debug Visualization ==========

    /**
     * Get debug statistics
     * 디버그 통계 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Debug",
        meta = (DisplayName = "Get Filter Statistics",
            Keywords = "debug stats statistics filter info",
            ToolTip = "Get debug statistics about the filter performance"))
    static FString GetFilterStatistics(const UBaseFilterObject* Filter);

    /**
     * Draw filter response curve (for debug visualization)
     * 필터 응답 곡선 그리기 (디버그 시각화용)
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Debug",
        meta = (DisplayName = "Get Filter Response Curve",
            Keywords = "debug draw curve response filter",
            ToolTip = "Get points for drawing filter response curve",
            CallInEditor = "true"))
    static TArray<FVector2D> GetFilterResponseCurve(
        EFilterType FilterType,
        EFilterPreset Preset,
        int32 NumPoints = 100);

    // ========== Filter Chain System ==========

    /**
     * Create a filter chain with multiple filters
     * 여러 필터로 필터 체인 생성
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Chain",
        meta = (DisplayName = "Create Filter Chain",
            Keywords = "create chain multiple filters combine blend weights",
            ToolTip = "Create a chain of filters with blend weights for combining outputs"))
    static TArray<FFilterChainNode> CreateFilterChain(
        const TArray<EFilterType>& FilterTypes,
        const TArray<EFilterPreset>& Presets);

    /**
     * Create a filter chain with custom blend weights
     * 커스텀 블렌드 가중치로 필터 체인 생성
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Chain",
        meta = (DisplayName = "Create Filter Chain With Weights",
            Keywords = "create chain multiple filters combine blend weights custom",
            ToolTip = "Create a filter chain with custom blend weights for combining outputs"))
    static TArray<FFilterChainNode> CreateFilterChainWithWeights(
        const TArray<EFilterType>& FilterTypes,
        const TArray<EFilterPreset>& Presets,
        UPARAM(meta = (DisplayName = "Blend Weights"))
        const TArray<float>& BlendWeights);

    /**
     * Process value through filter chain
     * 필터 체인을 통해 값 처리
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Chain",
        meta = (DisplayName = "Process Through Chain",
            Keywords = "process chain filter sequential",
            ToolTip = "Process a value through a chain of filters"))
    static float ProcessThroughChain(
        const TArray<FFilterChainNode>& FilterChain,
        float RawValue);

    /**
     * Blend multiple filter outputs
     * 여러 필터 출력 블렌딩
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Chain",
        meta = (DisplayName = "Blend Filter Outputs",
            Keywords = "blend mix combine filter outputs",
            ToolTip = "Blend outputs from multiple filters based on weights"))
    static float BlendFilterOutputs(
        const TArray<UBaseFilterObject*>& Filters,
        const TArray<float>& Weights,
        float RawValue);

    // ========== Custom Preset System ==========

    /**
     * Create custom filter preset
     * 커스텀 필터 프리셋 생성
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Custom Preset",
        meta = (DisplayName = "Create Custom Preset",
            Keywords = "create custom preset save filter settings",
            ToolTip = "Create a custom filter preset with specific parameters"))
    static FCustomFilterPreset CreateCustomPreset(
        const FString& PresetName,
        EFilterType FilterType,
        UPARAM(meta = (DisplayName = "Process Noise (Kalman) / Min Cutoff (OneEuro)"))
        float ProcessNoiseOrMinCutoff,
        UPARAM(meta = (DisplayName = "Measurement Noise (Kalman) / Beta (OneEuro)"))
        float MeasurementNoiseOrBeta,
        UPARAM(meta = (DisplayName = "DCutoff (OneEuro Only)"))
        float DCutoff = 1.0f);

    /**
     * Apply custom preset to filter
     * 필터에 커스텀 프리셋 적용
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Custom Preset",
        meta = (DisplayName = "Apply Custom Preset",
            Keywords = "apply custom preset filter settings",
            ToolTip = "Apply a custom preset to a filter"))
    static bool ApplyCustomPreset(
        UBaseFilterObject* Filter,
        const FCustomFilterPreset& Preset);

    /**
     * Save custom preset to string
     * 커스텀 프리셋을 문자열로 저장
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Custom Preset",
        meta = (DisplayName = "Preset to String",
            Keywords = "save preset string serialize",
            ToolTip = "Convert a custom preset to a string for saving"))
    static FString PresetToString(const FCustomFilterPreset& Preset);

    /**
     * Load custom preset from string
     * 문자열에서 커스텀 프리셋 로드
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Custom Preset",
        meta = (DisplayName = "String to Preset",
            Keywords = "load preset string deserialize",
            ToolTip = "Convert a string back to a custom preset"))
    static FCustomFilterPreset StringToPreset(const FString& PresetString);

    // ========== Performance Profiling ==========

    /**
     * Start performance profiling
     * 성능 프로파일링 시작
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Performance",
        meta = (DisplayName = "Start Profiling",
            Keywords = "start performance profiling measure",
            ToolTip = "Start measuring filter performance"))
    static void StartProfiling(const FString& ProfileID);

    /**
     * Stop performance profiling
     * 성능 프로파일링 중지
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Performance",
        meta = (DisplayName = "Stop Profiling",
            Keywords = "stop performance profiling measure",
            ToolTip = "Stop measuring filter performance"))
    static FFilterPerformanceData StopProfiling(const FString& ProfileID);

    /**
     * Measure filter update time
     * 필터 업데이트 시간 측정
     */
    UFUNCTION(BlueprintCallable, Category = "Advanced Filters|Performance",
        meta = (DisplayName = "Profile Filter Update",
            Keywords = "measure time filter update performance",
            ToolTip = "Measure the time taken for a filter update"))
    static float ProfileFilterUpdate(
        UBaseFilterObject* Filter,
        float RawValue,
        FFilterPerformanceData& OutPerformance);

    /**
     * Get filter instance by ID
     * ID로 필터 인스턴스 가져오기
     */
    UFUNCTION(BlueprintPure, Category = "Advanced Filters|Utility",
        meta = (DisplayName = "Get Filter Instance",
            Keywords = "get filter instance object id",
            ToolTip = "Get a filter instance by its ID"))
    static UBaseFilterObject* GetFilterInstance(const FString& FilterID);

private:
    // Performance tracking
    static TMap<FString, FDateTime> ProfileStartTimes;
    static TMap<FString, FFilterPerformanceData> PerformanceData;
};