//$DEV SEVEN-SEGMENT-D 10 3 3

    ORG 0
INIT:
    LD A, P_IH_ENTRY
    MOV IH, A

    LD A, #1
    SHL A, 2
    MOV B, A
    LD A, #1
    MOV C, A
    LD A, SEG_BASE_IRQ1
    MOV X, A
LOOP_READY1:
    LD A, @%_SEG_STATE
    AND A, C
    SKNE
    JMP LOOP_READY1

    LD A, SEG_LIGHTALL
    ST A, @%_SEG_CMD

    JMP MAIN

P_IH_ENTRY BOX IH_ENTRY

IO_BRIDGE	EQU	0
PIC_IRR	EQU	96
PIC_ISR	EQU	97
PIC_CMD	EQU	98
PIC_IMR	EQU	99

// Commands for PIC(Programmerble Interrupt Controller)		
PIC_MASKON	BOX	100
PIC_MASKOFF	BOX	200
PIC_MASKSET	BOX	300
PIC_ICL	BOX	997
PIC_ICE	BOX	998
PIC_EOI	BOX	999

// 7 세그먼트 장치의 레지스터 주소 (IO Address)		
SEG_BASE_IRQ1	BOX	10
_SEG_DATA	EQU	0
_SEG_ADDR	EQU	1
_SEG_CMD	EQU	2
_SEG_STATE	EQU	3
_SEG_DMACMD	EQU	4
_SEG_DMAOFF	EQU	5
_SEG_DMASRC	EQU	6
_SEG_DMACNT	EQU	7

// Command for 7SEG Device		
SEG_WRITE_AA	BOX	100
SEG_LIGHT_AA	BOX	200
SEG_OFF_AA	BOX	300
SEG_READ_AA	BOX	400
SEG_WRITE	BOX	981
SEG_LIGHT	BOX	982
SEG_READ_LIGHT	BOX	983
SEG_READ	BOX	984
SEG_LIGHTALL	BOX	992
SEG_OFFALL	BOX	993
SEG_RESET	BOX	999
SEG_DMAWRITE	BOX	991

    ORG 200
// ============================
//      Interrupt Handler
//   Only for DMA Interrupt
//         SP - TEMP
//     D0, D1, D2 - COUNT
//        D3 - SEG_STATE
// ============================

IH_ENTRY:
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
    
C_START BOX 1
N_DATA  RESBOX 1
TERM1   BOX 1
TERM2   BOX 1
TERM3   BOX 1
TERM4   BOX 1
    
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