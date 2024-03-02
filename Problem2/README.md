# **rev-basic-0**

![01](https://github.com/idong00/ReversingStudy/assets/55074166/bb9b9446-a9c9-4572-abbf-8ee86315f813)
### Link : https://dreamhack.io/wargame/challenges/15
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](https://github.com/idong00/ReversingStudy/assets/55074166/0d133f55-8c96-45d4-b3cd-c39f78a700fc)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](https://github.com/idong00/ReversingStudy/assets/55074166/6b1395a3-7538-48b2-9047-a7373d7ddc11)

  - #### [rsp+08]에서 오프셋을 0부터 1씩 증가시키며 특정 문자와 비교연산 수행하는 로직 확인. 비교에 실패한 경우 리턴
    ![04](https://github.com/idong00/ReversingStudy/assets/55074166/f52a743e-56c7-4465-930e-01cb974fe3e5)
    ![05](https://github.com/idong00/ReversingStudy/assets/55074166/4a1255de-44cf-4d71-80ba-35d621b7ecfe)

  - #### Wrong 출력
    ![06](https://github.com/idong00/ReversingStudy/assets/55074166/30d86a64-fe16-4501-9c8a-6430a5b48e55)
    ![07](https://github.com/idong00/ReversingStudy/assets/55074166/b06b6ee0-1cc0-4872-8973-aae50f0d1af3)

  - #### "Compar3_the_ch4ract3r" 입력 시 eax에 1이 세팅되어 test 명령어 수행 시 ZF 0 세팅
    ![08](https://github.com/idong00/ReversingStudy/assets/55074166/960efd33-a359-466f-ba93-0fcb5dd0a75b)
    ![09](https://github.com/idong00/ReversingStudy/assets/55074166/18c47d91-2780-42d1-b54d-fa5ca9c552f4)

### 3. 결과
  - #### Correct 출력
    ![10](https://github.com/idong00/ReversingStudy/assets/55074166/4244ae21-dcd4-46bc-908b-832b1f949ea9)
