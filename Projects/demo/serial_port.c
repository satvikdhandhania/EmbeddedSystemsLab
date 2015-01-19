

#include <at89c51xd2.h>

//Transfer letter 'A' serially at 4800 baud rate continuously.
//USe 8b data and 1 stop bit
void main(void)
{
TMOD = 0x20; //Timer 1 in mode 2 8b auto reload
TH1 = 0xFA;
TR1 = 1;
SCON = 0x40;
while(1)
{
SBUF = 'A';
while(TI == 0);
TI=0;
}

}