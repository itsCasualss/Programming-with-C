//Swapping.c
#include <stdio.h>

void swap(int *first, int *second); // FNCT PROTOTYPE

int main(void) {
	int a =5, b=10;

	printf("At first, a = %d, b = %d.\n", a, b);
	swap(&a, &b); //user defined function

	printf("After swapping, a =%d, b =%d", a, b);
	getchar();return 0;}

void swap(int *first, int *second){
int temp = *first; // Create temp to ref first
*first = *second; //swaps first with second
*second = temp;  } // makes second's value the temp, originally set to first
