/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link: https://github.com/TheerthaScientist/ARM-Programs                              */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip

#include <lpc17xx.h>
//#include "stdutils.h"
#include<LiquidCrystal.h>
unsigned int c;
unsigned char recdata;
int main()
{
	int i=0;
char a[]="hello world\r";
	Lcd_Begin();

  LPC_SC->PCONP |=0X00000008;
   LPC_PINCON->PINSEL0=0X00000050;
   LPC_UART0->LCR=0X83;
   LPC_UART0->DLL=0XA2;
   LPC_UART0->DLM=0X00;
   LPC_UART0->LCR=0X03;
   LPC_UART0->FCR=0X07;
	Lcd_WriteString(a);
	 delay(100000);

while(1)
{
while((LPC_UART0->LSR & 0X20)==0X20)
{
for(i=0;i<=a[i];i++)
LPC_UART0->THR=a[i];

   }
  }
}

