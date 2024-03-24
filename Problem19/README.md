# **You shall not pass**

![01](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/100
### Tools : Visual Studio, PE-bear, dnSpy

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 실행 파일을 실행하여 문제의 의도 파악. 콘솔창에 flag: " 문자열이 출력되고, 임의의 문자열 입력 시 콘솔창 닫힘.
    ![02](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/02.PNG?raw=true)

### 2. 정적/동적 분석 진행
  - #### PE 구조에서 Data Directory .Net header의 값이 0이 아닌 것을 확인하여 C#으로 작성된 파일이라 판단. dnSpy를 사용하여 분석.
    ![03](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/03.PNG?raw=true)
    ![04](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/04.PNG?raw=true)
    
  - #### 먼저 "flag: " 문자열이 출력되고, 문자열 비교를 위한 함수를 호출하기 전 선처리를 위한 조건 확인. 입력한 문자열 길이가 32이고, 문자열의 시작과 끝이 각각 "DH{", "}" 이어야 함.
    ![05](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/05.PNG?raw=true)

  - #### Invoke 함수를 호출하여 내부를 따라가다 보면 UnsafeInvokeInternal 함수 내부에서 RuntimeMethodHandle.InvokeMethod 함수 호출 결과가 true인 경우 "correct! :)" 출력.
    ![06](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/06.PNG?raw=true)

  - #### RuntimeMethodHandle.InvokeMethod 함수 분석. Line 9에서 입력한 문자열을 배열로 변환. Line 12에서 변환한 배열을 0부터 31까지 순회하여 현재 문자(array[i])와 다음 문자(array[i + 1])를 xor 연산하여 현재 문자에 저장. Line 18에서 31부터 0까지 순회하여 현재 문자(array[j])와 이전 문자(array[j - 1 & 31])를 더한 값을 array2[length - j - 1 & 31]에 저장. 마지막으로 Line 23에서 array2(변환된 데이터)와 A_2(비교대상)를 비교하여 변환된 결과가 일치하는지 판단.
    ![07](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/07.PNG?raw=true)

  - #### 핵심 로직을 역으로 연산한 결과.
    ![08](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/08.PNG?raw=true)
    ![09](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/09.PNG?raw=true)
    
### 3. 결과
  - #### correct! :) 출력.
    ![10](https://github.com/idong00/ReversingStudy/blob/main/Problem19/Image/10.PNG?raw=true)
