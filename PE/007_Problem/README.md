# **rev-basic-3**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/17
### Tools : x64dbg, Visual Studio

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인
    ![04](Image/04.PNG?raw=true)
    
  - #### [rsp](루프 카운트) 값을 rax에 저장하고, 0x7FF6D8DF3000을 rcx에 저장. [rcx+rax] 위치에서 1바이트만 참조하여 eax에 저장.(비교 대상)
    ![05](Image/05.PNG?raw=true)
    ![06](Image/06.PNG?raw=true)

  - #### 매 루프마다 오프셋을 1씩 증가시키며 입력한 문자열에서 문자를 한 개씩 추출하여 ecx에 저장. ecx를 [rsp](루프 카운트)와 xor 연산을 수행하여 ecx에 저장. [rsp](루프 카운트)를 rdx에 저장 후 rcx+rdx*2 값을 ecx에 저장. eax와 ecx를 비교연산 하여 실패 시 리턴하고, 성공 시 총 0x18번 반복
    ![07](Image/07.PNG?raw=true)

  - #### C++ 코드 작성
    ![08](Image/08.PNG?raw=true)

  - #### C++ 코드 실행결과
    ![09](Image/09.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![10](Image/10.PNG?raw=true)
