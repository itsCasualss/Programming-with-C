#include<stdio.h>

int main(void)

{int num = 50, i; float array[num];
printf("How many numbers do you have?\n"); scanf("%d", &num);
float *array_ptr;

array_ptr=&array[0];

for(i=0; i<num; i++)
{printf("Please, enter a value for %d number: ", i); scanf("%f", &array[i]);}

printf("\n\n"); printf(" I am reversing the order of the numbers.\nHere we go\n");

array_ptr=&array[i-1];
for(i=0;i<num;i++)
{printf("\n %0.2f", *array_ptr); array_ptr--;}

}
