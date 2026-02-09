<div align="center">

<h2>[2025] HellTaker 모작 🔥</h2>
<p>C++ / SFML 기반<br>
소코반(Sokoban) 장르 퍼즐 게임<br>
</p>

</div>


## 📂 HellTaker/ 폴더 구조
```
MM1152/HellTaker/
├z── README.md
└── Project/
    ├── hell_taker/                    # 💻 소스 코드 디렉토리
    │   ├── main.cpp                   # 프로그램 진입점
    │   ├── stdafx.h / stdafx.cpp      # 사전 컴파일된 헤더
    │   │
    │   ├── Framework/                 # 🎮 게임 엔진 프레임워크
    │   │   ├── Framework.h/cpp        # 메인 게임 루프 & 초기화
    │   │   ├── SceneMgr.h/cpp         # 씬 관리자 (게임/에디터/개발)
    │   │   ├── InputMgr.h/cpp         # 키보드/마우스 입력 관리
    │   │   ├── ResourceMgr.h          # 리소스 로드 관리 (텍스처, 폰트)
    │   │   ├── SoundMgr.h/cpp         # 사운드 재생 관리
    │   │   ├── Utils.h/cpp            # 유틸리티 함수 (Lerp, 파일I/O 등)
    │   │   ├── Map.h/cpp              # 맵 데이터 관리 (싱글톤)
    │   │   ├── Define.h               # 전역 정의 (enum, 상수)
    │   │   ├── Singleton.h            # 싱글톤 패턴 템플릿
    │   │   │
    │   │   ├── GameObject.h/cpp       # 게임 오브젝트 추상 베이스 클래스
    │   │   ├── Scene.h/cpp            # 씬 추상 베이스 클래스
    │   │   ├── Animator.h/cpp         # 애니메이션 재생 시스템
    │   │   ├── AnimationClip.h/cpp    # 애니메이션 클립 데이터
    │   │   └── rapidcsv.h             # CSV 파싱 라이브러리 (외부)
    │   │
    │   ├── Scene/                     # 🎬 게임 씬 구현
    │   │   ├── GameScene.h/cpp        # 메인 게임 플레이 씬
    │   │   ├── SceneDev1.h/cpp        # 개발/테스트용 씬
    │   │   └── SceneMapEditor.h/cpp   # 맵 에디터 씬
    │   │
    │   ├── GameObjects/               # 🕹️ 게임 오브젝트들
    │   │   ├── Player.h/cpp           # 플레이어 캐릭터
    │   │   ├── Obstacle.h/cpp         # 장애물 베이스 클래스
    │   │   ├── ImmovableObstacle.h/cpp # 고정 장애물 (벽 등)
    │   │   ├── MoveAbleObject.h/cpp   # 이동 가능 오브젝트
    │   │   │
    │   │   ├── NPC.h/cpp              # 스테이지 클리어 NPC
    │   │   ├── Box.h/cpp              # 밀 수 있는 상자
    │   │   ├── Stone.h/cpp            # 돌 장애물
    │   │   ├── Huddle.h/cpp           # 허들(장애물)
    │   │   ├── GoldKey.h/cpp          # 황금 열쇠 아이템
    │   │   │
    │   │   ├── Boss.h/cpp             # 보스 맵 배경
    │   │   ├── BossHuddle.h/cpp       # 보스맵 장애물
    │   │   ├── BossLayser.h/cpp       # 보스 레이저 공격
    │   │   ├── Layser.h/cpp           # 레이저 객체
    │   │   ├── LayserBlock.h/cpp      # 레이저 차단 블록
    │   │   │
    │   │   ├── SpriteGo.h/cpp         # 스프라이트 게임 오브젝트
    │   │   ├── TextGo.h/cpp           # 텍스트 게임 오브젝트
    │   │   ├── Grid.h/cpp             # 그리드 시스템 (맵 에디터용)
    │   │   ├── Button.h/cpp           # UI 버튼
    │   │   ├── ButtonSprite.h/cpp     # 스프라이트 버튼
    │   │   ├── InputText.h/cpp        # 텍스트 입력 UI
    │   │   ├── ChangeMapUI.h/cpp      # 맵 전환 애니메이션 UI
    │   │   └── InteractiveViewer.h/cpp # 상호작용 뷰어
    │   │
    │   ├── Effect/                    # ✨ 이펙트 시스템
    │   │   ├── Effect.h/cpp           # 이펙트 베이스 클래스
    │   │   ├── MoveEffect.h/cpp       # 이동 이펙트
    │   │   ├── HitEffect.h/cpp        # 피격 이펙트
    │   │   └── KickEffect.h/cpp       # 킥 이펙트
    │   │
    │   ├── Sound.h/cpp                # 사운드 객체
    │   └── ChangeMapUI.h              # 맵 변경 UI 헤더
    │   
    └── hell_taker-bin/                # 🚀 빌드된 실행 파일 디렉토리
```

