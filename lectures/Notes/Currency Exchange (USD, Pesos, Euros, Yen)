//Exchange_Functions001.c Please download this
#include <stdio.h>
void make_exchange_table(float rate, char title[]);// Function prototype

int main (void){

//Show Pesos
make_exchange_table(11.317466,"Pesos");
//Show Euros
make_exchange_table(0.823857,"Euros");
//Show Yen
make_exchange_table(119.60, "Yen");

//Wait for the user to press Enter
getchar();
return 0;
}


void make_exchange_table(float rate, char title[]){
float i;

printf("%10s %10s\n", "Dollar", title);
for (i=10.00; i<=100.00;i +=10){
printf("%10.2f %10.2f\n", i, i*rate);
}
printf("\n\n");
}
