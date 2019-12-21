%% machine load v08
    ORG 0
    JMP 200

DATA1:
D1LOW BOX 0000
D1HIGH BOX 0522

DATA2:
D2LOW BOX 2500
D2HIGH BOX 0471

RESULT:
RLOW RESBOX 1
RHIGH RESBOX 1

HI1 RESBOX 1
LO1 RESBOX 1
HI2 RESBOX 1
LO2 RESBOX 1

A1 RESBOX 1
A2 RESBOX 1
A3 RESBOX 1
B1 RESBOX 1
B2 RESBOX 1
B3 RESBOX 1

// =======UNSIGNED MULTIPLY===========
UMUL:
    LD A, #0
    MOV X, A
    CMP D0, A
    SKN
    JMP ELSE
    CMP D1, A
    SKN
    JMP POS_X_NEG
    JMP NEG_X_NEG
ELSE:
    CMP D1, A
    SKN
    JMP POS_X_POS
    JMP POS_X_NEG
NEG_X_NEG:
    MOV A, D0
    IMUL A, D1
    ADD X, D0
    ADD X, D1
    JMP *RTN
POS_X_NEG:
    CMP D1, A
    SKN
    SWAP D0, D1
    CMP D0, A
    SKNE
    JMP ZERO_X_NEG
    MOV A, D0
    IMUL A, D1
    SKCA
    DEC X
    ADD X, D0
    SWAP D0, D1
    JMP *RTN
POS_X_POS:
    MOV A, D0
    IMUL A, D1
    JMP *RTN
ZERO_X_NEG:
    CLR A
    CLR X
    JMP *RTN

// ====200===
    ORG 200
    JMP FP_MUL

// ======3 BOXES ADD======
// =====INPUT: A1 ~ A3, B1 ~ B3
// =====DOING: A = A+B
// =====CAN CAUSE INCREASING C REGISTER
// =====X <= TMP=====
ADD_3:
    LD A, A3
    MOV X, A
    LD A, B3
    ADD A, X
    ST A, A3
    
    LD A, A2
    MOV X, A
    LD A, B2
    SKCA
    JMP TWO
CA_TWO:
    ADD A, X
    SKCA
    JMP CA_TWO_2
    INC A
    ST A, A2
    JMP CA_THREE
CA_TWO_2:
    ADD A, #1
    ST A, A2
    SKCA
    JMP THREE
    JMP CA_THREE
TWO:
    ADD A, X
    ST A, A2
    SKCA
    JMP THREE
    JMP CA_THREE
    
CA_THREE:
    LD A, A1
    MOV X, A
    LD A, B1
    ADD A, X
    SKCA
    JMP CA_THREE_2
    INC A
    ST A, A1
    JMP SHIFT_RIGHT
CA_THREE_2:
    ADD A, #1
    ST A, A1
    SKCA
    JMP RETURN
    JMP SHIFT_RIGHT
THREE:
    LD A, A1
    MOV X, A
    LD A, B1
    ADD A, X
    ST A, A1
    SKCA
    JMP RETURN
SHIFT_RIGHT:
    INC C
    LD A, A3
    SHR A, 1
    MOV X, A
    LD A, A2
    SHL A, 3
    ADD A, X
    ST A, A3
    
    LD A, A2
    SHR A, 1
    MOV X, A
    LD A, A1
    SHL A, 3
    ADD A, X
    ST A, A2
    
    LD A, A1
    SHR A, 1
    MOV X, A
    LD A, =1000
    ADD A, X
    ST A, A1
RETURN:
    CLR A
    ST A, B1
    ST A, B2
    ST A, B3
    JMP *RTN

// =======FLOATING POINT MULTIPLY=======
FP_MUL:
// =======SET EE======

    LD A, D1HIGH
    SHL A, 1
    SHR A, 2
    MOV C, A
    LD A, D2HIGH
    SHL A, 1
    SHR A, 2
    ADD C, A
    LD A, =50
    NEG A
    ADD C, A
// ======LOAD======
    LD A, D1HIGH
    SHL A, 3
    ST A, D0
    LD A, D1LOW
    SHR A, 1
    ADD A, D0
    ST A, HI1
    LD A, D1LOW
    SHL A, 3
    ST A, LO1

    LD A, D2HIGH
    SHL A, 3
    ST A, D0
    LD A, D2LOW
    SHR A, 1
    ADD A, D0
    ST A, HI2
    LD A, D2LOW
    SHL A, 3
    ST A, LO2
// =====MULTIPLY AND ADD=====
    CLR A
    ST A, A1
    ST A, A2
    ST A, A3
    ST A, B1
    ST A, B2
    ST A, B3
    
    LD A, LO1
    MOV D0, A
    LD A, LO2
    MOV D1, A
    SETRTN2
    JMP UMUL
    SWAP A, X
    ST A, A3
    
    LD A, LO1
    MOV D0, A
    LD A, HI2
    MOV D1, A
    SETRTN2
    JMP UMUL
    ST A, B3
    SWAP A, X
    ST A, B2
    
    SETRTN2
    JMP ADD_3
    
    LD A, LO2
    MOV D0, A
    LD A, HI1
    MOV D1, A
    SETRTN2
    JMP UMUL
    ST A, B3
    SWAP A, X
    ST A, B2
    
    SETRTN2
    JMP ADD_3
    
    LD A, HI1
    MOV D0, A
    LD A, HI2
    MOV D1, A
    SETRTN2
    JMP UMUL
    ST A, B2
    SWAP A, X
    ST A, B1
    
    SETRTN2
    JMP ADD_3
// =====NORMALIZE======
    LD A, A1
    MOV D0, A
    LD A, A2
    MOV D1, A
    LD A, A3
    MOV D2, A
    CLR X
    
LOOP:
    MOV A, D0
    SHR A, 3
    CMP A, X
    SKZ
    JMP END_LOOP
    DEC C
    MOV A, D0
    SHL A, 1
    MOV D0, A
    MOV A, D1
    SHR A, 3
    ADD D0, A
    MOV A, D1
    SHL A, 1
    MOV D1, A
    MOV A, D2
    SHR A, 3
    ADD D1, A
    MOV A, D2
    SHL A, 1
    MOV D2, A
    JMP LOOP
END_LOOP:
    MOV A, D0
    ST A, A1
    MOV A, D1
    ST A, A2
    MOV A, D2
    ST A, A3
// =========ROUND=========
    LD A, #5
    SHL A, 2
    ST A, B2
    
    SETRTN2
    JMP ADD_3
// ========STORE=======
STORE:
    MOV A, C
    SHL A, 2
    SHR A, 1
    MOV C, A
    
    LD A, D1HIGH
    SHR A, 3
    MOV X, A
    LD A, D2HIGH
    SHR A, 3
    CMP A, X
    CLR A
    SKZ
    LD A, #9
    SHL A, 3
    ADD C, A
    
    LD A, A1
    SHR A, 3
    ADD A, C
    ST A, RHIGH
    
    LD A, A1
    SHL A, 1
    MOV X, A
    LD A, A2
    SHR A, 3
    ADD A, X
    ST A, RLOW

END_FP_MUL:
    COB