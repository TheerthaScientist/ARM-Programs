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

#define switchPinNumber 11
#define LedPinNumber 19
#define Led1PinNumber 20
int main (void)
{
uint32_t switchStatus;
LPC_GPIO1->FIODIR=0X07f80000;
LPC_GPIO1->FIOCLR=0X07f80000;
LPC_GPIO2->FIODIR=0X00000000;
while(1)
{
switchStatus=(LPC_GPIO2->FIOPIN>>switchPinNumber)& 0x01;
if(switchStatus==1)
{
LPC_GPIO1->FIOPIN=(1<<LedPinNumber);
LPC_GPIO1->FIOPIN=(0<<LedPinNumber);
}
else
{
LPC_GPIO1->FIOPIN=(0<<LedPinNumber);
LPC_GPIO1->FIOPIN=(1<<LedPinNumber);
}
}
}