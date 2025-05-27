# 언리얼 엔진용 고급 필터 플러그인

*다른 언어로 읽기: [English](README.md), [한국어](README_KR.md)*

언리얼 엔진 5.5+ 를 위한 칼만 필터와 원유로 필터를 포함한 고급 필터링 도구

[![Unreal Engine](https://img.shields.io/badge/언리얼%20엔진-5.5+-blue.svg)](https://www.unrealengine.com)
[![License](https://img.shields.io/badge/라이선스-MIT-green.svg)](LICENSE)
[![Version](https://img.shields.io/badge/버전-1.0.0-orange.svg)](https://github.com/yourusername/AdvancedFilters/releases)

## 🎯 개요

고급 필터 플러그인은 언리얼 엔진 프로젝트를 위한 전문가급 노이즈 필터링 기능을 제공합니다. 노이즈가 있는 센서 데이터 smoothing, 카메라 움직임 안정화, VR/AR 입력 개선, 더욱 세련된 게임플레이 경험 구현에 완벽합니다.

### 주요 기능

- **두 가지 산업 표준 필터**
  - **칼만 필터**: 예측을 통한 최적 상태 추정
  - **원유로 필터**: 저지연 적응형 필터링
  
- **사용자 친화적 설계**
  - 완전한 제어를 위한 3-노드 시스템
  - 즉시 필터링을 위한 원클릭 매크로
  - 직관적인 Low/Medium/High 프리셋

- **전문가 기능**
  - Float 및 Vector 지원
  - 커스텀 프리셋
  - 필터 체인
  - 성능 프로파일링
  - 자동 튜닝

## 📦 설치 방법

### 방법 1: 패키지된 플러그인
1. [Releases](https://github.com/yourusername/AdvancedFilters/releases)에서 최신 버전 다운로드
2. 프로젝트의 `Plugins` 폴더에 압축 해제
3. 언리얼 에디터 재시작
4. 편집 → 플러그인 → Advanced Filters 활성화

### 방법 2: 소스에서 빌드
1. 이 저장소 클론
2. `AdvancedFilters` 폴더를 프로젝트의 `Plugins` 디렉토리에 복사
3. `.uproject` 파일 우클릭 후 "Generate Visual Studio project files" 선택
4. 프로젝트 컴파일

## 🚀 빠른 시작

### 원클릭 필터링 (가장 쉬운 방법)

```blueprint
Event Tick
    ↓
[센서 값 가져오기]
    ↓
[Kalman Filter Value]
- Preset: Medium
- Filter ID: "MySensor"
    ↓
[필터링된 값 설정]
```

### 3-노드 시스템 (더 많은 제어)

```blueprint
Begin Play:
[Create Filter (Kalman)] → [Initialize (Medium)] → [변수로 저장]

Event Tick:
[필터 가져오기] → [Update Estimate (센서 값)] → [결과 사용]
```

## 📊 필터 비교

| 특징 | 칼만 필터 | 원유로 필터 |
|------|-----------|-------------|
| **적합한 용도** | 예측 가능한 움직임, 센서 | 사용자 입력, VR/AR |
| **지연 시간** | 5-10 프레임 | 0-3 프레임 |
| **부드러움** | 매우 부드러움 | 적응형 |
| **노이즈 제거** | 95% 이상 | 85% 이상 |

## 🎮 일반적인 사용 사례

### 카메라 안정화 (칼만)
```blueprint
[카메라 흔들림 가져오기] → [Kalman Filter Vector] → [카메라 위치 설정]
```

### VR 컨트롤러 (원유로)
```blueprint
[컨트롤러 위치 가져오기] → [One Euro Filter Vector] → [손 메시 업데이트]
```

### 마우스 스무딩 (원유로)
```blueprint
[마우스 델타 가져오기] → [One Euro Filter Value] → [회전 입력 적용]
```

## 📖 문서

### 시작하기
- [빠른 시작 가이드](docs/QuickStart_KR.md) - 5분 안에 시작하기
- [설치 가이드](docs/Installation_KR.md) - 상세한 설치 방법

### 사용자 가이드
- [사용자 매뉴얼](docs/UserManual_KR.md) - 전체 기능 가이드
- [블루프린트 예제](docs/Examples_KR.md) - 샘플 프로젝트와 블루프린트
- [모범 사례](docs/BestPractices_KR.md) - 팁과 권장사항

### 기술 문서
- [API 레퍼런스](docs/APIReference_KR.md) - 모든 노드와 파라미터
- [성능 가이드](docs/Performance_KR.md) - 최적화 팁
- [문제 해결](docs/Troubleshooting_KR.md) - 일반적인 문제와 해결법

### 고급 주제
- [커스텀 프리셋](docs/CustomPresets_KR.md) - 나만의 필터 설정 만들기
- [필터 체이닝](docs/FilterChaining_KR.md) - 여러 필터 조합하기
- [마이그레이션 가이드](docs/Migration_KR.md) - 이전 버전에서 업데이트

## 🛠️ 고급 기능

### 커스텀 프리셋
나만의 필터 설정 만들기:
```blueprint
[Create Custom Preset]
- Name: "MyVRConfig"
- Process Noise: 0.05
- Beta: 0.0001
```

### 필터 체인
여러 필터 조합:
```blueprint
[Create Filter Chain] → [칼만 + 원유로] → [Process Through Chain]
```

### 성능 프로파일링
필터 성능 측정:
```blueprint
[Start Profiling] → [필터 작업] → [Stop Profiling]
```

## 📊 성능

- **CPU 사용량**: 필터 인스턴스당 < 0.1%
- **메모리**: 필터당 ~100-150 바이트
- **지연 시간**: 필터와 프리셋에 따라 0-10 프레임

## 🤝 기여하기

기여를 환영합니다! 자세한 내용은 [기여 가이드](CONTRIBUTING_KR.md)를 참조하세요.

## 📄 라이선스

이 프로젝트는 MIT 라이선스 하에 배포됩니다 - 자세한 내용은 [LICENSE](LICENSE) 파일을 참조하세요.

## 🙏 감사의 말

- 칼만 필터는 Rudolf E. Kálmán의 원본 연구를 기반으로 합니다
- 원유로 필터는 [Géry Casiez의 연구](http://cristal.univ-lille.fr/~casiez/1euro/)를 기반으로 합니다

## 📞 지원

- **이슈**: [GitHub Issues](https://github.com/yourusername/AdvancedFilters/issues)
- **디스코드**: [커뮤니티 참여](https://discord.gg/yourserver)
- **이메일**: support@yourcompany.com

---

언리얼 엔진 커뮤니티를 위해 ❤️를 담아 제작했습니다