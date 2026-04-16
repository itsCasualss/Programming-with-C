//Where_is_Walldo2.c
#include <stdio.h>
int main(void){
int a[5]={-40,7853,74,19,449378};
//Print out the address of all variables
printf("Address of a[1]: %p\n", &a[1]);
printf("Address of a[2]: %p\n", &a[2]);
printf("Address of a[3]: %p\n", &a[3]);
printf("Address of a[4]: %p\n", &a[4]);
printf("Address of a[5]: %p\n", &a[5]);
getchar(); return 0;}
//Not only array’s address, you can find function’s address also! (Use &my_fnct) 

// Prints the address of each element of this array. 
