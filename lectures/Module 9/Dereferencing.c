//Dereferencing.c
#include <stdio.h>
int main (void){
	int a = 456;
	int *x;
	x=&a;
	
	//Inintialization 
	printf("Address of a: %p\n", x);
	printf("a at start: %d\n",a);
	printf("*x at start: %d\n", *x);
	
	//Value changing 
	*x=123; //We ane not changinc a directly!!!
	
	printf(" a at end: %d\n", a);
	printf(" *x at end: %d\n", *x);
	getchar();
	
	return 0;
}
