#include <stdio.h>

int main(void)
{
  unsigned short int inches = 3435;
  unsigned short int feet_inch;

unsigned short int inches_remainder;
  float feet_float;
  //conversions
  feet_inch=inches/12;
  inches_remainder=inches%12;
    feet_float =inches/12; //removing the ".0"  changes the output from a 0.25 remainder to the only 286 feet

  //printing results
  printf("%u inches is %u feet, %u inches. \n", inches, feet_inch, inches_remainder);
  printf("As a float, that's %0.2f feet. \n", feet_float);

getchar();
return 0;
}
