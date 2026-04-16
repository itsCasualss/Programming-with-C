/*memory.c*/
#include<stdio.h>
#include<stdlib.h>
int main(void) {
/*Declare a void pointer variable*/
void *x;
/*Request a block of memory with 1000 bytes*/
x=malloc(1000);
/*Print out the starting address of the memory block*/
printf("Starting block address: %p\n",x);
/*Return the block to the pool*/
free(x);
x=NULL;
printf("Starting block address: %p\n",x);
getchar(); return 0;
}
