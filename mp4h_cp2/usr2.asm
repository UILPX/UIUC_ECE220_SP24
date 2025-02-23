	.ORIG	x3000
	
TASK0_START

	LEA	R0, TASK1_START
	LD	R1, TASK1_SP
	TRAP	xFE ; SPAWN
	
TASK0_LOOP
	
	;;; IMPLEMENT ME ;;;;

	; LOAD R0 with TASK0_ACC and increment it by one 

	; LOAD R0 with SHARED_ACC and increment it by one 
	
	BR	TASK0_LOOP

TASK1_SP
	.FILL	x4100

TASK1_START
TASK1_LOOP
	
	;;; IMPLEMENT ME ;;;;

	
	; LOAD R0 with TASK1_ACC and increment it by one 

	; LOAD R0 with SHARED_ACC and increment it by one 
	
	BR	TASK1_LOOP

TASK0_ACC
	.FILL	#0

TASK1_ACC
	.FILL	#0

SHARED_ACC
	.FILL	#0

	.END
	
