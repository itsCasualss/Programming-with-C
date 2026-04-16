#include <stdio.h>

int main()
{
    int n, exams;
    int i, j, k;
    
    printf("How many students are in the class? ");
    scanf("%d", &n);

    printf("How many exams were given? ");
    scanf("%d", &exams);

    char name[n][20];
    int scores[n][exams];
    double average[n];
    char grade[n];

    double sum;
    double classSum = 0;

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i+1);

        printf("Enter first name: ");
        scanf("%s", name[i]);

        sum = 0;

        for(j = 0; j < exams; j++)
        {
            printf("Enter score for Exam %d: ", j+1);
            scanf("%d", &scores[i][j]);

            sum += scores[i][j];
        }

        average[i] = sum / exams;
        classSum += average[i];

        if(average[i] >= 89.5)
            grade[i] = 'A';
        else if(average[i] >= 79.5)
            grade[i] = 'B';
        else if(average[i] >= 69.5)
            grade[i] = 'C';
        else if(average[i] >= 59.5)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }

    double classAverage = classSum / n;

    double sorted[n];
    double temp;

    for(i = 0; i < n; i++)
        sorted[i] = average[i];

    for(i = 0; i < n; i++)
    {
        for(k = 0; k < n-1; k++)
        {
            if(sorted[k] > sorted[k+1])
            {
                temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }

    double median;

    if(n % 2 == 1)
        median = sorted[n/2];
    else
        median = (sorted[n/2 - 1] + sorted[n/2]) / 2;

    printf("\nSEMESTER GRADE REPORT\n\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d (%s)  Average: %.2f  Grade: %c\n",
               i+1, name[i], average[i], grade[i]);
    }

    printf("\nClass Average: %.2f\n", classAverage);
    printf("Class Median: %.2f\n", median);

    return 0;
}



==================


  #include <stdio.h>

int main()
{
    int n, exams; // n = number of students, exams = # exams students took
    int i, j, k; // assigned loop values.
    
    //UI prompt for # students in the class, assigned to n 
	printf("How many students are in the class? ");
    scanf("%d", &n);

	//UI for exams each student completed, assigned to exams 
    printf("How many exams were given? ");
    scanf("%d", &exams);

    char name[n][20]; // name := 2D Array, stores each student's name 
    int scores[n][exams]; // scores := 2D Array will store each student's exam score. 
    double average[n]; //defining average for each student's exam
    char grade[n]; //defining the array for each student's exam grade. 

    double sum;
    double classSum = 0;

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i+1);

        printf("Enter first name: ");
        scanf("%s", name[i]);

        sum = 0; // Lines 24-31 for -> sum = 0 -> promps for user input for each students name, loops until elements completed. after all student names are inserted, reset sum double to 0. 

        for(j = 0; j < exams; j++) // see next comment 
        {
            printf("Enter score for Exam %d: ", j+1);
            scanf("%d", &scores[i][j]);

            sum += scores[i][j];
        } // Prompts for each exam score, runs loop x1 per exam administered. 

        average[i] = sum / exams;
        classSum += average[i];

        if(average[i] >= 89.5)
            grade[i] = 'A';
        else if(average[i] >= 79.5)
            grade[i] = 'B';
        else if(average[i] >= 69.5)
            grade[i] = 'C';
        else if(average[i] >= 59.5)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }

    double classAverage = classSum / n;

    double sorted[n];
    double temp;

    for(i = 0; i < n; i++)
        sorted[i] = average[i];

    for(i = 0; i < n; i++)
    {
        for(k = 0; k < n-1; k++)
        {
            if(sorted[k] > sorted[k+1])
            {
                temp = sorted[k];
                sorted[k] = sorted[k+1];
                sorted[k+1] = temp;
            }
        }
    }

    double median;

    if(n % 2 == 1)
        median = sorted[n/2];
    else
        median = (sorted[n/2 - 1] + sorted[n/2]) / 2;

    printf("\nSEMESTER GRADE REPORT\n\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d (%s)  Average: %.2f  Grade: %c\n",
               i+1, name[i], average[i], grade[i]);
    }

    printf("\nClass Average: %.2f\n", classAverage);
    printf("Class Median: %.2f\n", median);

    return 0;
}

