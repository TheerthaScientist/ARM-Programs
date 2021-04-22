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
//Delay fuction [creates time delay using for loop]
void delay_ms(unsigned int ms)
{
unsigned int i,j;
for(i=0;i<ms;i++)
for(j=0;j<20;j++);
}
int main()
{
SystemInit();
LPC_GPIO0->FIODIR=0x04000000;
while(1)
{
LPC_GPIO0->FIOSET=0x04000000;
delay_ms(200);
LPC_GPIO0->FIOCLR=0x04000000;
delay_ms(200);
}
}