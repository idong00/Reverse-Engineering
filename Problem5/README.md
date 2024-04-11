# **rev-basic-8**

![01](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/22
### Tools : x64dbg, Visual Studio

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인
    ![04](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/04.PNG?raw=true)
    
  - #### 문자를 한 개씩 비교하기 위해 오프셋을 증가시키며 문자 한개를 추출
    ![05](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/05.PNG?raw=true)
    ![06](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/06.PNG?raw=true)

  - #### eax와 0xFB를 곱하기 연산 한 후 eax에 대입하고, eax를 0xFF와 and 연산을 수행하여 1바이트 추출
    ![07](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/07.PNG?raw=true)

  - #### rdx에 0x7FF79F593000를 대입하고, rdx에 rcx를 더해준 위치를 1바이트만 참조하여 ecx에 대입 후 eax와 ecx 비교. 만약 같은 경우 [rsp]에 있는 값을 1씩 증가시키며 총 21번 반복
    ![08](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/08.PNG?raw=true)

  - #### 처음에는 계산기를 사용하여 문자를 추출. (eax(입력한 문자) * 0xFB) & 0xFF == 0x7FF79F593000 + rcx에서 eax를 알아내기 위해 계산기로 251(0xFB)씩 증가시키며 최하위 1바이트와 일치하는 값을 찾음. 그러나 실수의 여지가 있고, 21개의 문자를 찾아야하기 때문에 코드를 사용하기로 결정
    ![09](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/09.PNG?raw=true)
    ![10](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/10.PNG?raw=true)
    
  - #### 먼저 0x7FF79F593000 위치에서 문자 21개 확인
    ![11](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/11.PNG?raw=true)

  - #### C++ 코드 작성 및 실행결과
    ![12](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/12.PNG?raw=true)
    ![13](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/13.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![14](https://github.com/idong00/ReversingStudy/blob/main/Problem5/Image/14.PNG?raw=true)
