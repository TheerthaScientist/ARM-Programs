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
	for(j=0;j<90000;j++);
}

//defining  some constants
#define SBIT_CNTEN 0
#define SBIT_PWMEN 2
#define SBIT_PWMMROR 1
#define SBIT_PWMENA3 11
#define PWM_3  4

//main function to run DC motor
int main(void)
{
	int dutyCycle;
	SystemInit();
	LPC_PINCON->PINSEL4=(1<<PWM_3);
	LPC_PWM1->TCR=(1<<SBIT_CNTEN)|(1<<SBIT_PWMEN);
	LPC_PWM1->PR=0x00;
	LPC_PWM1->MCR=(1<<SBIT_PWMMROR);
	LPC_PWM1->MR0=100;
	LPC_PWM1->PCR=(1<<SBIT_PWMENA3);
	
	//infinite loop
	while(1)
	{
		//increasing speed [0% to 100%]
		for(dutyCycle=0;dutyCycle<100;dutyCycle++)
		{
			LPC_PWM1->MR3=dutyCycle;
			delay_ms(5);
		}
		delay_ms(500);
		//decreasing speed [100% to 0%]
		for(dutyCycle=100;dutyCycle>0;dutyCycle--)
		{
			LPC_PWM1->MR3=dutyCycle;
			delay_ms(5);
		}
		delay_ms(500);
	}
}