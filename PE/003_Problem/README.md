# **Inject ME!!!**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/119
### Tools : x64dbg, PEview, Visual Studio

# **Solution Process**
### 1. dll 파일 동작 확인
  - #### dll을 로드하기 위해 먼저 C++ 코드 작성. 로드는 성공하였으나 정답확인 불가
  - #### 로드에 성공하면 DllMain에서 특정 조건 만족 시 정답을 보여줄 것이라 추측
    ```cpp
    int main()
    {
	      HMODULE Module = ::LoadLibrary(TEXT("prob_rev.dll"));
	      if (!Module)
	      {
              std::cout << "Failed..";
	      }
	      else
	      {
              std::cout << "Succeded!!";
	      }

	      return 0;
    }
    ```
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석 진행
  - #### .rdata 섹션에서 의심스러운 문자열("dreamhack.exe") 확인
    ![03](Image/03.PNG?raw=true)
  - #### TargetName을 dreamhack으로 변경
    ![04](Image/04.PNG?raw=true)

### 3. 결과
  - #### 정답 출력
    ![05](Image/05.PNG?raw=true)

### 4. 회고
  - #### 처음 dll 파일을 C++ 코드로 로드했을 때 성공을 반환한 것에 힌트를 얻어 바로 PEview를 확인했어야 했으나 동적분석을 진행하였음. 이는 의미없는 행위였고, 뒤늦게 DllMain에서 조건처리가 있을 것이라 생각하였음.
