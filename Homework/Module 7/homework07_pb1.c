#include <stdio.h>
#include <math.h>

int main(void)
{
    int V[8];      // x0 y0 x1 y1 x2 y2 x3 y3
    int D2[6];     // storing the d^2 values for each of the squared distances. 
    int i, j;

    printf("Enter 4 vertices as 8 integers with only spaces between the values as follows: x0 y0 x1 y1 x2 y2 x3 y3\n");
    for (i = 0; i < 8; ++i) {
        if (scanf("%d", &V[i]) != 1) {
            printf("Input error.\n");
            return 1;
        }
    }

	//Calculating the distance from each points to eachother. 

    // (0,1)
    D2[0] = (V[0]-V[2])*(V[0]-V[2]) + (V[1]-V[3])*(V[1]-V[3]);
    // (0,2)
    D2[1] = (V[0]-V[4])*(V[0]-V[4]) + (V[1]-V[5])*(V[1]-V[5]);
    // (0,3)
    D2[2] = (V[0]-V[6])*(V[0]-V[6]) + (V[1]-V[7])*(V[1]-V[7]);
    // (1,2)
    D2[3] = (V[2]-V[4])*(V[2]-V[4]) + (V[3]-V[5])*(V[3]-V[5]);
    // (1,3)
    D2[4] = (V[2]-V[6])*(V[2]-V[6]) + (V[3]-V[7])*(V[3]-V[7]);
    // (2,3)
    D2[5] = (V[4]-V[6])*(V[4]-V[6]) + (V[5]-V[7])*(V[5]-V[7]);

    // sort D2 ascending (bubble sort)
    for (i = 0; i < 6; ++i) {
        for (j = 0; j < 5; ++j) {
            if (D2[j] > D2[j+1]) {
                int temp = D2[j];
                D2[j] = D2[j+1];
                D2[j+1] = temp;
            }
        }
    }

    // degenerate
    if (D2[0] == 0) {
    printf("NEITHER (degenerate)\n");
}
else if (D2[0] == D2[1] && D2[1] == D2[2] && D2[2] == D2[3] &&
         D2[4] == D2[5] &&
         D2[4] == 2 * D2[0]) {

    printf("SQUARE\n");
    printf("Area = %.2f\n", (double)D2[0]);
}
else if (D2[0] == D2[1] &&
         D2[2] == D2[3] &&
         D2[4] == D2[5] &&
         (D2[0] + D2[2] == D2[4]) &&
         (D2[0] != D2[2])) {

    double area = sqrt((double)D2[0] * (double)D2[2]);
    printf("RECTANGLE\n");
    printf("Area = %.2f\n", area);
}
else {
    printf("NEITHER\n");
}
}
