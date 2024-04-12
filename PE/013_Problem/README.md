# **What is your name?**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/252
### Tools : x64dbg

# **Solution Process**
### 1. 문제에서 주어진 파일 확인
  - #### 파일을 압축해제 후 실행 파일을 실행하여 문제의 의도 파악. 실행파일은 총 11개가 있고, 실행 시 콘솔창이 잠시 출력되었다가 사라짐.(11개 모두 동일)
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### 특별한 단서를 찾지 못하여 처음부터 따라가면서 확인. 0x7FF64AF91010 함수 내부에서 0x7FF64AF91000 함수를 호출 시 ExitProcess 함수를 호출하여 프로세스 종료. 0x7FF64AF91000 함수 이후 로직에서 "index %d : " 문자열이 확인되어 0x7FF64AF91000 함수를 건너뛰고 확인하기로 하였음.
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)

  - #### RIP에 0x7FF64AF91027 저장하여 0x7FF64AF91000 함수를 강제로 건너뜀.
    ![05](Image/05.PNG?raw=true)

  - #### 0x7FF64AF910C0 함수에서 rcx("index %d : "), rdx(0x0B)에 저장된 값을 활용하여 콘솔창에 출력. 다른 실행 파일도 똑같은 플로우로 작성되어 있는데 rdx 값에 0x01 ~ 0x0B 중 하나를 저장.
    ![06](Image/06.PNG?raw=true)
    ![07](Image/07.PNG?raw=true)

  - #### [rsp+130](루프 카운트)에 0을 저장하고, [rsp+28](실행파일 이름)을 rax에 저장. 문자를 한 개씩 추출하기 위해 [rsp+130]을 rcx에 저장하고, [rax+rcx] 위치에서 1바이트 참조하여 eax에 저장. eax와 0x2E를 비교하여 성공 시 리턴, 실패 시 반복(반복되는 로직은 아래의 단계에서 설명)
    ![08](Image/08.PNG?raw=true)

  - #### [rsp+28]을 rax에 저장하고, [rsp+130](루프 카운트)을 rcx에 저장. [rax+rcx] 위치에서 1바이트 참조하여 ecx에 저장하여 문자를 한 개씩 추출. 0x7FF64AFAD000 위치에서 4바이트 참조한 값을 ecx와 더함. 0x7FF64AF92F20 함수를 호출하여 ecx 문자 출력.
    ![09](Image/09.PNG?raw=true)
    ![10](Image/10.PNG?raw=true)

  - #### 하나의 실행파일을 실행한 결과
    ![11](Image/11.PNG?raw=true)

  - #### 모든 실행파일을 위 단계를 거쳐 정답을 도출한 결과
    ![12](Image/12.PNG?raw=true)

### 3. 결과
  - #### 도출한 결과를 인덱스 순서대로 배치한 결과
    ![13](Image/13.PNG?raw=true)
