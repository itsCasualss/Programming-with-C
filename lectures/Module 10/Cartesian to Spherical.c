#include <stdio.h>
#include <math.h>

#define ROWS 3
#define XYZ 3
#define OUTCOLS 6

void inputCartesian(double points[ROWS][XYZ]);
void convertToSpherical(double points[ROWS][XYZ], double result[ROWS][OUTCOLS]);
void printTable(double result[ROWS][OUTCOLS]);

int main(void)
{
    double points[ROWS][XYZ];
    double result[ROWS][OUTCOLS];

    inputCartesian(points);
    convertToSpherical(points, result);
    printTable(result);

    return 0;
}

void inputCartesian(double points[ROWS][XYZ])
{
    int i;

    for (i = 0; i < ROWS; i++)
    {
        printf("Enter x y z for point %d: ", i + 1);
        scanf("%lf %lf %lf", &points[i][0], &points[i][1], &points[i][2]);
    }
}

void convertToSpherical(double points[ROWS][XYZ], double result[ROWS][OUTCOLS])
{
    int i;
    double x, y, z, r, theta, phi;
    double pi = 3.141592653589793;

    for (i = 0; i < ROWS; i++)
    {
        x = points[i][0];
        y = points[i][1];
        z = points[i][2];

        r = sqrt(x * x + y * y + z * z);

        theta = atan2(y, x) * 180.0 / pi;

        if (r == 0)
            phi = 0;
        else
            phi = acos(z / r) * 180.0 / pi;

        result[i][0] = x;
        result[i][1] = y;
        result[i][2] = z;
        result[i][3] = r;
        result[i][4] = theta;
        result[i][5] = phi;
    }
}

void printTable(double result[ROWS][OUTCOLS])
{
    int i;

    printf("\n%s %s %s %s %-10s %-10s\n", "x", "y", "z", "r", "theta", "phi");

    for (i = 0; i < ROWS; i++)
    {
        printf("%-8.2f %-8.2f %-8.2f %-10.2f %-10.2f %-10.2f\n",
               result[i][0], result[i][1], result[i][2],
               result[i][3], result[i][4], result[i][5]);
    }
}
