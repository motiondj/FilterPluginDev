# API 레퍼런스 (개선판)

*다른 언어로 읽기: [English](APIReference.md), [한국어](APIReference_KR.md)*

고급 필터 플러그인의 모든 노드와 함수에 대한 완전한 기술 레퍼런스

## 📍 네비게이션

- [← 이전: 사용자 매뉴얼](UserManual_KR.md)
- [→ 다음: 블루프린트 예제](Examples_KR.md)

---

## 🗂️ 노드 카테고리 가이드

블루프린트에서 노드를 찾을 때 다음 카테고리를 확인하세요:

| 카테고리 | 포함된 노드 | 용도 |
|---------|-----------|------|
| **Advanced Filters > Core** | Create Filter, Initialize Filter, Update Filter | 3-노드 시스템의 핵심 기능 |
| **Advanced Filters > One-Click** | Kalman/OneEuro Filter Value/Vector | 원클릭 매크로 |
| **Advanced Filters > Utility** | Reset, Get Current Value, Cleanup | 유틸리티 기능 |
| **Advanced Filters > Advanced** | Compare Outputs, Auto Tune | 고급 기능 |
| **Advanced Filters > Chain** | Create Chain, Process Through Chain | 필터 체인 |
| **Advanced Filters > Custom Preset** | Create/Apply Custom Preset | 커스텀 프리셋 |
| **Advanced Filters > Performance** | Start/Stop Profiling | 성능 측정 |
| **Advanced Filters > Debug** | Get Statistics, Response Curve | 디버깅 도구 |
| **Advanced Filters > Recommendation** | Recommend Filter Type | 필터 추천 |

---

## 📋 목차

