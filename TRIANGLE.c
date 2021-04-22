/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link: https://github.com/TheerthaScientist/ARM-Programs                              */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include<lpc17xx.h>
uint32_t result=0x00000040,val;
int main()
{
SystemInit();
LPC_PINCON->PINSEL1|=0X02<<20;
while(1)
{
while(1)
{
result=result+128;
val=result&0x0001FFC0;
LPC_DAC->DACR=val;
if(val>=0x0000FFC0)
{
break;
}
}
while(1)
{
result=result-128;
val=result&0x0001FFC0;
LPC_DAC->DACR=val;
if(val<=0x00000040)
{
break;
}
}
}
}



