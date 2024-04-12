# **rev-basic-1**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/15
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](Image/03.PNG?raw=true)

  - #### [rsp+08]에서 오프셋을 0부터 1씩 증가시키며 특정 문자와 비교연산 수행하는 로직 확인. 비교에 실패한 경우 리턴
    ![04](Image/04.PNG?raw=true)
    ![05](Image/05.PNG?raw=true)

  - #### Wrong 출력
    ![06](Image/06.PNG?raw=true)
    ![07](Image/07.PNG?raw=true)

  - #### "Compar3_the_ch4ract3r" 입력 시 eax에 1이 세팅되어 test 명령어 수행 시 ZF 0 세팅
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)

### 3. 결과
  - #### Correct 출력
    ![10](Image/10.PNG?raw=true)
