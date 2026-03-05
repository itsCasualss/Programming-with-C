#include <stdio.h>

//array = fixed-size collection of elements of the same data type, similar to the variable but it holds more than one value. 

int main(){
	
	int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80}; //each value in an array is an element, starting with 0, 1, 2, 3, .. 
	char grades[] = {'A', 'B', 'C', 'D', 'F'};
	char name[] = "its Casuals"; 



	int size = sizeof(numbers) / sizeof(numbers[0]); 
	
	printf("These are the values in the array: "); 
	
	for(int i = 0; i < size; i++){
		printf("%d ", numbers[i]);
		
	}
	printf("\nThere are %d elements in the array", size);
	
/*	
	
	printf("%d\n", sizeof(numbers)); // display integer , call size of function (gives size in bytes)
	printf("%d\n", sizeof(numbers[0]));
	

	for(int i = 0; i< 5; i++){
		printf("%c\n", grades[i]);
	}
	
	
	
	for(int i = 0; i< 12; i++){
		printf("%c ", name[i]);
	}
	
	printf("\n");
	for(int i = 0; i< 5; i++){
		printf("%d ", numbers[i]);
	}
	*/
	
	
	
	return 0;
}

