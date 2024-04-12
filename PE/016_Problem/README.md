# **Kick the door**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/523
### Tools : x64dbg, Visual Studio, Visual Studio Code, PE-bear, dnSpy

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 유니티로 개발된 게임으로 스페이스바를 누르면 게임 종료. 스페이스바를 눌렀을 때 힌트가 있을 것이라 추측.
    ![02](Image/02.PNG?raw=true)

### 2. 정적 분석 진행
  - #### dnSpy를 사용하여 디컴파일 진행. PlayerController.Update 함수에서 스페이스바를 누른 경우 PlayerController.KickTheDoor 함수 호출 확인. 
    ![03](Image/03.PNG?raw=true)

  - #### PlayerController.KickTheDoor 함수에서 쿨타임이 아닌 경우 PlayerController._quitProgram 변수가 true인 경우 프로그램 종료 로직 확인. 해당 변수는 true로 초기화 되어 있고 이후에 변경 로직은 확인되지 않음. 초기화 시 false를 세팅하도록 변경 후 컴파일. 스페이스바를 누르면 프로그램이 종료되지 않으나 특별한 변화 없음.
    ![04](Image/04.PNG?raw=true)
    ![05](Image/05.PNG?raw=true)

  - #### GameManager.Start 함수에서 PlayerController.kickAction과 new Action(this.OnKickTheDoor)을 Combine하여 PlayerController.kickAction에 저장. 스페이스바를 누르면 GameManager.OnKickTheDoor 호출.
    ![06](Image/06.PNG?raw=true)

  - #### Application.streamingAssetsPath 경로에 flag 파일이 존재하는 경우 해당 파일을 읽음. 파일의 데이터를 파라미터로 받아 GameManager.CheckFlag 함수 호출 후 결과가 true인 경우 Success 씬으로 전환. GameManager.CheckFlag 함수는 CheckFlag.dll에서 exports.
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)

### 3. 동적 분석 진행
  - #### 동적 분석을 진행한 결과 Application.streamingAssetsPath 경로에 flag 파일을 생성하는 로직은 없는 것으로 확인되어 직접 해당 경로에 flag 파일을 생성.
    ![09](Image/09.PNG?raw=true)

  - #### CheckFlag 위치(0x7FFC5E1714DD) 확인.
    ![10](Image/10.PNG?raw=true)
    ![11](Image/11.PNG?raw=true)
    ![12](Image/12.PNG?raw=true)

  - #### [rsp+124]에 루프 카운트 초기화. [rbp+124](루프 카운트) rax에 저장. [rbp+rax+10](입력한 문자열 + 루프 카운트) 위치에서 1바이트 참조하여 eax에 저장. [rbp+124](루프 카운트)를 rcx에 저장 후 1증가한 값을 0x19와 and 연산 수행. [rbp+rcx+10](입력한 문자열 + ecx) 위치에서 1바이트 참조하여 eax와 xor 연산 수행. [rbp+124](루프 카운트)를 rcx에 저장. [rbp+rcx+10] 위치에서 1바이트 참조한 위치에 al 저장.
    ![13](Image/13.PNG?raw=true)

  - #### 최종적으로 연산된 문자열을 0x7FFC5E187000 위치의 데이터와 비교 연산을 수행하여 성공 시 CheckFlag 함수 true 리턴.
    ![14](Image/14.PNG?raw=true)
    ![15](Image/15.PNG?raw=true)

  - #### 0x7FFC5E187000 위치에 있는 데이터들은 연산 후의 데이터이므로 이를 역으로 연산하여 flag 파일에 저장되어야할 문자열을 추출.
    ![16](Image/16.PNG?raw=true)
    ![17](Image/17.PNG?raw=true)
    
### 4. 결과
  - #### flag 파일에 도출한 결과를 저장 후 스페이스바를 누른 결과.
    ![18](Image/18.PNG?raw=true)
    ![19](Image/19.PNG?raw=true)
