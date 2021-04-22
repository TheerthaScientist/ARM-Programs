/*===============================================================================================*/
/*	Application : Keil uVision                                                                   */
/*	Developer	: THEERTHA                                                                       */
/*	College		: Government Engineering College, Chamarajanagara                                */
/*	Copy Rights	: GNU public license															 */
/*	Git Hub link:                                                                                */
/*===============================================================================================*/
//program to run DC Motor with variable speed (USING PWM)

//header file includes i/o modules of LPC17XX chip
#include"lpc17xx.h"
//header file ti include liquid crystel Display
#include"LiquidCrystal.h"
//////////////////////////////
//Matrix keypad Scanning Routine
//
// COL1 COL2 COL3 COL4
//  0    1    2   3   ROW 1
// 	4 	 5	  6   7   ROW 2
//  8    9    A   B   ROW 3
//  C    D    E   F   ROW 4
//////////////////////////////
#define COL1    0
#define COL2    1
#define COL3    4
#define COL4    8

#define ROW1    9
#define ROW2    10
#define ROW3    14
#define ROW4    15

#define COLMASK         ((1<<COL1)|(1<<COL2)|(1<<COL3)|(1<<COL4))
#define ROWMASK         ((1<<ROW1)|(1<<ROW2)|(1<<ROW3)|(1<<ROW4))

#define KEY_CTRL_DIR  LPC_GPIO1->FIODIR
#define KEY_CTRL_SET  LPC_GPIO1->FIOSET
#define KEY_CTRL_CLR  LPC_GPIO1->FIOCLR
#define KEY_CTRL_PIN  LPC_GPIO1->FIOPIN
///////////COLUMN WRITE//////////
void col_write(unsigned char data)
{
	unsigned int temp=0;
	temp=(data)&COLMASK;
	KEY_CTRL_CLR|=COLMASK;
	KEY_CTRL_SET|=temp;
}
//////////////////////////MAIN////////////////////////
int main(void)
{
	unsigned char key,i;
	unsigned char rval[]={0x77,0x07,0x0d};
		unsigned char keyPadMatrix[]={
			'4','8','B','F',
			'3','7','A','E',
			'2','6','0','D',
			'1','5','9','C'
		};
		SystemInit();
		Lcd_Begin();
		KEY_CTRL_DIR|=COLMASK; //Set COLs as Outputs
		KEY_CTRL_DIR&=~(ROWMASK);  //Set ROW lines as inputs
		
		Lcd_WriteStringLS(0,"Press HEX Keys..");
		Lcd_WriteStringLS(1,"key Pressed= ");
		while(1)
		{
			key=0;
			for(i=0;i<4;i++)
			{
				//turn on COL output one by one 
				col_write(rval[i]);
				//read rows-break when key press detected
				if(!(KEY_CTRL_PIN&(1<<ROW1)))
					break;
				
				key++;
				if(!(KEY_CTRL_PIN&(1<<ROW2)))
					break;
				
				key++;
				if(!(KEY_CTRL_PIN&(1<<ROW3)))
					break;
				
				key++;
				if(!(KEY_CTRL_PIN&(1<<ROW4)))
					break;
				
				key++;
			}
			if(key==0x10){
				Lcd_WriteStringLS(1,"Key Pressed= ");
				delay(100);
			}
			else
			{
				Lcd_SetCursor(1,14);
				Lcd_WriteChar(keyPadMatrix[key]);
			} 
		}
	}