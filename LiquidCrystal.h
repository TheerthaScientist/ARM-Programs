#ifndef LIQUIDCRYSTAL_H_INCLUDED
#define LIQUIDCRYSTAL_H_INCLUDED

#include<lpc17xx.h>

/* Configure the data bus and Control bus as per the hardware connection */
#define LcdDataBusPort      LPC_GPIO0->FIOPIN
#define LcdControlBusPort   LPC_GPIO0->FIOPIN

#define LcdDataBusDirnReg   LPC_GPIO0->FIODIR
#define LcdCtrlBusDirnReg   LPC_GPIO0->FIODIR

#define LCD_D4     19
#define LCD_D5     20
#define LCD_D6     21
#define LCD_D7     22

#define LCD_RS     9
#define LCD_RW     10
#define LCD_EN     11

/* Masks for configuring the DataBus and Control Bus direction */
#define LCD_ctrlBusMask   ((1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_EN))
#define LCD_dataBusMask   ((1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7))

/* local function to generate some delay */
void delay(int cnt)
{
    int i;
    for(i=0;i<cnt;i++);
}

/* Function send the a nibble on the Data bus (LCD_D4 to LCD_D7) */
void sendNibble(char nibble)
{
    LcdDataBusPort&=~(LCD_dataBusMask);                   // Clear previous data
    LcdDataBusPort|= (((nibble >>0x00) & 0x01) << LCD_D4);
    LcdDataBusPort|= (((nibble >>0x01) & 0x01) << LCD_D5);
    LcdDataBusPort|= (((nibble >>0x02) & 0x01) << LCD_D6);
    LcdDataBusPort|= (((nibble >>0x03) & 0x01) << LCD_D7);
}

/* Function to send the command to LCD.
   As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */
void Lcd_CmdWrite(char cmd)
{
    sendNibble((cmd >> 0x04) & 0x0F);  //Send higher nibble
    LcdControlBusPort &= ~(1<<LCD_RS); // Send LOW pulse on RS pin for selecting Command register
    LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
    LcdControlBusPort |= (1<<LCD_EN);  // Generate a High-to-low pulse on EN pin
    delay(1000);
    LcdControlBusPort &= ~(1<<LCD_EN);

    delay(10000);

    sendNibble(cmd & 0x0F);            //Send Lower nibble
    LcdControlBusPort &= ~(1<<LCD_RS); // Send LOW pulse on RS pin for selecting Command register
    LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
    LcdControlBusPort |= (1<<LCD_EN);  // Generate a High-to-low pulse on EN pin
    delay(1000);
    LcdControlBusPort &= ~(1<<LCD_EN);

    delay(10000);
}

/*Function to send data to LCD*/
void Lcd_DataWrite(char dat)
{
    sendNibble((dat >> 0x04) & 0x0F);  //Send higher nibble
    LcdControlBusPort |= (1<<LCD_RS);  // Send HIGH pulse on RS pin for selecting data register
    LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
    LcdControlBusPort |= (1<<LCD_EN);  // Generate a High-to-low pulse on EN pin
    delay(1000);
    LcdControlBusPort &= ~(1<<LCD_EN);

    delay(10000);

    sendNibble(dat & 0x0F);            //Send Lower nibble
    LcdControlBusPort |= (1<<LCD_RS);  // Send HIGH pulse on RS pin for selecting data register
    LcdControlBusPort &= ~(1<<LCD_RW); // Send LOW pulse on RW pin for Write operation
    LcdControlBusPort |= (1<<LCD_EN);  // Generate a High-to-low pulse on EN pin
    delay(1000);
    LcdControlBusPort &= ~(1<<LCD_EN);

    delay(10000);
}

/*Function to clear data in LCD*/
void Lcd_Clear(void)
{
	Lcd_CmdWrite(0x01);
}

/*Function to Set CursorPoint */
int Lcd_SetCursor(unsigned char x,unsigned char y)
{
	unsigned int res=1;
	if((x > 1 )&&(y > 15))
	{
		res=0;
	}
	else
	{
		if(x == 0)
			Lcd_CmdWrite(0xc0+y);
	}
	return res;
}

/*Function to Write Chrector to LCD */
void Lcd_WriteChar(unsigned char c)
{
	Lcd_DataWrite(c);
}

/*Function to Write string to LCD */
void Lcd_WriteString(char *string)
{
while(*string != '\0')
{
	Lcd_PutChar(*string);
	string++;
}
}

/*Function to Write string with set cursor to LCD */
void Lcd_WriteString(unsigned char line,char *string)
{
	unsigned char len = 16;
	Lcd_SetCursor(line,0);
	while(*string!='\0' && len--)
	{
		Lcd_WriteChar(*string);
		string++;
	}
}

/*Function to Start LCD */
void Lcd_Begin(void)
{
	LcdDataBusDirnReg |= LCD_dataBusMask;
	LcdControlBusPort |= LCD_ctrlBusMask; 
	Lcd_CmdWrite(0x03);
	delay(2000);
	Lcd_CmdWrite(0x03);
	delay(1000);
	Lcd_CmdWrite(0x03);
	delay(100);
	Lcd_CmdWrite(0x02);
	
	Lcd_CmdWrite(0x28);
	
	Lcd_CmdWrite(0x0e);
	
	Lcd_CmdWrite(0x06);
	
	Lcd_CmdWrite(0x01);
	delay(1);
	}


#endif // LIQUIDCRYSTAL_H_INCLUDED
