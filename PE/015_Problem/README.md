# **rev-basic-9**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/23
### Tools : x64dbg, Visual Studio

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘.
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인.
    ![03](Image/03.PNG?raw=true)

  - #### 입력한 문자열 길이 확인.
    ![04](Image/04.PNG?raw=true)

  - #### edx가 0이기 때문에 (입력한 문자열 길이 + 1) & 0x07의 결과가 0인 경우 통과.
    ![05](Image/05.PNG?raw=true)

  - #### 7자의 문자열("TestTes") 입력 후 다시 수행. [rsp+20] 위치에 루프 카운트 0으로 초기화. [rsp+24](입력한 문자열 길이)를 eax에 저장 후 1증가. eax와 [rsp+20] 값을 비교 후 성공 시 루프 종료. 실패 시 rax에 루프 카운트를 저장하고, [rsp+40](입력한 문자열)을 rcx에 저장 후 rax를 더함. rcx를 rax에 저장 후 rax를 rcx에 저장. 0x7FF7573510A0 함수 호출. 0x7FF75735103A 위치로 이동.
    ![06](Image/06.PNG?raw=true)

  - #### 0x7FF7573510A0 함수 호출 내부 진입. 루프 진입 전 입력한 문자열에서 첫 번째 문자를 [rsp]에 저장. [rsp+8]에 루프1 카운트 저장.
    ![07](Image/07.PNG?raw=true)

  - #### 이중 for 문으로 작성된 로직 확인. 루프1은 총 0x10번 반복. 루프1 안에 루프2는 총 0x08번 반복. [rsp](최초 루프1 진입 시점의 값은 입력한 문자열의 첫 번째 문자이고, 이후의 값은 루프2 안에서 연산한 결과를 [rsp]에 저장). [rsp]를 eax에 저장. [rsp+4](루프2 카운트)를 rcx에 저장. [rsp+rcx+10](Key 문자열 + 루프2 카운트) 위치에서 1바이트 참조하여 ecx에 저장. eax와 ecx를 xor 연산. rcx에 0x7FF757354020(문자 집합)을 저장. [rcx+rax] 위치에서 1바이트 참조하여 eax에 저장. [rsp+4]를 ecx에 저장 후 1증가한 값을 0x07과 and 연산 수행. [rsp+50](입력한 문자열)을 rdx에 저장. [rdx+rcx] 위치에서 1바이트 참조하여 ecx에 저장. eax와 ecx를 더하여 eax에 저장 후 al을 5만큼 Right Rotation 수행. [rsp]에 al 저장. [rsp+4](루프2 카운트)를 eax에 저장 후 1증가한 값을 0x07과 and 연산 수행. [rsp+50](입력한 문자열)을 rcx에 저장. [rsp](변환된 문자)를 edx에 저장. [rcx+rax](입력한 문자열에서 루프2 카운트 + 1 위치. 단, 0x07 보다 큰 경우 0) 1바이트 참조한 위치에 dl 저장.
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)

  - #### 함수 리턴 후 memcmp 수행. 비교 길이는 0x19이고, 0x7FF757354000(비교할 대상)을 rdx에 저장. [rsp+40](변환된 문자열)을 rcx에 저장. 비교 성공 시 정답.
    ![10](Image/10.PNG?raw=true)
    ![11](Image/11.PNG?raw=true)

  - #### 정담을 도출하기 위해 0x7FF757354000에 저장되어 있는 데이터를 역으로 변환해서 입력해야하는 문자열을 추론해야함. 먼저 핵심 로직을 C++ 코드로 변환. 그 후 코드를 역으로 작성하여 입력한 문자열 추출.
    ![12](Image/12.PNG?raw=true)
    ![13](Image/13.PNG?raw=true)
    ![14](Image/14.PNG?raw=true)

  - #### 0x7FF757354000에 저장되어 있는 데이터를 역으로 변환한 결과.
    ![15](Image/15.PNG?raw=true)

### 3. 결과
  - #### Correct 출력
    ![16](Image/16.PNG?raw=true)
