'/*==============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link: https://github.com/TheerthaScientist/ARM-Programs                              */
/*===============================================================================================*/

;alp to find product of ten integers'
	AREA	product,CODE,READONLY
	EXPORT mult10
 ENTRY
sumten

     mov r1,#0x0a
	 mov r2,#0x01

loop
      mla r3,r2,r1;
	  subs r1,#0x01
	  bne loop
	  
	  bx lr
	  end