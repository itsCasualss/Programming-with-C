#include <stdio.h>

int main()
{
    double coef[6];                     // 0=a,1=b,2=c,3=d,4=e,5=f
    double denom, x, y;                 // denom = ae-bd, then x,y
    char again = 'Y';                   // ask to redo w new values \\ loop control
    int choice;                         // which coefficient we’re asking for

    while (again == 'Y' || again == 'y')
    {
        for(choice = 0; choice < 6; choice++)          // loop through a..f
        {
            switch(choice)                              // pick the right prompt
            {
                case 0: printf("Enter a: "); break;
                case 1: printf("Enter b: "); break;
                case 2: printf("Enter c: "); break;
                case 3: printf("Enter d: "); break;
                case 4: printf("Enter e: "); break;
                case 5: printf("Enter f: "); break;
            }
            scanf("%lf", &coef[choice]);               // store input into the array
        }

        denom = coef[0]*coef[4] - coef[1]*coef[3];     // ae - bd

        if (denom == 0)                                // can’t divide by 0, so no unique x,y
        {
            printf("No unique solution (ae - bd = 0).\n");
        }
        else
        {
            x = (coef[2]*coef[4] - coef[1]*coef[5]) / denom;   // (ce - bf)/(ae - bd)
            y = (coef[0]*coef[5] - coef[2]*coef[3]) / denom;   // (af - cd)/(ae - bd)

            printf("With given values of \"a\", \"b\", \"c\", \"d\", \"e\", and \"f\", ");
            printf("the answer for x is %.4f and y is %.4f\n", x, y);
        }

        printf("Continue? (Y to keep going): ");
        scanf(" %c", &again);                          // space eats the leftover newline
    }

    return 0;
}
