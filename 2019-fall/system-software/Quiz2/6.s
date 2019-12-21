// IMUL 제거 1796 -> 1646 싸이클
// RESTORE_NEW_TASK 부분의 BLKMOV 제거 1646 -> 1514 싸이클
// SAVE_CURR_TASK 부분의 BLKMOV 제거, IH_ENTRY 부분으로 옮김 1514 -> 1358 싸이클
// JMP SWITCH_TASK 제거 1358 -> 1354 싸이클

// v08
// 입력: 2, 1 --> 출력: 1, 3
// 싸이클: 1514
		
	ORG	0
INIT:
	LD	A, P_IH_ENTRY
	MOV	IH, A

	LD	A, P_TCB_CTX
	MOV	B, A
	CLR	X
	LDCTX	@%0	
	IRET		
	COB		// will not come back here
			
P_IH_ENTRY	BOX	IH_ENTRY	

IO_BRIDGE	EQU	0	
PIC_IRR	EQU	96	
PIC_ISR	EQU	97	
PIC_CMD	EQU	98	
PIC_IMR	EQU	99	
			
// Commands for PIC(Programmerble Interrupt Handler)			
PIC_MASKON	BOX	100	
PIC_MASKOFF	BOX	200	
PIC_MASKSET	BOX	300	
PIC_ICL	BOX	997	
PIC_ICE	BOX	998	
PIC_EOI	BOX	999	

P_TCB_START	BOX	_TCB_START	
P_TCB_CTX	BOX	_TCB_CTX	
P_TCB_VISIBLE	BOX	_TCB_VISIBLE	// TCB 중 visible register의 저장이 시작된 곳
TCB_LENGTH	BOX	_TCB_LENGTH_	

_TCB_START:			
TCB0	BOX	0	// State - 0:Ready, 1:Wating, -1:Finished
_TCB_CTX:			
TCB0_PC	BOX	CPU_BOUND_TASK	// REC_ADD
TCB0_PSR	BOX	0,0,CPU_BOUND_TASK/1000	
TCB0_SP	BOX	U(3000)	// User Stack for Task 0: ~~ 2999
_TCB_VISIBLE:			
TCB0_D3	BOX	0	// TID(Task 식별자)로 사용(편의상 D3에 고정하고 D3는 다른 용도로는 사용하지 않음)
TCB0_OTHER_REG	RESBOX	8	// D2,D1,D0,C,B,RTN,X,A
_TCB_LENGTH_	EQU	$-TCB0
_CTX_SIZE	EQU	_TCB_VISIBLE - _TCB_CTX	
TCB1	BOX	0	// State - 0:Ready, 1:Wating, -1:Finished
TCB1_PC	BOX	CPU_BOUND_TASK	// REC_ADD
TCB1_PSR	BOX	0,0,CPU_BOUND_TASK/1000	
TCB1_SP	BOX	U(4000)	// User Stack for Task 1: ~~ 3999
TCB1_D3	BOX	1	// TID(Task 식별자)로 사용(편의상 D3에 고정하고 D3는 다른 용도로는 사용하지 않음)
TCB1_OTHER_REG	RESBOX	8	// D2,D1,D0,C,B,R,X,A

S_STACK_BTM	BOX	U(2000)	// 시스템 스택:  ~~ 1999
CONTEXT_FLAG	RESBOX	1	// Starting addr of visible registers of the current task

TCB_LENGTH_TABLE:
  BOX 0
  BOX _TCB_LENGTH_

TCB_VISIBLE_BTM:
	BOX	_TCB_VISIBLE + 9
	BOX	_TCB_VISIBLE + _TCB_LENGTH_ + 9

// 인터럽트 핸들러			
	ORG	200	// 100~199번지는 IO 주소와 매창되어 있으므로 코드가 들어가지 않도록 주의해야 함
IH_ENTRY:			// PC, ST, PSR are saved in iRTN, iST, iPSR
SAVE_CURR_TASK:
	SWAP	A, SP
	SWAP	X, D3
	LD	A, @TCB_VISIBLE_BTM
	SWAP	A, SP
	SWAP	X, D3
	PUSHALL

