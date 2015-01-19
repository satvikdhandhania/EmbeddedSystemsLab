#include <at89c51xd2.h>
#include<math.h>
void main()
{ 
  float i,a;
  while(1)
  {
    for(i=0.0;i<3.14;)
	{  
	   a=sin(i);
	   i=i+0.1;
	  
	 }
    for(i=3.14;i<6.28;)
	 { 
	   a=sin(i); 
	   
	   i=i+0.1;
	  
	 }	
  }
}