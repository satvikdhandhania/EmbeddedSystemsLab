#include <at89c51xd2.h>
sbit D0 = P0^0; // set P0.0-P0.7 (D0-D7) as input pins of mux
sbit D1 = P0^1;
sbit D2 = P0^2;
sbit D3 = P0^3;
sbit D4 = P0^4;
sbit D5 = P0^5;
sbit D6 = P0^6;
sbit D7 = P0^7;
sbit S0 = P1^0; // set P1.0-P1.2(S0-S2) as select pins of mux
sbit S1 = P1^1;
sbit S2 = P1^2;
sbit EN = P1^7; // set P1.7 as enable pin
sbit pin = P3^5; // set P3.5 as output
main()
{
P3=0x00;P0=0xFF; // clear op and set all ips
next:while(EN==1){} // wait till enable pin becomes 0
if((S0==0)&&(S1==0)&&(S2==0)) pin = D0; // if select inputs are 000 op is	first ip
else if((S0==1)&&(S1==0)&&(S2==0)) pin = D1; // if select inputs are 001 op is second ip
else if((S0==0)&&(S1==1)&&(S2==0)) pin = D2; // same as above
else if((S0==1)&&(S1==1)&&(S2==0)) pin = D3;
else if((S0==0)&&(S1==0)&&(S2==1)) pin = D4;
else if((S0==1)&&(S1==0)&&(S2==1)) pin = D5;
else if((S0==0)&&(S1==1)&&(S2==1)) pin = D6;
else if((S0==1)&&(S1==1)&&(S2==1)) pin = D7;  

else pin = 0; // by default op is cleared
goto next; // go for next input
}