# **rev-basic-4**

![01](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/18
### Tools : x64dbg, Visual Studio

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인
    ![04](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/04.PNG?raw=true)
    
  - #### 문자를 한 개씩 비교하기 위해 오프셋을 증가시키며 문자 한 개를 추출. 첫 번째 추출 시 eax 저장하고, 우측 시프트(4비트) 연산을 수행하여 eax에 저장. 두 번째 추출 시 ecx에 저장하고, 좌측 시프트(4비트) 연산을 수행하여 ecx에 저장. ecx는 0xF0와 and 연산을 수행하여 ecx에 저장 후 eax와 ecx를 or 연산하여 eax에 저장
    ![05](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/05.PNG?raw=true)

  - #### [rsp](루프 카운트) 값을 rcx에 저장. 0x7FF6780F3000을 rdx에 저장. [rdx+rcx]를 1바이트만 참조하여 ecx에 저장 후 eax와 ecx 비교. 비교연산에 성공 시 이를 반복하고, 0x1C번 수행하면 리턴
    ![06](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/06.PNG?raw=true)

  - #### C++ 코드 작성
    ![07](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/07.PNG?raw=true)

  - #### C++ 코드 실행결과
    ![08](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/08.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![09](https://github.com/idong00/ReversingStudy/blob/main/Problem7/Image/09.PNG?raw=true)
