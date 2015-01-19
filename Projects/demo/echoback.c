#include <at89c51xd2.h>
void main(void)
{
unsigned char rx_byte;
TMOD = 0x20; //timer 1 in mode 2 auto reload mode
TH1 = 0xFA;
TR1 = 1;
SCON = 0x50;
while(1)
{
while(RI == 0);
rx_byte = SBUF;
P1 = rx_byte;
RI=0;
SBUF = rx_byte;
while(TI == 0);
TI = 0;
}
}