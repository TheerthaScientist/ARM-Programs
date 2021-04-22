/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link: https://github.com/TheerthaScientist/ARM-Programs                              */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include"lpc17xx.h"
void delay();
//Delay fuction [creates time delay using for loop]
void delay()
{
	int i,j;
	for(i=0;i<0xff;i++)
	for(j=0;j<0x400;j++);
}
int main(void)
{
	char rotate=0;
	SystemInit();
	LPC_GPIO0->FIODIR |=0x00078000;
	while(1)
	{
		if(rotate==1)
		{
		LPC_GPIO0->FIOPIN=0x00008000;
			delay();
			LPC_GPIO0->FIOPIN=0x00010000;
			delay();
			LPC_GPIO0->FIOPIN=0x00020000;
			delay();
			LPC_GPIO0->FIOPIN=0x00040000;
			delay();
		}
		else
		{
			LPC_GPIO0->FIOPIN=0x00040000;
			delay();
			LPC_GPIO0->FIOPIN=0x00020000;
			delay();
			LPC_GPIO0->FIOPIN=0x00010000;
			delay();
			LPC_GPIO0->FIOPIN=0x00008000;
			delay();
		}
		if(!(LPC_GPIO2->FIOPIN & 0x00000800))
		{
			while(!(LPC_GPIO2->FIOPIN & 0x00000800));
			rotate=1;
		}
		else if(!(LPC_GPIO2->FIOPIN & 0x00001000))
		{
			while(!(LPC_GPIO2->FIOPIN & 0x00001000));
			rotate=0;
		}
	}
}
