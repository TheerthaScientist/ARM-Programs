	;alp to find sum of ten integers
	AREA RESET,DATA,READONLY
	AREA PROGRAM1,CODE
		NUM1 EQU 3
		NUM2 EQU 2
			//EXPORT sumten
 ENTRY
sumten

     mov r1,#10
	 mov r2,#0

loop
      add r2,r2,r1
	  subs r1,#0x01
	  bne loop
	  
	  bx lr
	  end