1. [핵심 노드](#핵심-노드)
2. [원클릭 매크로](#원클릭-매크로)
3. [고급 노드](#고급-노드)
4. [유틸리티 노드](#유틸리티-노드)
5. [데이터 타입](#데이터-타입)
6. [열거형](#열거형)

---

## 🔧 핵심 노드

### Create Filter (필터 생성)
**카테고리:** Advanced Filters > Core

지정된 타입의 새 필터 인스턴스를 생성합니다.

```
Create Filter
├─ 입력
│  └─ Filter Type (EFilterType): Kalman 또는 OneEuro
└─ 출력
   └─ Filter Object (UBaseFilterObject*): 생성된 필터 인스턴스
```

**사용 예제:**
```blueprint
[Create Filter (Kalman)] → [변수: MyFilter]
```

**참고사항:**
- 초기화되지 않은 필터 생성
- 사용 전 Initialize 호출 필요
- 메모리 자동 관리

---

### Initialize Filter (필터 초기화)
**카테고리:** Advanced Filters > Core

지정된 프리셋으로 필터를 초기화합니다.

```
Initialize Filter
├─ 입력
│  ├─ Target (UBaseFilterObject*): 초기화할 필터
│  └─ Preset (EFilterPreset): Low, Medium, 또는 High
└─ 출력
   └─ Success (bool): 초기화 성공 시 True
```

**프리셋 값:**

| 프리셋 | Kalman Q | Kalman R | OneEuro MinCutoff | OneEuro Beta |
|--------|----------|----------|-------------------|--------------|
| Low | 0.1 | 0.01 | 1.0 | 0.001 |
| Medium | 0.01 | 0.1 | 0.5 | 0.007 |
| High | 0.001 | 1.0 | 0.1 | 0.01 |

---

### Update Filter Float (Float 필터 업데이트)
**카테고리:** Advanced Filters > Core

새 float 값으로 필터를 업데이트하고 필터링된 결과를 반환합니다.

```
Update Filter Float
├─ 입력
│  ├─ Target (UBaseFilterObject*): 필터 인스턴스
│  └─ Raw Value (float): 새 측정값
└─ 출력
   └─ Filtered Value (float): 필터링된 결과
```

**알고리즘:**
- 칼만: 예측 → 업데이트 → 추정값 반환
- 원유로: 적응형 컷오프를 사용한 저역 통과

---

### Update Filter Vector (Vector 필터 업데이트)
**카테고리:** Advanced Filters > Core

새 벡터 값으로 필터를 업데이트하고 필터링된 결과를 반환합니다.

```
Update Filter Vector
├─ 입력
│  ├─ Target (UBaseFilterObject*): 필터 인스턴스
│  └─ Raw Value (FVector): 새 측정값
└─ 출력
   └─ Filtered Value (FVector): 필터링된 결과
```

**참고사항:**
- X, Y, Z를 독립적으로 필터링
- 각 축에 대해 별도의 상태 유지

---

## 🎯 원클릭 매크로

### Kalman Filter Value (칼만 필터 값)
**카테고리:** Advanced Filters > One-Click

float 값을 위한 원클릭 칼만 필터링.

```
Kalman Filter Value
├─ 입력
│  ├─ Raw Value (float): 필터링할 값
│  ├─ Preset (EFilterPreset): 필터 강도
│  └─ Filter ID (FString): 고유 식별자
└─ 출력
   └─ Return Value (float): 필터링된 결과
```

**특징:**
- ID를 기반으로 필터 자동 생성/재사용
- 초기화 불필요
- 스레드 안전 인스턴스 관리

---

### Kalman Filter Vector (칼만 필터 벡터)
**카테고리:** Advanced Filters > One-Click

벡터 값을 위한 원클릭 칼만 필터링.

```
Kalman Filter Vector
├─ 입력
│  ├─ Raw Value (FVector): 필터링할 벡터
│  ├─ Preset (EFilterPreset): 필터 강도
│  └─ Filter ID (FString): 고유 식별자
└─ 출력
   └─ Return Value (FVector): 필터링된 결과
```

---

### One Euro Filter Value (원유로 필터 값)
**카테고리:** Advanced Filters > One-Click

float 값을 위한 원클릭 원유로 필터링.

```
One Euro Filter Value
├─ 입력
│  ├─ Raw Value (float): 필터링할 값
│  ├─ Delta Time (float): 마지막 업데이트 이후 시간
│  ├─ Preset (EFilterPreset): 필터 강도
│  └─ Filter ID (FString): 고유 식별자
└─ 출력
   └─ Return Value (float): 필터링된 결과
```

**중요:**
- Delta Time 필수
- Event Tick의 Delta Seconds 사용
- 신호 속도에 적응

---

### One Euro Filter Vector (원유로 필터 벡터)
**카테고리:** Advanced Filters > One-Click

벡터 값을 위한 원클릭 원유로 필터링.

```
One Euro Filter Vector
├─ 입력
│  ├─ Raw Value (FVector): 필터링할 벡터
│  ├─ Delta Time (float): 마지막 업데이트 이후 시간
│  ├─ Preset (EFilterPreset): 필터 강도
│  └─ Filter ID (FString): 고유 식별자
└─ 출력
   └─ Return Value (FVector): 필터링된 결과
```

---

## 🚀 고급 노드

### Set Process Noise (프로세스 노이즈 설정 - 칼만)
**카테고리:** Advanced Filters > Advanced

칼만 필터 프로세스 노이즈 (Q 파라미터) 조정.

```
Set Process Noise
├─ 입력
│  ├─ Target (UKalmanFilter*): 칼만 필터 인스턴스
│  └─ Process Noise (float): Q 값 (0.0001 - 1.0)
└─ 출력
   └─ Success (bool): 설정 성공 시 True
```

**효과:**
- 높은 Q = 측정값을 더 신뢰
- 낮은 Q = 예측값을 더 신뢰

---

### Set Measurement Noise (측정 노이즈 설정 - 칼만)
**카테고리:** Advanced Filters > Advanced

칼만 필터 측정 노이즈 (R 파라미터) 조정.

```
Set Measurement Noise
├─ 입력
│  ├─ Target (UKalmanFilter*): 칼만 필터 인스턴스
│  └─ Measurement Noise (float): R 값 (0.001 - 10.0)
└─ 출력
   └─ Success (bool): 설정 성공 시 True
```

---

### Set Min Cutoff (최소 컷오프 설정 - 원유로)
**카테고리:** Advanced Filters > Advanced

원유로 필터 최소 컷오프 주파수 조정.

```
Set Min Cutoff
├─ 입력
│  ├─ Target (UOneEuroFilter*): 원유로 필터 인스턴스
│  └─ Min Cutoff (float): Hz 단위 주파수 (0.001 - 10.0)
└─ 출력
   └─ Success (bool): 설정 성공 시 True
```

**효과:**
- 낮음 = 더 많은 스무딩
- 높음 = 더 적은 스무딩

---

### Set Beta (베타 설정 - 원유로)
**카테고리:** Advanced Filters > Advanced

원유로 필터 속도 계수 조정.

```
Set Beta
├─ 입력
│  ├─ Target (UOneEuroFilter*): 원유로 필터 인스턴스
│  └─ Beta (float): 속도 계수 (0.0 - 1.0)
└─ 출력
   └─ Success (bool): 설정 성공 시 True
```

**효과:**
- 낮음 = 더 안정적
- 높음 = 속도에 더 민감

---

### Create Custom Preset (커스텀 프리셋 생성)
**카테고리:** Advanced Filters > Custom Preset

특정 파라미터로 커스텀 필터 프리셋 생성.

```
Create Custom Preset
├─ 입력
│  ├─ Preset Name (FString): 고유 이름
│  ├─ Filter Type (EFilterType): Kalman 또는 OneEuro
│  ├─ Process Noise/Min Cutoff (float): 
│  │   - Kalman 선택 시: Process Noise (Q)
│  │   - OneEuro 선택 시: Min Cutoff
│  ├─ Measurement Noise/Beta (float):
│  │   - Kalman 선택 시: Measurement Noise (R)
│  │   - OneEuro 선택 시: Beta
│  └─ DCutoff (float): OneEuro 전용 (기본값: 1.0)
└─ 출력
   └─ Custom Preset (FCustomFilterPreset): 생성된 프리셋
```

⚠️ **중요 주의사항:**
- 파라미터의 의미가 필터 타입에 따라 달라집니다!
- Kalman 필터: 첫 번째 = Process Noise (Q), 두 번째 = Measurement Noise (R)
- OneEuro 필터: 첫 번째 = Min Cutoff, 두 번째 = Beta
- DCutoff는 OneEuro 필터에서만 사용됩니다

**사용 예제:**
```blueprint
// Kalman 프리셋 생성
[Create Custom Preset]
├─ Preset Name: "MyKalmanPreset"
├─ Filter Type: Kalman
├─ Process Noise/Min Cutoff: 0.05 (Q로 사용됨)
├─ Measurement Noise/Beta: 0.1 (R로 사용됨)
└─ DCutoff: 1.0 (무시됨)

// OneEuro 프리셋 생성
[Create Custom Preset]
├─ Preset Name: "MyOneEuroPreset"
├─ Filter Type: OneEuro
├─ Process Noise/Min Cutoff: 0.5 (Min Cutoff로 사용됨)
├─ Measurement Noise/Beta: 0.001 (Beta로 사용됨)
└─ DCutoff: 1.5 (사용됨)
```

---

### Apply Custom Preset (커스텀 프리셋 적용)
**카테고리:** Advanced Filters > Custom Preset

이전에 생성한 커스텀 프리셋을 필터에 적용.

```
Apply Custom Preset
├─ 입력
│  ├─ Target (UBaseFilterObject*): 필터 인스턴스
│  └─ Preset (FCustomFilterPreset): 적용할 프리셋
└─ 출력
   └─ Success (bool): 적용 성공 시 True
```

⚠️ **주의사항:**
- 필터 타입과 프리셋 타입이 일치해야 합니다
- Kalman 프리셋은 Kalman 필터에만 적용 가능
- OneEuro 프리셋은 OneEuro 필터에만 적용 가능

---

### Create Filter Chain (필터 체인 생성)
**카테고리:** Advanced Filters > Chain

순차 처리를 위한 다중 필터 체인 생성.

```
Create Filter Chain
├─ 입력
│  ├─ Filter Types (TArray<EFilterType>): 필터 타입 목록
│  └─ Presets (TArray<EFilterPreset>): 프리셋 목록
└─ 출력
   └─ Filter Chain (TArray<FFilterChainNode>): 체인 배열
```

---

### Process Through Chain (체인을 통한 처리)
**카테고리:** Advanced Filters > Chain

여러 필터를 순차적으로 통과하여 값 처리.

```
Process Through Chain
├─ 입력
│  ├─ Filter Chain (TArray<FFilterChainNode>): 체인 배열
│  ├─ Raw Value (float): 입력 값
│  └─ Delta Time (float): 시간 델타 (미사용)
└─ 출력
   └─ Filtered Value (float): 최종 결과
```

---

## 🛠️ 유틸리티 노드

### Reset Filter (필터 리셋)
**카테고리:** Advanced Filters > Utility

필터를 초기 상태로 리셋.

```
Reset Filter
├─ 입력
│  └─ Target (UBaseFilterObject*): 리셋할 필터
└─ 출력
   └─ (없음)
```

---

### Get Current Value (현재 값 가져오기)
**카테고리:** Advanced Filters > Utility

업데이트 없이 현재 필터링된 값 가져오기.

```
Get Current Value (Float)
├─ 입력
│  └─ Target (UBaseFilterObject*): 필터 인스턴스
└─ 출력
   └─ Current Value (float): 마지막 필터링된 값
```

---

### Is Filter Initialized (필터 초기화 확인)
**카테고리:** Advanced Filters > Utility

필터가 초기화되었는지 확인.

```
Is Filter Initialized
├─ 입력
│  └─ Target (UBaseFilterObject*): 확인할 필터
└─ 출력
   └─ Is Initialized (bool): 준비되었으면 True
```

---

### Get Kalman Gain (칼만 게인 가져오기)
**카테고리:** Advanced Filters > Advanced

현재 칼만 게인 값 가져오기 (진단용).

```
Get Kalman Gain
├─ 입력
│  └─ Target (UKalmanFilter*): 칼만 필터
└─ 출력
   └─ Kalman Gain (float): 현재 게인 (0-1)
```

**해석:**
- 0에 가까움 = 예측 신뢰
- 1에 가까움 = 측정 신뢰

---

### Get Error Covariance (오차 공분산 가져오기)
**카테고리:** Advanced Filters > Advanced

현재 오차 공분산 (불확실성) 가져오기.

```
Get Error Covariance
├─ 입력
│  └─ Target (UKalmanFilter*): 칼만 필터
└─ 출력
   └─ Error Covariance (float): 현재 불확실성
```

---

### Cleanup All Filters (모든 필터 제거)
**카테고리:** Advanced Filters > Utility

캐시된 모든 필터 인스턴스 제거.

```
Cleanup All Filters
└─ 출력
   └─ (없음)
```

**사용 사례:**
- 레벨 전환
- 메모리 정리
- 테스트

---

### Get Filter Memory Usage (필터 메모리 사용량)
**카테고리:** Advanced Filters > Performance

모든 필터가 사용하는 총 메모리 보고.

```
Get Filter Memory Usage
└─ 출력
   ├─ Filter Count (int32): 활성 필터 수
   └─ Memory Bytes (int32): 총 메모리 사용량
```

---

### Start Filter Profiling (필터 프로파일링 시작)
**카테고리:** Advanced Filters > Performance

필터의 성능 프로파일링 시작.

```
Start Filter Profiling
├─ 입력
│  └─ Profile ID (FString): 프로파일 식별자
└─ 출력
   └─ (없음)
```

---

### Stop Filter Profiling (필터 프로파일링 중지)
**카테고리:** Advanced Filters > Performance

프로파일링을 중지하고 성능 데이터 반환.

```
Stop Filter Profiling
├─ 입력
│  └─ Profile ID (FString): 프로파일 식별자
└─ 출력
   ├─ Average Time MS (float): 평균 업데이트 시간
   ├─ Peak Time MS (float): 최대 업데이트 시간
   └─ Update Count (int32): 총 업데이트 횟수
```

---

## 🔍 디버그 및 추천 노드

### Recommend Filter Type (필터 타입 추천)
**카테고리:** Advanced Filters > Recommendation

사용 사례에 따른 최적 필터 타입 추천.

```
Recommend Filter Type
├─ 입력
│  ├─ Needs Fast Response (bool): 빠른 반응 필요
│  ├─ Needs Precise Prediction (bool): 정밀한 예측 필요
│  ├─ Is VR/AR Input (bool): VR/AR 입력인지
│  └─ Has Variable Frame Rate (bool): 가변 프레임레이트
└─ 출력
   └─ Filter Type (EFilterType): 추천 필터 타입
```

---

### Get Filter Statistics (필터 통계)
**카테고리:** Advanced Filters > Debug

디버깅을 위한 상세한 필터 정보.

```
Get Filter Statistics
├─ 입력
│  └─ Target (UBaseFilterObject*): 필터 인스턴스
└─ 출력
   └─ Statistics (FString): 상세 통계 문자열
```

---

## 📊 데이터 타입

### UBaseFilterObject

모든 필터 타입의 기본 클래스.

**속성:**
- `bIsInitialized`: 필터 사용 준비 여부
- `CurrentValue`: 마지막 필터링된 값
- `UpdateCount`: 총 업데이트 횟수

**블루프린트 접근:** 읽기 전용

---

### UKalmanFilter

칼만 필터 구현.

**추가 속성:**
- `StateEstimate`: 현재 상태 추정값
- `ErrorCovariance`: 현재 불확실성
- `ProcessNoise`: Q 파라미터
- `MeasurementNoise`: R 파라미터
- `KalmanGain`: 현재 게인

**블루프린트 접근:** 읽기 전용

---

### UOneEuroFilter

원유로 필터 구현.

**추가 속성:**
- `MinCutoff`: 최소 컷오프 주파수
- `Beta`: 속도 계수  
- `DCutoff`: 미분 컷오프
- `LastTime`: 마지막 업데이트 타임스탬프

**블루프린트 접근:** 읽기 전용

---

### FCustomFilterPreset

커스텀 필터 프리셋 구조체.

**속성:**
- `PresetName`: 프리셋 이름
- `FilterType`: 필터 타입 (Kalman/OneEuro)
- `ProcessNoise`: Kalman Q 파라미터
- `MeasurementNoise`: Kalman R 파라미터
- `MinCutoff`: OneEuro 최소 컷오프
- `Beta`: OneEuro 속도 계수
- `DCutoff`: OneEuro 미분 컷오프

---

### FFilterChainNode

필터 체인 노드 구조체.

**속성:**
- `Filter`: 필터 인스턴스
- `Weight`: 블렌딩 가중치 (0.0 - 1.0)

---

### FFilterPerformanceData

성능 데이터 구조체.

**속성:**
- `AverageProcessingTime`: 평균 처리 시간
- `MaxProcessingTime`: 최대 처리 시간
- `UpdateCount`: 업데이트 횟수
- `TotalProcessingTime`: 총 처리 시간

---

## 🔤 열거형

### EFilterType (필터 타입)

생성할 필터의 타입을 지정.

```cpp
enum class EFilterType : uint8
{
    Kalman      UMETA(DisplayName = "칼만 필터"),
    OneEuro     UMETA(DisplayName = "원유로 필터")
};
```

---

### EFilterPreset (필터 프리셋)

사전 정의된 필터 구성.

```cpp
enum class EFilterPreset : uint8
{
    Low         UMETA(DisplayName = "Low (빠른 반응)"),
    Medium      UMETA(DisplayName = "Medium (균형)"),
    High        UMETA(DisplayName = "High (최대 스무딩)")
};
```

---

## 💡 성능 참고사항

### 계산 복잡도

| 작업 | 칼만 | 원유로 |
|------|------|--------|
| 업데이트 (Float) | O(1) | O(1) |
| 업데이트 (Vector) | O(3) | O(3) |
| 인스턴스당 메모리 | ~100 바이트 | ~150 바이트 |

### 스레딩

- 모든 노드는 스레드 안전
- 필터 인스턴스는 스레드 간 공유 가능
- 원클릭 매크로는 내부 잠금 사용

### 모범 사례

1. **필터 ID 재사용** - 중복 인스턴스 생성 방지
2. **배치 업데이트** - 한 프레임에 여러 값 처리
3. **성능 프로파일** - 개발 중 프로파일링 노드 사용
4. **미사용 필터 제거** - 레벨 변경 시 메모리 해제

---

## 🚧 아직 구현되지 않은 기능

### 예측 기능 (문서에는 있지만 코드에는 없음)

다음 기능들은 향후 업데이트에서 추가될 예정입니다:

```
// 예정된 기능
Predict Next State (칼만 필터)
├─ 입력
│  ├─ Target (UKalmanFilter*): 칼만 필터
│  └─ Steps Ahead (int32): 예측할 스텝 수
└─ 출력
   └─ Predicted Value (float): 예측된 값

Get Predicted Value (칼만 필터)
├─ 입력
│  └─ Target (UKalmanFilter*): 칼만 필터
└─ 출력
   └─ Predicted Value (float): 현재 예측값
```

---

## 📝 예제 코드

### 기본 칼만 필터링 (Advanced Filters > Core 사용)
```blueprint
// Begin Play
Create Filter (Kalman) → Initialize (Medium) → 변수 설정 (MyFilter)

// Event Tick
변수 가져오기 (MyFilter) → Update Filter Float (센서 값) → Set Actor Location
```

### 커스텀 프리셋을 사용한 고급 원유로
```blueprint
// Begin Play - Kalman 커스텀 프리셋
Create Custom Preset
├─ Preset Name: "VR_Hand_Kalman"
├─ Filter Type: Kalman
├─ Process Noise/Min Cutoff: 0.05 (Q로 사용)
├─ Measurement Noise/Beta: 0.02 (R로 사용)
└─ DCutoff: 1.0 (무시됨)

// Begin Play - OneEuro 커스텀 프리셋
Create Custom Preset
├─ Preset Name: "VR_Hand_OneEuro"
├─ Filter Type: OneEuro
├─ Process Noise/Min Cutoff: 0.3 (Min Cutoff로 사용)
├─ Measurement Noise/Beta: 0.0001 (Beta로 사용)
└─ DCutoff: 1.0 (사용됨)

// 필터 생성 및 프리셋 적용
Create Filter (OneEuro) → Apply Custom Preset ("VR_Hand_OneEuro") → 변수 설정

// Event Tick
변수 가져오기 → Update Filter Vector (컨트롤러 위치, Delta Time) → Set Hand Mesh Location
```

---

실제 예제는 [블루프린트 예제](Examples_KR.md)를 참조하세요 →