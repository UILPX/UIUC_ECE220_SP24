;partners:yzhua2,aaronw9
;This assembly language program for the LC-3 architecture 
;implements a stack calculator capable of evaluating postfix 
;expressions entered by the user, performing operations such 
;as addition, subtraction, multiplication, division, and 
;power, while ensuring proper handling of spaces and signaling 
;invalid expressions.
;
;
.ORIG x3000

;your code goes here

;R0 ASCII value entered

USERINPUT
	GETC				;Getuser inputs
	OUT				;echo inputs
	JSR	EVALUATE
	BR	USERINPUT

INVALID
	LEA	R0,INVALID_STRING	;output invalid string
	PUTS

DONE	HALT				;Program Halt

INVALID_STRING	.STRINGZ "Invalid Expression"

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R2- destination register
;R3- value to print in hexadecimal
;R4- bit counter
;R6- counter for bits in hex

PRINT_HEX
	AND	R6,R6,#0
	ADD	R6,R6,#4
	AND	R5,R5,#0
	ADD	R5,R5,R3

EXTRACT
	AND	R2,R2,#0	;clear destiniation register R2
	AND	R4,R4,#0	;clear bit counter R4
	ADD	R4,R4,#4	;initializa bit counter to 4

EXTRACT_LOOP
	ADD	R2,R2,R2	;shift R2 to make space for next bit
	ADD	R3,R3,#0	;observer the highest bit of R3
	BRzp	SHIFT		;if highest bit is 0, skip to adding 1 to R2
	ADD	R2,R2,#1	;add 1 to R2

SHIFT	ADD	R3,R3,R3	;left shift R3
	ADD	R4,R4,#-1	;decrement bit counter
	BRp	EXTRACT_LOOP	;if there are still more bits, loop back

	ADD	R0,R2,#-9	;compare digit with 9
	BRnz	PRINT_NUMERICAL	;if difit is 0-9, go to PRINT_NUMERICAL
	LD	R0,A		;else, load ASCII value of "A"
	ADD	R0,R0,R2	;R0 <- R2+'A'
	ADD	R0,R0,#-10	;R0 <- R0-10
	BRnzp	DIG_LOOP_DONE	;use OUT trap

PRINT_NUMERICAL
	LD	R0,ZERO		;load ASCII value of '0'
	ADD	R0,R0,R2	;R0 <- R2+'0'

DIG_LOOP_DONE
	OUT			;use OUT trap
	ADD	R6,R6,#-1
	BRp	EXTRACT
	BR	DONE

A		.FILL x41
ZERO		.FILL x30

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R3 - Number out to print
;R6 - current numerical output
;
;
EVALUATE
	LD	R1,NEG_EQUAL		;Check if input is equal,if not, go to next
	ADD	R1,R1,R0
	BRnp	SPACE

	LD	R5, STACK_TOP 		;Check if there is exactly 1 result on the stack
	ADD	R5, R5, #1
	LD	R6, STACK_START
	NOT	R6, R6
	ADD	R6, R6, #1
	ADD	R5, R5, R6 
	BRnp	INVALID			;if there is not 1 value is stack, print invalid
	JSR	POP
	AND	R5,R5,R5
	BRp	INVALID
	AND	R3,R3,#0
	ADD	R3,R3,R0
	BR	PRINT_HEX		;if there is only one valuse is stack, print that one

SPACE
	LD	R1,NEG_SPACE		;check if input is space,if not go next
	ADD	R1,R1,R0
	BRnp	NUMBER			;if space, go back to user input
	BR	USERINPUT

NUMBER
	LD	R1,NEG_ZERO		;check if the input is number, if not go next
	ADD	R1,R1,R0		;if number, store the value to stack
	BRn	CHECK_OP
	ADD	R1,R1,#-9
	BRp	CHECK_OP
	LD	R1,NEG_ZERO
	ADD	R0,R0,R1
	JSR	PUSH			;push the value to stack
	BR	USERINPUT		;go back to wait for next input

