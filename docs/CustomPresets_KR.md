# 커스텀 프리셋

*다른 언어로 읽기: [English](CustomPresets.md), [한국어](CustomPresets_KR.md)*

커스텀 필터 프리셋 생성 및 관리를 위한 고급 가이드

## 📍 네비게이션

- [← 이전: 모범 사례](BestPractices_KR.md)
- [→ 다음: 필터 체이닝](FilterChaining_KR.md)

### 📖 전체 문서
- **시작하기**
  - [빠른 시작 가이드](QuickStart_KR.md)
  - [설치 가이드](Installation_KR.md)
- **사용자 가이드**
  - [사용자 매뉴얼](UserManual_KR.md)
  - [블루프린트 예제](Examples_KR.md)
  - [모범 사례](BestPractices_KR.md)
- **기술 문서**
  - [API 레퍼런스](APIReference_KR.md)
  - [성능 가이드](Performance_KR.md)
  - [문제 해결](Troubleshooting_KR.md)
- **고급 주제**
  - **커스텀 프리셋** (현재 페이지)
  - [필터 체이닝](FilterChaining_KR.md)
  - [마이그레이션 가이드](Migration_KR.md)

---

## 📋 목차

1. [프리셋 이해하기](#프리셋-이해하기)
2. [커스텀 프리셋 생성](#커스텁-프리셋-생성)
3. [프리셋 관리](#프리셋-관리)
4. [사용 사례 예제](#사용-사례-예제)
5. [고급 기법](#고급-기법)
6. [프리셋 문제 해결](#프리셋-문제-해결)

---

## 🎯 프리셋 이해하기

### 프리셋이란?

필터 프리셋은 필터의 동작 방식을 정의하는 미리 구성된 파라미터 세트입니다. 개별 파라미터를 수동으로 조정하는 대신, 프리셋은 일반적인 시나리오에 최적화된 구성을 제공합니다.

### 내장 프리셋

플러그인에는 세 가지 내장 프리셋이 포함되어 있습니다:

| 프리셋 | 칼만 Q | 칼만 R | 원유로 MinCutoff | 원유로 Beta | 사용 사례 |
|--------|--------|--------|------------------|-------------|----------|
| **Low** | 0.1 | 0.01 | 1.0 | 0.001 | 빠른 반응, 최소 필터링 |
| **Medium** | 0.01 | 0.1 | 0.5 | 0.007 | 균형잡힌 성능 |
| **High** | 0.001 | 1.0 | 0.1 | 0.01 | 최대 스무딩 |

### 커스텀 프리셋을 만들어야 할 때

다음과 같은 경우 커스텀 프리셋을 만드세요:
- ✅ 내장 프리셋이 특정 요구사항을 충족하지 못할 때
- ✅ 고유한 하드웨어 특성이 있을 때 (VR 헤드셋, 센서)
- ✅ 애플리케이션에 특정 지연/스무딩 요구사항이 있을 때
- ✅ 팀 전체에서 설정을 표준화하고 싶을 때

---

## 🛠️ 커스텀 프리셋 생성

### 방법 1: 블루프린트 생성

#### 기본 커스텀 프리셋
```blueprint
Event BeginPlay
    ↓
[Create Custom Preset]
├─ Preset Name: "MyVRController"
├─ Process Noise (칼만 Q): 0.05
├─ Measurement Noise (칼만 R): 0.02
├─ Min Cutoff (원유로): 0.3
├─ Beta (원유로): 0.0001
└─ DCutoff (원유로): 1.0
    ↓
[Success] → 나중에 사용할 프리셋 이름 저장
```

#### 커스텀 프리셋 적용
```blueprint
[Create Filter] (Type: OneEuro)
    ↓
[Apply Custom Preset]
├─ Target: 필터 참조
└─ Preset Name: "MyVRController"
    ↓
[필터가 이제 커스텀 파라미터 사용]
```

### 방법 2: 런타임 생성

조건에 따라 동적으로 프리셋 생성:

```blueprint
// 적응형 프리셋 생성
Get Hardware Type
├─ Branch (모바일 기기인가?)
│   ├─ True: "MobileOptimized" 프리셋 생성
│   │   ├─ Q: 0.2 (빠른 반응)
│   │   ├─ R: 0.01 (측정값 신뢰)
│   │   ├─ MinCutoff: 1.5 (적은 스무딩)
│   │   └─ Beta: 0.0005
│   └─ False: "DesktopOptimized" 프리셋 생성
│       ├─ Q: 0.005 (더 부드러움)
│       ├─ R: 0.5 (더 많은 필터링)
│       ├─ MinCutoff: 0.2 (더 많은 스무딩)
│       └─ Beta: 0.01
```

### 파라미터 가이드라인

#### 칼만 필터 파라미터

**Process Noise (Q):**
- 높은 값 (0.1+): 새로운 측정값을 더 신뢰, 빠른 적응
- 낮은 값 (0.001-0.01): 예측값을 더 신뢰, 부드러운 출력
- 일반적인 범위: 0.001 ~ 1.0

**Measurement Noise (R):**
- 높은 값 (1.0+): 측정값이 노이즈가 많다고 가정, 더 많은 스무딩
- 낮은 값 (0.01-0.1): 측정값 신뢰, 적은 스무딩
- 일반적인 범위: 0.01 ~ 10.0

#### 원유로 필터 파라미터

**Min Cutoff:**
- 높은 값 (1.0+): 적은 스무딩, 빠른 반응
- 낮은 값 (0.1-): 많은 스무딩, 느린 반응
- 일반적인 범위: 0.001 ~ 10.0

**Beta (속도 계수):**
- 높은 값 (0.01+): 더 많은 속도 적응
- 낮은 값 (0.0001-): 적은 속도 적응
- 일반적인 범위: 0.0001 ~ 1.0

**DCutoff (미분 컷오프):**
- 보통 1.0으로 설정
- 높은 값: 더 부드러운 미분 계산
- 범위: 0.1 ~ 10.0

---

## 📚 프리셋 관리

### 프리셋 저장 및 로드

#### 프리셋을 파일로 저장
```blueprint
[Create Custom Preset] → Success
    ↓
[Save Preset to Config]
├─ Preset Name: "MyPreset"
├─ File Path: "Config/FilterPresets.ini"
└─ Section: "CustomPresets"
```

#### 파일에서 프리셋 로드
```blueprint
Event BeginPlay
    ↓
[Load Preset from Config]
├─ Preset Name: "MyPreset"
├─ File Path: "Config/FilterPresets.ini"
└─ Section: "CustomPresets"
    ↓
[필터에 적용]
```

### 프리셋 검증

오류를 방지하기 위해 프리셋 파라미터 검증:

```blueprint
[Validate Custom Preset]
├─ Preset Name: 입력 문자열
├─ 파라미터 확인:
│   ├─ Q > 0 그리고 Q < 10
│   ├─ R > 0 그리고 R < 100
│   ├─ MinCutoff > 0 그리고 MinCutoff < 100
│   └─ Beta >= 0 그리고 Beta <= 1
└─ 결과: 유효/무효 + 오류 메시지
```

### 프리셋 컬렉션

여러 프리셋 정리:

```blueprint
// VR용 프리셋 컬렉션 생성
[Create Preset Collection]
├─ Collection Name: "VR_Presets"
├─ Presets:
│   ├─ "VR_Head": 높은 스무딩, 낮은 지연
│   ├─ "VR_Controllers": 중간 스무딩, 매우 낮은 지연
│   └─ "VR_Haptics": 낮은 스무딩, 즉각적 반응
└─ 컬렉션 저장
```

---

## 🎮 사용 사례 예제

### 예제 1: VR 모션 컨트롤러

최소 지연으로 손 추적에 완벽:

```blueprint
[Create Custom Preset]
├─ Name: "VR_Hands"
├─ Process Noise: 0.0    // 원유로에서 사용 안 함
├─ Measurement Noise: 0.0 // 원유로에서 사용 안 함
├─ Min Cutoff: 0.4       // 적당한 스무딩
├─ Beta: 0.00001         // 최소 속도 적응
└─ DCutoff: 1.0          // 표준 미분
```

**이 값들을 선택한 이유:**
- 낮은 MinCutoff: 눈에 띄는 지연 없이 떨림 제거
- 매우 낮은 Beta: 손 떨림에 과도하게 적응하지 않음
- 표준 DCutoff: 안정적인 미분 계산

### 예제 2: 고정밀 마우스 조준

경쟁적 게임 애플리케이션용:

```blueprint
[Create Custom Preset]
├─ Name: "Gaming_Mouse"
├─ Process Noise: 0.0    // 원유로만 해당
├─ Measurement Noise: 0.0
├─ Min Cutoff: 2.0       // 최소 스무딩
├─ Beta: 0.001           // 가벼운 속도 적응
└─ DCutoff: 2.0          // 빠른 미분
```

**특성:**
- 높은 MinCutoff: 빠른 움직임 보존
- 낮은 Beta: 빠른 조준을 과도하게 스무딩하지 않음
- 높은 DCutoff: 속도 변화에 반응적

### 예제 3: 시네마틱 카메라 스무딩

부드럽고 전문적인 카메라 움직임용:

```blueprint
[Create Custom Preset]
├─ Name: "Cinematic_Cam"
├─ Process Noise: 0.001  // 예측에 높은 신뢰
├─ Measurement Noise: 2.0 // 노이즈가 있는 입력 가정
├─ Min Cutoff: 0.05      // 최대 스무딩
├─ Beta: 0.02            // 강한 속도 적응
└─ DCutoff: 0.5          // 부드러운 미분
```

**칼만 중심 프리셋:**
- 매우 낮은 Q: 부드러운 예측 우선
- 높은 R: 입력 노이즈를 많이 필터링
- 반응성보다 시네마틱 품질 우선

### 예제 4: 모바일 터치 인터페이스

다양한 정밀도의 터치 스크린에 최적화:

```blueprint
[Create Custom Preset]
├─ Name: "Mobile_Touch"
├─ Process Noise: 0.08   // 적당한 적응
├─ Measurement Noise: 0.3 // 어느 정도 노이즈 예상
├─ Min Cutoff: 0.8       // 균형잡힌 스무딩
├─ Beta: 0.005           // 적당한 속도 반응
└─ DCutoff: 1.5          // 안정적인 미분
```

**모바일 고려사항:**
- 손가락 크기와 부정확함 고려
- 부드러움과 반응성 균형
- 다양한 화면 크기에서 잘 작동

### 예제 5: 센서 데이터 처리

노이즈가 있는 센서 데이터용 (가속도계, 자이로스코프):

```blueprint
[Create Custom Preset]
├─ Name: "Sensor_Stable"
├─ Process Noise: 0.01   // 모델 예측 신뢰
├─ Measurement Noise: 5.0 // 매우 노이즈가 많은 센서
├─ Min Cutoff: 0.1       // 강한 스무딩
├─ Beta: 0.001           // 최소 속도 적응
└─ DCutoff: 0.3          // 매우 부드러운 미분
```

**센서별 튜닝:**
- 높은 R 값으로 센서 노이즈 수용
- 낮은 Beta로 진동에 과도하게 반응하지 않음
- 안정적인 출력을 위한 강한 스무딩

---

## 🚀 고급 기법

### 동적 프리셋 전환

게임 상태에 따라 프리셋 전환:

```blueprint
// 컨텍스트 인식 필터링
Get Game State
├─ Branch (전투 중인가?)
│   ├─ True: "Combat_Responsive" 적용
│   │   └─ 낮은 지연, 최소 스무딩
│   └─ False: Branch (메뉴에 있는가?)
│       ├─ True: "Menu_Smooth" 적용
│       │   └─ 높은 스무딩, 시각적 우선
│       └─ False: "Exploration_Balanced" 적용
│           └─ 균형잡힌 설정
```

### 프리셋 보간

프리셋 간 부드러운 전환:

```blueprint
[Interpolate Between Presets]
├─ Preset A: "Current_Settings"
├─ Preset B: "Target_Settings"
├─ Alpha: 0.0-1.0 (전환 진행도)
└─ Output: 보간된 프리셋
    ↓
[Apply Interpolated Preset] 필터에 적용
```

### A/B 테스트 프리셋

다른 프리셋 비교:

```blueprint
// 테스트 프레임워크
[Create Test Session]
├─ Preset A: "Conservative"
├─ Preset B: "Aggressive"
├─ Switch every: 30초
└─ 사용자 선호도 로그
    ↓
[Analyze Results] → 최적 프리셋 선택
```

### 하드웨어별 프리셋

하드웨어 감지하여 적절한 프리셋 적용:

```blueprint
[Detect Hardware]
├─ Get Platform
├─ Get Input Device Type
└─ Get Performance Level
    ↓
[Select Preset]
├─ VR + 높은 성능: "VR_Premium"
├─ 모바일 + 낮은 성능: "Mobile_Efficient"
├─ 데스크톱 + 게임: "Desktop_Responsive"
└─ 기본값: "Universal_Balanced"
```

---

## 🔧 프리셋 최적화

### 성능 고려사항

일부 파라미터 조합이 더 효율적:

**빠른 프리셋** (낮은 CPU 사용량):
- 높은 MinCutoff 값
- 낮은 Beta 값
- 표준 DCutoff (1.0)

**품질 프리셋** (높은 CPU 사용량):
- 낮은 MinCutoff 값
- 높은 Beta 값
- 커스텀 DCutoff 값

### 메모리 관리

커스텀 프리셋은 추가 메모리 사용:

```blueprint
// 프리셋 메모리 사용량 모니터링
[Get Preset Memory Usage]
├─ Total Presets: 개수
├─ Memory per Preset: ~50 바이트
└─ Total Memory: 개수 × 50 바이트
```

**최적화 팁:**
- 10-20개의 커스텀 프리셋으로 제한
- `Clear Custom Presets`로 미사용 프리셋 정리
- 유사한 사용 사례에서 프리셋 재사용

---

## 🔍 프리셋 문제 해결

### 일반적인 문제

#### 프리셋이 적용되지 않음
**문제:** 커스텀 프리셋이 작동하지 않는 것 같음

**해결책:**
1. 프리셋 이름이 정확히 일치하는지 확인
2. 프리셋이 성공적으로 생성되었는지 확인
3. 파라미터가 유효한 범위 내에 있는지 확인
4. 프리셋 재생성 시도

#### 파라미터가 올바르지 않은 느낌
**문제:** 커스텀 프리셋 동작이 예상과 다름

**디버그 접근법:**
```blueprint
[Get Current Filter Parameters]
├─ 실제 Q, R 값 표시 (칼만)
├─ MinCutoff, Beta 값 표시 (원유로)
└─ 의도한 프리셋 값과 비교
```

#### 성능 문제
**문제:** 커스텀 프리셋이 성능 문제 야기

**해결책:**
1. 파라미터가 너무 극단적인지 확인
2. 원유로의 Beta 값 감소
3. 적은 처리를 위해 MinCutoff 증가
4. `Start Filter Profiling`로 프로파일

### 검증 도구

#### 파라미터 범위 체커
```blueprint
[Validate Preset Parameters]
├─ Input: 커스텀 프리셋
├─ Check: 모든 파라미터가 유효한 범위에 있는지
├─ Warning: 극단적인 파라미터
└─ Output: 검증 보고서
```

#### 프리셋 비교 도구
```blueprint
[Compare Presets]
├─ Preset A: "Built-in Medium"
├─ Preset B: "Custom Settings"
├─ Test Input: 노이즈가 있는 사인파
└─ Output: 나란히 비교
```

---

## 📊 프리셋 라이브러리

### 커뮤니티 프리셋

커뮤니티에서 테스트된 프리셋:

#### 게임 프리셋
```cpp
// FPS 마우스 조준
"FPS_Pro": MinCutoff=3.0, Beta=0.0008, DCutoff=2.5

// 레이싱 게임 핸들
"Racing_Wheel": Q=0.15, R=0.05

// RTS 카메라
"Strategy_Cam": Q=0.005, R=1.5
```

#### VR/AR 프리셋
```cpp
// 손 추적
"VR_Hands_Stable": MinCutoff=0.3, Beta=0.00005, DCutoff=1.0

// 헤드 추적
"VR_Head_Comfort": MinCutoff=0.6, Beta=0.0001, DCutoff=1.2

// 시선 추적
"AR_Gaze": MinCutoff=1.2, Beta=0.0003, DCutoff=1.5
```

#### 창작 애플리케이션
```cpp
// 디지털 아트
"Drawing_Smooth": MinCutoff=0.4, Beta=0.002, DCutoff=0.8

// 3D 모델링
"Modeling_Precise": Q=0.08, R=0.15

// 애니메이션
"Keyframe_Smooth": Q=0.002, R=3.0
```

### 프리셋 템플릿

일반적인 시나리오를 위한 시작점:

```blueprint
// 템플릿: 높은 반응성
Process Noise: 0.1-0.5
Measurement Noise: 0.01-0.1
MinCutoff: 1.0-5.0
Beta: 0.0001-0.001

// 템플릿: 최대 스무딩
Process Noise: 0.001-0.01
Measurement Noise: 1.0-10.0
MinCutoff: 0.01-0.2
Beta: 0.005-0.02

// 템플릿: 균형잡힌 성능
Process Noise: 0.01-0.1
Measurement Noise: 0.1-1.0
MinCutoff: 0.2-1.0
Beta: 0.001-0.01
```

---

## 📝 모범 사례 요약

### 해야 할 것 ✅
1. **철저히 테스트**: 항상 실제 데이터로 커스텀 프리셋 테스트
2. **프리셋 문서화**: 특정 값을 선택한 이유 기록
3. **보수적으로 시작**: 적당한 값으로 시작하여 조정
4. **의미있는 이름 사용**: "Preset1"이 아닌 "VR_Controllers"
5. **파라미터 검증**: 적용 전 범위 확인

### 하지 말아야 할 것 ❌
1. **극단적인 값 사용 금지**: 불안정성 야기 가능
2. **과도한 최적화 금지**: 작은 차이는 종종 중요하지 않음
3. **컨텍스트 무시 금지**: 같은 프리셋이 모든 곳에서 작동하지 않을 수 있음
4. **테스트 건너뛰기 금지**: 항상 실제 사용 사례로 확인
5. **성능 무시 금지**: CPU/메모리 영향 모니터링

---

## 🎯 빠른 참조

### 파라미터 빠른 가이드

| 더 원하는 것... | 칼만 | 원유로 |
|-----------------|------|--------|
| **반응성** | ↑ Q, ↓ R | ↑ MinCutoff, ↓ Beta |
| **부드러움** | ↓ Q, ↑ R | ↓ MinCutoff, ↑ Beta |
| **속도 적응** | Q/R 비율 조정 | ↑ Beta |
| **안정성** | Q/R 균형 | ↓ Beta, MinCutoff 튜닝 |

### 일반적인 프리셋 공식

```cpp
// 게임 (빠른 반응)
Q = 0.1, R = 0.01
MinCutoff = 2.0, Beta = 0.0005

// UI (부드러운 시각)  
Q = 0.005, R = 1.0
MinCutoff = 0.1, Beta = 0.01

// VR (편안함 우선)
MinCutoff = 0.4, Beta = 0.00001

// 모바일 (균형)
Q = 0.05, R = 0.2
MinCutoff = 0.8, Beta = 0.003
```

---

즐거운 프리셋 제작하세요! 🎨

여러 필터 조합은 [필터 체이닝](FilterChaining_KR.md)을 참조하세요 →