SAVE_CURR_TASK2:
	SWAP	A, SP
	ST	A, CONTEXT_FLAG
	MOV B, A
	STCTX @%(-_CTX_SIZE)

	LD	A, S_STACK_BTM
	SWAP	A, SP

	// 인터럽트의 원인을 알아냄		
	CLR	C
	MOV	X, EX	// 먼저 EX 레지스터의 값을 읽어서 Exception 또는 SW Trap이 발생했는지를 확인
	CMP	X, C
	SKZ		// if EX is zero
	JMP	HANDLE_EXCEPTION	
	IN	PIC_ISR	// Exception이나 SW Trap이 아니면 어떤 장치가 인터럽트를 걸었는지 확인
	MOV	X, A	// PIC의 ISR 레지스터에는 인터럽트를 건 장치의 IRQ 값이 저장되어 있음
	JMP	*@IRQ_JUMP_TABLE

IH_EOIRTN:			
	LD	A, PIC_EOI	
	OUT	PIC_CMD	
IH_RTN:			
	LD	A, CONTEXT_FLAG	
	MOV	SP, A	// 스택에서 visible 레지스터가 저장된 곳 위에 있는 값은 SP를 조정하여 일괄로 무시한다.
	POPALL		// restore context info
	IRET		// restore PC, ST, PSR from iRTN, iST, iPSR
			
HANDLE_EXCEPTION:			
	CLR	EX	
	JMP	*@EXCEPTION_JUMP_TABLE	
			
IRQ_JUMP_TABLE:			
	BOX	IH_EOIRTN	// IRQ 0
	BOX	IH_EOIRTN	// IRQ 1
	BOX	IH_EOIRTN	// IRQ 2
	BOX	IH_EOIRTN	// IRQ 3
	BOX	IH_EOIRTN	// IRQ 4
	BOX	IH_EOIRTN	// IRQ 5
	BOX	IH_EOIRTN	// IRQ 6
	BOX	IH_EOIRTN	// IRQ 7
	BOX	IH_EOIRTN	// IRQ 8
	BOX	IH_EOIRTN	// IRQ 9
			
EXCEPTION_JUMP_TABLE:			
	BOX	IH_RTN	// EX 0
	BOX	TRAP1_YIELD	// EX 1: SWITCH_TASK between TID 0 & TID 1
	BOX	TRAP2_FINISH	// EX 2: Finish Task
	BOX	TRAP3_IDLE	// EX 3: goto IDLE
	BOX	TRAP4_IN	// EX 4: IN 0
	BOX	TRAP5_OUT	// EX 5: OUT 0
	BOX	IH_RTN	// EX 6
	BOX	IH_RTN	// EX 7
	BOX	IH_RTN	// EX 8
	BOX	IH_RTN	// EX 9
	// Exception number 범위 끝까지 …		
			
OTHER_TASK:			
	BOX	1	// 0 --> 1
	BOX	0	// 1--> 0
			
TRAP1_YIELD:			
	MOV	X, D3	// D3: current task
	LD	A, @OTHER_TASK	
	MOV	D2, A	// D2: new task
	LD	A, P_TCB_START	
	MOV	D1, A

    // my code
    MOV X, D2
    LD A, @TCB_LENGTH_TABLE

	//LD	A, TCB_LENGTH
	//IMUL	A, D2	// D2: index for new task
	
    ADD	D1, A	// D1: Addr for State of the task
	MOV	A, *D1	// new task의 상태를 읽는다
	CLR	C
	CMP	A, C
	SKZ		// new task의 상태가 0(Ready) 이면 SWITCH_TASK를 수행
	JMP	IH_RTN	// 0(Ready)이 아니면 1(Waiting) 또는 -1(Finished)이므로 switch하지 않고 리턴

SWITCH_TASK:
	// Stack에 중단된 task의 visible register가 있음		
	// D2: a new Task, D3: the current Task					
	//LD	A, CONTEXT_FLAG
	//MOV	D0, A	// D0: Source: on Stack

