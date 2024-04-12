# **CSharp**

![01](Image/01.PNG?raw=true)
### Link : http://reversing.kr/challenge.php
### Tools : PE-bear, dnSpy, Visual Studio

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 문자열 입력 공간과 버튼이 있고, 임의의 문자열("Test") 입력 시 "Wrong" 출력.
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석
  - #### PE-bear를 사용하여 PE 구조 확인. 32비트이고, .Net header 크기가 0이 아니므로 C#으로 작성된 프로그램으로 파악.
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)

  - #### Main 함수에서 파라미터로 Form1(Form)을 전달하여 Application.Run 호출.
    ![05](Image/05.PNG?raw=true)

  - #### Form1 생성자에서 InitializeComponent 함수를 호출하여 TextBox와 버튼 생성. 버튼의 Callback 함수로 btnCheck_Click 등록.
    ![06](Image/06.PNG?raw=true)

  - #### btnCheck_Click 함수에서 MetMetMet 함수를 호출하여 입력한 문자열을 Base64로 변경 후 method.Invoke(Line 131) 함수를 호출하여 내부에서 MetM 함수 호출. array[0] 값이 1이 아닌 경우 "Correct!!" 출력.
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)

### 3. 동적 분석
  - #### MetM 함수 내부 확인. Base64로 변환된 각각의 문자와 특정 수를 xor 연산하여 조건을 만족하지 못한 경우 array[0]에 1이 저장되어 "Wrong" 출력.
    ![09](Image/09.PNG?raw=true)

### 4. C/C++ 코드 작성
  - #### 먼저 MetM 함수 내부를 역으로 연산하여 Base64 문자열 추출.
    ![10](Image/10.PNG?raw=true)

  - #### Base64 문자열을 디코딩하여 원래 문자열 추출.
    ![11](Image/11.PNG?raw=true)
    ![12](Image/12.PNG?raw=true)

### 5. 결과
  - #### "Correct!!" 출력.
    ![13](Image/13.PNG?raw=true)
