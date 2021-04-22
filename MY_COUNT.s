'/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link: https://github.com/TheerthaScientist/ARM-Programs                              */
/*===============================================================================================*/

     ;alp to find sum of ten integers'
		AREA myData,DATA
	
COUNT EQU 10
SUM EQU 0
		AREA Mycode,CODE
		entry
	export _main

_main
	LDR r0,=COUNT
	LDR r1,=SUM
	LDR	r2,=1
	
myloop
     ADD r1,r2,r1
	 ADD r2,r2,#1
	 SUBS r4,r0,r2
	 BNE myloop
	 ADD R1,R2,R1
STOP B STOP
     END
	