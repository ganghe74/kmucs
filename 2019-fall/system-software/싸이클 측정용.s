// 리틀맨 기본행동 - 1싸이클
    NOP
    //COB

// 레지스터 내장회로 - 1싸이클
    INC A
    SHL A, 3
    SHR A, 2
    DEC A
    NEG A
    INV A
    CLR A

// 레지스터 이동 - 1싸이클 (한 명령안에서 (CPU 내부에서) 몇번을 하든 1싸이클.)
    MOV X, A

// ALU 단순 연산 - 2싸이클
    ADD A, A
    ADD A, #1

// ALU 곱셈/나눗셈 - 11싸이클
    IMUL A, A
    IDIV A, A

// 메모리 접근 - 3싸이클 (기본행동 1 + 메모리접근 2)
    LD A, DATA
    LD A, @DATA
    LD A, P_DATA
    MOV B, A // - 1싸이클
    LD A, *B
    LD A, @*B
    LD A, %0
    LD A, @%0
    ST A, DATA

    PUSHALL // - 19싸이클 (A, X, RTN, B, C, D0, D1, D2, D3)

// 점프 - 1싸이클 (레지스터 변경)
    JMP F1
F1:
    LD A, P_F2
    JMP *A

P_F2 BOX F2
F2:
    COB

    ORG 500
P_DATA BOX DATA
DATA BOX 1234