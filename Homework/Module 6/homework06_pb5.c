#include <stdio.h>
#include <math.h>

int main(void)
{
    // Defining user inputed floats for the 3 verticies
    float x1, y1, x2, y2, x3, y3;

    // Defining floats for sides, semiperimeter, area
    float A, B, C, s, inside, area;

    
	//command line prints for prompting user inputs. 
	printf("Enter First Coordinate Pair (X_1, Y_1), Numerical Values only:\n"); if (scanf("%f %f", &x1, &y1) != 2) { printf("Invalid input.\n"); return 1; }
    printf("Enter Second Coordinate Pair (X_2, Y_2), Numerical Values only:\n"); if (scanf("%f %f", &x2, &y2) != 2) { printf("Invalid input.\n"); return 1; }
    printf("Enter Third Coordinate Pair (X_3, Y_3), Numerical Values only:\n"); if (scanf("%f %f", &x3, &y3) != 2) { printf("Invalid input.\n"); return 1; }

    // Distance formula for side lengths (
    A = (float)sqrt(pow((double)(x2 - x1), 2.0) + pow((double)(y2 - y1), 2.0));
    B = (float)sqrt(pow((double)(x3 - x2), 2.0) + pow((double)(y3 - y2), 2.0));
    C = (float)sqrt(pow((double)(x1 - x3), 2.0) + pow((double)(y1 - y3), 2.0));

    // Heron's formula
    s = (A + B + C) / 2.0f; //semiperimeter 
    inside = s * (s - A) * (s - B) * (s - C); //area

    if (inside <= 0.0f) area = 0.0f;            // invalid/degenerate triangle (or rounding)
    else area = (float)sqrt((double)inside);

    printf("-With the given vertices (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f) the area of the triangle is %.2f.\n",
           x1, y1, x2, y2, x3, y3, area);

    return 0;
}
