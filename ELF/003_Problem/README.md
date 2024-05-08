# **Easy Assembly**

![01](Image/01.png?raw=true)
### Link : https://dreamhack.io/wargame/challenges/1095
### Tools : IDA Freeware, Visual Studio

# **Solution Process**
### 1. 실행파일 확인
  - #### ELF 형식의 prob 파일 존재.
    ![02](Image/02.png?raw=true)

### 2. 정적 분석
  - #### strlen 함수를 호출하여 ds:len에 입력한 문자열의 길이 저장. edi에 enc_flag, esi에 입력한 문자열 저장. ecx에 0 저장. check_password 함수를 호출하여 결과가 0인 경우 "You nailed it! You're ASM savvy, aren't ya? Good job" 출력.
    ![03](Image/03.png?raw=true)

  - #### edx에 0저장. dl에 입력한 문자열에서 1바이트 참조하여 저장. dl과 ds:len을 XOR 연산. dl과 enc_flag를 1바이트 참조한 값을 XOR 연산. ecx와 edx OR 연산. esi, edi 1씩 증가. eax(길이) 1 감소하여 0인 경우 루프 탈출.
    ![04](Image/04.png?raw=true)

### 3. C/C++ 코드 작성
  - #### 입력한 문자열을 찾기 위한 Brute Force 코드 작성.
    ![05](Image/05.png?raw=true)

### 4. 결과
  - #### "DH{UGxlYXNlIGRvIG5vdCBiYXNlNjQgZGVjb2RlIGl0Lg==}" 출력.
    ![06](Image/06.png?raw=true)
