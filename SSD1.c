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
unsigned int ssd[]={0x00000100,0x000001E1,0x00000090,0x000000C0,
	                  0x00000061,0x00000042,0x00000002,0x000001E0,
	                  0x00000000,0x00000040,0x00000020,0x00000003,
                    0x00000112,0x00000081,0x00000012,0x00000032};
unsigned int k;

//Delay fuction [creates time delay using for loop]
void delay(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<50000;j++);
}

int main(void)
{
	SystemInit();
	LPC_GPIO0->FIODIR = 0x000001F7;
	LPC_GPIO0->FIOSET = 0x00000004;
	while(1)
	{
		for(k=0;k<16;k++)
		{
			LPC_GPIO0->FIOCLR = 0x000001F3;
			LPC_GPIO0->FIOSET = ssd[k];
			delay(200);
		}
	}
}
			