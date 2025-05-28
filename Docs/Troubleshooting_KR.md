# 문제 해결 가이드

*다른 언어로 읽기: [English](Troubleshooting.md), [한국어](Troubleshooting_KR.md)*

고급 필터 플러그인의 일반적인 문제와 해결책

## 📍 네비게이션

- [← 이전: 성능 가이드](Performance_KR.md)
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
  - **문제 해결** (현재 페이지)

---

## 📋 목차

1. [설치 문제](#설치-문제)
2. [블루프린트 노드 문제](#블루프린트-노드-문제)
3. [런타임 오류](#런타임-오류)
4. [성능 문제](#성능-문제)
5. [필터 동작 문제](#필터-동작-문제)
6. [플랫폼별 문제](#플랫폼별-문제)

---

## 🔧 설치 문제

### 플러그인이 플러그인 메뉴에 보이지 않음

**증상:**
- 편집 → 플러그인에서 플러그인이 나타나지 않음
- 플러그인 목록에서 "Advanced Filters"를 찾을 수 없음

**해결책:**

1. **폴더 구조 확인:**
   ```
   YourProject/Plugins/AdvancedFilters/
   ├── AdvancedFilters.uplugin  ← 반드시 존재해야 함
   ├── Source/
   └── Resources/
   ```

2. **플러그인 파일 확인:**
   - 텍스트 에디터로 `AdvancedFilters.uplugin` 열기
   - `"EngineVersion": "5.5"`가 엔진과 일치하는지 확인

3. **플러그인 목록 새로고침:**
   - 언리얼 엔진 종료
   - `YourProject/Saved/` 폴더 삭제
   - 재시작 후 다시 확인

4. **수동 등록:**
   ```json
   // YourProject.uproject에 추가:
   "Plugins": [
     {
       "Name": "AdvancedFilters",
       "Enabled": true
     }
   ]
   ```

---

### 컴파일 오류

**증상:**
- "플러그인 컴파일 실패" 오류
- 모듈 누락 오류
- 링크 오류

**해결책:**

1. **엔진 버전 확인:**
   - 언리얼 엔진 5.5 이상이어야 함
   - 확인: 도움말 → 언리얼 엔진 정보

2. **프로젝트 파일 재생성:**
   ```bash
   # Windows
   .uproject 우클릭 → Generate Visual Studio project files
   
   # Mac
   .uproject 우클릭 → Generate Xcode project files
   ```

3. **중간 파일 정리:**
   ```
   다음 폴더 삭제:
   - Plugins/AdvancedFilters/Binaries/
   - Plugins/AdvancedFilters/Intermediate/
   - 재빌드
   ```

4. **빌드 도구 확인:**
   - Windows: C++ 도구가 포함된 Visual Studio 2022
   - Mac: 명령줄 도구가 포함된 최신 Xcode
   - Linux: GCC 11+ 또는 Clang 13+

---

## 🎯 블루프린트 노드 문제

### 노드가 나타나지 않음

**증상:**
- 블루프린트에서 필터 노드를 찾을 수 없음
- 검색 결과가 없음
- 카테고리가 누락됨

**해결책:**

1. **플러그인 활성화:**
   - 편집 → 플러그인 → "Advanced Filters" 검색
   - 체크박스가 선택되어 있는지 확인
   - 에디터 재시작

2. **컨텍스트 확인:**
   - 일부 노드는 특정 컨텍스트에서만 나타남
   - Actor 또는 Character 블루프린트에서 시도

3. **검색 변형:**
   ```
   다음을 검색해보세요:
   - "Kalman"
   - "One Euro"
   - "Filter Value"
   - "Advanced Filters"
   ```

4. **블루프린트 컴파일:**
   - 컴파일 버튼 클릭
   - 컴파일러 결과에서 오류 확인

---

### 노드에 오류 표시

**증상:**
- 노드에 빨간색 오류
- "Node impure" 경고
- 핀 연결 누락

**해결책:**

1. **노드 새로고침:**
   - 노드 우클릭 → Refresh Node
   - 또는 삭제 후 다시 추가

2. **실행 핀 확인:**
   - 흰색 실행 핀이 연결되어 있는지 확인
   - 원클릭 매크로는 실행 핀 불필요

3. **입력 검증:**
   - 원유로에는 Delta Time 필수
   - Filter ID는 비어있지 않은 문자열이어야 함
   - Preset은 유효한 열거형 값이어야 함

---

## ⚠️ 런타임 오류

### 필터가 스무딩되지 않음

**증상:**
- 출력이 입력과 동일
- 필터링 효과 없음
- 값이 튐

**일반적인 원인과 해결책:**

1. **일관되지 않은 Filter ID:**
   ```blueprint
   // 나쁨 - 매 프레임 새 필터 생성
   Filter ID: "Filter_" + Random Int
   
   // 좋음 - 같은 필터 재사용
   Filter ID: "PlayerPosition"
   ```

2. **초기화 누락:**
   - 3-노드 시스템: Initialize 호출 필수
   - 원클릭: 자동 (ID 일관성 확인)

3. **잘못된 프리셋:**
   - Low 프리셋 = 최소 필터링
   - 더 많은 스무딩을 위해 Medium 또는 High 시도

4. **프레임 의존적 값:**
   - Delta Time이 연결되어 있는지 확인 (원유로)
   - 고정 시간 값 사용 금지

---

### 과도한 지연/딜레이

**증상:**
- 필터 출력이 입력보다 뒤처짐
- 변화에 대한 느린 반응
- "떠다니는" 느낌

**해결책:**

1. **필터 타입 전환:**
   - 낮은 지연을 위해 칼만 → 원유로
   - 원유로는 일반적으로 3-5배 빠른 반응

2. **프리셋 조정:**
   - High → Medium 또는 Low
   - 낮은 프리셋 = 빠른 반응

3. **커스텀 파라미터:**
   ```blueprint
   // 칼만 - Q 증가
   Set Process Noise (0.1 → 1.0)
   
   // 원유로 - Min Cutoff 증가
   Set Min Cutoff (0.1 → 1.0)
   ```

---

### 메모리 누수

**증상:**
- 시간이 지남에 따라 메모리 사용량 증가
- 에디터가 느려짐
- 장시간 사용 후 충돌

**해결책:**

1. **미사용 필터 정리:**
   ```blueprint
   // 레벨 종료 또는 상태 변경 시
   Clear All Filters
   ```

2. **Filter ID 재사용:**
   - 불필요하게 고유 ID 생성 금지
   - 일관된 명명 체계 사용

3. **필터 개수 확인:**
   ```blueprint
   // 디버그 - 필터 개수 로그
   Get Filter Memory Usage
   → Print String (Filter Count)
   ```

---

## 🐌 성능 문제

### 낮은 프레임 레이트

**증상:**
- 필터 사용 시 FPS 하락
- 끊김 또는 버벅임
- 성능 경고

**해결책:**

1. **LOD 구현:**
   ```blueprint
   Distance = 카메라까지 거리
   If Distance > 50
       필터 업데이트 건너뛰기
   ```

2. **업데이트 빈도 감소:**
   ```blueprint
   // N 프레임마다 업데이트
   If Frame Counter % 3 == 0
       필터 업데이트
   ```

3. **조건부 업데이트 사용:**
   ```blueprint
   If Abs(New - Old) > 임계값
       필터 업데이트
   ```

4. **성능 프로파일:**
   ```
   콘솔 명령:
   stat Filter
   stat FilterDetailed
   ```

---

### 높은 CPU 사용량

**증상:**
- CPU 사용량 급증
- 열 스로틀링
- 배터리 소모 (모바일)

**해결책:**

1. **배치 처리:**
   - 유사한 필터 그룹화
   - 배치로 업데이트

2. **필터 개수 최적화:**
   - 사용 중인 모든 필터 감사
   - 중복 필터 제거

3. **플랫폼별 설정:**
   - 모바일: Low 프리셋 사용
   - VR: 눈당 50개 필터로 제한

---

## 🔍 필터 동작 문제

### 출력 진동

**증상:**
- 필터 출력이 앞뒤로 흔들림
- 불안정한 값
- 과도한 보정

**해결책:**

1. **입력 안정성 확인:**
   - 입력이 빠르게 전환되지 않는지 확인
   - 입력 검증 추가

2. **파라미터 조정:**
   ```blueprint
   // 칼만 - Q 감소
   Set Process Noise (0.01)
   
   // 원유로 - Beta 감소
   Set Beta (0.0001)
   ```

3. **다른 필터 사용:**
   - 다른 필터 타입으로 전환
   - 다른 프리셋 시도

---

### 예측 없음 (칼만)

**증상:**
- 칼만 필터가 예측하지 않음
- 단순한 스무딩처럼 작동
- 움직임 예상 없음

**해결책:**

1. **필터 타입 확인:**
   - 원유로가 아닌 칼만 사용 확인
   - Create Filter 노드 확인

2. **일관된 업데이트:**
   - 매 프레임 업데이트
   - 프레임 건너뛰기 금지

3. **적절한 파라미터:**
   - Medium 또는 High 프리셋
   - 과도한 R 값 피하기

---

## 🖥️ 플랫폼별 문제

### 모바일 성능

**문제:** 모바일 기기에서 낮은 성능

**해결책:**
1. Low 프리셋만 사용
2. 최대 50-100개 필터로 제한
3. 적극적인 LOD 구현
4. float16 정밀도 고려

### VR 편안함

**문제:** 필터링으로 인한 멀미

**해결책:**
1. 컨트롤러에 원유로 사용
2. 최소 지연을 위한 Low 프리셋
3. 헤드 트래킹은 절대 필터링 금지
4. 다양한 사용자와 테스트

### 콘솔 호환성

**문제:** 콘솔에서 플러그인 작동 안 함

**해결책:**
1. 대상 플랫폼용 재빌드
2. 플랫폼별 코드 확인
3. 셰이더 컴파일 확인
4. 콘솔 SDK 지원 문의

---

## 🔧 디버그 명령

### 유용한 콘솔 명령

```
// 필터 통계 표시
stat Filter

// 상세 성능
stat FilterDetailed

// 메모리 사용량
ShowFlag.FilterMemory 1

// 디버그 시각화
r.Filter.ShowDebug 1

// 모든 필터 리셋
Filter.ClearAll
```

### 블루프린트 디버그 노드

```blueprint
// 필터 상태 로그
Get Filter Statistics → Print String

// 성능 확인
Start/Stop Filter Profiling

// 메모리 감사
Get Filter Memory Usage → Log
```

---

## 📞 추가 도움 받기

문제가 지속되면:

1. **기존 이슈 검색:**
   - [GitHub Issues](https://github.com/yourusername/AdvancedFilters/issues)
   - 닫힌 이슈도 확인

2. **상세한 보고서 작성:**
   - 언리얼 엔진 버전
   - 플러그인 버전
   - 재현 단계
   - 오류 메시지/로그
   - 스크린샷/동영상

3. **지원 문의:**
   - Discord: [서버 참여](https://discord.gg/yourserver)
   - 이메일: support@yourcompany.com
   - 가능하면 프로젝트 파일 포함

---

## 📋 빠른 참조

### 가장 일반적인 해결책

| 문제 | 빠른 해결 |
|------|----------|
| 노드를 찾을 수 없음 | 플러그인 활성화 & 재시작 |
| 스무딩 없음 | Filter ID 일관성 확인 |
| 너무 많은 지연 | 원유로 또는 Low 프리셋으로 전환 |
| 성능 문제 | LOD 시스템 구현 |
| 컴파일 오류 | 프로젝트 파일 재생성 |
| 메모리 누수 | Clear All Filters 호출 |

---

기억하세요: 대부분의 문제는 간단한 해결책이 있습니다. 먼저 기본사항을 확인하세요! 🎯