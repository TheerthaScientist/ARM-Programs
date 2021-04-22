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
//header file ti include liquid crystel Display
#include<LiquidCrystal.h>

#define COL0    0
#define COL1    1
#define COL2    4
#define COL3    8

#define ROW0    9
#define ROW1    10
#define ROW2    14
#define ROW3    15

int col[] = {COL0, COL1, COL2, COL3};
int row[] = {ROW0, ROW1, ROW2, ROW3};
char c[4][4] = {{'0','4','8','C'},
								{'1','5','9','D'},
								{'2','6','A','E'},
								{'3','7','B','F'}};
int i,j,flag=0;

int main(void)
{
	SystemInit();
	Lcd_Begin();
	
	LPC_GPIO1->FIODIR |= ((1<<COL0)|(1<<COL1)|(1<<COL2)|(1<<COL3));
	LPC_GPIO1->FIOCLR |= ((1<<COL0)|(1<<COL1)|(1<<COL2)|(1<<COL3));
	Lcd_WriteString("Press HEX Keys..");
	Lcd_SetCursor(1,0);
	Lcd_WriteString("key Pressed= ?");
	Lcd_SetCursor(1,13);
	while(1)
	{
		for(i=0;i<4;i++)
		{
			LPC_GPIO1->FIOSET = (1<<col[i]);
		  for(j=0;j<4;j++)
			{
				if(LPC_GPIO1->FIOPIN & (1<<row[j]))
		    {
			  Lcd_WriteChar(c[i][j]);
				flag=1;
			  break;
		    }
			}
			LPC_GPIO1->FIOCLR |= ((1<<COL0)|(1<<COL1)|(1<<COL2)|(1<<COL3));
			if(flag==1)
			{
				flag=0;
				break;
			}
	  }
	}
}