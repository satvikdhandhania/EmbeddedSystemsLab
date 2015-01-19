#include<REG52.H>
#include<stdio.h>
unsigned char ch=0x00;
void delay()
{
TMOD|=0x01;
TH0=0xAF;
TL0=0x3C;
TF0=0;
TR0=1;
while(TF0==0);
}
main()
{
 int i,c1=4,c2=3,c3=5;
 SCON=0x50;
 TMOD=0x20;
 TH1=0xDD;
 TR1=1;
 P2=ch;
 while(1)				
 {
  for(i=0;i<100;i++)
   delay();
  if(P2^0==1)
  { 
    TI=1;
	printf("\n1.Coke Selected ..Pay within 1 sec..pressP2_6 to pay ");
	while(TI==0){}
	for(i=0;i<100;i++)
	  delay();
	if(P2^6==1)
	{
		 if(c1>0)
		{	
			 c1--;
			 TI=1;
		   printf("\nCoke Bought !!!");
		   while(TI==0){}
		}
		else
		{
		   TI=1;
		   printf("\nNot Available ...Stock Finished !!!");
		   while(TI==0){}
		}
    }
	else
	{
	  TI=1;
	  printf("\nAborted !!!");
	  while(TI==0){}
 	}
  }	
  else if(P2==0x02)
  { 
    TI=1;
	printf("\n1.Pepsi Selected ..Pay within 1 sec...pressP2_6 to pay");
	while(TI==0){}
	for(i=0;i<100;i++)
	  delay();
	if(P2^6==1)
	{
	  if(c2>0)
		{	
		   c2--;
	       TI=1;
		   printf("\nPepsi Bought !!!");
		   while(TI==0){}
		}
	  else
		{
		   TI=1;
		   printf("\nNot Available ...Stock Finished !!!");
		   while(TI==0){}
		}
	}
	else
	{
	  TI=1;
	  printf("\nAborted !!!");
	  while(TI==0){}
 	}
  }
  else if(P2^2==1)
  { 
    TI=1;
	printf("\n1.Miranda Selected ..Pay within 1 sec..pressP2_6 to pay ");
	while(TI==0){}
	for(i=0;i<100;i++)
	  delay();
	if(P2^6==1)
	{
		 if(c3>0)
		{	
			 c3--;
			 TI=1;
		   printf("\nMiranda Bought !!!");
		   while(TI==0){}
		}
		else
		{
		   TI=1;
		   printf("\nNot Available ...Stock Finished !!!");
		   while(TI==0){}		
		}
	}
	else
	{
	  TI=1;
	  printf("\nAborted !!!");
	  while(TI==0){}
 	}
  }
  else if(P2^7==1)
  {
   TI=1;
   printf("\nCoke Sold:%d Earned:%d",4-c1,c1*10);
   while(TI==0){}
   TI=1;
   printf("\nPepsi Sold:%d Earned:%d",3-c2,c2*20);
   while(TI==0){}
   TI=1;
   printf("\nMiranda Sold:%d Earned:%d",5-c3,c3*30);
   while(TI==0){}
  }	 
 P2=ch;
}
}