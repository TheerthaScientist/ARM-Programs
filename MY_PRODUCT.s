;alp to find product of ten integers
		AREA myData,DATA
	
COUNT EQU 10
PROD EQU 1
		AREA Mycode,CODE
		entry
	export _main

_main
	LDR r0,=COUNT
	LDR r1,=PROD
	LDR	r2,=1
	
myloop
     MUL r1,r2,r1;
	 ADD r2,r2,#1
	 SUBS r4,r0,r2
	 BNE myloop
	
STOP B STOP
     END
	