# **patch**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/49
### Tools : x64dbg

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 실행 시 'DH{flag}' 형태가 그려져 있고, flag 영역이 가려져 있음. 문자열을 출력한 것이 아닌 선을 그리는 방식으로 출력된 것을 확인할 수 있음. 또한 단순 콘솔창이 아닌 WinAPI를 사용하기 때문에 그리는 처리가 WndProc 함수에 있을 것이라 추측.
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### RegisterClass 함수를 호출하는 곳을 찾아 WndProc 함수 주소를 찾음.
    ![03](Image/03.PNG?raw=true)

  - #### WndProc 함수내에서 BeginPaint, EndPaint 함수 확인. 오브젝트를 생성하기 위한 GridCreateFromHDC 함수와 오브젝트를 제거하는 GridDeleteGraphics 함수 사이에 의심스러운 0x7FF7C7292C40 함수 확인.
    ![04](Image/04.PNG?raw=true)

  - #### 0x7FF7C7292C40 함수 내부에는 0x7FF7C7292B80 함수를 일정 횟수를 반복해서 호출하고, 이후에는 매번 다른 함수를 호출하는 패턴을 보임. 함수 내부에서 GridDrawLine 함수를 호출하고 있어 특정 함수를 호출하지 않으면 가려진 부분을 확인할 수 있을 것이라 추측.
    ![05](Image/05.PNG?raw=true)
    ![06](Image/06.PNG?raw=true)

  - #### 규칙적인 부분과 불규칙적인 부분을 나누어서 생각하기로 하였음. 먼저 불규칙적인 부분을 호출하지 않기 위해 0x7FF7C7292FCC 까지만 명령을 수행하고, RIP를 리턴 지점으로 강제 이동하였음.
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)

  - #### flag를 제외한 낙서 그림만 출력되어 규칙적인 부분을 호출하지 않기로 하였음. 0x7FF7C7292C40 함수 내에서 00007FF7C7292C42까지만 명령을 수행하고, RIP를 0x7FF7C7292FD1 지점으로 강제 이동하였음.
    ![10](Image/10.PNG?raw=true)
### 3. 결과
  - #### DH{UPATCHED} 출력
    ![11](Image/11.PNG?raw=true)
