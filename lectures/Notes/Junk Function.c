#include <stdio.h>

void discard_input(void);// Functions prototype

void discard_input (void);
int main(){
	
	//Prompt the user
	printf("Yell at me, teach. Watch me do nothing with it. I am a student :P : ");
	//Read the input
	getchar();
	
	// Discard everything else
	
	discard_input();
	
	// Wait for user to press Enter or Return.
	getchar();
	return 0;}
	
	void discard_input(void){
		char junk;
	do{junk = getchar();
	}while (junk != 'P');
	}
