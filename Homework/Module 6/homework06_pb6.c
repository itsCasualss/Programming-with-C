#include <stdio.h>

int main(void)
{
    // User inputs + loop control
    float a, b, c, d, e, f, denom, x, y;
    char again = 'Y';

    while (again == 'Y' || again == 'y')
    {
    	printf("Given two equations in the following format: \n ax + by = c \n dx + ey = f \nInput the numberical values for a-f to solve for x and y:\n\n");
        printf("Enter a:\n"); if (scanf("%f", &a) != 1) { printf("Invalid input.\n"); return 1; }
        printf("Enter b:\n"); if (scanf("%f", &b) != 1) { printf("Invalid input.\n"); return 1; }
        printf("Enter c:\n"); if (scanf("%f", &c) != 1) { printf("Invalid input.\n"); return 1; }
        printf("Enter d:\n"); if (scanf("%f", &d) != 1) { printf("Invalid input.\n"); return 1; }
        printf("Enter e:\n"); if (scanf("%f", &e) != 1) { printf("Invalid input.\n"); return 1; }
        printf("Enter f:\n"); if (scanf("%f", &f) != 1) { printf("Invalid input.\n\n"); return 1; }

		printf("\nEquation 1: %0.2fx + %0.2fy = %0.2f\n", a, b, c);
        printf("Equation 2: %0.2fx + %0.2fy = %0.2f\n\n", d, e, f);
		
        denom = (a * e) - (b * d); // ae - bd (denominator)

        if (denom == 0.0f) { //division by zero
            printf("With given values of \"a\", \"b\", \"c\", \"d\", \"e\", and \"f\", the answer is undefined (ae - bd = 0).\n");
        }
        else {
            x = (c * e - b * f) / denom; // x = (ce - bf)/(ae - bd)
            y = (a * f - c * d) / denom; // y = (af - cd)/(ae - bd)
            printf("With given values of \"a\", \"b\", \"c\", \"d\", \"e\", and \"f\", the answer for x is %0.2f and y is %0.2f\n", x, y);
        }

        printf("Would you like to continue on finding answers for other equations? (Y/N):\n");
        if (scanf(" %c", &again) != 1) { printf("Invalid input.\n"); return 1; }
    }

    return 0;
}
