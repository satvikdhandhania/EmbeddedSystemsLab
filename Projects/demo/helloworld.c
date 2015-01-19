#include <at89c51xd2.h>

#define led P0

void main ()
{
	int i;
	led =0;
	while(1)						  
	{
	  led=~led;
      for(i=0;i<1000;i++);

	}
}