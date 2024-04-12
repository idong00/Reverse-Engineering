# **Direct3D FPS**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : IDA Freeware

# **Solution Process**
### 1. 실행 파일 확인
  - #### 실행파일 실행 시 FPS 게임이 출력되고, 이동 및 사격 기능이 있으며 몬스터들이 있음. 몬스터와 충돌 했을 때 "Game Over! You are dead" 문자열 출력.
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석
  - #### 문자열 리스트를 확인하여 "Game Clear!" 문자열 확인.
    ![03](Image/03.PNG?raw=true)

  - #### 해당 문자열을 참조하는 코드 확인.
    ![04](Image/04.PNG?raw=true)

  - #### sub_1339C0 함수에서 eax에 0x139194(첫 번째 엘레먼트에서 생존여부 플래그 위치) 저장. eax를 4바이트 참조하여 1과 비교 후 생존여부 확인. 몬스터가 죽은 경우 오프셋을 0x210씩 증가시키며 반복하고, 살아 있는 경우 루프 종료. 모든 몬스터의 플래그가 0이면 "Game Clear!" 출력.
    ![05](Image/05.PNG?raw=true)

  - #### 0x139194(첫 번째 엘레먼트에서 생존여부 플래그 위치)를 참조하는 코드 확인.
    ![06](Image/06.PNG?raw=true)

### 3. 동적 분석
  - #### sub_133400 함수 안에서 sub_133440 함수를 호출하여 탄환에 피격된 몬스터의 인덱스를 얻음. 몬스터의 인덱스와 오프셋(0x210)을 곱하여 해당 몬스터의 체력 위치를 ecx에 저장. 몬스터의 체력이 0인 경우 0x139194[ecx]에 0 세팅.
    ![07](Image/07.PNG?raw=true)

### 4. Code Patch
  - #### sub_133400 함수에서 배열을 순회하여 생존여부 플래그를 모두 0으로 수정하기로 결정. 오프셋 0x210. 몬스터 (0x13F8B4 - 0x139194) / 0x210 = 0x32마리.
    ![08](Image/08.PNG?raw=true)

  - #### IDA Patch 기능을 이용하여 Assembly 코드 작성.
    ![09](Image/09.PNG?raw=true)

### 5. 결과
  - #### "Game Clear!" 출력.
    ![10](Image/10.PNG?raw=true)
