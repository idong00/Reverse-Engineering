# **rev-basic-5**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/19
### Tools : x64dbg, Visual Studio

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘.
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인.
    ![03](Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인
    ![04](Image/04.PNG?raw=true)

  - #### [rsp](루프 카운트)를 rax에 저장. [rsp+20](입력한 문자열)을 rcx에 저장. 문자를 한 개씩 추출하기 위해 [rcx+rax] 위치에서 1바이트 참조하여 eax에 저장. 다시 [rsp](루프 카운트)를 ecx에 저장하고 1 증가. [rsp+20]을 rdx에 저장하고, [rdx+rcx] 위치에서 1바이트 참조하여 ecx에 저장. eax와 ecx를 더해서 eax에 저장. 정리하면 입력한 문자열에서 현재 루프 카운트(인덱스) 위치에 있는 문자와 현재 루프 카운트(인덱스) + 1 위치의 문자 총 2개를 추출하여 더함.
    ![05](Image/05.PNG?raw=true)

  - #### [rsp](루프 카운트)를 rcx에 저장. 0x7FF685633000을 rdx에 저장. [rdx+rcx] 위치에서 1바이트 참조하여 ecx에 저장. eax와 ecx를 비교하여 성공 시 총 0x18번 이를 반복하고, 실패 시 리턴.
    ![06](Image/06.PNG?raw=true)
    ![07](Image/07.PNG?raw=true)

  - #### C++ 코드 작성. 문자열을 찾을 때 앞에서 부터 찾는 경우 고려해야할 부분이 많아 뒤에서 부터 확인. 먼저 알고리즘이 현재 인덱스와 현재 인덱스 + 1 위치에 있는 문자를 참조하기 때문에 오버 플로우를 고려하여 문자 개수가 0x17개라는 것을 추론할 수 있음. 그러므로 인덱스 22(0x4C) 위치를 기준으로 22 인덱스 문자와 23 인덱스 문자를 더하면 0x4C가 되어야 하고, 23 인덱스는 '\0'이므로 22 인덱스는 0x4C라는 것을 알 수 있음.
    ![08](Image/08.PNG?raw=true)

  - #### 실행결과
    ![09](Image/09.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![10](Image/10.PNG?raw=true)
