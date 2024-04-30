# **Replace**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : PE-bear, x32dbg, Visual Studio

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 입력창, 버튼 그리고 "Wrong" 문자열 출력. 임의의 문자열("123") 입력 시 프로그램 종료.
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석
  - #### Imports 항목에서 GetDlgItemInt 함수 확인. 임의의 문자열 입력 후 버튼 클릭 시 GetDlgItemInt 함수에 의해 값이 반환될 것이라 추측.
    ![03](Image/03.PNG?raw=true)

### 3. 동적 분석
  - #### GetDlgItemInt 위치에 중단점 설정 후 로직 확인.
    ![04](Image/04.PNG?raw=true)

  - #### 0x4084D0 4바이트 참조한 위치에 GetDlgItemInt 결과값 저장 후 0x40466F 호출.
    ![05](Image/05.PNG?raw=true)

  - #### 0x40467A 호출. 0x40467A 내부에서 0x404689 호출하여 0x4084D0 4바이트 참조하여 2 증가 후 리턴하여 0x4084D0 4바이트 참조한 위치에 0x601605C7 더함. 0x404689 호출. 0x404689 내부에서 0x4084D0 4바이트 참조하여 2 증가 후 리턴.
    ![06](Image/06.PNG?raw=true)
    ![07](Image/07.PNG?raw=true)

  - #### 0x404690 점프.
    ![08](Image/08.PNG?raw=true)

  - #### 0x4084D0 4바이트 참조한 값을 eax에 저장. 0x404689 호출하여 내부에서 0x4084D0 4바이트 참조하여 2 증가 후 리턴. 0x40466F 호출하여 내부에서 eax 1바이트 참조한 위치에 90 저장. 해당 로직은 크래시를 유발하여 프로그램 종료. EIP를 0x404672로 변경 후 리턴. eax 1증가 후 다시 0x40466F 호출. 마찬가지로 내부에서 eax 1바이트 참조한 위치에 90 저장. 크래시를 유발하므로 EIP 이동 후 리턴. 0x401071 점프.
    ![09](Image/09.PNG?raw=true)
    ![10](Image/10.PNG?raw=true)
    ![11](Image/11.PNG?raw=true)

  - #### 0x401071에서 0x401084 위치로 점프하기 때문에 "Correct!" 출력 불가.
    ![12](Image/12.PNG?raw=true)

  - #### 위에서 eax 1바이트 참조한 위치에 0x90을 대입하고, eax 1증가 후 다시 eax 1바이트 참조한 위치에 0x90을 대입하므로 0xEB11을 0x9090으로 변경할 경우 점프하지 않고 "Correct!"를 출력할 수 있을 것이라 판단.
    ![13](Image/13.PNG?raw=true)

### 4. C/C++ 코드 작성
  - #### 2687109798 출력.
    ![14](Image/14.PNG?raw=true)
    ![15](Image/15.PNG?raw=true)

### 5. 결과
  - #### "Correct!" 출력.
    ![16](Image/16.PNG?raw=true)
