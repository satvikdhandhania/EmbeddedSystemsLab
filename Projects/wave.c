#include <REGx51.h> //header file for 89C51
void main(){
//main function starts
unsigned int i;
//Initializing Port1 pin1
P1_1 = 0; //Make Pin1 o/p
while(1){
//Infinite loop main application
//comes here
for(i=0;i<1000;i++)
; //delay loop
P1_1 = ~P1_1;
//complement Port1.1
//this will blink LED connected on Port1.1
}
}