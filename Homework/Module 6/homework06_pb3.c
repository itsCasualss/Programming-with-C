// Problem 2 but with Switch statements; 

#include <stdio.h>

int main(void)
{
    //User Inputs defined ->
    float r1, r2, r3, RT; //Values for r1, r2, r3 and total resistance (RT)
    char type;            //choice for S, P, or C for resistors connection type using SWITCH


	//User Input section, errors if any value is <= 0 
    printf("What is the resistance of R1?\n"); if (scanf("%f", &r1) != 1) { printf("Invalid input.\n"); return 1; } if (r1 <= 0.0f) { printf("Invalid input: R1 must be positive.\n"); return 1; }
    printf("What is the resistance of R2?\n"); if (scanf("%f", &r2) != 1) { printf("Invalid input.\n"); return 1; } if (r2 <= 0.0f) { printf("Invalid input: R2 must be positive.\n"); return 1; }
    printf("What is the resistance of R3?\n"); if (scanf("%f", &r3) != 1) { printf("Invalid input.\n"); return 1; } if (r3 <= 0.0f) { printf("Invalid input: R3 must be positive.\n"); return 1; }

    printf("What kind of combination result are you looking for? Valid Inputs = S, P, or C: \n");
    if (scanf(" %c", &type) != 1) { printf("Invalid input.\n"); return 1; }
    if (type >= 'a' && type <= 'z') type = (char)(type - ('a' - 'A')); // forces uppercase input

    switch (type)
    {
        case 'S': // Series: RT = r1 + r2 + r3
            RT = r1 + r2 + r3;
            printf("The Total Resistance is %0.2f Ohms since R1, R2 and R3 are connected in series manner.\n", RT);
            break;

        case 'P': // Parallel: RT = 1 / (1/r1 + 1/r2 + 1/r3)
            RT = 1.0f / ((1.0f / r1) + (1.0f / r2) + (1.0f / r3));
            printf("The Total Resistance is %0.2f Ohms since R1, R2, R3 are connected in parallel manner.\n", RT);
            break;

        case 'C': // Combination: r1 + (r2||r3) => RT = r1 + (r2*r3)/(r2+r3)
            RT = r1 + (r2 * r3) / (r2 + r3);
            printf("The Total Resistance is %0.2f ohms since R1, R2, R3 are connected in combination manner.\n", RT);
            break;

        default: // Invalid choice
            printf("Invalid choice. Please type S, P, or C.\n");
            return 1;
    }

    return 0;
}
