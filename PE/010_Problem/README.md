# **Easy_CrackMe**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. Dialog Box가 출력되고 입력기능이 존재. 임의의 문자열("Test") 입력 시 Message Box에 "Incorrect Passward" 출력. 실행파일을 분석하여 문제에서 원하는 Passward를 입력해야하는 것으로 확인.
    ![02](Image/02.PNG?raw=true)
    ![03](Image/03.PNG?raw=true)

### 2. 동적 분석 진행
  - #### Dialog Box를 사용하고 있어 DialogProc 함수를 확인하기로 하였음. DialogBoxParam 함수에 중단점을 설정하고, 이전 스택 프레임에서 4번째 파라미터 확인.
    ![04](Image/04.PNG?raw=true)
    ![05](Image/05.PNG?raw=true)
    ![06](Image/06.PNG?raw=true)
    
  - #### 0x401020 값을 DialogProc으로 주소로 확인. 임의의 문자열("Test") 입력 후 확인 버튼 클릭 시 0x40104E 위치로 이동.
    ![07](Image/07.PNG?raw=true)

  - #### 0x401080 함수 호출. 내부에서 GetDlgItemTextA 함수 호출 확인. 3번째 파라미터에 입력한 문자열 저장.
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)
    ![10](Image/10.PNG?raw=true)

  - #### 문자열 비교 과정
    1. #### [esp+5](입력한 문자열에서 두 번째 문자)와 61('a')를 비교
       ![11](Image/11.PNG?raw=true)
    2. #### ecx(입력한 문자열에서 세 번째 문자), 0x406078(비교할 문자열 위치), 2를 파라미터로 넘겨주고, 0x401150 호출. [ebp+C] ('5y')를 4바이트 참조하여 esi에 저장하고, edi와 1바이트 비교연산 수행. [esi-1] 1바이트 참조하여 al('y')에 저장하고, [edi-1] 1바이트 참조(입력한 문자열에서 네 번째 문자)하여 al과 비교연산 수행.
       ![12](Image/12.PNG?raw=true)
       ![13](Image/13.PNG?raw=true)
       ![14](Image/14.PNG?raw=true)
       
    3. #### 이후의 문자들은 한 루프 안에서 문자를 2개씩 비교하여 실패 시 리턴하고, 성공 시 0 값을 만날 때 까지 반복.("R3versing"에서 2개씩 끊으면 g 다음 0)
       ![15](Image/15.PNG?raw=true)
       ![16](Image/16.PNG?raw=true)
       ![17](Image/17.PNG?raw=true)

    4. #### 마지막으로 [esp+4](입력한 문자열의 첫 번째 문자)와 0x45('E')를 비교.
       ![18](Image/18.PNG?raw=true)
    
### 3. 결과
  - #### Congratulation !! 출력
    ![19](Image/19.PNG?raw=true)
