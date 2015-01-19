#include <at89c51xd2.h>
sbit CLKL = P1^0; //Clock Line (>CLK)of 8-bit shift reg U5 (Serial In Parralel Out)
sbit LED = P1^3; //Data Line of the 8-bit shift reg U5
unsigned int i,j;
void delay()
{
  TF0=0;
  ET0=0;
  TMOD=0X01;
  TL0=0xAF;
  TH0=0X3C;
  TR0=1;
  while(TF0==0){}
  TR0=0;
}
void main()
{
////clear all ledswhile(1)	//clear all leds
{
CLKL = 0; //clear clock input intially
LED = 1; //set data input as 1
	for(j=0;j<8;j++) //apply 8 clock pulses
	{
		CLKL = 1;
		CLKL =0;
		for(i=0;i<20;i++)//delay for 1 sec delay generates 50ms delay therefore 20x50ms=1sec
		 delay();
	}
//set all leds
CLKL = 0; //clear clock input initially
LED = 0; //set data input as 0
//apply 8 clock pulses
	for(j=0;j<8;j++)
	{
		CLKL = 1;
		CLKL =0;
		for(i=0;i<20;i++)//delay for 1 sec delay generates 50ms delay therefore 20x50ms=1sec
		 delay();
	}
 }
}