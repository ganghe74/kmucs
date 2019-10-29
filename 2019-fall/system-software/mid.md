# 중간고사

12:10 ~ 14:10 예정이었으나 서버문제로 인해 20분 연장됨, ~ 14:50까지 진행되었음.

QUIZ 15분, 나머지 라이브코딩

------
## ECAMPUS QUIZ

5지선다, T/F, 주관식

1. 정수를 2의 보수로 표현할때의 특징이 아닌 것은?
2. TMP RESBOX 2는 TMP 번지를 2로 초기화 하는 것이다.
3. Stack 구조에서 정상으로 초기화된 SP는 항상 그 stack의 top을 가리킨다.
4. Little Man은 실제 그 CPU의 ALU와 같은 것이다.
5. Little Man은 hand counter가 가리키는 mailbox에서 값을 읽고 실행하는데 무조건 명령으로만 인식한다.
6. LMC 프로그램 끝에 COB 명령이 생략되어도 데이터가 나타나면 Little Man은 실행을 멈춘다.
7. ORG 90은 assembly code의 주소를 90으로 하고 이 곳부터 주소를 계산해 나간다는 LMC 명령어로 Little Man은 이를 실행한다.
8. MAR, MDR은 CPU의 control unit에 속한 visible register 이므로 프로그램에서 직접 활용할 수 있다.
9. LDA *@40 명령을 실행한 후 A register의 값은? (메모리 주어짐)
10. Direct addressing의 반대가 되는 것은 relative addressing인데 PC relative와 Base register addressing 2가지가 있다
11. SEEMMMMM 형식에서 +0.00001X^10 ~ +0.00003X^10 사이에는 1개의 숫자가 더 표현된다. 그렇다면 SEEEMMMM 형식에서 +0.0001X^10 ~ +0.0003X10^10 사이에는 몇 개의 숫자가 더 표현되겠는가?
12. 모든 주소가 relative addressing mode로만 되어 있다면 그 프로그램은 어느 곳에 탑재(load) 되어도 그대로 실행할 수 있다.
------
## 라이브코딩

명령어 정의 / 코드 채우기

전체를 코딩하는 문제는 없었고, 일부 코드를 채워넣는 문제들이었음.\
핵심적인 뼈대 코드가 모두 주어져서 난이도는 쉬웠음.

1. LXA 명령어 정의 (메모리에 연속되어있는 HI, LO 2개 값을 X, A에 로드)
2. CALL 명령어 정의 (PUSHRTN + JMP)
3. LDA *@ ? 이런식의 2중 Addressing 명령어 정의
4. Table을 이용한 Switch 문 구현하기
5. Stack을 이용한 함수호출 구현하기
6. 크기 20 배열이 주어지고, 변수 MAX를 입력받아 MAX번째 원소까지의 배열의 합 구하기
7. MAIN 함수에서 수 3개를 입력받고 지역변수로 저장, 각 수들의 포인터를 다른 함수에 전달, 세 수의 합을 RETURN
8. DATA, TABLE 배열이 있음. cnt, filter 를 입력받아서 DATA 배열에