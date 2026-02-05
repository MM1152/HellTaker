<div align="center">

<h2>[2025] HellTaker 모작 🔥</h2>
<p>C++ / SFML 기반<br>
소코반(Sokoban) 장르 퍼즐 게임<br>
</p>

</div>

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
  <img src="" height="400"/><br>
  <sub>인게임 퍼즐 플레이</sub>
</td>
<td align="center">
  <img src="" height="400"/><br>
  <sub>오브젝트 상호작용(상자 밀기 등)</sub>
</td>
</tr>
<tr>
<td align="center">
  <img src="" height="400"/><br>
  <sub>맵 툴(에디터)</sub>
</td>
<td align="center">
  <img src="" height="400"/><br>
  <sub>스테이지 데이터 로드/플레이</sub>
</td>
</tr>
</table>
