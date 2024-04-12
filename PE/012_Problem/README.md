# **rev-basic-7**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/21
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘.
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인.
    ![03](Image/03.PNG?raw=true)

  - #### 문자열 비교를 위한 로직 확인.
    ![04](Image/04.PNG?raw=true)

  - #### 매 루프마다 루프 카운트를 1씩 증가하여 [rsp]에 저장. 
    ![05](Image/05.PNG?raw=true)

  - #### [rsp](루프 카운트)를 eax에 저장하고, 0x07과 and 연산 수행. [rsp](루프 카운트)를 ecx에 저장하고, ecx를 [rsp+8]에 저장. [rsp+20](입력한 문자열)을 rdx에 저장. al을 ecx에 저장. [rsp+8](루프 카운트)을 rax에 저장하고, [rdx+rax] 위치에서 1바이트 참조(입력한 문자열 맨 앞부터 문자 한 개씩 추출)하여 eax에 저장. al을 cl번 만큼 Left Roation 연산을 수행하여 al에 저장. eax를 [rsp](루프 카운트)와 xor 연산 수행.
    ![06](Image/06.PNG?raw=true)

  - #### [rsp](루프 카운트)를 rcx에 저장. 0x7FF62AC33000를 rdx에 저장. [rdx+rcx] 위치에서 1바이트 참조하여 ecx에 저장. eax와 ecx를 비교하여 성공 시 총 0x1F번 반복하고, 실패 시 리턴.
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)

  - #### C++ 코드 작성 및 실행 결과
    ![09](Image/09.PNG?raw=true)
    ![10](Image/10.PNG?raw=true)
    
### 3. 결과
  - #### Correct 출력
    ![11](Image/11.PNG?raw=true)
