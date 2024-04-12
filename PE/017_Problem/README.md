# **babycmp**

![01](Image/01.PNG?raw=true)
### Link : https://dreamhack.io/wargame/challenges/778
### Tools : x64dbg, Visual Studio, PE-bear

# **Solution Process**
### 1. 실행 파일 동작 확인
  - #### 문자열을 입력 공간과 버튼이 존재. 임의의 문자열("Test") 입력 시 재시도 MessageBox 출력.
    ![02](Image/02.PNG?raw=true)

### 2. 동적 분석 진행
  - #### MessageBox 출력 전 문자열 일치 여부를 확인하는 로직이 있을 것이라 판단하여 MessageBox에 중단점 설정 후 이전의 로직 확인.
    ![03](Image/03.PNG?raw=true)
    ![04](Image/04.PNG?raw=true)
    
  - #### 0x7FF604761C30 함수 호출.
    ![05](Image/05.PNG?raw=true)

  - #### 0x7FF604764F50 위치에서 2바이트 참조하여 [rbp+F]에 저장. 0x7FF604764F52 위치에서 2바이트 참조하여 [rbp+11]에 저장. r15에 입력한 문자열 길이 저장. 문자열 길이가 0x18이 아닌 경우 리턴.
    ![06](Image/06.PNG?raw=true)

  - #### 문자열 길이를 0x18에 맞춰 "aaaaaaaaaaaaaaaaaaaaaaaa" 입력. r8에 입력한 문자열 저장. rax에 "DH{" 문자열 주소 저장 후 [rcx(루프 카운트)+rax] 위치에서 1바이트 참조하여 eax에 저장. [rcx(루프 카운트)+r8] 위치에서 1바이트 참조하여 al과 비교. 성공 시 이를 0x03번 반복. 실패 시 리턴.
    ![07](Image/07.PNG?raw=true)
    ![08](Image/08.PNG?raw=true)

  - #### "DH{aaaaaaaaaaaaaaaaaaaaa" 입력. rax에 입력한 문자열 저장 후 [rax+0x17] 위치에서 1바이트 참조하여 "}"와 비교. 실패시 리턴.
    ![09](Image/09.PNG?raw=true)

  - #### "DH{aaaaaaaaaaaaaaaaaaaa}" 입력. 동적할당 받은 메모리(0x1F0D5FD4280)에 입력한 문자열 복사. 
    ![10](Image/10.PNG?raw=true)
    ![11](Image/11.PNG?raw=true)
    ![12](Image/12.PNG?raw=true)

  - #### 위 조건을 모두 통과한 경우 0x7FF604761A10 호출.
    ![13](Image/13.PNG?raw=true)

  - #### 함수 내부에서 0x60 크기의 메모리 동적할당(0x1F0D5FD2590).
    ![14](Image/14.PNG?raw=true)
    ![15](Image/15.PNG?raw=true)

  - #### 동적할당 받은 메모리(0x1F0D5FD2590)를 0으로 초기화.
    ![16](Image/16.PNG?raw=true)

  - #### 입력한 문자열을 바탕으로 총 4번 연산을 수행하여 동적할당 받은 메모리에 저장.
      - #### [r9(루프 카운트)+r8(입력한 문자열)] 위치에서 1바이트 참조하여 문자 하나 추출. 추출한 문자를 [rcx] 위치에서 4바이트 참조한 위치에 저장. [rax(입력한 문자열)+r9(루프 카운트)*4] 위치에서 4바이트 참조한 값을 4만큼 Right Rotation 수행하여 할당받은 메모리에 저장.
        ![17](Image/17.PNG?raw=true)
      
      - #### edx(초기값 0)를 eax에 저장하고, 0x80000007과 and 연산 수행. [rsp+rax+38] 위치에서 1바이트 참조하여 ecx에 저장. [r8(할당받은 메모리)] 위치에서 4바이트 참조하여 ecx와 xor 연산 수행. rsp+38("neko_hat")에서 문자를 참조하기 위해 사용하는 오프셋은 7을 넘지 않음.
        ![18](Image/18.PNG?raw=true)
        ![19](Image/19.PNG?raw=true)

      - #### edx(초기값 0)를 eax에 저장하고, 0x80000003과 and 연산 수행. [rsp+rax+38] 위치에서 1바이트 참조하여 eax에 저장. [r8(할당받은 메모리)] 위치에서 4바이트 참조한 값에 eax 더함. rsp+38("neko_hat")에서 문자를 참조하기 위해 사용하는 오프셋은 3을 넘지 않음.
        ![20](Image/20.PNG?raw=true)

      - #### 할당받은 메모리 위치에서 4바이트 참조한 값에 0x7530 더함. edx, r9 1씩 증가. edx를 rax에 저장. rax와 문자열 길이를 비교. 성공 시 리턴. 실패 시 0x18번 반복.
        ![21](Image/21.PNG?raw=true)

      - #### rcx에 0x7FF604768050(비교대상) 저장. 오프셋을 8씩 증가하며 8바이트씩 비교. 할당받은 메모리와 비교대상 메모리를 8바이트씩 비교하여 모두 일치하는 경우 정답.
        ![22](Image/22.PNG?raw=true)

  - #### 로직 검증을 위한 테스트 코드 작성.
    ![23](Image/23.PNG?raw=true)

  - #### 로직을 역으로 계산하여 입력 문자열 도출.
    ![24](Image/24.PNG?raw=true)
    ![25](Image/25.PNG?raw=true)
        
### 3. 결과
  - #### Congraturations! 출력
    ![26](Image/26.PNG?raw=true)
