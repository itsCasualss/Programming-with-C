//No_Way.c
#include <stdio.h>

	int main(void){
		int a[]={3, 23, 14,7,12};
		int *b=&a[1]; //defined a interger pointer variable but be careful w index
		//this essentially forces the array to start at 1 (the second entry), causing the pointer array to be
		//12, 14, 7, 12
		
		
		printf("Third entry in the array is %d \n", a[2]);
		printf("Third entry in the pointer array is %d\n", b[2]);

		return 0;
		getchar();
		
	}
