# **CSHOP**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : PE-bear, dnSpy

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 아무것도 표시되지 않는 윈도우 출력.
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석
  - #### PE-bear를 활용하여 PE 구조 파악. 32비트이고, .NET header 크기가 0이 아니므로 C#으로 작성된 프로그램으로 확인.
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)

  - #### dnSpy를 활용하여 디컴파일 수행. Main 함수 확인. 파라미터로 FrmMain(Form) 전달하여 Application.Run() 호출.
    ![05](Image/05.PNG?raw=true)

  - #### FrmMain 생성자에서 this.InitializeComponent() 호출
    ![06](Image/06.PNG?raw=true)

  - #### InitializeComponent에서 Layer와 Button을 생성하고 데이터를 세팅하는 로직 확인. 
    ![07](Image/07.PNG?raw=true)

  - #### 버튼의 Callback 함수로 this.\uFFFD\uFFFD\uFFFD\uFFFD\uFFFD\uFFFD\uFFFD\uFFFD_Click 함수를 등록하고 있는 것을 확인. 내부에서 모든 Layer의 Text 값을 변경(초기값 " "). 버튼의 크기를 (0, 0) -> (150, 150) 변경하였으나 특정 함수와 변수에 '\\' 기호가 포함되어 있어 컴파일 에러 발생.
    ![08](Image/08.PNG?raw=true)
    ![09](Image/09.PNG?raw=true)
    ![10](Image/10.PNG?raw=true)

  - #### 함수이름, 변수이름 그리고 버튼의 크기 수정.
    ![11](Image/11.PNG?raw=true)

### 3. 결과
  - #### "P4W6RP6SES" 출력.
    ![12](Image/12.PNG?raw=true)
