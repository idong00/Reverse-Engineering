# **2048 Revenge**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/922
### Tools : PE-bear, IDA Freeware, Visual Studio

# **Solution Process**
### 1. 실행파일 동작 확인
  - #### 실행파일 실행 시 20 X 20 크기의 그리드가 그려져 있고, 숫자가 적혀 있음. W/A/S/D 키 입력 시 숫자 및 숫자 위치 변경. 
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석
  - #### string을 분석하여 "Correct!", "Fail!" 확인. "Correct!" 문자열을 참조하는 위치 확인. 
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)

  - #### CheckGameClear 함수 분석.
    - #### unk_7FF6DCF345E0 배열에 저장되어 있는 데이터를 rbp+0C0h+var_140 배열에 복사.
      ![05](Image/05.PNG?raw=true)

    - #### 이중 for 문으로 작성된 로직 확인. 첫 번째, 두 번째 루프 모두 최대 루프 카운트 6.
      ![06](Image/06.PNG?raw=true)

    - #### 이중 for문을 순회하며 dword_7FF6DCF39CE0 배열과 rbp+0C0h+var_140 배열을 LoopCount1 * 6 + LoopCount2 값으로 접근(8바이트 참조)하여 값을 비교. 모두 같은 경우 "Correct!" 출력. 다른 경우 "Fail!" 출력. (dword_7FF6DCF39CE0 배열은 아래에서 자세히 설명)
      ![07](Image/07.PNG?raw=true)

  - #### CheckGameClear 함수를 호출하는 CheckGameResult 함수 분석.
    - #### 디컴파일 결과.
      ![08](Image/08.PNG?raw=true)
    
    - #### qword_7FF6DCF39040 변수를 확인한 결과 최초 시작 시점을 제외하면 변경점이 없어 (*(_DWORD *)qword_7FF6DCF39040 != 36) 조건을 무시하도록 로직 수정.
      ![09](Image/09.PNG?raw=true)
      
    - #### 36자의 플래그를 입력하여 동적할당 메모리에 저장. 이후 루프를 순회하며 함수 포인터를 계산 후 void (__fastcall *)(const char *, __int64, __int64, void *) 타입의 함수를 총 36번 호출.
      ![10](Image/10.PNG?raw=true)

    - #### CheckGameClear 호출.
      ![11](Image/11.PNG?raw=true)
  
  - #### CheckGameResult 함수를 호출하는 CheckGameState 함수 분석.
    - #### 20 X 20 크기의 그리드를 한 칸씩 순회하며 한 칸이라도 0x1000000000 값인 경우 CheckGameResult 호출.
      ![12](Image/12.PNG?raw=true)

    - #### 조건을 제거하여 CheckGameResult를 호출하도록 수정.
      ![13](Image/13.PNG?raw=true)

  - #### CheckGameState 함수를 호출하는 sub_7FF7E631358A 함수 분석.
    - #### getch() 함수를 호출하여 키 입력을 받고, W/A/S/D 입력 시 KeyDownW/KeyDownA/KeyDownS/KeyDownD 함수 호출. 각각의 함수는 내부에서 Map 배열의 데이터 값을 변경하고 있으나 결과에 영향을 주지 않음.
      ![14](Image/14.PNG?raw=true)

### 3. 동적 분석
  - #### CheckGameResult 함수에서 함수 포인터를 계산하여 총 36번 호출하는 로직을 확인하기 위해 임의의 36자 문자열("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") 입력.
    ![15](Image/15.PNG?raw=true)

  - #### 36개의 함수 분석 결과 Function01 ~ Function09 내부에 로직 존재. Function10 ~ Function36 비어있는 함수. dword_7FF6DCF39CE0 배열은 Function09에서 변경.
    ![16](Image/16.PNG?raw=true)
    ![17](Image/17.PNG?raw=true)

### 4. C/C++ 코드 작성
  - ### 분석을 통해 Function01 ~ Function09 함수의 로직을 역으로 연산하는 코드 작성.
    ![18](Image/18.PNG?raw=true)

### 5. 결과
  - #### "Correct!" 출력.
    ![19](Image/19.PNG?raw=true)
