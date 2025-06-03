# 블루프린트 예제 (개선판)

*다른 언어로 읽기: [English](Examples.md), [한국어](Examples_KR.md)*

고급 필터 플러그인의 실용적인 예제와 사용 사례

## 📍 네비게이션

- [← 이전: API 레퍼런스](APIReference_KR.md)
- [→ 다음: 모범 사례](BestPractices_KR.md)

### 📖 전체 문서
- **시작하기**
  - [빠른 시작 가이드](QuickStart_KR.md)
  - [설치 가이드](Installation_KR.md)
- **사용자 가이드**
  - [사용자 매뉴얼](UserManual_KR.md)
  - **블루프린트 예제** (현재 페이지)
  - [모범 사례](BestPractices_KR.md)
- **기술 문서**
  - [API 레퍼런스](APIReference_KR.md)
  - [성능 가이드](Performance_KR.md)
  - [문제 해결](Troubleshooting_KR.md)

---

## 🗂️ 노드 카테고리 빠른 참조

이 문서의 예제에서 사용되는 노드들의 위치:

| 사용 빈도 | 노드 | 카테고리 |
|----------|------|---------|
| ⭐⭐⭐ | Kalman/OneEuro Filter Value/Vector | Advanced Filters > One-Click |
| ⭐⭐ | Create/Initialize/Update Filter | Advanced Filters > Core |
| ⭐⭐ | Create/Apply Custom Preset | Advanced Filters > Custom Preset |
| ⭐ | Create Filter Chain | Advanced Filters > Chain |
| ⭐ | Get Filter Statistics | Advanced Filters > Debug |

---

## 📋 목차

