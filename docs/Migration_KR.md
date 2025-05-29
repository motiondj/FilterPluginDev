# 마이그레이션 가이드

*다른 언어로 읽기: [English](Migration.md), [한국어](Migration_KR.md)*

고급 필터 플러그인 버전 업그레이드를 위한 완전한 가이드

## 📍 네비게이션

- [← 이전: 필터 체이닝](FilterChaining_KR.md)
- [← README로 돌아가기](../README_KR.md)

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
  - [커스텀 프리셋](CustomPresets_KR.md)
  - [필터 체이닝](FilterChaining_KR.md)
  - **마이그레이션 가이드** (현재 페이지)

---

## 📋 목차

1. [마이그레이션 개요](#마이그레이션-개요)
2. [버전 히스토리](#버전-히스토리)
3. [마이그레이션 전 체크리스트](#마이그레이션-전-체크리스트)
4. [마이그레이션 절차](#마이그레이션-절차)
5. [마이그레이션 후 테스트](#마이그레이션-후-테스트)
6. [마이그레이션 문제 해결](#마이그레이션-문제-해결)

---

## 🔄 마이그레이션 개요

### 마이그레이션이란?

마이그레이션은 기능을 보존하고 중단을 최소화하면서 고급 필터 플러그인의 이전 버전에서 새 버전으로 프로젝트를 업그레이드하는 과정입니다.

### 왜 마이그레이션해야 하나요?

**최신 버전 유지의 이점:**
- ✅ 최신 성능 최적화
- ✅ 새로운 기능과 능력
- ✅ 버그 수정 및 안정성 개선
- ✅ 보안 업데이트
- ✅ 지속적인 지원 및 문서화

### 마이그레이션 유형

1. **패치 업데이트** (1.0.1 → 1.0.2)
   - 버그 수정만
   - 호환성 깨지는 변경 없음
   - 자동 마이그레이션

2. **마이너 업데이트** (1.0 → 1.1)
   - 새 기능 추가
   - 하위 호환성 유지
   - 선택적 마이그레이션 단계

3. **메이저 업데이트** (1.x → 2.x)
   - 중대한 변경사항
   - 호환성 깨지는 변경 포함 가능
   - 수동 마이그레이션 필요

---

## 📚 버전 히스토리

### 버전 1.0.0 (현재)
**릴리스 날짜:** 초기 릴리스
**호환성:** 언리얼 엔진 5.5+

**기능:**
- 칼만 및 원유로 필터
- 3-노드 및 원클릭 시스템
- 커스텀 프리셋
- 필터 체이닝
- 성능 프로파일링

**API 상태:** 안정
**호환성 깨지는 변경:** 없음 (초기 버전)

---

### 향후 버전 로드맵

#### 버전 1.1.0 (계획됨)
**예상 기능:**
- GPU 가속 필터링
- 추가 필터 유형
- 향상된 디버깅 도구
- 모바일 최적화

**예상 호환성:** 하위 호환
**마이그레이션 난이도:** 쉬움

#### 버전 2.0.0 (미래)
**잠재적 기능:**
- 완전한 API 재설계
- 고급 ML 기반 필터링
- 클라우드 기반 처리
- 새로운 블루프린트 인터페이스

**예상 호환성:** 호환성 깨지는 변경 가능성
**마이그레이션 난이도:** 복잡

---

## ✅ 마이그레이션 전 체크리스트

### 시작하기 전에

마이그레이션을 시작하기 전에 이 체크리스트를 완료하세요:

#### 1. 프로젝트 백업
```bash
# 완전한 프로젝트 백업 생성
cp -r YourProject YourProject_Backup_v1.0.0

# 또는 버전 관리 사용
git commit -m "마이그레이션 전 백업 - v1.0.0"
git tag "pre-migration-v1.0.0"
```

#### 2. 현재 설정 문서화
```blueprint
// 현재 플러그인 버전 기록
Plugin Version: 1.0.0
Engine Version: 5.5.1
Project Name: YourProject

// 사용 중인 모든 기능 목록
Used Features:
- 칼만 필터: [위치 목록]
- 원유로 필터: [위치 목록]
- 커스텀 프리셋: [이름 목록]
- 필터 체인: [구성 목록]
```

#### 3. 현재 기능 테스트
- [ ] 모든 필터가 올바르게 작동
- [ ] 성능이 요구사항 충족
- [ ] 로그에 오류 메시지 없음
- [ ] 모든 커스텀 프리셋 기능적
- [ ] 필터 체인이 적절히 작동

#### 4. 의존성 확인
- [ ] 언리얼 엔진 버전 호환성
- [ ] 다른 플러그인 호환성
- [ ] 플랫폼별 요구사항
- [ ] 서드파티 통합

#### 5. 릴리스 노트 검토
- [ ] 새 버전의 변경 로그 읽기
- [ ] 호환성 깨지는 변경사항 확인
- [ ] 새 기능 주목
- [ ] 사용 중단 경고 확인

---

## 🔧 마이그레이션 절차

### 자동 마이그레이션 (패치 업데이트)

패치 업데이트 (1.0.1, 1.0.2 등)의 경우:

#### 1단계: 새 버전 다운로드
```bash
# 최신 패치 다운로드
wget https://github.com/yourrepo/AdvancedFilters/releases/v1.0.2.zip

# 또는 패키지 매니저 사용
ue4-plugin-manager update AdvancedFilters
```

#### 2단계: 플러그인 파일 교체
```bash
# 현재 버전 백업
mv Plugins/AdvancedFilters Plugins/AdvancedFilters_v1.0.1

# 새 버전 압축 해제
unzip AdvancedFilters_v1.0.2.zip -d Plugins/
```

#### 3단계: 프로젝트 파일 재생성
```bash
# Windows
YourProject.uproject → Generate Visual Studio project files

# Mac
YourProject.uproject → Generate Xcode project files

# Linux
./GenerateProjectFiles.sh
```

#### 4단계: 재컴파일
```bash
# IDE에서 컴파일하거나
ue4 -project="YourProject.uproject" -compile
```

---

### 수동 마이그레이션 (마이너/메이저 업데이트)

호환성 깨지는 변경이 있는 업데이트의 경우:

#### v1.0에서 v1.1로 마이그레이션 (예시)

**1단계: API 변경사항 평가**
```cpp
// 이전 v1.0 API (사용 중단)
CreateFilter(EFilterType::Kalman);

// 새 v1.1 API (권장)
CreateAdvancedFilter(EFilterType::Kalman, EFilterVersion::V2);
```

**2단계: 블루프린트 노드 업데이트**
```blueprint
// 사용 중단된 노드 교체
이전: [Create Filter]
새로운: [Create Advanced Filter]

// 파라미터 업데이트
이전: Preset (Low/Medium/High)
새로운: Preset (Low/Medium/High/Ultra/Custom)
```

**3단계: 커스텀 프리셋 마이그레이션**
```blueprint
// v1.0 커스텀 프리셋 형식
[Create Custom Preset]
├─ Name: "MyPreset"
├─ Q: 0.1
├─ R: 0.01
├─ MinCutoff: 0.5
└─ Beta: 0.001

// v1.1 확장 형식 (가상)
[Create Advanced Custom Preset]
├─ Name: "MyPreset"
├─ Version: V2
├─ Kalman Settings:
│  ├─ Q: 0.1
│  ├─ R: 0.01
│  └─ Adaptive: true
├─ OneEuro Settings:
│  ├─ MinCutoff: 0.5
│  ├─ Beta: 0.001
│  └─ DynamicBeta: true
└─ Performance Settings:
   ├─ GPUAccelerated: true
   └─ BatchSize: 32
```

**4단계: 필터 체인 업데이트**
```blueprint
// v1.0 체인 생성
[Create Filter Chain]
├─ Filters: [Kalman, OneEuro]
└─ Weights: [0.7, 0.3]

// v1.1 향상된 체인 (가상)
[Create Advanced Filter Chain]
├─ Chain Type: Sequential
├─ Stages:
│  ├─ Stage 1: Kalman (Preset: Medium)
│  └─ Stage 2: OneEuro (Preset: Low)
├─ Optimization: Enabled
└─ GPU Processing: Auto
```

---

### 마이그레이션 자동화 도구

#### 내장 마이그레이션 어시스턴트

```blueprint
// 마이그레이션 어시스턴트 실행
[Launch Migration Assistant]
├─ Source Version: 1.0.0
├─ Target Version: 1.1.0
├─ Project Path: YourProject
└─ Migration Options:
   ├─ Backup Project: true
   ├─ Auto-Update Blueprints: true
   ├─ Preserve Custom Presets: true
   └─ Generate Migration Report: true
```

#### 마이그레이션 스크립트 (미래 기능)
```python
# Python 마이그레이션 스크립트
import ue_migration_tools

# 마이그레이션 구성
migration = ue_migration_tools.Migration(
    from_version="1.0.0",
    to_version="1.1.0",
    project_path="YourProject"
)

# 자동 마이그레이션 실행
migration.backup_project()
migration.update_plugin()
migration.migrate_blueprints()
migration.migrate_presets()
migration.generate_report()
```

---

## 🧪 마이그레이션 후 테스트

### 자동 테스트

#### 테스트 슈트 실행
```blueprint
// 포괄적인 테스트 슈트 실행
[Run Migration Test Suite]
├─ 기본 기능 테스트:
│  ├─ 필터 생성: ✅ 통과
│  ├─ 필터 초기화: ✅ 통과
│  ├─ 필터 업데이트: ✅ 통과
│  └─ 필터 정리: ✅ 통과
├─ 고급 기능 테스트:
│  ├─ 커스텀 프리셋: ✅ 통과
│  ├─ 필터 체인: ⚠️ 경고 - 성능 변화
│  ├─ 병렬 처리: ✅ 통과
│  └─ 오류 처리: ✅ 통과
└─ 성능 테스트:
   ├─ 단일 필터 속도: ✅ 15% 개선
   ├─ 체인 처리: ✅ 8% 개선
   ├─ 메모리 사용량: ✅ 5% 감소
   └─ 시작 시간: ✅ 변화 없음
```

### 수동 테스트 체크리스트

#### 핵심 기능
- [ ] 기존 모든 필터가 여전히 작동
- [ ] 성능이 유지되거나 개선됨
- [ ] 새로운 오류 메시지 없음
- [ ] 메모리 사용량이 안정적
- [ ] 모든 플랫폼이 여전히 지원됨

#### 고급 기능
- [ ] 커스텀 프리셋이 올바르게 로드됨
- [ ] 필터 체인이 예상대로 작동
- [ ] 새 기능이 문서대로 작동
- [ ] 하위 호환성이 유지됨
- [ ] 설정 마이그레이션이 성공적

#### 통합 테스트
- [ ] 다른 플러그인과 여전히 호환
- [ ] 프로젝트가 성공적으로 빌드됨
- [ ] 패키지된 빌드가 올바르게 작동
- [ ] 플랫폼별 테스트 완료
- [ ] 성능 목표 달성

---

## 🚨 마이그레이션 문제 해결

### 일반적인 마이그레이션 문제

#### 문제 1: 블루프린트 컴파일 오류

**증상:**
- 블루프린트에서 빨간색 오류 노드
- "Node not found" 메시지
- 컴파일 실패

**해결책:**
```blueprint
// 1단계: 블루프린트 노드 새로고침
노드 우클릭 → Refresh Node

// 2단계: 사용 중단된 노드 교체
이전 노드 → 삭제 → 새 노드 추가

// 3단계: 블루프린트 재컴파일
Blueprint → Compile → 오류 수정
```

#### 문제 2: 커스텀 프리셋이 로드되지 않음

**증상:**
- 마이그레이션 후 커스텀 프리셋 누락
- 기본 프리셋이 대신 사용됨
- 프리셋 관련 오료

**해결책:**
```blueprint
// 프리셋 마이그레이션 확인
[Validate Custom Presets]
├─ 모든 프리셋 목록
├─ 파라미터 범위 확인
├─ 명명 규칙 검증
└─ 필요시 재생성
```

#### 문제 3: 성능 저하

**증상:**
- 필터 처리 속도 저하
- 높은 CPU 사용량
- 메모리 누수

**해결책:**
```blueprint
// 성능 진단
[Profile Filter Performance]
├─ 전후 지표 비교
├─ 병목 현상 식별
├─ 새 기본 설정 확인
└─ 구성 조정
```

#### 문제 4: 필터 체인 손상

**증상:**
- 체인 처리가 작동 중지
- 예상치 못한 필터 동작
- 체인 구성 오류

**해결책:**
```blueprint
// 체인 마이그레이션 단계
[Migrate Filter Chains]
├─ 체인 구성 내보내기
├─ 새 형식으로 업데이트
├─ 각 체인을 개별적으로 테스트
└─ 복잡한 체인 재구축
```

---

### 마이그레이션 복구

#### 롤백 절차

마이그레이션이 실패할 경우 이 롤백 과정을 따르세요:

```bash
# 1단계: 언리얼 엔진 중지
# 모든 언리얼 에디터 인스턴스 종료

# 2단계: 백업 복원
rm -rf Plugins/AdvancedFilters
mv Plugins/AdvancedFilters_Backup Plugins/AdvancedFilters

# 3단계: 프로젝트 파일 복원
git checkout pre-migration-backup
# 또는 파일 백업에서 복원

# 4단계: 프로젝트 파일 재생성
# 플랫폼용 프로젝트 파일 재생성

# 5단계: 재컴파일
# 원본 버전으로 프로젝트 컴파일
```

#### 부분 마이그레이션

일부 기능만 마이그레이션에 실패한 경우:

```blueprint
// 하이브리드 접근법
[Partial Migration Strategy]
├─ 새 버전에서 작동하는 기능 유지
├─ 문제가 있는 기능 롤백
├─ 남은 기능 점진적 마이그레이션
└─ 각 구성 요소를 개별적으로 테스트
```

---

## 📊 마이그레이션 계획

### 시간 추정

| 마이그레이션 유형 | 준비 | 실행 | 테스트 | 총계 |
|------------------|------|------|--------|-------|
| **패치** (1.0.1) | 30분 | 15분 | 1시간 | 2시간 |
| **마이너** (1.1.0) | 2시간 | 1시간 | 4시간 | 7시간 |
| **메이저** (2.0.0) | 1일 | 4시간 | 2일 | 4일 |

### 위험도 평가

#### 낮은 위험도 마이그레이션
- 패치 업데이트
- 버그 수정 릴리스
- 성능 개선
- 문서 업데이트

#### 중간 위험도 마이그레이션
- 새 기능 추가
- API 확장
- 구성 변경
- 플랫폼 업데이트

#### 높은 위험도 마이그레이션
- API 호환성 깨지는 변경
- 주요 아키텍처 업데이트
- 사용 중단 기능 제거
- 엔진 버전 요구사항

---

## 📝 마이그레이션 모범 사례

### 마이그레이션 전
1. **항상 백업**하세요 - 프로젝트를 완전히 백업
2. **격리된 환경에서 테스트**를 먼저 해보세요
3. **릴리스 노트를 철저히** 읽어보세요
4. **마이그레이션 중 다운타임을** 계획하세요
5. **팀과 변경사항에 대해** 소통하세요

### 마이그레이션 중
1. **절차를 단계별로** 따르세요
2. **발생한 문제를** 문서화하세요
3. **과정 중 자주** 테스트하세요
4. **향후 참조를 위해** 노트를 유지하세요
5. **과정을 서두르지** 마세요

### 마이그레이션 후
1. **즉시 포괄적인 테스트를** 실행하세요
2. **며칠 동안 성능을** 모니터링하세요
3. **새 기능에 대해 팀 멤버들을** 교육하세요
4. **필요에 따라 문서를** 업데이트하세요
5. **다음 마이그레이션** 일정을 계획하세요

---

## 🎯 빠른 참조

### 마이그레이션 명령어

```bash
# 프로젝트 백업
cp -r Project Project_Backup

# 플러그인 업데이트
wget new_version.zip && unzip -o

# 파일 재생성
Generate_Project_Files.bat

# 프로젝트 컴파일
Build_Project.sh
```

### 비상 연락처

마이그레이션 중 중요한 문제가 발생하면:

- 🆘 **중요한 문제:** support@yourcompany.com
- 💬 **커뮤니티 도움:** [Discord 서버](https://discord.gg/yourserver)
- 🐛 **버그 보고:** [GitHub Issues](https://github.com/yourrepo/issues)
- 📚 **문서:** 문제 해결 가이드 확인

---

## 🚀 미래 대비

### 마이그레이션 준비 상태 유지

1. **정기 업데이트**: 마이너 버전을 건너뛰지 마세요
2. **코드 리뷰**: 사용 중단된 기능 확인
3. **자동화된 테스트**: 문제를 조기에 발견
4. **문서화**: 마이그레이션 히스토리 유지
5. **팀 교육**: 모든 사람이 과정을 알도록

### 마이그레이션 전략

```blueprint
[장기 마이그레이션 전략]
├─ 분기별 검토: 새 버전 확인
├─ 단계별 롤아웃: 테스트 → 개발 → 스테이징 → 프로덕션
├─ 롤백 계획: 항상 탈출 전략 보유
├─ 팀 교육: 기술을 최신 상태로 유지
└─ 문서화: 배운 교훈 기록
```

---

**성공적인 마이그레이션으로 프로젝트를 최신, 안전, 고성능 상태로 유지하세요!** 🎉

마이그레이션 질문이 있으시면 [문제 해결 가이드](Troubleshooting_KR.md)를 확인하거나 지원팀에 문의하세요.