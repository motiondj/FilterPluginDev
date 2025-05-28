# 블루프린트 예제

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
├─ [Kalman Filter Vector]
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
├─ [One Euro Filter Value] (X)
│  ├─ Raw Value: Mouse X
│  ├─ Delta Time: Event Delta
│  ├─ Preset: Low
│  └─ Filter ID: "MouseX"
├─ [One Euro Filter Value] (Y)
│  ├─ Raw Value: Mouse Y
│  ├─ Delta Time: Event Delta
│  ├─ Preset: Low
│  └─ Filter ID: "MouseY"
└─ Add Controller Input (Yaw, Pitch)
```

**핵심 포인트:**
- 최소 지연을 위한 원유로 필터
- 반응성 유지를 위한 Low 프리셋
- X, Y 축을 위한 별도 필터

---

## 🎯 게임 메커니즘

### 예제 3: 체력바 애니메이션

전문적인 UI 느낌을 위한 부드러운 체력바 변화.

**블루프린트 설정:**
```blueprint
On Health Changed 이벤트
├─ [Kalman Filter Value]
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
├─ [Kalman Filter Vector]
│  ├─ Raw Value: 경로 포인트
│  ├─ Preset: Medium
│  └─ Filter ID: "AI_" + 캐릭터 이름
└─ Move To Location (필터링됨)
```

**고급 버전:**
```blueprint
// 전체 경로 스무딩
Get Path Points Array
├─ For Each Loop
│  ├─ [Kalman Filter Vector]
│  │  ├─ Raw Value: 경로 포인트
│  │  ├─ Preset: Low
│  │  └─ Filter ID: "PathSmooth"
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
├─ [One Euro Filter Vector]
│  ├─ Raw Value: 마우스 위치
│  ├─ Delta Time: UI Delta Time
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
├─ [Kalman Filter Value]
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

**블루프린트 설정:**
```blueprint
// VR 폰에서
Event Tick
├─ Get Controller Location (오른쪽)
├─ [One Euro Filter Vector]
│  ├─ Raw Value: 컨트롤러 위치
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: Low
│  └─ Filter ID: "RightHand"
├─ Get Controller Rotation
├─ [One Euro Filter Vector] (벡터로 변환)
│  ├─ Raw Value: 벡터로 변환된 회전
│  ├─ Delta Time: Delta Seconds
│  ├─ Preset: Medium
│  └─ Filter ID: "RightHandRot"
└─ Set Hand Mesh Transform
```

**VR용 커스텀 프리셋:**
```blueprint
Begin Play
├─ [Create Custom Preset]
│  ├─ Name: "VR_Controllers"
│  ├─ Process Noise: 0.0
│  ├─ Measurement Noise: 0.0
│  ├─ Min Cutoff: 0.3
│  ├─ Beta: 0.00001
│  └─ DCutoff: 1.0
└─ 양손에 적용
```

---

### 예제 8: AR 객체 배치

표면에서 AR 객체 배치 안정화.

**블루프린트 설정:**
```blueprint
// AR 배치 매니저
On Surface Detected
├─ Get Surface Point
├─ [Kalman Filter Vector]
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

**블루프린트 설정:**
```blueprint
// 초부드러운 카메라를 위한 이중 필터링
Event Tick
├─ Get Target Location
├─ [One Euro Filter Vector] (Low 프리셋)
│  └─ Filter ID: "CameraStage1"
├─ [Kalman Filter Vector] (Medium 프리셋)
│  └─ Filter ID: "CameraStage2"
└─ Set Camera Location
```

**필터 체인 노드:**
```blueprint
// 체인 시스템 사용
Begin Play
├─ [Create Filter Chain]
│  ├─ Types: [OneEuro, Kalman]
│  └─ Presets: [Low, High]
└─ FilterChain으로 저장

