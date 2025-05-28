# 설치 가이드

*다른 언어로 읽기: [English](Installation.md), [한국어](Installation_KR.md)*

고급 필터 플러그인 설치 및 설정을 위한 단계별 가이드

## 📍 네비게이션

- [← 이전: 빠른 시작 가이드](QuickStart_KR.md)
- [→ 다음: 사용자 매뉴얼](UserManual_KR.md)

### 📖 전체 문서
- **시작하기**
  - [빠른 시작 가이드](QuickStart_KR.md)
  - **설치 가이드** (현재 페이지)
- **사용자 가이드**
  - [사용자 매뉴얼](UserManual_KR.md)
  - [블루프린트 예제](Examples_KR.md)
  - [모범 사례](BestPractices_KR.md)
- **기술 문서**
  - [API 레퍼런스](APIReference_KR.md)
  - [성능 가이드](Performance_KR.md)
  - [문제 해결](Troubleshooting_KR.md)

---

## 📋 목차

1. [시스템 요구사항](#시스템-요구사항)
2. [설치 방법](#설치-방법)
3. [플러그인 활성화](#플러그인-활성화)
4. [설치 확인](#설치-확인)
5. [설치 문제 해결](#설치-문제-해결)
6. [플러그인 업데이트](#플러그인-업데이트)

---

## 💻 시스템 요구사항

### 최소 요구사항

- **언리얼 엔진**: 5.5 이상
- **운영체제**: 
  - Windows 10/11 (64비트)
  - macOS 12.0 이상
  - Linux (Ubuntu 20.04 LTS 이상)
- **개발 도구**:
  - Visual Studio 2022 (Windows)
  - Xcode 14+ (macOS)
  - GCC 11+ (Linux)
- **RAM**: 최소 8GB (16GB 권장)
- **저장 공간**: 500MB 여유 공간

### 지원 플랫폼

| 플랫폼 | 지원 상태 | 참고사항 |
|--------|-----------|----------|
| Windows | ✅ 완전 지원 | 주요 개발 플랫폼 |
| macOS | ✅ 완전 지원 | Intel 및 Apple Silicon |
| Linux | ✅ 완전 지원 | Ubuntu에서 테스트됨 |
| Android | ⚠️ 실험적 | 성능이 다를 수 있음 |
| iOS | ⚠️ 실험적 | 추가 설정 필요 |
| 콘솔 | ❌ 미테스트 | 수정 후 작동 가능 |

---

## 📦 설치 방법

### 방법 1: 패키지된 플러그인 (권장)

대부분의 사용자에게 가장 쉬운 설치 방법입니다.

#### 1단계: 플러그인 다운로드

1. [릴리스 페이지](https://github.com/yourusername/AdvancedFilters/releases) 방문
2. 최신 버전 다운로드:
   - `AdvancedFilters_v1.0.0_UE5.5.zip`
3. 다운로드 확인:
   - 파일 크기가 릴리스 노트와 일치하는지 확인
   - 선택사항: SHA256 체크섬 확인

#### 2단계: 플러그인 압축 해제

1. **Plugins 폴더 생성** (없는 경우):
   ```
   YourProject/
   ├── Content/
   ├── Config/
   └── Plugins/    ← 이 폴더 생성
   ```

2. **ZIP 파일 압축 해제**:
   - 다운로드한 파일 우클릭
   - "압축 풀기" 선택 (Windows) 또는 더블클릭 (macOS)
   - `YourProject/Plugins/`에 압축 해제

3. **폴더 구조 확인**:
   ```
   YourProject/Plugins/AdvancedFilters/
   ├── Source/
   ├── Resources/
   └── AdvancedFilters.uplugin
   ```

#### 3단계: 플러그인 활성화

1. 언리얼 엔진에서 프로젝트 열기
2. **편집 → 플러그인** 이동
3. "Advanced Filters" 검색
4. 체크박스를 선택하여 활성화
5. 재시작 메시지가 나타나면 "지금 재시작" 클릭

---

### 방법 2: 소스에서 설치

플러그인을 수정하려는 개발자를 위한 방법입니다.

#### 1단계: 저장소 클론

```bash
# 프로젝트의 Plugins 폴더로 이동
cd YourProject/Plugins

# 저장소 클론
git clone https://github.com/yourusername/AdvancedFilters.git

# 또는 ZIP으로 다운로드 후 압축 해제
```

#### 2단계: 프로젝트 파일 생성

**Windows:**
1. `.uproject` 파일 우클릭
2. "Generate Visual Studio project files" 선택

**macOS:**
1. `.uproject` 파일 우클릭
2. "Generate Xcode project files" 선택

**Linux:**
```bash
# 프로젝트 루트 디렉토리에서
./GenerateProjectFiles.sh
```

#### 3단계: 플러그인 컴파일

**옵션 A: IDE 사용**
1. 생성된 솔루션/프로젝트 파일 열기
2. Development Editor 구성으로 프로젝트 빌드
3. IDE에서 에디터 실행

**옵션 B: 언리얼 엔진 사용**
1. 언리얼 엔진에서 프로젝트 열기
2. 컴파일 메시지가 나타나면 "예" 클릭
3. 컴파일 완료 대기

---

### 방법 3: 엔진 플러그인 설치

컴퓨터의 모든 프로젝트에서 사용할 수 있도록 설치합니다.

#### 1단계: 엔진 플러그인 폴더 찾기

**Windows:**
```
C:\Program Files\Epic Games\UE_5.5\Engine\Plugins\
```

**macOS:**
```
/Users/Shared/Epic Games/UE_5.5/Engine/Plugins/
```

**Linux:**
```
~/UnrealEngine/Engine/Plugins/
```

#### 2단계: 플러그인 복사

1. 새 폴더 생성: `Engine/Plugins/Marketplace/AdvancedFilters`
2. 모든 플러그인 파일을 이 폴더에 복사
3. 언리얼 엔진 재시작

#### 3단계: 프로젝트에서 활성화

1. 프로젝트 열기
2. **편집 → 플러그인** 이동
3. Marketplace에서 "Advanced Filters" 찾기
4. 플러그인 활성화

---

## ✅ 플러그인 활성화

### 첫 설정

1. **플러그인 설정 열기**:
   - 편집 → 플러그인
   - 검색: "Advanced Filters"

2. **플러그인 활성화**:
   - 플러그인 이름 옆 체크박스 선택
   - "지금 재시작" 클릭

3. **설치 확인**:
   - 재시작 후 플러그인이 여전히 활성화되어 있는지 확인
   - 출력 로그에 오류 메시지가 없는지 확인

### 블루프린트 노드 가시성

1. **블루프린트 열기**:
   - 새로 만들거나 기존 블루프린트 열기

2. **이벤트 그래프에서 우클릭**:
   - "Kalman" 검색
   - 필터 노드가 표시되어야 함

3. **카테고리 확인**:
   - "Advanced Filters" 카테고리 확인
   - 모든 노드가 표시되어야 함

---

## 🔍 설치 확인

### 빠른 테스트

1. **테스트 블루프린트 생성**:
   ```
   콘텐츠 브라우저 → 블루프린트 클래스 → Actor → "BP_FilterTest"
   ```

2. **간단한 필터 추가**:
   ```blueprint
   Event BeginPlay
   → Print String "플러그인 로드 성공!"
   
   Event Tick
   → Random Float in Range (0, 100)
   → Kalman Filter Value (Preset: Medium, ID: "Test")
   → Print String
   ```

3. **테스트 실행**:
   - 레벨에 액터 배치
   - Play 버튼 누르기
   - 출력 로그에서 필터링된 값 확인

### 확인 체크리스트

- [ ] 플러그인이 플러그인 메뉴에서 "활성화됨"으로 표시
- [ ] 컴파일 오류 없음
- [ ] 블루프린트 노드가 보임
- [ ] 기본 필터링 작동
- [ ] 성능 경고 없음

---

## 🚨 설치 문제 해결

### 일반적인 문제와 해결책

#### 플러그인이 보이지 않음

**문제**: 플러그인이 플러그인 메뉴에 나타나지 않음

**해결책**:
1. 폴더 구조가 올바른지 확인
2. `.uplugin` 파일이 존재하는지 확인
3. 플러그인 목록 새로고침:
   ```
   편집 → 플러그인 → 새로고침 아이콘 클릭
   ```

#### 컴파일 오류

**문제**: "플러그인 컴파일 실패" 오류

**해결책**:
1. 언리얼 엔진 버전 확인 (5.5+)
2. 필수 개발 도구 설치
3. 특정 오류에 대한 빌드 로그 확인:
   ```
   창 → 개발자 도구 → 출력 로그
   ```

#### 노드가 나타나지 않음

**문제**: 블루프린트에서 필터 노드를 찾을 수 없음

**해결책**:
1. 플러그인이 활성화되어 있는지 확인
2. 활성화 후 에디터 재시작
3. 블루프린트 컨텍스트 확인:
   - 일부 노드는 특정 컨텍스트에서만 나타남
4. 특정 노드 이름으로 검색:
   - "Kalman Filter Value"
   - "One Euro Filter Value"

#### 성능 문제

**문제**: 설치 후 에디터가 느리게 실행됨

**해결책**:
1. 시스템 요구사항 확인
2. 다른 플러그인 일시적으로 비활성화
3. 파생 데이터 캐시 지우기:
   ```
   편집 → 에디터 환경설정 → 파생 데이터 캐시 → 지우기
   ```

---

## 🔄 플러그인 업데이트

### 업데이트 과정

1. **현재 버전 백업**:
   ```
   이름 변경: Plugins/AdvancedFilters → Plugins/AdvancedFilters_backup
   ```

2. **새 버전 다운로드**:
   - 릴리스 페이지에서 최신 버전 받기
   - 호환성 노트 확인

3. **파일 교체**:
   - 이전 플러그인 폴더 삭제 (백업 제외)
   - 새 버전 압축 해제

4. **정리 및 재빌드**:
   - Binaries와 Intermediate 폴더 삭제
   - 프로젝트 파일 재생성
   - 재컴파일

### 마이그레이션 참고사항

**v0.x에서 v1.0으로**:
- API 변경: 없음 (첫 릴리스)
- 블루프린트 호환성: 해당 없음

**향후 업데이트**:
- 주요 변경사항은 릴리스 노트 확인
- 별도 프로젝트에서 먼저 테스트

---

## 📝 플랫폼별 참고사항

### Windows

- Visual Studio 2022 이상 사용
- "C++를 사용한 게임 개발" 워크로드 설치
- 권한 문제 시 관리자 권한으로 실행

### macOS

- Xcode Command Line Tools 필요
- Apple Silicon: Universal Binary 지원 포함
- 필요시 전체 디스크 접근 권한 부여

### Linux

- 개발 패키지 설치:
  ```bash
  sudo apt-get install build-essential
  sudo apt-get install mono-complete
  ```
- 더 나은 호환성을 위해 clang++ 사용

---

## 🆘 도움 받기

설치 중 문제가 발생하면:

1. **FAQ 확인**: [문제 해결 가이드](Troubleshooting_KR.md)
2. **이슈 검색**: [GitHub Issues](https://github.com/yourusername/AdvancedFilters/issues)
3. **커뮤니티 문의**: [Discord 서버](https://discord.gg/yourserver)
4. **지원 문의**: support@yourcompany.com

---

## ✅ 다음 단계

축하합니다! 고급 필터 플러그인이 설치되었습니다.

**필터링을 시작할 준비가 되셨나요?**
- [빠른 시작 가이드](QuickStart_KR.md) - 5분 안에 기본 배우기
- [사용자 매뉴얼](UserManual_KR.md) - 모든 기능 탐색
- [블루프린트 예제](Examples_KR.md) - 실제 사용 예시 보기

---

즐거운 필터링 되세요! 🎉