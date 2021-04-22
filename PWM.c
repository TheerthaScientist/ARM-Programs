/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link:                                                                                */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include <lpc17xx.h>
//Delay fuction [creates time delay using for loop]
void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<60000;j++);
}
#define SBIT_CNTEN  0
#define SBIT_PWMEN  2
#define RBIT_PWMTCR  1
#define SBIT_PWMENA1  9
#define PWM_1  0
int main(void)
{
	int dutyCycle;
	SystemInit();
	LPC_PINCON->PINSEL4=(1<<PWM_1);
LPC_PWM1->TCR=(1<<SBIT_CNTEN)|(1<<SBIT_PWMEN);
LPC_PWM1->PR=0x00;
LPC_PWM1->MCR=(1<<RBIT_PWMTCR);
LPC_PWM1->MR0=100;
LPC_PWM1->MR1=100;	
LPC_PWM1->PCR=(1<<SBIT_PWMENA1);	
while(1)
{
	for(dutyCycle=0;dutyCycle<100;dutyCycle++)
	{
		LPC_PWM1->MR1=dutyCycle;
		delay_ms(5);
	}
	for(dutyCycle=100;dutyCycle>0;dutyCycle--)
	{
	LPC_PWM1->MR1=dutyCycle;
		delay_ms(5);
	}
}
}