;the following code is similar, check if it is the operator.Go to the next operator if it 
;is not. if it is, check if there is two number in the stack. go to invalid if there is no
;two number. If there is exactly two number, do the operator, push the value, and go get
;next user input.

CHECK_OP
	AND	R3,R3,#0		
	AND	R4,R4,#0

	LD	R6,NEG_PLUS
	ADD	R2,R0,R6
	BRnp	ISMIN
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R4,R0,R4
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R3,R0,R3
	JSR	PLUS
	JSR	PUSH
	BR	USERINPUT

ISMIN
	LD	R6,NEG_MIN
	ADD	R2,R0,R6
	BRnp	ISMUL
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R4,R0,R4
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R3,R0,R3
	JSR	MIN
	JSR	PUSH
	BR	USERINPUT

ISMUL
	LD	R6,NEG_MUL
	ADD	R2,R0,R6
	BRnp	ISDIV
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R4,R0,R4
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R3,R0,R3
	JSR	MUL
	JSR	PUSH
	BR	USERINPUT

ISDIV
	LD	R6,NEG_DIV
	ADD	R2,R0,R6
	BRnp	ISEXP
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R4,R0,R4
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R3,R0,R3
	JSR	DIV
	JSR	PUSH
	BR	USERINPUT

ISEXP
	LD	R6,NEG_EXP
	ADD	R2,R0,R6
	BRnp	INVALID
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R4,R0,R4
	JSR	POP
	ADD	R5,R5,#0
	BRp	INVALID
	ADD	R3,R0,R3
	JSR	EXP
	JSR	PUSH
	BR	USERINPUT

;these are negetive value of ASCII to check the input.

NEG_EQUAL	.FILL	xFFC3
NEG_SPACE	.FILL	xFFE0
NEG_ZERO	.FILL	xFFD0


NEG_PLUS	.FILL #-43
NEG_MIN		.FILL #-45
NEG_MUL		.FILL #-42
NEG_DIV		.FILL #-47
NEG_EXP		.FILL #-94


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
	ADD	R0,R3,R4
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
	NOT	R4,R4				;not R4 using 2's complement and perform add
	ADD	R4,R4,#1
	ADD	R0,R3,R4
	RET
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
	AND	R0,R0,#0			;Subroutine for Multiplication
	AND	R5,R5,#0			;Use as a counter for the multiplication
	ADD	R5,R5,R4
	BRzp	#3
	NOT	R5,R5
	ADD	R5,R5,#1
	BRz	#3				;Prevent the user input x*0 
	ADD	R0,R0,R3
	ADD	R5,R5,#-1
	BRp	#-3
	ADD	R4,R4,#0
	BRzp	#2
	NOT	R0,R0
	ADD	R0,R0,#1
	RET
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
	AND	R0,R0,#0
	NOT	R5,R4
	ADD	R5,R5,#1
	ADD	R3,R3,R5
	BRn	#2			;Stop when R3 is negatvie
	ADD	R0,R0,#1
	BRnzp	#-4
	RET
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
	AND	R4,R4,R4
	BRnp	NOT_ZERO
	AND	R0,R0,#0		;if R4 is zero, return 1
	ADD	R0,R0,#1
	BR	RETU

NOT_ZERO
	ADD	R4,R4,#-1
	BRnp	NOT_ONE			;if R4 is one, return R3
	AND	R0,R0,#0
	ADD	R0,R0,R3
	BR	RETU

NOT_ONE
	AND	R6,R6,#0		;loop to perform exponent
	AND	R0,R0,#0
	ADD	R0,R0,R3
EXPO
	ADD	R6,R6,R3
	ADD	R6,R6,#-1
	AND	R1,R1,#0
	ADD	R1,R1,R0
MULT
	ADD	R0,R0,R1
	ADD	R6,R6,#-1
	BRp	MULT
	ADD	R4,R4,#-1
	BRp	EXPO
RETU	RET	


;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET

POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

.END
