/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link:                                                                                */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include "lpc17xx.h"
#include "LiquidCrystal.h"
#include<stdio.h>
#define VREF 3.3
#define ADC_CLK_EN (1<<12)
#define SEL_AD0_2 (1<<2)
#define CLKDIV 1
#define PWRUP (1<<21)
#define START_CMV (1<<24)
#define ADC_DONE (1U<<31)
#define ADCR_SETUP_SCM ((CLKDIV<<8)|PWRUP)
void Init_ADC()
{
	LPC_SC->PCONP|=ADC_CLK_EN;
	LPC_ADC->ADCR=ADCR_SETUP_SCM|SEL_AD0_2;
	LPC_PINCON->PINSEL1|=(1<<18);
}
unsigned int Read_ADC()
{
	unsigned int i=0;
	LPC_ADC->ADCR|=START_CMV;
  while((LPC_ADC->ADDR2 & ADC_DONE)==0);
	i=(LPC_ADC->ADDR2>>4)&0xFFF;
}
	void Display_ADC()
	{
		unsigned int adc_value=0;
		char buf[4]={5};
		float voltage=0.0;
		adc_value=Read_ADC();
		sprintf((char*)buf,"%3d",adc_value);
		Lcd_WriteStringLS(0,"ADCVAL=000");
		Lcd_WriteStringLS(1,"Voltage: 00v  V");
		Lcd_SetCursor(0,10);
		Lcd_WriteString(buf);
		
		voltage=(adc_value*3.3)/4095;
		Lcd_SetCursor(1,8);
		sprintf(buf,"%3.2f",voltage);
		Lcd_WriteString(buf);
	}
	int main(void)
	{
		SystemInit();
		Lcd_Begin();
		Init_ADC();
		Lcd_WriteStringLS(0,"  JSMATCH  ");
		Lcd_WriteStringLS(1,"  Technologies ");
		delay(100000000);
		Lcd_WriteStringLS(0,"ADC Value..");
		Lcd_WriteStringLS(1,"voltage.....");
		delay(100000000);
		Lcd_CmdWrite(0x01);  
		while(1)
		{
			Display_ADC();
			delay(20000000);
		}
	}