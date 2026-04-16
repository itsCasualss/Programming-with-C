#include <stdio.h>
int main (void){
	int a = 456; char b='j';
	
	//Create two pointers, properly typed.
	int *x; 
	char *y;
	
	//Store the addresses of the pointers
	x = &a;
	y = &b;
	
	printf("Address of a: %p\n", &a);
	printf("Address of a: %p\n", x);
	printf("Address of b: %p\n", &b);
	printf("Address of b: %p\n", y);
	
	// Print the size of four variables
	
	printf("Size of a: %d\n", sizeof(a));
	printf("Size of b: %d\n", sizeof(b));
	printf("Size of x: %d\n", sizeof(x));
	printf("Size of y: %d\n", sizeof(y));
	getchar();
	return 0;
}

