#include <at89c51xd2.h>
void delay()
{
  TL0=0AF;
  TH0=0X3C;
  TR0=1;
  while(TF0==0){}
  TR0=0;
}
main()