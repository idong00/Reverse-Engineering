# **power cube**

![01](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/1185
### Tools : Visual Studio Code, HxD, IDA Freeware

# **Solution Process**
### 1. 실행 파일 확인
  - #### HxD를 사용하여 elf 파일인 것을 확인한 후 정적 분석을 진행하기로 결정. 
    ![02](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/02.PNG?raw=true)

### 2. 정적 분석 진행
  - #### main 함수 안에서 eax와 [rbp+var_38]을 0으로 초기화. loc_12BC로 이동하여 0x456BEEFCAFEBAB번 반복 시작.
    ![03](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/03.PNG?raw=true)

  - #### 루프 안에서 sub_1259 함수를 호출하면서 루프 카운트 1씩 증가.
    ![04](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/04.PNG?raw=true)

  - #### sub_1259 함수에서 qword_4010 값을 3 제곱하여 qword_4010에 저장. qword_4010 초기값은 0xDEADBEEFDEADBEEF.
    ![05](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/05.PNG?raw=true)
    ![06](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/06.PNG?raw=true)

  - #### 루프 종료 후 rdx에 rbp+var_30 저장. rdi에 0x4010(위에서 연산한 변수 주소) 저장. rdi, 8, rax를 파라메타로 받아 sha256 연산. rbp+var_30(암호한 결과 주소)을 rdi에 저장 후 sub_11A9 호출.
    ![07](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/07.PNG?raw=true)

  - #### sub_11A9 함수에서 [rbp+var_18]에 rbp+var_30(암호화 결과 주소)를 저장. [rbp+var_8]에 동적할당 메모리 저장(크기 0x41) 후 마지막 위치에 0 저장. [rbp+var_C](루프 카운트) 0 저장. loc_124D로 이동 후 0x20번 반복 시작.
    ![08](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/08.PNG?raw=true)

  - #### 매 루프 마다 동적할당 메모리[루프 카운트 * 2]에 0x4020[암호화 결과[루프 카운트] >> 4]를 저장하고, 동적할당 메모리[루프 카운트 * 2 + 1]에 0x4020[암호화 결과[루프 카운트] & 0x0F]를 저장.
    ![09](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/09.PNG?raw=true)

  - #### rdi에 format("You've waited so long.... Here's your flag!!! DH{%s}\n"), rsi에 연산 결과를 저장하여 printf 호출.
    ![10](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/10.PNG?raw=true)

  - #### C/C++을 사용하여 코드 작성 시 오버플로우로 인해 정확한 값을 출력하지 못하여 Python으로 작성.
    ![11](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/11.PNG?raw=true)  

### 3. 결과
  - #### 플래그 출력.
    ![12](https://github.com/idong00/ReversingStudy/blob/main/Problem21/Image/12.PNG?raw=true)