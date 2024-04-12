# **Easy_KeygenMe**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : Visual Studio, PE-bear, IDA Freeware

# **Solution Process**
### 1. 텍스트 및 실행 파일 동작 확인
  - #### ReadMe.txt, Easy_KeygenMe.exe 파일이 주어짐. ReadMe.txt 파일에서 Serial 번호 확인. 실행 파일을 실행하여 Input Name에 임의의 문자열("Test") 입력 후 Input Serial에 Serial ("5B134977135E7D13")를 입력 시 프로그램 종료. 올바른 Input Name을 입력 시 정답을 도출할 것이라 추측.
    ![02](Image/02.PNG?raw=true)
    ![03](Image/03.PNG?raw=true)

### 2. 동적 분석 진행
  - #### Input Name 문자열을 입력 받은 후 ebp(입력한 문자열 인덱스), esi(변환에 사용될 데이터 배열 인덱스)를 0으로 초기화.
    ![04](Image/04.PNG?raw=true)

  - #### esi는 0x19FE04(변환에 사용될 배열) 배열에 접근하기 위한 인덱스로써 루프마다 1씩 증가하며 3인 경우 다시 0 저장. esp+13Ch+var_130은 변환에 사용될 배열이고, esp+13Ch+var_12C는 입력한 문자열. 매 루프마다 esi(변환에 사용될 배열 인덱스), ebp(입력한 문자열 인덱스)로 접근하며 문자를 하나씩 추출. 추출한 두 문자를 xor 연산하여 0x19FE6C(Buffer)에 저장.
    ![05](Image/05.PNG?raw=true)
    ![06](Image/06.PNG?raw=true)
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)

  - #### 변환 후 Serial 입력.
    ![10](Image/10.PNG?raw=true)

  - #### Serial과 변환된 문자열을 한 루프에 [eax], [esi]를 1바이트 참조하여 비교 후 [eax+1], [esi+1]를 1바이트 참조하여 비교. 두 조건이 모두 만족하는 경우 eax와 esi를 2씩 증가. 이를 값이 0이 나올 때까지 반복.
    ![11](Image/11.PNG?raw=true)

  - #### Serial과 변환된 문자열이 모두 같은 경우 Correct! 출력.
    ![12](Image/12.PNG?raw=true)

  - #### 분석한 코드를 역으로 연산환 결과.
    ![13](Image/13.PNG?raw=true)

### 3. 결과
  - #### Correct! 출력.
    ![14](Image/14.PNG?raw=true)