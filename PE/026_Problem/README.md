# **My_First_Game_v0.1**

![01](Image/01.png?raw=true)
### Link : https://dreamhack.io/wargame/challenges/1237
### Tools : PE-bear, IDA Freeware, Visual Studio

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 "A", "D" 키를 입력할 수 있고, 입력 시 한 축으로만 카메라 이동 가능. 이동 시 플래그를 확인할 수 있으나 플래그 방향으로 이동이 불가능하여 모든 플래그를 확인할 수 없음.
    ![02](Image/02.png?raw=true)

### 2. 동적 분석
  - #### "A" 또는 "D" 키를 입력했을 때 전역변수 0x7FF7E79C0468를 수정. 해당 변수를 사용해서 특정 축을 기준으로 이동한다는 것을 추론할 수 있음.
    ![03](Image/03.png?raw=true)

  - #### 전역변수 0x7FF7E79C0468를 참조하는 위치 확인. 0x7FF7E79C0468 값에 따라 전역변수 0x7FF7E79C0694의 값이 결정되는 것을 확인할 수 있음. 최종적으로 0x7FF7E79C0694 값이 특정 축을 기준으로 이동하는 이동량이라는 것을 추론할 수 있음.
    ![04](Image/04.png?raw=true)

  - #### "WindowsProject1.exe" 프로세스에 Dll Injection을 시도하여 D3DXMatrixTranslation 함수를 후킹 후 카메라를 이동해야겠다고 판단. 

### 3. C/C++ 코드 작성
  - #### D3DXMatrixTranslation 함수를 후킹하여 원래 함수를 호출하기 전 "W", "S" 키 입력 시 Z 축을 기준으로 이동하여 모든 플래그를 확인할 수 있도록 작성.
    ![05](Image/05.png?raw=true)
    ![06](Image/06.png?raw=true)
    ![07](Image/07.png?raw=true)
  
### 4. 결과
  - #### 모든 플래그 출력.
    ![08](Image/08.png?raw=true)
