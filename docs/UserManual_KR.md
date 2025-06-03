# 사용자 매뉴얼 (개선판)

*다른 언어로 읽기: [English](UserManual.md), [한국어](UserManual_KR.md)*

언리얼 엔진용 고급 필터 플러그인 완벽 가이드

## 📍 네비게이션

- [← 이전: 빠른 시작 가이드](QuickStart_KR.md)
- [→ 다음: API 레퍼런스](APIReference_KR.md)

### 📖 전체 문서
- **시작하기**
  - [빠른 시작 가이드](QuickStart_KR.md)
  - [설치 가이드](Installation_KR.md)
- **사용자 가이드**
  - **사용자 매뉴얼** (현재 페이지)
  - [블루프린트 예제](Examples_KR.md)
  - [모범 사례](BestPractices_KR.md)
- **기술 문서**
  - [API 레퍼런스](APIReference_KR.md)
  - [성능 가이드](Performance_KR.md)
  - [문제 해결](Troubleshooting_KR.md)

---

## 🗂️ 블루프린트 노드 찾기 가이드

### 노드 카테고리 맵

블루프린트 에디터에서 우클릭 시 다음 카테고리에서 노드를 찾을 수 있습니다:

```
Advanced Filters
├── Core (핵심 3-노드 시스템)
│   ├── Create Filter
│   ├── Initialize Filter
│   └── Update Filter (Float/Vector)
├── One-Click (원클릭 매크로)
│   ├── Kalman Filter Value
│   ├── Kalman Filter Vector
│   ├── One Euro Filter Value
│   └── One Euro Filter Vector
├── Utility (유틸리티)
│   ├── Reset Filter
│   ├── Get Current Value
│   ├── Is Filter Initialized
│   └── Cleanup All Filters
├── Advanced (고급 기능)
│   ├── Set Process Noise
│   ├── Set Measurement Noise
│   ├── Set Min Cutoff
│   └── Set Beta
├── Custom Preset (커스텀 프리셋)
│   ├── Create Custom Preset
│   └── Apply Custom Preset
├── Chain (필터 체인)
│   ├── Create Filter Chain
│   └── Process Through Chain
├── Performance (성능)
│   ├── Start Profiling
│   └── Stop Profiling
├── Debug (디버그)
│   └── Get Filter Statistics
└── Recommendation (추천)
    └── Recommend Filter Type
```

**💡 팁**: 검색창에 "Advanced Filters"를 입력하면 모든 관련 노드가 표시됩니다!

---

## 📋 목차

