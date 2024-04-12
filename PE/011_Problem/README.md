**[wargame.kr] DLL with notepad**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/331
### Tools : x64dbg, PE-bear

# **Solution Process**
### 1. 문제의도 파악
  - #### 문제에서 주어진 링크 확인. download를 클릭하여 바이너리와 dll을 다운로드. 문자열을 입력 기능이 있음. 올바른 문자열 입력 시 정답을 알려주는 것으로 추측. 아래에는 localtime 힌트가 있음.
  ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### dll 시작지점으로 이동하기 위해 PE-bear를 사용해서 start 함수의 RAV를 알아내고, eip 값을 0x62D50000 + 0x1000(start 함수의 RVA)으로 변경.
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)
    ![05](Image/05.PNG?raw=true)

  - #### 내부에서 CreateThread 호출 확인. 세 번째 파라미터에 저장된 함수 포인터 주소(0x62D51240) 확인.
    ![06](Image/06.PNG?raw=true)

  - #### 0x62D51240 함수안에서 0x62d5125a를 호출하고, 내부에는 시간관련 함수를 사용하고 있음. 시간 관련 힌트를 주었기 때문에 0x62d5125a 내부를 분석하기로 하였음.
    ![07](Image/07.PNG?raw=true)

  - #### 첫 번째 루프. 0x625d11a1에서 esi(루프 카운트)와 eax("oh! handsome guy!" 길이)를 비교하여 성공 시 루프를 탈출. 루프 내부 동작은 "oh! handsome guy!" 문자열에서 문자를 하나씩 추출하여 연산을 취한 후 0x62d53388 + esi(루프 카운트) 위치에 연산한 문자를 저장. 총 17번 반복.
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)

  - #### 첫 번째 루프. 0x625d1221에서 esi(루프 카운트)와 eax("Air fares to NY don't come cheap." 길이)를 비교하여 성공 시 루프를 탈출. 루프 내부 동작은 "Air fares to NY don't come cheap." 문자열에서 문자를 하나씩 추출하여 연산을 취한 후 0x62d53348 + esi(루프 카운트) 위치에 연산한 문자를 저장. 총 33번 반복.
    ![10](Image/10.PNG?raw=true)
    ![11](Image/11.PNG?raw=true)

  - #### "oh! handsome guy!" 문자열에 대응되는 데이터는 "{v12|w+#422,D2B%M", "Air fares to NY don't come cheap." 문자열에 대응되는 데이터는 "M{3>34$D1b>?t*;/Rch'z,u042J<G#%:|". 이 중 "M{3>34$D1b>?t*;/Rch'z,u042J<G#%:|" 문자열을 웹 페이지에 입력 시 정답 도출.
    
### 3. 결과
  - #### DH{flag}
    ![12](Image/12.PNG?raw=true)
