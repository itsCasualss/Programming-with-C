//Return_Function_Factorial.c

#include<stdio.h>
unsigned long long int return_factorial(unsigned int num);
int main(void){
	
	char input[3];
	int number;
	
	//prompt the user
	printf("Enter a positive integer for which the factorial will be calculated:");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%d", &number);
	
	//check the inpout as a conditional
	if (number >0){
		printf("The factorial of %d is %lu.\n", number, return_factorial(number));
	} else {
		printf("You must enter a positive integer!\n");
	}	
	getchar();
	
	return 0;
	}
	
