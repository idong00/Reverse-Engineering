# **x64 Lotto**

![01](Image/01.png?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : PE-bear, IDA Freeware

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 숫자를 입력하라는 "Input the number" 문자열 출력. 총 6개의 숫자를 요구하며 입력 시 특별한 변화 없음.
    ![02](Image/02.png?raw=true)

### 2. 정적 분석
  - #### "LOTTO" 타이틀 출력 후 wscanf_s를 호출하여 6개의 정수를 입력으로 받음. 이후 화면을 클리어 하고, 0.5초 대기. ebx에 0 세팅.
    ![03](Image/03.png?raw=true)

  - #### 랜덤값을 추출해서 연산을 취한 후 [rsp+rbx*4+0xB8+var_64] 배열에 rbx를 1부터 6까지 1씩 증가하며 연산한 값 저장.
    ![04](Image/04.png?raw=true)

  - #### 입력 받은 번호 배열과 랜덤 연산한 번호 배열을 하나씩 비교하여 6개의 숫자가 모두 같으면 통과.
    ![05](Image/05.png?raw=true)

  - #### 이 문제는 비교 대상 숫자가 랜덤한 값에서 연산한 것이기 때문에 6개의 숫자를 모두 맞출 때까지 Brute Force를 수행할 수도 있지만, 상당한 시간이 소요될 것이라 판단. 강제로 실행흐름을 변경하여 통과시키기로 함. 이후의 로직을 분석한 결과 6개의 숫자를 사용하는 연산은 수행하지 않음.

### 3. 동적 분석
  - #### ZF를 1로 변경 후 실행흐름 변경.
    ![06](Image/06.png?raw=true)
    ![07](Image/07.png?raw=true)

  - #### [rsp+0xB8+var_48] 부터 [rsp+0xB8+var_16] 까지 2 바이트 크기의 배열에 값 저장.
    ![08](Image/08.png?raw=true)

  - #### rdx는 unk_7FF61DEA3021이고, 위에서 세팅한 [rsp+0xB8+var_48] 배열에 unk_7FF61DEA3021와 연산을 취한 값을 저장.
    ![09](Image/09.png?raw=true)
    ![10](Image/10.png?raw=true)

  - #### rdx에 rsp+0xB8+var_48 저장. rsp+0xB8+var_48 위치에서 2바이트 참조하여 eax에 저장. rdx 2증가. ax와 0x0F를 xor 연산. ax에 cx 더함. ecx 1증가. ecx < 0x19 비교. 다시 rdx에서 2를 뺀 후 2바이트 참조한 위치에 ax 저장. 0x19번 반복 후 탈출.
    ![11](Image/11.png?raw=true)

  - #### "%s\n" 포멧과 [rsp+0xB8+var_48] 배열을 파라미터로 받아 출력.
    ![12](Image/12.png?raw=true)

### 4. 결과
  - #### "Password is from_GHL2_-_!" 출력.
    ![13](Image/13.png?raw=true)
