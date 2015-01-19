/* LCD related functions. */
#include "at89c51xd2.h"				 
#include <intrins.h>	//For _nop_();

// LCD FUNCTION PROTOTYPE

extern void lcd_comm(void); 
extern void wr_cn(void);
extern void wr_dn(void);
void delay(int);

extern unsigned char temp1;
extern unsigned char temp2;
unsigned char var;

//function to initialize the LCD
//P2 (RS / EN / RW / VCC / D3 - D0)
void lcd_init(void)
{
    temp1 = 0x30;  	// D5(P3.3)=1,D4(P3.2)=1   
	wr_cn();
	delay(500);
		
    temp1 = 0x30; 	// D5(P3.3)=1,D4(P3.2)=1  
	wr_cn();
	delay(500);
	
	temp1 = 0x30; 	// D5(P3.3)=1,D4(P3.2)=1  
	wr_cn();
	delay(500);
		
	temp1 = 0x20;	// D5(P3.3)=1
	wr_cn();
	delay(500);
	  
    temp1 = 0x28;  	// Set   retrun home (2) and display off and cursor off
  	lcd_comm();
	delay(500);
  
	temp1 = 0x0f;  //display on,cursor on, cursor blinking
  	lcd_comm();
	delay(500);

  	temp1 = 0x06;  //shift cursor right with auto increment
	lcd_comm();
	delay(500);
	
	temp1 = 0x80;  //clear display with cursor on first position
	lcd_comm();
	delay(500);

	temp1 = 0x01;	// clear the display screen
	lcd_comm();
	delay(500);
}

// Function to pass commands to LCD
void lcd_comm(void) 
{
 	var = temp1; 
  	temp1 = temp1 & 0xf0; 
  	temp1 = temp1 >> 4;
	
	wr_cn();

  	temp1 = var & 0x0f;
	wr_cn();

	delay(60);
}

// Function to pass data to LCD
void lcd_data(void)
{
   	var = temp2; 
  	temp2 = temp2 & 0xf0;  // convert the byte into nibble
  	temp2 = temp2 >> 4; 
  	wr_dn();
  	
	temp2 = var & 0x0f;
//	temp2 = temp2 << 2;
  	wr_dn();

	delay(60);
}  

// Function to write to command reg of LCD
//P2 (RS / EN / RW / VCC / D3 - D0)
void wr_cn(void)
{
	temp1 = temp1 & 0x7f;	//	RS(P3^7)=0	enable the LCD, sending command to lcd
	temp1 = temp1 & 0xDF;	//  sending command , enable lcd, read from lcd
	temp1 = temp1 | 0x40;	//	EN(P3^6)=1, TXD(P3^1)=1, RXD(P3^0)=1 => enable and write to lcd
	
	P2 = temp1;

	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();			
   	

	temp1 = temp1 & 0xbf;	//	EN(P3^6)=0,	=> disable lcd
	P2 = temp1;	
	
}

// Function to write to data reg of LCD 
//P2 (RS / EN / RW / VCC / D3 - D0)
void wr_dn(void)
{
	temp2 = temp2 | 0xc0;	//	RS(P3^7)=1,EN=1,TXD=1,RXD=1	  enable and send data to lcd
	temp2 = temp2 & 0xDF;	// sending data to lcd, enable and read lcd
	P2 = temp2;

	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();

	temp2 = temp2 & 0xbf;	//	EN = 0	   //disable lcd
	P2 = temp2;
}


void delay(int count)
{
	int i;

	for(i=0;i<count;i++);
}
