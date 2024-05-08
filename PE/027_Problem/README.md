# **PEPassword**

![01](Image/01.png?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : PE-bear, IDA Freeware, x32dbg, Visual Studio

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 파일 다운로드 시 "Original.exe", "Packed.exe" 2개의 실행파일 존재. "Original.exe" 실행 시 Password가 출력되지만 ??? 형식으로 가려져 있고, "Packed.exe" 실행 시 입력창이 나오지만 문자를 계속 입력하여도 특별한 변화 없음.
    ![02](Image/02.png?raw=true)
    ![03](Image/03.png?raw=true)
    ![04](Image/04.png?raw=true)

### 2. 정적 분석
  - #### "Original.exe" 파일 분석. esp+eax+0x14C+var_13C, esp+eax+0x14C+var_14C 배열에 특정 값이 저장되어 있음. dl과 cl을 XOR 연산 후 dl을 cl에 저장.  dl과 cl을 각각 esp+eax+0x14C+var_14C와 esp+eax+0x14C+var_10D 배열에 저장하는데 esp+eax+0x14C+var_10D 배열은 아래에서 esp+0x150+Text의 영역과 일부 겹쳐 Password가 ???로 변경.
    ![05](Image/05.png?raw=true)

  - #### "Packed.exe" 파일 분석. 정적 분석으로 특별한 정보를 얻을 수 없었음.
    ![06](Image/06.png?raw=true)

### 3. 동적 분석
  - #### "Packed.exe" 파일이 의심스러워 동적분석 진행. SendMessage에 중단점 설정 후 임의의 문자를 입력하여 콜 스택 확인.
    ![07](Image/07.png?raw=true)
    ![08](Image/08.png?raw=true)

  - #### SendMessage 리턴 후 0x4091D8을 호출하여 결과가 0xE98F842A인 경우 EndDialog 호출.
    ![09](Image/09.png?raw=true)

  - #### 0x4091D8 함수 내부를 C/C++ 코드로 변경하였으나 역으로 연산하는 것이 불가능하여 다른 방법 시도.
    ![10](Image/10.png?raw=true)
    ![11](Image/11.png?raw=true)

  - #### IDA를 통해 확인했었던 함수에 중단점을 설정하고, 0x4091D8 호출 후 결과 비교를 성공하도록 패치한 결과 0x409200에서 중단. 0x4091DA 함수는 위에서 호출했던 0x4091D8 함수의 일부이고, 이를 2번 호출하여 첫 번째 결과는 ebx, 두 번째 결과는 eax에 저장.
    ![12](Image/12.png?raw=true)

  - #### edi(0x00401000)은 코드 영역인데 4바이트 참조하여 XOR 연산을 수행하고 있어 코드를 복호화하는 과정이라 추론할 수 있음. 결과적으로 정확한 초기 eax, ebx 값을 아는 경우 "Original.exe" 파일과 동일한 코드를 얻을 수 있음.
    ![13](Image/13.png?raw=true)
    ![14](Image/14.png?raw=true)

#### 4. C/C++ 코드 작성
  - #### 올바른 복호화 코드를 만들기 위해 eax와 ebx 값을 찾는 로직 작성.
    ![15](Image/15.png?raw=true)

  - #### eax는 "Packed.exe" 파일과 "Original.exe" 파일의 0x00401000 위치값과 연산하면 구할 수 있고, ebx는 Brute Force를 사용하여 2개의 값을 얻을 수 있음. 이를 복호화 코드 수행 전 강제로 대입하면 정답 도출.
    ![16](Image/16.png?raw=true)

### 5. 결과
  - #### "Password is From_GHL2_!!" 출력.
    ![17](Image/17.png?raw=true)
