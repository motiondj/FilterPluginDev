# 모범 사례

*다른 언어로 읽기: [English](BestPractices.md), [한국어](BestPractices_KR.md)*

고급 필터 플러그인의 최적 사용을 위한 가이드라인과 권장사항

## 📍 네비게이션

- [← 이전: 블루프린트 예제](Examples_KR.md)
- [→ 다음: 성능 가이드](Performance_KR.md)

### 📖 전체 문서
- **시작하기**
  - [빠른 시작 가이드](QuickStart_KR.md)
  - [설치 가이드](Installation_KR.md)
- **사용자 가이드**
  - [사용자 매뉴얼](UserManual_KR.md)
  - [블루프린트 예제](Examples_KR.md)
  - **모범 사례** (현재 페이지)
- **기술 문서**
  - [API 레퍼런스](APIReference_KR.md)
  - [성능 가이드](Performance_KR.md)
  - [문제 해결](Troubleshooting_KR.md)

---

## 📋 목차

1. [필터 선택 가이드라인](#필터-선택-가이드라인)
2. [블루프린트 모범 사례](#블루프린트-모범-사례)
3. [성능 최적화](#성능-최적화)
4. [일반적인 패턴](#일반적인-패턴)
5. [피해야 할 안티패턴](#피해야-할-안티패턴)
6. [고급 기법](#고급-기법)

---

## 🎯 필터 선택 가이드라인

### 올바른 필터 선택하기

사용 사례에 최적인 필터를 선택하는 의사결정 트리:

```
여기서 시작
    ↓
지연 시간이 중요한가? (< 3 프레임)
├─ 예 → 원유로 필터 사용
│       ├─ VR/AR 컨트롤러
│       ├─ 마우스 입력
│       └─ 터치 인터페이스
└─ 아니오 → 예측이 필요한가?
            ├─ 예 → 칼만 필터 사용
            │       ├─ AI 움직임
            │       ├─ 카메라 추적
            │       └─ 물리 객체
            └─ 아니오 → 두 필터 모두 가능
                        └─ 선호도에 따라 선택
```

### 필터 특성 요약

| 사용 사례 | 권장 필터 | 프리셋 | 이유 |
|-----------|----------|--------|------|
| VR 손 추적 | 원유로 | Low | 최소 지연 시간 중요 |
| 카메라 따라가기 | 칼만 | Medium | 부드러운 예측 필요 |
| UI 요소 | 칼만 | High | 시각적 부드러움 우선 |
| 마우스 조준 | 원유로 | Low | 즉각적인 반응 필요 |
| 체력 바 | 칼만 | High | 부드러운 전환 |
| 차량 움직임 | 칼만 | Medium | 예측 가능한 모션 |
| 터치 제스처 | 원유로 | Medium | 부드러움과 반응성 균형 |

---

## 📘 블루프린트 모범 사례

### 1. 필터 ID 관리

**✅ 올바른 방법: 일관된 ID 사용**
```blueprint
// 좋음 - 같은 ID가 필터 상태 유지
Filter ID: "PlayerHealth"
Filter ID: "PlayerHealth"  // 기존 필터 재사용
```

**❌ 잘못된 방법: 동적 ID 생성**
```blueprint
// 나쁨 - 매 프레임 새 필터 생성
Filter ID: "Health_" + FrameNumber
Filter ID: "Health_" + RandomInt
```

### 2. 필터 수명 주기

**✅ 올바른 방법: 한 번만 초기화**
```blueprint
// 좋음 - BeginPlay에서 초기화
Event BeginPlay
├─ Create Filter
├─ Initialize (Medium)
└─ 변수에 저장

Event Tick
└─ 저장된 필터 사용
```

**❌ 잘못된 방법: 매 프레임 생성**
```blueprint
// 나쁨 - 낭비적이고 상태 리셋됨
Event Tick
├─ Create Filter  // 잘못됨!
├─ Initialize     // 잘못됨!
└─ Update
```

### 3. Delta Time 사용

**✅ 올바른 방법: 원유로에는 항상 Delta Time 연결**
```blueprint
// 좋음 - 프레임 레이트 독립적
One Euro Filter Value
├─ Raw Value: 입력
├─ Delta Time: Event Tick Delta ← 필수!
└─ Filter ID: "MouseX"
```

**❌ 잘못된 방법: 고정값 사용**
```blueprint
// 나쁨 - 다른 프레임 레이트에서 문제 발생
One Euro Filter Value
├─ Raw Value: 입력
├─ Delta Time: 0.016  // 잘못됨!
└─ Filter ID: "MouseX"
```

### 4. 프리셋 선택

**✅ 올바른 방법: 사용 사례에 맞는 프리셋**
```blueprint
// 좋은 예시
UI 애니메이션: High 프리셋 (최대 부드러움)
플레이어 입력: Low 프리셋 (빠른 반응)
일반 사용: Medium 프리셋 (균형)
```

**❌ 잘못된 방법: 모든 곳에 하나의 프리셋**
```blueprint
// 나쁨 - 최적이 아닌 결과
모든 필터: High 프리셋  // 입력에 너무 많은 지연
모든 필터: Low 프리셋   // UI에 너무 떨림
```

---

## ⚡ 성능 최적화

### 1. 조건부 업데이트

값이 크게 변경될 때만 필터 업데이트:

```blueprint
// 효율적인 필터링
Get New Value
├─ 마지막 값 빼기
├─ 절대값
├─ Branch (> 임계값)
│   ├─ True: 필터 업데이트
│   └─ False: 캐시된 값 사용
└─ 결과 저장
```

### 2. LOD 기반 필터링

거리에 따라 필터 품질 조정:

```blueprint
// 성능 스케일링
Get Distance to Camera
├─ < 10m: High 프리셋 (최고 품질)
├─ < 50m: Medium 프리셋
├─ < 100m: Low 프리셋
└─ > 100m: 필터링 건너뛰기
```

### 3. 배치 처리

여러 값을 효율적으로 처리:

```blueprint
// 좋음 - 배열에 단일 필터
For Each (위치 배열)
├─ 필터 업데이트 (같은 ID + Index)
└─ 결과 저장

// 더 좋음 - 커스텀 배치 노드
Update Filter Batch
├─ Input: 배열
└─ Output: 필터링된 배열
```

### 4. 프레임 레이트 고려사항

성능에 맞춰 적응:

```blueprint
// 동적 품질 조정
Get Frame Rate
├─ > 60 FPS: High 프리셋 사용
├─ > 30 FPS: Medium 프리셋 사용
└─ < 30 FPS: Low 프리셋 사용
```

---

## 🔄 일반적인 패턴

### 패턴 1: 부드러운 카메라 시스템

```blueprint
// 전문적인 카메라 따라가기
Player Controller
├─ 원하는 카메라 위치 가져오기
├─ [Kalman Filter Vector]
│   ├─ Preset: Medium
│   └─ ID: "CameraPosition"
├─ 원하는 카메라 회전 가져오기
├─ [One Euro Filter] (벡터로)
│   ├─ Preset: Low
│   ├─ Delta Time: 연결됨
│   └─ ID: "CameraRotation"
└─ 카메라 트랜스폼 설정
```

### 패턴 2: 입력 스무딩

```blueprint
// 반응적이지만 부드러운 입력
Input Component
├─ 원본 입력 축 가져오기
├─ [One Euro Filter Value]
│   ├─ Preset: Low
│   ├─ Delta Time: 연결됨
│   └─ ID: "Input_" + AxisName
├─ 데드존 적용
└─ 움직임 입력 추가
```

### 패턴 3: UI 애니메이션

```blueprint
// 부드러운 UI 전환
Widget Blueprint
├─ On Value Changed
├─ [Kalman Filter Value]
│   ├─ Preset: High
│   └─ ID: WidgetName + "_Anim"
├─ 커브 (선택사항)
└─ 위젯 속성 설정
```

### 패턴 4: 네트워크 움직임

```blueprint
// 부드러운 네트워크 위치
On Rep Position
├─ [Kalman Filter Vector]
│   ├─ Preset: Medium
│   └─ ID: "NetPos_" + PlayerID
├─ 위치로 보간
└─ 액터 위치 설정
```

---

## ❌ 피해야 할 안티패턴

### 안티패턴 1: 필터 체이닝 남용

**❌ 나쁨: 너무 많은 필터**
```blueprint
// 과도함 - 지연 시간 추가
값 → 칼만 → 원유로 → 칼만 → 결과
```

**✅ 좋음: 목적이 있는 체이닝**
```blueprint
// 정당함 - 각각 목적이 있음
값 → 원유로 (떨림 제거) → 칼만 (스무딩) → 결과
```

### 안티패턴 2: 잘못된 프리셋 매칭

**❌ 나쁨: 잘못된 컨텍스트**
```blueprint
// 마우스 입력에 High 프리셋 = 느림
마우스 입력 → 칼만 (High) → 카메라 회전
```

**✅ 좋음: 컨텍스트에 적합**
```blueprint
// 입력에 Low 프리셋 = 반응적
마우스 입력 → 원유로 (Low) → 카메라 회전
```

### 안티패턴 3: 메모리 누수

**❌ 나쁨: 필터를 절대 정리하지 않음**
```blueprint
// 영원히 축적됨
랜덤 ID로 필터 생성
Clear Filters 호출 안 함
```

**✅ 좋음: 적절한 정리**
```blueprint
// 레벨 변경 시 정리
Event End Play
└─ Clear All Filters
```

### 안티패턴 4: 프레임 독립성 무시

**❌ 나쁨: 프레임 의존적 로직**
```blueprint
// 다른 FPS에서 문제 발생
If (FilteredValue - LastValue > 0.1)
    무언가 실행  // 임계값이 FPS에 의존
```

**✅ 좋음: 프레임 독립적**
```blueprint
// 모든 FPS에서 작동
If (FilteredValue - LastValue > 0.1 * DeltaTime)
    무언가 실행  // 임계값이 시간에 따라 조정
```

---

## 🚀 고급 기법

### 기법 1: 적응형 필터링

컨텍스트에 따라 필터 강도를 동적으로 조정:

```blueprint
// 컨텍스트 인식 필터링
Get Player State
├─ 전투 중: Low 프리셋 (반응적)
├─ 메뉴에서: High 프리셋 (부드러움)
└─ 탐험 중: Medium 프리셋 (균형)

// 속도 기반 적응
Get Velocity Magnitude
├─ Map to Range (0-1000 → 0.0-1.0)
├─ Create Custom Preset
│   └─ Beta: 매핑된 값
└─ 필터에 적용
```

### 기법 2: 예측 필터링

미리보기를 위한 칼만의 예측 사용:

```blueprint
// 조준 예측
Get Target Velocity
├─ 칼만 필터 (참조 저장)
├─ "Predict Next State" 호출
│   └─ Steps: 5-10 프레임
├─ 선도 위치 계산
└─ 예측된 위치에 조준
```

### 기법 3: 필터 블렌딩

최적의 결과를 위한 다중 필터 결합:

```blueprint
// 하이브리드 접근
Get Input Value
├─ 경로 1: 원유로 (Low) → 70% 가중치
├─ 경로 2: 칼만 (Medium) → 30% 가중치
├─ 가중 평균
└─ 최종 결과
```

### 기법 4: 성능 프로파일링

필터 성능 모니터링 및 최적화:

```blueprint
// 성능 모니터링
Begin Play
└─ 필터 프로파일링 시작 (디버그 빌드)

Event End Play
├─ 필터 프로파일링 중지
├─ 평균 시간 로그
├─ 최대 시간 로그
└─ 병목 현상 식별
```

---

## 📊 의사결정 매트릭스

### 빠른 참조 가이드

| 시나리오 | 필터 | 프리셋 | Delta Time | 참고 |
|----------|------|--------|------------|------|
| FPS 조준 | 원유로 | Low | 필수 | 최소 지연 |
| 3인칭 카메라 | 칼만 | Medium | 불필요 | 부드러운 따라가기 |
| UI 애니메이션 | 칼만 | High | 불필요 | 시각적 우선 |
| VR 컨트롤러 | 원유로 | Low | 필수 | 멀미 방지 |
| 차량 물리 | 칼만 | Medium | 불필요 | 예측 가능한 모션 |
| 터치 제스처 | 원유로 | Medium | 필수 | 자연스러운 느낌 |
| 체력/마나 바 | 칼만 | High | 불필요 | 부드러운 변화 |
| 파티클 효과 | 둘 다 | Low | 상황별 | 성능 우선 |

---

## ✅ 체크리스트

출시 전 확인사항:

- [ ] 모든 필터가 일관된 ID 사용
- [ ] 원유로 필터에 Delta Time 연결됨
- [ ] 각 사용 사례에 적절한 프리셋
- [ ] Tick 이벤트에서 필터 생성 없음
- [ ] 레벨 전환 시 메모리 정리
- [ ] 목표 프레임 레이트에서 성능 테스트됨
- [ ] 많은 필터에 대한 LOD 시스템 구현됨
- [ ] 엣지 케이스에 대한 오류 처리

---

## 📚 추가 읽기

- [성능 가이드](Performance_KR.md) - 상세한 최적화
- [문제 해결](Troubleshooting_KR.md) - 일반적인 문제
- [API 레퍼런스](APIReference_KR.md) - 기술적 세부사항

---

기억하세요: 최고의 필터는 특정 문제를 효율적으로 해결하는 필터입니다! 🎯