1. [기본 예제](#기본-예제)
2. [게임 메커니즘](#게임-메커니즘)
3. [UI 예제](#ui-예제)
4. [VR/AR 예제](#vrar-예제)
5. [고급 기법](#고급-기법)
6. [성능 예제](#성능-예제)

---

## 🎮 기본 예제

### 예제 1: 부드러운 카메라 따라가기

떨림 없이 플레이어를 부드럽게 따라가는 카메라 만들기.

**블루프린트 설정:**
```blueprint
Event Tick
├─ Get Player Location
├─ [Kalman Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 플레이어 위치
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraFollow"
└─ Set Camera Location (오프셋 포함)
```

**핵심 포인트:**
- 예측 스무딩을 위한 칼만 필터 사용
- Medium 프리셋으로 반응성과 부드러움 균형
- 카메라를 플레이어 뒤/위에 유지하기 위한 오프셋 추가

**변형:**
- 액션 게임용 Low 프리셋 (빠른 반응)
- 시네마틱 시퀀스용 High 프리셋
- 완전한 부드러움을 위한 회전 필터링 추가

---

### 예제 2: 마우스 시점 스무딩

더 나은 조준을 위한 떨리는 마우스 움직임 감소.

**블루프린트 설정:**
```blueprint
Event Tick
├─ Get Mouse Delta
├─ Break Vector2D (X, Y)
├─ [One Euro Filter Value] (X)  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: Mouse X
│  ├─ Delta Time: Event Delta ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseX"
├─ [One Euro Filter Value] (Y)  ← 같은 카테고리
│  ├─ Raw Value: Mouse Y
│  ├─ Delta Time: Event Delta ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseY"
└─ Add Controller Input (Yaw, Pitch)
```

**핵심 포인트:**
- 최소 지연을 위한 원유로 필터
- 반응성 유지를 위한 Low 프리셋
- X, Y 축을 위한 별도 필터
- ⚠️ **원유로는 Delta Time 필수!**

---

## 🎯 게임 메커니즘

### 예제 3: 체력바 애니메이션

전문적인 UI 느낌을 위한 부드러운 체력바 변화.

**블루프린트 설정:**
```blueprint
On Health Changed 이벤트
├─ [Kalman Filter Value]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 새 체력
│  ├─ Preset: High
│  └─ Filter ID: "HealthBar"
├─ Divide (최대 체력으로)
└─ Set Progress Bar Percent
```

**타임라인 대안:**
```blueprint
// 애니메이션에 대한 더 많은 제어
On Health Changed
├─ Get Current Display Health
├─ [Kalman Filter Value] → 목표 체력
├─ Create Timeline
│  ├─ Start: 현재 표시 체력
│  ├─ End: 목표 체력
│  └─ Duration: 0.5초
└─ Update Progress Bar
```

---

### 예제 4: AI 경로 스무딩

AI 움직임을 더 자연스럽고 덜 로봇적으로 만들기.

**블루프린트 설정:**
```blueprint
// AI 컨트롤러에서
Event Receive Move Completed
├─ Get Next Path Point
├─ [Kalman Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 경로 포인트
│  ├─ Preset: Medium
│  └─ Filter ID: "AI_" + 캐릭터 이름
└─ Move To Location (필터링됨)
```

**고급 버전 (3-노드 시스템 사용):**
```blueprint
// 카테고리: Advanced Filters > Core
Begin Play:
├─ [Create Filter] (Type: Kalman)
├─ [Initialize Filter] (Preset: Low)
└─ AIPathFilter로 저장

// 전체 경로 스무딩
Get Path Points Array
├─ For Each Loop
│  ├─ [Update Filter Vector]
│  │  ├─ Target: AIPathFilter
│  │  └─ Raw Value: 경로 포인트
│  └─ 스무딩된 경로에 추가
└─ 스무딩된 경로 따라가기
```

---

## 🖼️ UI 예제

### 예제 5: 애니메이션 메뉴 커서

부드럽고 지연 없는 메뉴 커서 만들기.

**블루프린트 설정:**
```blueprint
// UI 위젯에서
Event Tick
├─ Get Mouse Position
├─ [One Euro Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 마우스 위치
│  ├─ Delta Time: UI Delta Time ← 필수!
│  ├─ Preset: Medium
│  └─ Filter ID: "MenuCursor"
└─ Set Cursor Widget Position
```

**가속도가 있는 향상된 버전:**
```blueprint
// "떠다니는" 느낌 추가
Get Mouse Position
├─ [One Euro Filter Vector] (Low 프리셋)
├─ [Kalman Filter Vector] (High 프리셋)
├─ Blend (0.7 원유로, 0.3 칼만)
└─ 보간으로 위치 설정
```

---

### 예제 6: 데미지 숫자

부드럽게 떠오르는 데미지 숫자.

**블루프린트 설정:**
```blueprint
// 데미지 숫자 위젯에서
Event Construct
├─ Random Offset (-50, 50)
├─ [Kalman Filter Value]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 랜덤 X 오프셋
│  ├─ Preset: High
│  └─ Filter ID: "DamageFloat"
└─ Set Initial Position

Event Tick
├─ 현재 위치 + (0, 0, Delta * 속도)
├─ [Kalman Filter Vector]
│  ├─ Raw Value: 새 위치
│  ├─ Preset: Medium
│  └─ Filter ID: "DamagePos"
└─ Set Widget Position
```

---

## 🥽 VR/AR 예제

### 예제 7: VR 손 추적

안정적인 손 존재감을 위한 컨트롤러 떨림 감소.

**커스텀 프리셋 생성 (중요!):**
```blueprint
// 카테고리: Advanced Filters > Custom Preset
Begin Play:
[Create Custom Preset]
├─ Preset Name: "VR_Hands"
├─ Filter Type: OneEuro ← 선택 중요!
├─ Process Noise/Min Cutoff: 0.4  ← OneEuro에서는 Min Cutoff
├─ Measurement Noise/Beta: 0.00001  ← OneEuro에서는 Beta
└─ DCutoff: 1.0
    ↓
VRHandPreset으로 저장
```

**필터 적용:**
```blueprint
// VR 폰에서
Event Tick
├─ Get Controller Location (오른쪽)
├─ [One Euro Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 컨트롤러 위치
│  ├─ Delta Time: Delta Seconds ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "RightHand"
├─ Get Controller Rotation
├─ [One Euro Filter Vector] (벡터로 변환)
│  ├─ Raw Value: 벡터로 변환된 회전
│  ├─ Delta Time: Delta Seconds ← 필수!
│  ├─ Preset: Medium
│  └─ Filter ID: "RightHandRot"
└─ Set Hand Mesh Transform
```

⚠️ **VR 주의사항:**
- 원유로 필터가 VR에 더 적합 (낮은 지연)
- Delta Time 연결 필수
- 너무 높은 필터링은 멀미 유발 가능

---

### 예제 8: AR 객체 배치

표면에서 AR 객체 배치 안정화.

**블루프린트 설정:**
```blueprint
// AR 배치 매니저
On Surface Detected
├─ Get Surface Point
├─ [Kalman Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: Hit 위치
│  ├─ Preset: High
│  └─ Filter ID: "ARSurface"
├─ Get Surface Normal
├─ [Kalman Filter Vector]
│  ├─ Raw Value: Hit Normal
│  ├─ Preset: High
│  └─ Filter ID: "ARNormal"
└─ AR 객체 배치 (필터링된 트랜스폼)
```

---

## 🚀 고급 기법

### 예제 9: 필터 체이닝

정교한 효과를 위한 다중 필터 조합.

**체인 생성:**
```blueprint
// 카테고리: Advanced Filters > Chain
Begin Play:
[Create Filter Chain]
├─ Filter Types: [Kalman, OneEuro]
├─ Presets: [High, Low]
└─ FilterChain으로 저장
```

**체인 사용:**
```blueprint
Event Tick
├─ Get Target Location
├─ [Process Through Chain]
│  ├─ Filter Chain: FilterChain
│  ├─ Raw Value: 목표 위치 (Float만 지원)
│  └─ Delta Time: Delta Seconds
└─ 결과 사용
```

⚠️ **현재 제한사항:** 체인은 Float 값만 지원합니다. Vector는 각 축별로 처리하세요.

---

### 예제 10: 적응형 필터링

게임플레이 상태에 따른 필터 강도 변경.

**동적 프리셋 전환:**
```blueprint
Event Tick
├─ Branch (조준 중?)
│  ├─ True: 프리셋 = Low 설정
│  └─ False: 프리셋 = High 설정
├─ [One Euro Filter Value]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: 입력
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: 동적 프리셋
│  └─ Filter ID: "AdaptiveAim"
└─ 카메라에 적용
```

**고급: 3-노드로 런타임 파라미터 변경:**
```blueprint
// 카테고리: Advanced Filters > Core + Advanced
Get Velocity → Length
├─ Map Range (0-600 → 0.0-1.0)
├─ [Set Beta]  ← 카테고리: Advanced Filters > Advanced
│  ├─ Target: 필터 인스턴스
│  └─ Beta: 매핑된 속도
└─ 움직임 필터에 적용
```

---

### 예제 11: 디버그 시각화

필터 동작을 실시간으로 확인.

**통계 표시:**
```blueprint
// 카테고리: Advanced Filters > Debug
Event Tick (매 30프레임)
├─ [Get Filter Statistics]
│  └─ Target: 디버그할 필터
├─ Print String
│  └─ Duration: 0.5초
└─ Draw Debug 정보
```

---

## ⚡ 성능 예제

### 예제 12: LOD 기반 필터링

거리에 따른 필터링으로 최적화.

**블루프린트 설정:**
```blueprint
// 캐릭터 틱에서
Get Distance to Camera
├─ Select Preset
│  ├─ < 10m: High (부드러운 애니메이션)
│  ├─ < 50m: Medium
│  └─ > 50m: Low (또는 건너뛰기)
├─ [Kalman Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Preset: 선택됨
│  └─ Filter ID: "Character_" + Index
└─ 스켈레탈 메시에 적용
```

---

### 예제 13: 성능 프로파일링

필터 성능 측정하기.

**프로파일링 설정:**
```blueprint
// 카테고리: Advanced Filters > Performance
Begin Play:
[Start Filter Profiling]
└─ Profile ID: "MainCharacterFilter"

End Play:
[Stop Filter Profiling]
├─ Profile ID: "MainCharacterFilter"
└─ 결과 로그:
    ├─ Average Time MS
    ├─ Peak Time MS
    └─ Update Count
```

---

### 예제 14: 조건부 필터링

필요할 때만 필터링하여 성능 절약.

**블루프린트 설정:**
```blueprint
// 스마트 필터링
Event Tick
├─ Get Change Amount (현재 - 마지막)
├─ Branch (변화 > 임계값?)
│  ├─ True: 필터 업데이트
│  └─ False: 캐시된 값 사용
└─ 결과 적용
```

---

## 📝 완전한 예제 프로젝트

### 부드러운 FPS 컨트롤러

필터링된 입력을 가진 완전한 1인칭 컨트롤러.

**플레이어 컨트롤러 설정:**
```blueprint
// 입력 스무딩
Input Axis MoveForward
├─ [One Euro Filter Value]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Raw Value: Axis Value
│  ├─ Delta Time: World Delta ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "MoveForward"
└─ Add Movement Input

Input Axis Turn
├─ [One Euro Filter Value]
│  ├─ Raw Value: Axis Value
│  ├─ Delta Time: World Delta ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "MouseTurn"
└─ Add Controller Yaw
```

**카메라 설정:**
```blueprint
// 카메라 스무딩
Event Tick
├─ Get Socket Location "Head"
├─ [Kalman Filter Vector]  ← 카테고리: Advanced Filters > One-Click
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraPos"
├─ Get Control Rotation
├─ [One Euro Filter Vector] (Rotator를 Vector로)
│  ├─ Delta Time: World Delta ← 필수!
│  ├─ Preset: Low
│  └─ Filter ID: "CameraRot"
└─ Set Camera Transform
```

---

## 🚧 알려진 제한사항

1. **필터 체인은 Float만 지원** - Vector는 각 축별로 처리
2. **예측 기능 미구현** - Predict Next State는 아직 사용 불가
3. **원유로는 Delta Time 필수** - 없으면 이상하게 작동

---

## 🎯 예제 팁

1. **간단하게 시작** - 원클릭 매크로로 테스트 후 필요시 3-노드로
2. **시각화** - Get Filter Statistics로 동작 확인
3. **프로파일** - 성능이 중요하면 Start/Stop Profiling 사용
4. **실험** - 다른 프리셋과 필터 타입 시도
5. **카테고리 기억** - 노드를 못 찾겠으면 카테고리 확인

---

## 📚 추가 읽기

- [모범 사례](BestPractices_KR.md) - 최적화 팁
- [성능 가이드](Performance_KR.md) - 상세한 벤치마크
- [문제 해결](Troubleshooting_KR.md) - 일반적인 문제

---

즐거운 필터링 되세요! 🎉