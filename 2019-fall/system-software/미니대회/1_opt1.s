// Optimized
// 430 싸이클

    LD A, P_DATA
    MOV B, A
    LD A, C_START
    ADD B, A

TERM_LOOP:
    SWAP SP, X
    LD A, TERM_COUNT
    MOV X, A
    INC A
    ST A, TERM_COUNT
    LD A, @TERM1
    ADD C, A
    SWAP SP, X
COUNT_LOOP:
    CMP C, X
    SKP
    JMP END_COUNT_LOOP

    LD A, @%0

    SWAP SP, X
    SHL A, 2
    SHR A, 3
    MOV X, A
    LD A, @GROUP_TABLE
    MOV X, A

    JMP *@JUMP_TABLE // 3
JUMP_TABLE:
    BOX INC_GROUP_0
    BOX INC_GROUP_1
    BOX INC_GROUP_2
INC_GROUP_0:
    INC D0 // 1
    JMP RET1 // 1
INC_GROUP_1:
    INC D1
    JMP RET1
INC_GROUP_2:
    INC D2
    JMP RET1
    
RET1:
    SWAP SP, X
    INC X
    JMP COUNT_LOOP

END_COUNT_LOOP:
    // 현재 마지막 TERM을 세는지 확인
    LD A, TERM_COUNT
    MOV SP, A
    LD A, #4
    CMP A, SP
    SKP
    JMP END_TERM_LOOP

OUTPUT:
    MOV A, D0
    OUT
    MOV A, D1
    OUT
    MOV A, D2
    OUT

    JMP TERM_LOOP

END_TERM_LOOP:
    LD A, #5
    OUT
    COB



GROUP_TABLE:
    BOX 1
    BOX 0
    BOX 0
    BOX 2
    BOX 1
    BOX 1
    BOX 1
    BOX 2
    BOX 2
    BOX 0

GROUP_COUNT:
    BOX 0, 0, 0

TERM_COUNT:
    BOX 0

    ORG 500
C_START BOX 1
N_DATA  RESBOX 1
TERM1   BOX 1
TERM2   BOX 1
TERM3   BOX 1
TERM4   BOX 1

COUNT:
COUNT0  RESBOX 1
COUNT1  RESBOX 1
COUNT2  RESBOX 1

P_DATA BOX DATA

    ORG 9000
DATA    BOX 0123 // 2 -> GROUP 0
        BOX 0122 // 2 -> GROUP 0
        BOX 1234 // 3 -> GROUP 2
        BOX 1235 // 3 -> GROUP 2
        BOX 1236 // 3 -> GROUP 2
        BOX 1237
        BOX 1238
        BOX 1239
        BOX 1240
        BOX 1251
        BOX 1262
        BOX 1273
        BOX 1284
        BOX 1295
        BOX 1306
        BOX 1417
        BOX 1528
        BOX 1639
        BOX 1740
        BOX 1851
        BOX 2962
        BOX 3073
        BOX 4184
        BOX 5295
        BOX 6306