# **rev-basic-0**

![01](https://github.com/idong00/ReversingStudy/assets/55074166/35c94994-f8a7-49d1-8dc4-de0a79cbbc6b)
### Link : https://dreamhack.io/wargame/challenges/14
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 "Input : " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘
    ![02](https://github.com/idong00/ReversingStudy/assets/55074166/a6b51bb0-3f01-438b-88f3-17746512b5b6)

### 2. 동적 분석 진행
  - #### __stdio_common_vfscanf 함수 호출 확인. 임의의 문자열("Test")을 입력하여 입력 이후의 플로우 확인
    ![03](https://github.com/idong00/ReversingStudy/assets/55074166/21176c72-438d-4bf4-b069-a0e54f3d7645)

  - #### "Test" 문자열과 "Compar3_the_str1ng" 문자열을 비교하는 로직 확인. strcmp 함수 실패. ZF 0
    ![04](https://github.com/idong00/ReversingStudy/assets/55074166/0cf40f73-2364-4211-b8ac-71f1c6cff592)
    ![05](https://github.com/idong00/ReversingStudy/assets/55074166/2357e538-7ad6-4e82-b48f-e3eae171e7d3)

  - #### [rsp + 20], eax에 0 세팅 후 리턴
    ![06](https://github.com/idong00/ReversingStudy/assets/55074166/d0656389-13c9-4890-a666-d95d4c3038cb)

  - #### test 명령어를 수행하여 ZF 1 세팅
    ![07](https://github.com/idong00/ReversingStudy/assets/55074166/09ba37a9-59c1-4810-a927-cec497ae35eb)

  - #### Wrong 출력
    ![08](https://github.com/idong00/ReversingStudy/assets/55074166/11e80406-b22d-42f9-8aeb-b6d7e37d83bc)
    ![09](https://github.com/idong00/ReversingStudy/assets/55074166/96970702-2da0-4805-b3fc-24494c07077f)

  - #### "Compar3_the_str1ng" 입력 시 eax에 1이 세팅되어 test 명령어 수행 시 ZF 0 세팅
    ![10](https://github.com/idong00/ReversingStudy/assets/55074166/3b21a873-9993-4b44-aade-c22c646be5ac)

### 3. 결과
  - #### Correct 출력
    ![11](https://github.com/idong00/ReversingStudy/assets/55074166/54e1cc9f-d090-42e9-b4b8-e783d55b0399)