---

### 🗂️ 개요

- **인원**: 1인
- **프로젝트명**: HellTaker 모작
- **장르**: 소코반(Sokoban) 기반 퍼즐
- **개발툴 / 라이브러리**: C++, SFML
- **기간**: 2025-07 ~ 2025-07 ( 2주 )

---

### 🎮 게임소개

- 원작 HellTaker의 “턴 기반 이동 + 상자 밀기” 감성을 목표로 한 모작 프로젝트입니다.
- 제한된 이동 횟수 안에서 퍼즐을 해결하며 스테이지를 클리어합니다.

---

<table align="center">
<tr>
<td align="center" width="50%">
   <img width="400" height="557" alt="Image" src="https://github.com/user-attachments/assets/0ec275cb-00d5-4ca5-bad4-4d8e1608716a" />
  <br>
  <sub>게임 메인화면/플레이 예시</sub>
</td>
<td align="center" width="50%">
 <img width="400" height="557" alt="Image" src="https://github.com/user-attachments/assets/b3e8edb9-2552-4841-a9c2-8173bd5918ad" />
  <br>
  <sub>개발/테스트 화면 예시</sub>
</td>
</tr>
</table>

---

### ★ 구현 파트

- **맵 툴(맵 에디터) 구현**
  - 스테이지를 제작/수정할 수 있는 맵 툴을 구현했습니다.
  - 제작한 맵 데이터를 파일로 저장하고, 게임에서 불러와 스테이지로 구성할 수 있도록 했습니다.
  - 맵 데이터에는 **타일 배치 정보**와 함께 **스테이지별 이동 제한 횟수(턴 제한)** 같은 플레이 규칙 데이터도 포함되도록 구성했습니다.

- **2차원 배열 기반 충돌/상호작용 처리**
  - 맵을 **2차원 배열(그리드)** 로 관리하고, 각 칸의 타일/오브젝트 상태를 값으로 표현했습니다.
  - 플레이어 이동 시 목표 좌표를 먼저 검사하여
    - 벽/장애물 충돌
    - 이동 가능/불가능 판정
    을 그리드 단위로 처리했습니다.
  - 실제 좌표 이동은 그리드 좌표를 기준으로 동작하도록 구현해 퍼즐 규칙을 명확하게 유지했습니다.

- **Lerp를 활용한 부드러운 이동 표현**
  - 소코반 특성상 논리 이동은 “칸 단위(턴 단위)”로 처리하되,
  - 화면에서 캐릭터/오브젝트 이동은 `Lerp` 보간을 사용해 **부드럽게 이동하는 연출**을 적용했습니다.
  - 입력 1회(1턴)마다 “시작 위치 → 목표 타일 위치”로 이동 목표를 잡고, 일정 시간 동안 보간하여 자연스러운 움직임이 보이도록 구현했습니다.

---

### 🏗️ 구현 화면 예시

<table align="center">
<tr>
<td align="center">
  <img src="https://github.com/user-attachments/assets/8d96315e-50c4-42d4-b892-2a312ced5847" height="400"/><br>
  <sub>NPC 상호작용</sub>
</td>
<td align="center">
  <img src="https://github.com/user-attachments/assets/22b2869a-25c6-4a22-acd6-7c6fb8746bb0" height="400"/><br>
  <sub>장애물 상호작용</sub>
</td>
</tr>
<tr>
<td align="center">
  <img src="https://github.com/user-attachments/assets/af8a9337-d686-4cf9-b906-cf09397252ce" height="400"/><br>
  <sub>스테이지 데이터 로드</sub>
</td>
<td align="center">
  <img src="https://github.com/user-attachments/assets/abbaffe2-adc4-426d-b07c-625fb9fd2cfd" height="400"/><br>
  <sub>맵 툴</sub>
</td>
</tr>
</table>
