# 고급 필터 플러그인 - 개별 테스트 상세 구현 가이드

## 🎯 개요
이 가이드는 종합 테스트 블루프린트의 Step 4 (개별 테스트 구현)를 초보자도 따라할 수 있도록 상세히 설명합니다.

---

## 🔧 테스트 1: 필터 생성 테스트

### 목적
필터가 정상적으로 생성되는지 확인합니다.

### 상세 블루프린트 구현

```
Custom Event: Test Filter Creation
    │
    ├─[Create Filter]
    │  └─ Filter Type: Kalman (드롭다운에서 선택)
    │      ↓
    │  (출력) Return Value → [Set TestKalmanFilter] (변수에 저장)
    │
    ├─[IsValid]
    │  └─ Object: Get TestKalmanFilter
    │      ↓
    │  (출력) Is Valid → [Branch]
    │                      ├─ True → [Log Test Result]
    │                      │         ├─ Test Name: "필터 생성"
    │                      │         ├─ Test Passed: True ✓
    │                      │         └─ Details: "칼만 필터 생성 성공"
    │                      │
    │                      └─ False → [Log Test Result]
    │                                 ├─ Test Name: "필터 생성"
    │                                 ├─ Test Passed: False ✗
    │                                 └─ Details: "필터 생성 실패"
```

### 노드별 설명
- **Create Filter**: Advanced Filters 카테고리에서 찾을 수 있음
- **IsValid**: Object가 null이 아닌지 확인하는 기본 노드
- **Branch**: If문과 같은 역할 (True/False 분기)
- **Log Test Result**: 우리가 만든 커스텀 함수

---

## 🔧 테스트 2: 필터 초기화 테스트

### 목적
생성된 필터가 정상적으로 초기화되는지 확인합니다.

### 상세 블루프린트 구현

```
Custom Event: Test Filter Initialization
    │
    ├─[Get TestKalmanFilter] (변수 가져오기)
    │      ↓
    ├─[Initialize Filter]
    │  ├─ Target: TestKalmanFilter (연결)
    │  └─ Preset: Medium (드롭다운에서 선택)
    │      ↓
    │  (출력) Success → [Set InitSuccess] (임시 변수 저장)
    │
    ├─[Is Filter Initialized]
    │  └─ Target: Get TestKalmanFilter
    │      ↓
    │  (출력) Is Initialized → [AND Boolean]
    │                            └─ B: Get InitSuccess
    │                                ↓
    │                            [Branch]
    │                            ├─ True → [Log Test Result]
    │                            │         ├─ Test Name: "필터 초기화"
    │                            │         ├─ Test Passed: True ✓
    │                            │         └─ Details: "Medium 프리셋 초기화 성공"
    │                            │
    │                            └─ False → [Log Test Result]
    │                                      └─ Details: "초기화 실패"
```

### 주요 포인트
- **Initialize Filter**의 Success 출력과 **Is Filter Initialized** 두 개를 모두 확인
- **AND Boolean**으로 두 조건이 모두 True인지 확인

---

## 🔧 테스트 3: Float 필터링 테스트

### 목적
Float 값이 정상적으로 필터링되는지 확인합니다.

### 상세 블루프린트 구현

```
Custom Event: Test Float Filtering
    │
    ├─[Set TestPassed] = True (기본값 설정)
    │
    ├─[For Loop]
    │  ├─ First Index: 0
    │  └─ Last Index: 9 (10회 반복)
    │      ↓
    │  Loop Body 실행핀 →
    │      │
    │      ├─[Random Float in Range]
    │      │  ├─ Min: -100.0
    │      │  └─ Max: 100.0
    │      │      ↓
    │      │  (출력) Return Value → [Set RawValue] (임시 저장)
    │      │
    │      ├─[Update Filter Float]
    │      │  ├─ Target: Get TestKalmanFilter
    │      │  └─ Raw Value: Get RawValue
    │      │      ↓
    │      │  (출력) Filtered Value → [Set FilteredValue]
    │      │
    │      ├─[Abs (Float)]
    │      │  └─ Value: (RawValue - FilteredValue)
    │      │      ↓
    │      │  (출력) → [Less Than] (<)
    │      │           └─ B: 200.0 (합리적인 범위)
    │      │               ↓
    │      │           [Branch]
    │      │           ├─ True → (계속 진행)
    │      │           └─ False → [Set TestPassed] = False
    │      │
    │      └─[Print String] (디버그용)
    │         └─ String: "Raw: [RawValue], Filtered: [FilteredValue]"
    │
    └─ Completed 실행핀 →
        │
        └─[Log Test Result]
           ├─ Test Name: "Float 필터링"
           ├─ Test Passed: Get TestPassed
           └─ Details: "10회 필터링 테스트 완료"
```

### 핵심 체크 포인트
- 필터링된 값이 원본과 너무 다르지 않은지 확인 (200 이내)
- 10회 반복하여 안정성 확인
- 한 번이라도 실패하면 전체 테스트 실패

---

## 🔧 테스트 4: Vector 필터링 테스트

### 목적
3D Vector 값이 정상적으로 필터링되는지 확인합니다.

### 상세 블루프린트 구현

