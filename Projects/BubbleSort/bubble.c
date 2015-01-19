#include <at89c51xd2.h>
void main()
{
  int a[5]={04,03,05,02,01};
  int i,j,temp,k;
  P0=0x00;
  for(i=0;i<5;i++)
  {
	for(j=0;j<4;j++)
  	{
	  if(a[j]>a[j+1])
	   {
	   	  temp=a[j];
		  a[j]=a[j+1];
		  a[j+1]=temp;
	   }
	   	for(k=0;k<32000;k++);
	}	  	  
  }
}
