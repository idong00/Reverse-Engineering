# **rev-basic-2**

![01](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/16
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인
    ![04](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/04.PNG?raw=true)
    
  - #### [rsp](루프 카운트)를 rax에 저장. 0x7FF72CB43000을 rcx에 저장. r8에 입력한 문자를 저장하고, [r8+rdx(루프 카운트)] 위치에서 1바이트만 참조하여 edx에 저장. edx와 [rcx+rax * 4]를 비교하여 실패 시 리턴하고, 성공 시 총 0x12번 반복. rcx+rax*4에서 rcx는 0x7FF72CB43000이고, rax는 루프 카운트이므로 매 루프마다 0x7FF72CB43000 + (루프 카운트 * 4) 위치를 4바이트 참조하여 edx와 비교
    ![05](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/05.PNG?raw=true)

  - #### Max 루프 카운트가 크지 않기 때문에 메모리 상태를 확인하여 결과 도출
    ![06](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/06.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![07](https://github.com/idong00/ReversingStudy/blob/main/Problem9/Image/07.PNG?raw=true)