```
Custom Event: Test Vector Filtering
    │
    ├─[Make Vector]
    │  ├─ X: [Random Float in Range] (-50, 50)
    │  ├─ Y: [Random Float in Range] (-50, 50)
    │  └─ Z: [Random Float in Range] (-50, 50)
    │      ↓
    │  (출력) Return Value → [Set TestVector]
    │
    ├─[Update Filter Vector]
    │  ├─ Target: Get TestKalmanFilter
    │  └─ Raw Value: Get TestVector
    │      ↓
    │  (출력) Filtered Value → [Set FilteredVector]
    │
    ├─[Vector Length]
    │  └─ Vector: Get FilteredVector
    │      ↓
    │  (출력) Return Value → [Greater Than] (>)
    │                         └─ B: 0.0
    │                             ↓
    │                         [Branch]
    │                         ├─ True → (벡터가 유효함)
    │                         └─ False → (오류)
    │
    ├─[Break Vector] (FilteredVector)
    │  ├─ X → [In Range (Float)]
    │  │       ├─ Min: -100
    │  │       └─ Max: 100
    │  ├─ Y → [In Range (Float)]
    │  └─ Z → [In Range (Float)]
    │      ↓
    │  모든 출력 → [AND Boolean] (3개 입력)
    │                 ↓
    │             [Log Test Result]
    │             ├─ Test Name: "Vector 필터링"
    │             ├─ Test Passed: AND 결과
    │             └─ Details: "X,Y,Z 모두 범위 내"
```

### 검증 내용
- 벡터 길이가 0이 아닌지 확인
- 각 축(X,Y,Z)의 값이 합리적인 범위 내에 있는지 확인

---

## 🔧 테스트 5: 원클릭 매크로 테스트

### 목적
원클릭 매크로가 정상 작동하는지 확인합니다.

### 상세 블루프린트 구현

```
Custom Event: Test One Click Macro
    │
    ├─[For Loop] (3회 반복)
    │  └─ Loop Body →
    │      │
    │      ├─[Random Float in Range] (-10, 10)
    │      │      ↓
    │      │  (출력) → [Kalman Filter Value]
    │      │           ├─ Raw Value: (연결)
    │      │           ├─ Preset: Medium
    │      │           └─ Filter ID: "TestMacro"
    │      │               ↓
    │      │           (출력) Return Value → [Set Result1]
    │      │
    │      ├─[Delay] (0.1초)
    │      │
    │      └─[Kalman Filter Value] (같은 ID로 다시 호출)
    │         ├─ Raw Value: 같은 랜덤 값
    │         ├─ Preset: Medium
    │         └─ Filter ID: "TestMacro" (동일!)
    │             ↓
    │         (출력) Return Value → [Set Result2]
    │
    └─ Completed →
        │
        ├─[Nearly Equal (Float)]
        │  ├─ A: Get Result1
        │  ├─ B: Get Result2
        │  └─ Error Tolerance: 0.001
        │      ↓
        │  [Branch]
        │  ├─ True → (같은 Filter ID = 같은 필터 사용)
        │  └─ False → (문제 있음)
        │
        └─[Log Test Result]
           ├─ Test Name: "원클릭 매크로"
           └─ Details: "Filter ID 일관성 확인"
```

### 테스트 포인트
- 같은 Filter ID를 사용하면 같은 필터 인스턴스를 재사용하는지 확인
- 연속 호출 시 상태가 유지되는지 검증

---

## 🔧 테스트 6: 커스텀 프리셋 테스트

### 상세 블루프린트 구현

```
Custom Event: Test Custom Preset
    │
    ├─[Create Custom Preset]
    │  ├─ Preset Name: "TestCustom"
    │  ├─ Process Noise: 0.05
    │  ├─ Measurement Noise: 0.1
    │  ├─ Min Cutoff: 0.5
    │  ├─ Beta: 0.001
    │  └─ DCutoff: 1.0
    │      ↓
    │  (출력) Success → [Branch]
    │                    └─ False → 오류 처리
    │
    ├─[Create Filter] (OneEuro)
    │      ↓
    │  (출력) → [Set TestOneEuroFilter]
    │
    ├─[Apply Custom Preset]
    │  ├─ Target: Get TestOneEuroFilter
    │  └─ Preset Name: "TestCustom"
    │      ↓
    │  (출력) Success → [Branch]
    │
    └─[Log Test Result]
       ├─ Test Name: "커스텀 프리셋"
       └─ Test Passed: 모든 Success 체크
```

---

## 💡 디버깅 팁

### 1. Print String 활용
```
각 단계마다 Print String 추가:
- "테스트 1 시작"
- "필터 생성됨: [IsValid 결과]"
- "초기화 결과: [Success]"
```

### 2. Breakpoint 사용
- 중요한 노드에 브레이크포인트 설정 (F9)
- 단계별 실행으로 값 확인

### 3. 변수 Watch
- Details 패널에서 변수 값 실시간 모니터링
- TestPassed, FilteredValue 등 주요 변수 확인

### 4. 실행 흐름 시각화
- 실행 핀(흰색 선)이 올바르게 연결되었는지 확인
- Sequence 노드로 순차 실행 보장

---

## 🎯 초보자를 위한 단계별 구현 순서

1. **먼저 Log Test Result 함수 만들기**
   - Functions → + → "LogTestResult"
   - 입력 추가: TestName(String), TestPassed(Bool), Details(String)

2. **가장 간단한 테스트부터 구현**
   - 테스트 1 (필터 생성) 먼저 완성
   - 작동 확인 후 다음 테스트로

3. **하나씩 테스트하며 진행**
   - 각 테스트 완성 후 Play로 확인
   - 오류 발생 시 즉시 수정

4. **복잡한 테스트는 나중에**
   - 기본 테스트가 모두 작동한 후
   - 성능 테스트, 체인 테스트 구현

이렇게 단계별로 구현하면 어렵지 않게 완성할 수 있습니다!