====================


  #include <stdio.h>   // allows the program to use input/output functions like printf and scanf

int main()           // main function where program execution begins
{
    int n, exams;   // n = number of students, exams = number of exams given
    int i, j, k;    // loop counters used throughout the program

    printf("How many students are in the class? ");   // ask user for number of students
    scanf("%d", &n);                                  // read the integer entered and store in n

    printf("How many exams were given? ");             // ask user for number of exams
    scanf("%d", &exams);                               // read the integer entered and store in exams

    char name[n][20];        // 2D array storing student names (up to 20 characters each)
    int scores[n][exams];    // 2D array storing exam scores for each student
    double average[n];       // array storing each student's average score
    char grade[n];           // array storing each student's letter grade

    double sum;              // temporary variable used to accumulate exam scores
    double classSum = 0;     // variable to accumulate all student averages for class average

    for(i = 0; i < n; i++)   // loop runs once for each student
    {
        printf("\nStudent %d:\n", i+1);   // display which student is currently being entered

        printf("Enter first name: ");     // prompt user for student's first name
        scanf("%s", name[i]);             // store the entered name in the name array

        sum = 0;                          // reset sum before collecting exam scores

        for(j = 0; j < exams; j++)        // loop runs once for each exam
        {
            printf("Enter score for Exam %d: ", j+1);   // prompt for exam score
            scanf("%d", &scores[i][j]);                 // store score in 2D score array

            sum += scores[i][j];                        // add exam score to running total
        }

        average[i] = sum / exams;       // compute average score for the student
        classSum += average[i];         // add student average to total class sum

        if(average[i] >= 89.5)          // check if student qualifies for an A
            grade[i] = 'A';             // assign letter grade A
        else if(average[i] >= 79.5)     // check if student qualifies for a B
            grade[i] = 'B';             // assign letter grade B
        else if(average[i] >= 69.5)     // check if student qualifies for a C
            grade[i] = 'C';             // assign letter grade C
        else if(average[i] >= 59.5)     // check if student qualifies for a D
            grade[i] = 'D';             // assign letter grade D
        else                            // otherwise student receives an F
            grade[i] = 'F';             // assign letter grade F
    }

    double classAverage = classSum / n;   // compute overall class average

    double sorted[n];    // create array to store averages for sorting
    double temp;         // temporary variable used when swapping values during sorting

    for(i = 0; i < n; i++)     // loop copies averages into sorting array
        sorted[i] = average[i];   // copy student average into sorted array

    for(i = 0; i < n; i++)         // outer loop of bubble sort algorithm
    {
        for(k = 0; k < n-1; k++)   // inner loop compares adjacent elements
        {
            if(sorted[k] > sorted[k+1])   // check if current value is larger than next value
            {
                temp = sorted[k];         // store current value temporarily
                sorted[k] = sorted[k+1];  // move smaller value to earlier position
                sorted[k+1] = temp;       // place stored value into next position
            }
        }
    }

    double median;      // variable that will store class median

    if(n % 2 == 1)      // check if number of students is odd
        median = sorted[n/2];   // median is the middle value of the sorted array
    else                        // if number of students is even
        median = (sorted[n/2 - 1] + sorted[n/2]) / 2;   // median is the average of the two middle values

    printf("\nSEMESTER GRADE REPORT\n\n");   // print title for report section

    for(i = 0; i < n; i++)   // loop prints results for each student
    {
        printf("Student %d (%s)  Average: %.2f  Grade: %c\n",
               i+1, name[i], average[i], grade[i]);   // print student number, name, average, and grade
    }

    printf("\nClass Average: %.2f\n", classAverage);   // display overall class average
    printf("Class Median: %.2f\n", median);            // display class median

    return 0;   // end program successfully
}
