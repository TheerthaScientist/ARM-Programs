/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link:                                                                                */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include<lpc17xx.h>
//Delay fuction [creates time delay using for loop]
void delay_ms(unsigned int ms)
{
unsigned int i,j;
for(i=0;i<ms;i++)
for(j=0;j<40000;j++);
}
int main()
{
SystemInit();
LPC_GPIO0->FIODIR = 0x000001f7;
while(1)
{
LPC_GPIO0->FIOSET = 0x00000004;
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000100;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x000001e1;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000090;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x000000c0;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000061;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000042;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000002;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x000001e0;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000000;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000040;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000020;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000003;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000112;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000081;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000012;
delay_ms(200);
LPC_GPIO0->FIOCLR = 0x000001f3;
LPC_GPIO0->FIOSET = 0x00000032;
delay_ms(200);
}
}



