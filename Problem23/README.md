# **ptrace_block**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/1197
### Tools : HxD, Visual Studio, IDA Freeware

# **Solution Process**
### 1. 실행파일 및 텍스트 파일 확인
  - #### ELF 파일과 해석할 수 없는 문자가 쓰여진 텍스트 파일이 문제로 주어짐.
    ![02](Image/02.PNG?raw=true)
    ![03](Image/03.PNG?raw=true)

### 2. 정적 분석
  - #### scanf 함수를 호출하여 rbp+var_510에 입력한 문자열을 저장하고, 입력한 문자열 주소, 암호화 결과를 저정할 주소, 크기(0x100)을 파라미터로 전달하여 sub_13F1 호출.
    ![04](Image/04.PNG?raw=true)

  - #### sub_13F1 함수에서 암호화 수행.
    - #### rax에 rbp+var_120(키 세팅 결과)를 저장. esi에 0x80(128) 저장. rdi에 byte_4010(키) 저장 후 AES_set_encrypt_key 호출.
      ![05](Image/05.PNG?raw=true)
      ![06](Image/06.PNG?raw=true)

    - #### rdx에 [rbp+var_134](0x100) 저장. rcx에 rbp+var_120(키 세팅 결과) 저장. rsi에 [rbp+var_130](입력한 문자열) 저장. r9에 암호모드 저장. r8에 IV 저장. rdi에 암호화 결과 저장 후 AES_cbc_encrypt 호출.
      ![07](Image/07.PNG?raw=true)

  - #### "out.txt" 파일 오픈 후 0x100 크기만큼 암호화 결과 저장.
    ![08](Image/08.PNG?raw=true)

  - #### C/C++ 코드를 작성하여 플래그를 추출하였으나 정상적이지 않은 문자열이 출력. 테스트 코드를 작성하여 로직은 이상이 없는 것으로 확인. 키에 문제가 있을 것이라는 생각이 들어 byte_4010이 참조되는 곳을 확인해보니 수정하는 로직이 존재하였음. sub_12C9, sub_1392 총 2개의 함수에서 이를 수정하고, _init_array에 함수 주소가 저장되어 있음. (_init_array는 실행 시 순차적으로 함수 호출)
    ![09](Image/09.PNG?raw=true)
      - #### sub_12C9 함수에서 4096번 순회하며 PTRACE_TRACEME 를 파라미터로 받아 ptrace 함수를 호출하여 결과를 v1에 저장. v1 * v2 * rand() 결과를 v2에 저장. 루프 종료 후 다시 (byte_4010 길이 - 1)번 순회하여 byte_4010[j + 1] += byte_4010[j] + v2를 수행. PTRACE_TRACEME는 디버거에 의해 실행 중이면 -1을 반환하고, 실행 중이 아닌 경우 0을 반환. 정상실행이라는 가정하에 0을 반환할 것이고, 이는 첫 번째 루프틑 의미 없으며 두 번째 루프의 v2 또한 무시.
        ![10](Image/10.PNG?raw=true)
      - #### sub_1392 함수에서 v3에 rand() 값을 저장 후 byte_4010 길이 만큼 순회하여 byte_4010[i] ^= v3 수행.
        ![11](Image/11.PNG?raw=true)

  - #### 결과적으로 sub_1392 함수 v3 변수에 저장되는 rand() 값에 따라 byte_4010(키)의 결과가 달라지고 있음. rand() 함수는 0 ~ 32767 범위의 값을 반환하므로 Brute Force를 수행하여 플래그 추출.  
    ![12](Image/12.PNG?raw=true)

### 3. 결과
  - #### 플래그 출력.
    ![13](Image/13.PNG?raw=true)
