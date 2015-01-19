#include <reg52.h>
#include <stdio.h>
void main (void)
{

/*Set Timer0 for 16 Åbit counter mode.
Set the Timer0 Run control bit.
*/
TMOD = (TMOD & 0xF0) | 0x05;
TR0 = 1;
P3=0x00;
while (1)
{

//display the count value
P1 = TH0; //MSB of timer 0
P2 = TL0; //LSB of timer 0
}
}