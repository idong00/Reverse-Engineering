# **Secure Mail**

![01](https://github.com/idong00/ReversingStudy/assets/55074166/27549fc5-89cc-489d-a826-303db14f7889)
### Link : https://dreamhack.io/wargame/challenges/92
### Tools : Visual Studio Code

# **Solution Process**
### 1. html 파일 동작 확인
  - #### 임의로 6자리 숫자를 입력했을 때 Wrong 출력 확인
    ![02](https://github.com/idong00/ReversingStudy/assets/55074166/4866d859-8955-451c-bd7d-c686b9772762)
    
### 2. 정적 분석 진행
  - #### html 로직에서 confirm 버튼 클릭 시 _0x9a220 함수가 호출되는 것을 확인
    ![03](https://github.com/idong00/ReversingStudy/assets/55074166/97570e13-c188-40f7-aef3-319260f84db8)
  - #### 코드를 읽어보다가 너무 어려워서 전부 대입하기로 결정
  - #### 먼저 html 파일을 Visual Studio Code로 오픈하여 알람을 뜨지 않게 수정
    - 변경 전
      ```html
      return alert('Wrong')
      ```
    - 변경 후
      ```html
      return false
      ```
  - #### 대입 코드 작성
    ![04](https://github.com/idong00/ReversingStudy/assets/55074166/78d1a6ce-f6f5-4ded-83d5-84b09c2a12d1)
    
### 3. 결과
  ![05](https://github.com/idong00/ReversingStudy/assets/55074166/7cf13152-38dd-4ba9-9490-8232903d21ad)
    
### 4. 회고
  - html 언어 공부의 필요성을 느낌