Event Tick
├─ [Process Through Chain]
│  ├─ Chain: FilterChain
│  ├─ Value: 목표 위치
│  └─ Delta Time: Delta Seconds
└─ 결과 사용
```

---

### 예제 10: 적응형 필터링

게임플레이 상태에 따른 필터 강도 변경.

**블루프린트 설정:**
```blueprint
// 동적 프리셋 전환
Event Tick
├─ Branch (조준 중?)
│  ├─ True: 프리셋 = Low 설정
│  └─ False: 프리셋 = High 설정
├─ [One Euro Filter Value]
│  ├─ Raw Value: 입력
│  ├─ Preset: 동적 프리셋
│  └─ Filter ID: "AdaptiveAim"
└─ 카메라에 적용
```

**속도 기반 적응:**
```blueprint
// 빠른 움직임 = 적은 필터링
Get Velocity → Length
├─ Map Range (0-600 → 0-1)
├─ [Create Custom Preset]
│  └─ Beta: 매핑된 속도
└─ 움직임 필터에 적용
```

---

### 예제 11: 예측 쇼케이스

미리보기를 위한 칼만 필터의 예측 사용.

**블루프린트 설정:**
```blueprint
// 예측 타겟팅
Event Tick
├─ Get Target Velocity
├─ Get Target Position
├─ [Kalman Filter Vector] → 현재 필터링됨
├─ [Get Predicted Value] (커스텀 노드)
│  ├─ Filter: 칼만 인스턴스
│  └─ Steps Ahead: 10
├─ Draw Debug Sphere (현재 - 파란색)
└─ Draw Debug Sphere (예측 - 빨간색)
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
├─ [Kalman Filter Vector]
│  ├─ Preset: 선택됨
│  └─ Filter ID: "Character_" + Index
└─ 스켈레탈 메시에 적용
```

---

### 예제 13: 배치 처리

여러 값을 효율적으로 필터링.

**블루프린트 설정:**
```blueprint
// 위치 배열 처리
Get All Particle Positions
├─ For Each Loop
│  ├─ [Kalman Filter Vector]
│  │  └─ Filter ID: "Particle_" + Index
│  └─ 필터링된 배열에 추가
└─ 모든 파티클 업데이트
```

**최적화된 버전:**
```blueprint
// 보이는 파티클만 처리
Get Visible Particles
├─ 거리별 필터
├─ 배치 업데이트 (커스텀 C++)
└─ 결과 적용
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
├─ [One Euro Filter Value]
│  ├─ Preset: Low
│  └─ Filter ID: "MoveForward"
└─ Add Movement Input

Input Axis Turn
├─ [One Euro Filter Value]
│  ├─ Preset: Low
│  ├─ Delta Time: Delta
│  └─ Filter ID: "MouseTurn"
└─ Add Controller Yaw
```

**카메라 설정:**
```blueprint
// 카메라 스무딩
Event Tick
├─ Get Socket Location "Head"
├─ [Kalman Filter Vector]
│  ├─ Preset: Medium
│  └─ Filter ID: "CameraPos"
├─ Get Control Rotation
├─ [One Euro Filter] (Rotator를 Vector로)
│  ├─ Preset: Low
│  └─ Filter ID: "CameraRot"
└─ Set Camera Transform
```

**무기 흔들림:**
```blueprint
// 무기 지연
Event Tick
├─ Get Look Velocity
├─ [Kalman Filter Vector]
│  ├─ Preset: High
│  └─ Filter ID: "WeaponSway"
├─ 흔들림 오프셋으로 매핑
└─ 무기 위치에 추가
```

---

## 🎯 예제 팁

1. **간단하게 시작** - 체이닝 전에 하나의 필터로 테스트
2. **시각화** - 디버그 드로우를 사용하여 필터 효과 확인
3. **프로파일** - 프로파일링 노드로 성능 모니터링
4. **실험** - 사용 사례에 맞는 다른 프리셋 시도
5. **프리셋 저장** - 재사용을 위한 커스텀 프리셋 생성

---

## 📚 추가 읽기

- [모범 사례](BestPractices_KR.md) - 최적화 팁
- [성능 가이드](Performance_KR.md) - 상세한 벤치마크
- [문제 해결](Troubleshooting_KR.md) - 일반적인 문제

---

즐거운 필터링 되세요! 🎉