1. [소개](#소개)
2. [필터 종류](#필터-종류)
3. [기본 사용법](#기본-사용법)
4. [고급 기능](#고급-기능)
5. [모범 사례](#모범-사례)
6. [성능 최적화](#성능-최적화)

---

## 🎯 소개

고급 필터 플러그인은 언리얼 엔진에서 전문적이고 세련된 경험을 만들 수 있도록 두 가지 산업 표준 필터링 알고리즘을 제공합니다. 노이즈가 있는 센서 데이터, 떨리는 입력, 예측할 수 없는 움직임을 다룰 때 이 필터들이 부드럽고 안정적인 결과를 달성하도록 도와줍니다.

### 필터를 사용해야 할 때

다음과 같은 경우에 필터가 필수적입니다:
- ✅ 센서 데이터에서 노이즈 제거
- ✅ 사용자 입력 스무딩 (마우스, 터치, VR 컨트롤러)
- ✅ 카메라 움직임 안정화
- ✅ 전문적인 UI 애니메이션 생성
- ✅ AI 움직임 패턴 개선

---

## 🔧 필터 종류

### 칼만 필터

칼만 필터는 과거 관측값을 기반으로 미래 상태를 예측하는 최적 상태 추정기입니다.

**특징:**
- 🎯 뛰어난 노이즈 제거 (95% 이상)
- 📊 예측 기능
- ⏱️ 5-10 프레임 지연
- 🔄 일관된 스무딩

**최적 사용 사례:**
- 카메라 안정화
- AI 경로 찾기
- 센서 데이터 처리
- 물리 시뮬레이션
- 체력/마나 바

### 원유로 필터

원유로 필터는 신호 속도에 따라 스무딩을 조정하는 적응형 필터입니다.

**특징:**
- ⚡ 낮은 지연 시간 (0-3 프레임)
- 🎮 속도 적응형 필터링
- 📈 85% 이상 노이즈 제거
- 🔀 동적 반응

**최적 사용 사례:**
- VR/AR 컨트롤러
- 마우스 입력
- 터치 인터페이스
- 실시간 상호작용
- 드로잉 애플리케이션

---

## 💡 기본 사용법

### 방법 1: 원클릭 매크로 (가장 간단)

초보자나 빠른 프로토타이핑에 완벽합니다.

#### Float 필터링
```blueprint
카테고리: Advanced Filters > One-Click

[노이즈 값] → [Kalman Filter Value] → [부드러운 결과]
               │
               ├─ Preset: Low/Medium/High
               └─ Filter ID: "고유ID"
```

#### Vector 필터링
```blueprint
카테고리: Advanced Filters > One-Click

[노이즈 위치] → [One Euro Filter Vector] → [부드러운 위치]
                 │
                 ├─ Preset: Medium
                 ├─ Delta Time: Event Tick Delta
                 └─ Filter ID: "Position"
```

### 방법 2: 3-노드 시스템 (완전한 제어)

필터 수명 주기와 파라미터에 대한 완전한 제어를 제공합니다.

#### 설정 단계
```blueprint
카테고리: Advanced Filters > Core

Begin Play:
[Create Filter] → [Initialize Filter] → [변수에 저장]
       │                    │
       │                    └─ Preset: Medium
       └─ Type: Kalman/OneEuro
```

#### 업데이트 단계
```blueprint
Event Tick:
[필터 변수 가져오기] → [Update Filter] → [결과 가져오기]
                           │
                           └─ New Value: 센서 값
```

### 프리셋 시스템

각 필터는 다양한 시나리오에 최적화된 세 가지 프리셋을 포함합니다:

| 프리셋 | 반응 | 스무딩 | 사용 사례 |
|--------|------|--------|----------|
| **Low** | 빠름 | 최소 | 빠른 반응 필요 |
| **Medium** | 균형 | 보통 | 범용 |
| **High** | 느림 | 최대 | 부드러운 시각 우선 |

---

## 🚀 고급 기능

### 커스텀 프리셋

특정 요구에 맞는 필터 구성을 만들 수 있습니다.

```blueprint
카테고리: Advanced Filters > Custom Preset

[Create Custom Preset]
├─ Name: "MyVRController"
├─ Filter Type: OneEuro 선택 시
│  ├─ Process Noise/Min Cutoff: 0.5 (Min Cutoff로 사용)
│  ├─ Measurement Noise/Beta: 0.0001 (Beta로 사용)
│  └─ DCutoff: 1.0
└─ Filter Type: Kalman 선택 시
   ├─ Process Noise/Min Cutoff: 0.05 (Process Noise로 사용)
   ├─ Measurement Noise/Beta: 0.1 (Measurement Noise로 사용)
   └─ DCutoff: (무시됨)
```

⚠️ **중요**: 파라미터 이름이 필터 타입에 따라 다른 의미를 가집니다!
- **Kalman 필터**: 첫 번째 = Process Noise (Q), 두 번째 = Measurement Noise (R)
- **OneEuro 필터**: 첫 번째 = Min Cutoff, 두 번째 = Beta

### 필터 체이닝

정교한 처리를 위해 여러 필터를 결합합니다.

```blueprint
카테고리: Advanced Filters > Chain

[Create Filter Chain]
├─ Filter 1: Kalman (High)    // 큰 노이즈 제거
├─ Filter 2: OneEuro (Low)    // 반응성 유지
└─ Blend Weight: 0.7          // 70% 첫 번째, 30% 두 번째
    ↓
[Process Through Chain]
├─ Input: 원본 신호
└─ Output: 이중 필터링된 결과
```

### 필터 블렌딩

여러 필터의 출력을 동적으로 혼합합니다.

```blueprint
카테고리: Advanced Filters > Chain

[Blend Filter Outputs]
├─ Filter A: 칼만 결과
├─ Filter B: 원유로 결과
├─ Weight: 0.0-1.0 (런타임 조정 가능)
└─ Output: 가중 평균
```

### 성능 프로파일링

실시간으로 필터 성능을 모니터링합니다.

```blueprint
카테고리: Advanced Filters > Performance

[Start Filter Profiling]
    ↓
[... 필터링 로직 ...]
    ↓
[Stop Filter Profiling]
    ↓
[Get Profile Data]
├─ Average Time: 0.02ms
├─ Peak Time: 0.05ms
├─ Update Count: 1847
└─ Memory Usage: 128 bytes
```

### 자동 튜닝

시스템이 자동으로 필터 파라미터를 조정하도록 합니다.

```blueprint
카테고리: Advanced Filters > Advanced

[Auto Tune Filter]
├─ Filter: 대상 필터
├─ Recent Values: 최근 100개 값 배열
└─ Success: 자동 조정 성공 여부
    ↓
[신호 특성에 따라 필터가 자동 조정됨]
```

### 필터 통계

디버깅을 위한 상세한 필터 정보에 접근합니다.

```blueprint
카테고리: Advanced Filters > Debug

[Get Filter Statistics]
├─ Target: 필터 인스턴스
└─ Output: 통계 문자열
    - 필터 타입
    - 현재 값
    - 칼만 게인 (칼만만)
    - 현재 컷오프 (원유로만)
    - 업데이트 횟수
```

---

## 📚 모범 사례

### 1. 필터 선택

사용 사례에 맞는 올바른 필터를 선택하세요:

```
지연 시간이 중요한가요? (VR/AR/마우스)
    ├─ 예 → 원유로 필터
    └─ 아니오 → 예측이 필요한가요?
                ├─ 예 → 칼만 필터
                └─ 아니오 → 둘 다 가능
```

### 2. 일관된 필터 ID

연속적인 필터링을 위해 항상 같은 필터 ID를 사용하세요:

✅ **좋은 예:**
```blueprint
Filter ID: "PlayerHealth"  // 매 프레임 같은 ID
```

❌ **나쁜 예:**
```blueprint
Filter ID: "Health_" + FrameCount  // 매 프레임 새 필터 생성!
```

### 3. 원유로의 Delta Time

원유로 필터에는 항상 Delta Time을 연결하세요:

```blueprint
[One Euro Filter Value]
├─ Raw Value: 입력
├─ Delta Time: Event Tick Delta ← 잊지 마세요!
├─ Preset: Medium
└─ Filter ID: "MouseX"
```

### 4. 프리셋 선택 가이드

- **Low**: 사용자 입력, 빠른 게임플레이
- **Medium**: 대부분의 상황
- **High**: 시네마틱 카메라, UI 요소

### 5. 메모리 관리

필터는 자동으로 관리되지만 다음 지침을 따르세요:
- 가능하면 필터 ID 재사용
- `Cleanup All Filters` 노드로 미사용 필터 정리 (Advanced Filters > Utility)
- `Get Filter Memory Usage`로 메모리 모니터링 (Advanced Filters > Performance)

---

## ⚡ 성능 최적화

### 성능 특성

| 작업 | 시간 | 메모리 |
|------|------|--------|
| 필터 생성 | 0.1ms | 100-150 바이트 |
| 업데이트 (Float) | 0.01ms | 0 바이트 |
| 업데이트 (Vector) | 0.03ms | 0 바이트 |
| 커스텀 프리셋 | 0.02ms | 50 바이트 |

### 최적화 팁

1. **배치 처리**
   ```blueprint
   // 같은 필터로 여러 값 처리
   [For Each Loop]
   └─ [Update Filter] (같은 필터 인스턴스 사용)
   ```

2. **조건부 업데이트**
   ```blueprint
   // 값이 크게 변할 때만 업데이트
   If (Abs(NewValue - LastValue) > Threshold)
       → Update Filter
   ```

3. **LOD 기반 필터링**
   ```blueprint
   // 거리에 따라 다른 프리셋 사용
   가까이: High 프리셋
   중간: Medium 프리셋
   멀리: Low 프리셋 또는 건너뛰기
   ```

4. **프레임 레이트 독립성**
   ```blueprint
   // 프레임 레이트에 관계없이 일관된 동작 보장
   원유로에는 항상 Delta Time 사용
   커스텀 프리셋에서 프레임 레이트 고려
   ```

---

## 🔍 디버깅

### 시각적 디버깅

필터 동작을 보기 위해 시각적 디버깅을 활성화하세요:

```blueprint
카테고리: Advanced Filters > Debug

[Get Filter Statistics]
├─ Filter: 대상 필터
└─ 출력을 Print String으로 표시
```

### 일반적인 문제

| 문제 | 원인 | 해결책 |
|------|------|--------|
| 스무딩 없음 | 잘못된 필터 ID | 일관된 ID 사용 |
| 너무 많은 지연 | High 프리셋 | Low/Medium으로 전환 |
| 출력이 튐 | Delta Time 누락 | Delta Time 연결 |
| 메모리 증가 | 새 필터 생성 | 필터 ID 재사용 |

---

## 🚧 아직 구현되지 않은 기능

다음 기능들은 문서에는 설명되어 있지만 현재 버전에서는 구현되지 않았습니다:

### 예측 기능 (향후 업데이트 예정)
- **Predict Next State**: 칼만 필터의 미래 상태 예측
- **Get Predicted Value**: 현재 예측값 가져오기

이 기능들은 다음 버전에서 추가될 예정입니다.

---

## 📝 요약

고급 필터 플러그인은 최소한의 노력으로 전문적이고 세련된 경험을 만들 수 있도록 지원합니다. VR 애플리케이션을 구축하든, 카메라 움직임을 안정화하든, 센서 데이터를 처리하든, 이 필터들이 필요한 도구를 제공합니다.

**핵심 요점:**
- 🎯 예측과 안정성을 위해 칼만 선택
- ⚡ 낮은 지연을 위해 원유로 선택
- 📊 프리셋으로 시작하고 필요에 따라 커스터마이즈
- 🔧 간단함을 위해 원클릭, 제어를 위해 3-노드 사용
- 📈 내장 프로파일링으로 성능 모니터링
- 🗂️ 카테고리를 이해하면 노드 찾기가 쉬워집니다!

---

즐거운 필터링 되세요! 🎉

기술적 세부사항은 [API 레퍼런스](APIReference_KR.md)를 참조하세요 →