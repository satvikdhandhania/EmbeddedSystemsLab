#include <at89c51xd2.h>
sbit D0=P1^0;
sbit D1=P1^1 ;
sbit D2=P1^2  ;
sbit D3=P1^3   ;
sbit D4=P1^4	;
sbit D5=P1^5	;
sbit D6=P1^6	 ;
sbit D7=P1^7	  ;
sbit D9=P0^0	   ;
sbit D10=P2^0;
unsigned char  ip=0xff;
p1=0xFF;
void main()
{
   int i;
   for(i=0;i<8;i++)
   {
   	   D10=1;
	   D9=D0;
	   D0=D1;
	   D1=D2;
	   D2=D3;
	   D3=D4;
	   D4=D5;
	   D5=D6;
	   D6=D7;
       while(D10); 

   }

}