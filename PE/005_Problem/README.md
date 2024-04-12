# **rev-basic-6**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/20
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
    
  - #### 문자를 한 개씩 비교하기 위해 오프셋을 증가시키며 문자 한개를 추출
    ![05](Image/05.PNG?raw=true)
    ![06](Image/06.PNG?raw=true)

  - #### rcx에 0x7FF754B03020을 저장하고, rcx에 rax(입력한 문자)를 더한 위치를 1바이트만 참조하여 eax에 저장
    ![07](Image/07.PNG?raw=true)

  - #### [rsp] 값(루프 카운트)을 rcx에 저장하고, rdx에 0x7FF754B03000을 저장. rdx에 rcx를 더한 위치에서 1바이트만 참조하여 ecx에 저장 후 eax와 ecx 비교
    ![08](Image/08.PNG?raw=true)

  - #### 데이터가 많아 실수의 여지가 있어 C++ 코드로 작성.
    ![09](Image/09.PNG?raw=true)
    
  - #### C++ 코드 실행결과
    ![10](Image/10.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![11](Image/11.PNG?raw=true)