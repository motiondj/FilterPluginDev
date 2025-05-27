# 빠른 시작 가이드

*다른 언어로 읽기: [English](QuickStart.md), [한국어](QuickStart_KR.md)*

고급 필터 플러그인을 단 5분 만에 시작해보세요!

## 📋 사전 준비사항

- 언리얼 엔진 5.5 이상
- 블루프린트 기본 지식
- 고급 필터 플러그인 설치 및 활성화 완료

## 🚀 3단계로 만드는 첫 번째 필터

### 1단계: 테스트 액터 생성

1. **새 블루프린트 액터 만들기**
   - Content Browser에서 우클릭
   - `Blueprint Class` → `Actor` 선택
   - 이름: `BP_MyFirstFilter`

2. **큐브 메시 추가**
   - Components 패널에서 `Add Component` 클릭
   - `Static Mesh` 선택
   - Static Mesh를 `Cube`로 설정
   - Scale을 (0.5, 0.5, 0.5)로 조정

### 2단계: 필터링 로직 추가

이벤트 그래프를 열고 다음과 같이 구성하세요:

![빠른 시작 다이어그램](images/quickstart_diagram.png)

```blueprint
Event Tick
    ↓
[Get Game Time in Seconds]
    ↓
[Sin] (100을 곱해서 움직임 범위 설정)
    ↓
[Random Float in Range] (-10, 10) → [Add] (노이즈 추가)
    ↓
[Kalman Filter Value]
- Preset: Medium
- Filter ID: "Position"
    ↓
[Make Vector] (X: 필터링된 값, Y: 0, Z: 0)
    ↓
[Set Actor Location]
```

### 3단계: 마법을 확인하세요!

1. 레벨에 **액터 배치**
2. **Play 버튼** 클릭
3. 노이즈에도 불구하고 **부드럽게 움직이는** 큐브를 확인!

## 🎯 무슨 일이 일어났나요?

방금 만든 큐브는:
- ✅ 사인파 경로를 따라 움직입니다
- ✅ 랜덤 노이즈가 추가됩니다 (센서 떨림 시뮬레이션)
- ✅ 칼만 필터로 움직임을 부드럽게 만듭니다
- ✅ 깔끔하고 전문적인 모션이 완성됩니다

## 🔥 이것도 해보세요

### 1. 필터링된 것과 안 된 것 비교

필터링하지 않은 두 번째 큐브를 추가해서 차이를 확인:

```blueprint
노이즈 신호에서 두 개의 경로 생성:
경로 1: 노이즈 신호 → 칼만 필터 → 큐브 1 (부드러움)
경로 2: 노이즈 신호 → 큐브 2 (떨림)
```

### 2. 다른 프리셋 시도

Preset 파라미터 변경:
- **Low**: 적은 필터링, 빠른 반응
- **Medium**: 균형잡힌 설정 (기본값)
- **High**: 최대 스무딩

### 3. 원유로 필터로 전환

`Kalman Filter Value`를 `One Euro Filter Value`로 교체:
- Event Tick에서 `Delta Time` 입력 추가
- 더 빠른 반응을 확인!

## 💡 원클릭 vs 3-노드 시스템

### 원클릭 (방금 사용한 방식)
```blueprint
[센서 값] → [Kalman Filter Value] → [결과]
```
✅ 장점: 매우 간단, 하나의 노드로 모든 것 처리
❌ 단점: Filter ID가 바뀌면 매번 새 필터 생성

### 3-노드 시스템 (더 많은 제어)
```blueprint
Begin Play:
[Create Filter] → [Initialize] → [변수로 저장]

Event Tick:
[변수] → [Update Estimate] → [결과]
```
✅ 장점: 완전한 제어, 런타임에 파라미터 변경 가능
❌ 단점: 3개의 노드와 변수 관리 필요

## 🎮 실제 사용 예제

### 부드러운 마우스 시점
```blueprint
[Mouse X] → [One Euro Filter Value] → [Add Controller Yaw Input]
```

### 안정적인 체력바
```blueprint
[현재 체력] → [Kalman Filter Value] → [체력바 퍼센트 설정]
```

### VR 손 추적
```blueprint
[컨트롤러 위치] → [One Euro Filter Vector] → [손 위치 설정]
```

## ❓ 자주 묻는 질문

**Q: 어떤 필터를 사용해야 하나요?**
- **칼만**: 예측 가능한 움직임에 최적 (카메라, AI)
- **원유로**: 사용자 입력에 최적 (마우스, VR 컨트롤러)

**Q: Filter ID는 뭐하는 건가요?**
- 고유한 필터 인스턴스를 식별합니다
- 같은 ID 사용 = 계속 필터링
- ID 변경 = 새로 시작

**Q: 필터가 부드럽지 않아요?**
- "High" 프리셋 사용해보세요
- Delta Time 연결 확인 (원유로만 해당)
- 일관된 Filter ID 사용 확인

## 🚨 문제 해결

| 문제 | 해결책 |
|------|--------|
| 필터 노드를 찾을 수 없음 | Plugins 메뉴에서 플러그인 활성화 확인 |
| 필터가 지연되는 것 같음 | 칼만은 정상, 원유로 시도 |
| 너무 많이 스무딩됨 | "Low" 프리셋 사용 |
| 스무딩이 부족함 | "High" 프리셋 사용 |

## 📚 다음 단계

축하합니다! 전문적인 노이즈 필터링을 성공적으로 구현했습니다.

**더 배울 준비가 되셨나요?**
- 모든 기능은 [사용자 매뉴얼](UserManual_KR.md) 참조
- 기술적 세부사항은 [API 레퍼런스](APIReference_KR.md) 확인
- 고급 사용법은 [예제 프로젝트](Examples_KR.md) 탐색

## 🆘 도움이 필요하신가요?

- 💬 [Discord 커뮤니티](https://discord.gg/yourserver)
- 📧 support@yourcompany.com
- 🐛 [이슈 보고](https://github.com/yourusername/AdvancedFilters/issues)

---

즐거운 필터링 되세요! 🎉