RESTORE_NEW_TASK:
    LD A, P_TCB_VISIBLE
    MOV D1, A
    MOV X, D2
    LD A, @TCB_LENGTH_TABLE
    ADD D1, A
    MOV B, D1
			
	CLR	X	
	LDCTX	@%(-_CTX_SIZE)	// Resotre iRTN, iPSR, iSP from TCB
	//BLKMOV	@*D0, @*D1	// Block copy from D1 to D0 (C: counter)

	MOV A, D1
	ST A, CONTEXT_FLAG

	JMP	IH_RTN
			
TRAP2_FINISH:			
	LD	A, P_TCB_START	
	MOV	D1, A	

    MOV X, D3
    LD A, @TCB_LENGTH_TABLE

	//LD	A, TCB_LENGTH
	//IMUL	A, D3	// D3: index for the current task
	ADD	D1, A	// D1: Addr for State of the current task
	CLR	A	
	DEC	A	// A= -1
	MOV	*D1, A	// set state to -1(Finished)
	JMP	TRAP1_YIELD	// 본인의 상태를 -1(Finished)로 세팅한 후 CPU를 양보(YIELD)
			
TRAP3_IDLE:			
IDLE_TASK:			
	COB		
	JMP	IDLE_TASK	
			
TRAP4_IN:			
	IN	IO_BRIDGE	
	ST	A, *D1	// D1이 매개변수 역할을 한다.
	JMP	IH_RTN	
			
TRAP5_OUT:			
	LD	A, *D1	// D1이 매개변수 역할을 한다.
	OUT	IO_BRIDGE	
	JMP	IH_RTN	
			
			
////////// User Program //////////			
	ORG	500	// 100~199번지는 IO 주소와 매창되어 있으므로 코드가 들어가지 않도록 주의해야 함
CPU_BOUND_TASK:			
	// SP는 OS가 TCB를 초기화할 때 설정한다.		
	CLR	B	// LD B, #0
	DEC	SP	// room for return value of MAIN
	SETRTN	NEAR RTN0	// CALL MAIN
	PUSH	RTN	
	JMP	MAIN	
RTN0:			
	INT	2	// Finish
	INT	3	// Goto Idle! 위 INT 2 에서 이 곳으로 리턴 했다는 것은 다른 task의 상태가 Ready가 아니어서 SWITCH_TASK 하지 못한 것임
	COB		// 여기까지 오게된 것은 잘못된 상황임
			
MAIN:			
	PUSH	B	
	MOV	B, SP	
	PUSHALL		// save visible registers
	DEC	SP	// room for return value of F_RECADD
	IN	IO_BRIDGE	
	PUSH	A	// pass parameter, (n)
	SETRTN	NEAR RTN1	// CALL F_RECADD
	PUSH	RTN	
	JMP	F_RECADD	
RTN1	INC	SP	// remove used arguments
	POP	A	// get return value
	OUT	IO_BRIDGE	
	POPALL		// restore visible registers
	MOV	SP, B	
	POP	B	
	POP	RTN	// RETURN
	JMP	*RTN	
			
F_RECADD:			
	PUSH	B	// PUSH B
	MOV	B, SP	// MOV B SP
	DEC	SP	// room for local variable
	PUSHALL		// save visible registers
	LD	A, %2	// get parameter
	CLR	C	
	CMP	A, C	// if (n==0)
	SKZ		
	JMP	ELSE	
	LD	A, #0	// return 0;
	ST	A, %3	// put return value
	POPALL		// restore visible registers
	MOV	SP, B	
	POP	B	
	POP	RTN	// RETURN
	JMP	*RTN	
ELSE:			
	DEC	SP	// room for return value of F_RECADD
	INT	1	// Yield - Task가 교체된다.
	LD	A, %2	// get n
	DEC	A	// n-1
	PUSH	A	// pass parameter
	SETRTN	NEAR RTN2	// CALL F_RECADD
	PUSH	RTN	
	JMP	F_RECADD	
RTN2	INC	SP	// remove used arguments
	POP	A	// get return value, recadd(n-1)
	ADD	A, %2	// recadd(n-1) + n
	ST	A, %-1	// r = …
	LD	A, %-1	// return r;
	ST	A, %3	// put return value
	POPALL		// restore visible registers
	MOV	SP, B	
	POP	B	
	POP	RTN	// RETURN
	JMP	*RTN	