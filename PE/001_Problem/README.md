# **rev-basic-0**

![01](Image/01.PNG?row=true)
### Link : https://dreamhack.io/wargame/challenges/14
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](Image/02.PNG?row=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](Image/03.PNG?row=true)

  - #### "Test" 문자열과 "Compar3_the_str1ng" 문자열을 비교하는 로직 확인. strcmp 함수 실패. ZF 0
    ![04](Image/04.PNG?row=true)
    ![05](Image/05.PNG?row=true)

  - #### [rsp + 20], eax에 0 세팅 후 리턴
    ![06](Image/06.PNG?row=true)

  - #### test 명령어를 수행하여 ZF 1 세팅
    ![07](Image/07.PNG?row=true)

  - #### Wrong 출력
    ![08](Image/08.PNG?row=true)
    ![09](Image/09.PNG?row=true)

  - #### "Compar3_the_str1ng" 입력 시 eax에 1이 세팅되어 test 명령어 수행 시 ZF 0 세팅
    ![10](Image/10.PNG?row=true)

### 3. 결과
  - #### Correct 출력
    ![11](Image/11.PNG?row=true)
