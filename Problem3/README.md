# **Inject ME!!!**

![01](https://github.com/idong00/ReversingStudy/assets/55074166/a322f244-d2f1-4224-82be-c9abaed6c0eb)
### Link : https://dreamhack.io/wargame/challenges/119
### Tools : x64dbg, PEview

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
    ![02](https://github.com/idong00/ReversingStudy/assets/55074166/3aac741b-838f-4cdc-bcdf-32df8271c373)

### 2. 정적 분석 진행
  - #### .rdata 섹션에서 의심스러운 문자열("dreamhack.exe") 확인
    ![03](https://github.com/idong00/ReversingStudy/assets/55074166/8a6228f4-7c06-4498-b993-3970851a582b)
  - #### TargetName을 dreamhack으로 변경
    ![04](https://github.com/idong00/ReversingStudy/assets/55074166/05da93e2-502d-47b9-8bea-87db6560a64a)

### 3. 결과
  - #### 정답 출력
    ![05](https://github.com/idong00/ReversingStudy/assets/55074166/01ee09e2-2a89-4439-9ab1-6092892965e9)

### 4. 회고
  - #### 처음 dll 파일을 C++ 코드로 로드했을 때 성공을 반환한 것에 힌트를 얻어 바로 PEview를 확인했어야 했으나 동적분석을 진행하였음. 이는 의미없는 행위였고, 뒤늦게 DllMain에서 조건처리가 있을 것이라 생각하였음.
