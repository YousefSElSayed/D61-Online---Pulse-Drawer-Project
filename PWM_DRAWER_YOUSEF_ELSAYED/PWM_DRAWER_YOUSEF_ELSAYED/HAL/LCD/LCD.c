#include "LCD.h"					 

// To write commands to the LCD using the control pins. 
void LCD_Command (char cmd)							 
{
	LCD_Data_Port = cmd;							 
	LCD_Command_Port &= ~((1<<RS)|(1<<RW));			 
	LCD_Command_Port |= (1<<EN);					 
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);								  
}

//Displays a character.
void LCD_Char (char char_data)						 
{
	LCD_Data_Port = char_data;						 
	LCD_Command_Port &= ~(1<<RW);				 
	LCD_Command_Port |= (1<<EN)|(1<<RS);			 
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);									 
}


// Initializes the LCD through specific LCD functions
void LCD_Init (void)								 
{
	LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		 
	LCD_Data_Dir = 0xFF;						 
	
	_delay_ms(20);								 
	LCD_Command (0x38);								 
	LCD_Command (0x0C);							 
	LCD_Command (0x06);								 
	LCD_Command (0x01);								 
	LCD_Command (0x80);							 
}

// Takes the address of a char array and loops until it has completely displayed each character in the "string"
void LCD_String (char *str)							 
{
	int i;
	for(i=0;str[i]!=0;i++)							 
	{
		LCD_Char (str[i]);						 
	}
}

// Sets a specific point in the LCD to move and begin writing from.
void LCD_String_xy (char row, char pos, char *str)	 
{
	if (row == 1)
	LCD_Command((pos & 0x0F)|0x80);				 
	else if (row == 2)
	LCD_Command((pos & 0x0F)|0xC0);			 
	LCD_String(str);								 
}


// Clearing the LCD screen. 
void LCD_Clear (void)								 
{
	LCD_Command (0x01);								 
	LCD_Command (0x80);								 
}
