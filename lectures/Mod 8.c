#include<stdio.h>
void discard_input(void);// Functions prototype
int main(void){
//Prompt the user
printf("Yell at me, teach. Watch me do nothing with it. I am a student :P :");
//Read the input.
getchar();
//Discard everything else
discard_input();
//Wait for user to press Enter or Return.
getchar();
return 0;

}
void discard_input(void){
char junk; //getting rid of extra input
//loop through the input and ignore.
do{junk = getchar();
}while(junk != 'P');
} //End of discard_input() function
