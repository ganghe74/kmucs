    SWAP A, SP
    LD A, PIC_EOI
    OUT PIC_CMD
    CLR D3 // SEG_STATE READY
    SWAP A, SP
    IRET
    
MAIN:
	CLR X
    CLR C
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
    SHL A, 1
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
    
RET1:
    SWAP SP, X
    INC X
    JMP COUNT_LOOP

// 현재 마지막 TERM인지 확인
END_COUNT_LOOP:
	// BACKUP
    MOV SP, B
    MOV RTN, X
    
    LD A, TERM_COUNT
    MOV X, A
    LD A, #4
    CMP A, X
    SKP
    JMP END_TERM_LOOP
	
    LD A, @P_OUTPUT_TABLE
    MOV B, A
MSG_CONV:
    // COUNT-0, 100의자리
    MOV A, D0
    SHL A, 1
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0
    
    // COUNT-0, 10의자리
    LD A, #3
    ADD B, A
    MOV A, D0
    SHL A, 2
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-0, 1의자리
    LD A, #3
    ADD B, A
    MOV A, D0
    SHL A, 3
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-1, 100의자리
    LD A, #3
    ADD B, A
    MOV A, D1
    SHL A, 1
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-1, 10의자리
    LD A, #3
    ADD B, A
    MOV A, D1
    SHL A, 2
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-1, 1의자리
    LD A, #3
    ADD B, A
    MOV A, D1
    SHL A, 3
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-2, 100의자리
    LD A, #3
    ADD B, A
    MOV A, D2
    SHL A, 1
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-2, 10의자리
    LD A, #3
    ADD B, A
    MOV A, D2
    SHL A, 2
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

    // COUNT-2, 1의자리
    LD A, #3
    ADD B, A
    MOV A, D2
    SHL A, 3
    SHR A, 3
    MOV X, A
    LD A, @SEG_CONV
    ST A, %0

SEG_READY:
    LD A, #1
    CMP A, D3 // COMPARE SEG_STATE
    SKP
    COB

SEG_OUTPUT:
    MOV D3, A // SET SEG_STATE READY
	LD A, TERM_COUNT
    MOV X, A
    LD A, @P_OUTPUT_TABLE
    OUT 16
    LD A, #9
    OUT 17
    LD A, SEG_DMAWRITE
    OUT 12

// RESTORE
    MOV B, SP
    MOV X, RTN

    JMP TERM_LOOP

END_TERM_LOOP:
    MOV A, D0
    OUT
    MOV A, D1
    OUT
    MOV A, D2
    OUT

	COB
    COB
    COB

// SEG_STATE == D3
SEG_STATE BOX 0 // 0-READY, 1-USING

TERM_COUNT:
    BOX 0
    
GROUP_TABLE:
    BOX 1
    BOX 0
    BOX 0
    BOX 1
    BOX 1
    BOX 2
    BOX 0
    BOX 2
    BOX 2
    BOX 2
    
P_SEG_CONV 	 BOX	SEG_CONV
SEG_CONV:		
	BOX	0b00111111
	BOX	0b00000110
	BOX	0b01011011
	BOX	0b01001111
	BOX	0b01100110
	BOX	0b01101101
	BOX	0b01111101
	BOX	0b00000111
	BOX	0b01111111
	BOX	0b01101111

P_OUTPUT_TABLE:
	BOX 0
	BOX OUTPUT_TABLE1
    BOX OUTPUT_TABLE2
    BOX OUTPUT_TABLE3
OUTPUT_TABLE1:
    BOX 0, 0, 981
    BOX 0, 1, 981
    BOX 0, 2, 981
    BOX 0, 3, 981
    BOX 0, 4, 981
    BOX 0, 5, 981
    BOX 0, 6, 981
    BOX 0, 7, 981
    BOX 0, 8, 981
OUTPUT_TABLE2:
    BOX 0, 0, 981
    BOX 0, 1, 981
    BOX 0, 2, 981
    BOX 0, 3, 981
    BOX 0, 4, 981
    BOX 0, 5, 981
    BOX 0, 6, 981
    BOX 0, 7, 981
    BOX 0, 8, 981
OUTPUT_TABLE3:
    BOX 0, 0, 981
    BOX 0, 1, 981
    BOX 0, 2, 981
    BOX 0, 3, 981
    BOX 0, 4, 981
    BOX 0, 5, 981
    BOX 0, 6, 981
    BOX 0, 7, 981
    BOX 0, 8, 981