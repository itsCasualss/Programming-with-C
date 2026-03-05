#include <stdio.h>

int main()
{
    int n; // array size, user prompted.
    int i;  // loop's counter
    int numbers[100]; // allows for 100 integers
    int sum = 0; // variable for sum of array values
    double average; // variabel for the final avg value

  printf("Enter size of array: ");

    if(scanf("%d", &n) != 1)// scans for array size input, rejects if non intg detected
    {
        printf("Error: Non-numerical input detected.\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);

        if(scanf("%d", &numbers[i]) != 1)
        {
            printf("Error: Non-numerical input detected.\n");
            return 1;
        }
    }// loops to collect all of the numbers

    for(i = 0; i < n; i++)
    {
        sum += numbers[i];
    }//loops to determine the sum

    average = (double)sum / n;// omg here we find the average


    printf("Average = %.2f\n", average); // prints the averages

    return 0;
}
