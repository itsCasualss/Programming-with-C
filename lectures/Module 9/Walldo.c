//Where_is_Walldo.c
#include <stdio.h>
int main(void){
	
int a =-40; int b = 7853; char c = 74; char d= 19; int e = 449378;
//Character’s numerical value

//Print out the address of all variables 
printf("Address of a: %p\n", &a);
printf("Address of b: %p\n", &b);
printf("Address of c: %p\n", &c);
printf("Address of d: %p\n", &d);
printf("Address of e: %p\n", &e);

getchar(); return 0;}
//Once you are done with %u option, try %p
// Provides different values to each int's pointer addresss
