/* Initial plan ::

	Define variables we know that we need ..
	# students = n
	# exams for semester = j


	-- Student's Name char name [n][20];
	-- Semester Averages across 'j' exams
	-- Assign a Letter Grade .. 89.5 rounds up, etc

	-- after all information inputed  compute & display:
	-> class Avg
	-> median semester average.main()

	finally, print format for sem avg.
	
	
	====================================================================

	PER PROF. JEONG, WE DO NOT NEED TO COLLECT THE STUDENT'S NAMES!!!!!

	====================================================================
	
	*/

#include <stdio.h>

int main()
{

	int n, exams; // n = # students, exams = # exams administered.
	int i, j, k; // loop variables for program
	

	//Asks user to input # students & exams.
	printf("How many students are in the class? ");
	scanf( "%d", &n);
	printf("How many exams were given? " );
	scanf("%d", &exams);

	printf("\n"); // formatting only

	//creating additional variables for the students.
	//char name [n][19]; // establishing 2D ARRAY for students' names, up to 19 characters per assignment.
	int scores [n][exams]; // Omg another 2D array, this one holds the scores for the exams for n exams
	double average [n]; //array to store the averages for the students
	char grade [n]; //Array that stores each students letter grade

	double sum; // going to use this to calculate the average, temporary placeholder
	double classSum; // check all stndt avg for the entire class averages


	for(i = 0; i < n; i++){
		printf("\nStudent %d: \n",i+1);
  		sum = 0; // resets sum before collecting Exam Scores
		
		for (j = 0; j < exams; j ++){
			printf("	Enter score for Exam %d: ", j+1); // Score for j+1, j starting at zero bc array
			scanf("%d", &scores[i][j]);
			
			sum+=scores [i][j];
		}
	average[i] = sum / exams;
	classSum += average[i];
	
	if(average[i]>= 89.5)
		grade[i]='A';
	else if(average[i]>=79.5)
		grade[i]='B';
	else if(average[i]>=69.5)
		grade[i]='C';
	else if(average[i]>=59.5)
		grade[i]='D';
	else
		grade[i]='F';

}

	//determining the class's Average grades, median
	double classAverage = classSum/n; //Hi TA, I lost my mind here because I was looking for why it wasnt providing me with the right output, alas I had it defined as an int instead of double.
	int sorted [n]; //creates the array to store the values while swapping
	int dummy;
	
	for(i = 0; i < n; i++)
		sorted[i] = average[i];

	//BUBBLE SORTING TIME!!!!! ---> actual purpose of this is to use nearest neighbor in making the order of the grades from least to greatest
	for( i = 0; i < n; ++i)
	{
		for(k = 0; k < n - 1; ++k)
		{
  			if(sorted[k] >= sorted[k+1])
			{
				dummy = sorted[k];
				sorted[k]=sorted[k+1];
				sorted[k+1]=dummy;
			}
		}
	}

    double median;      // variable that will store class median

    if(n % 2 == 1)      // check if number of students is odd
        median = sorted[n/2];   // median is the middle value of the sorted array
    else                        // if number of students is even
        median = (sorted[n/2 - 1] + sorted[n/2]) / 2;   // median is the average of the two middle values

		printf("\nSEMESTER GRADE REPORT\n\n");
		
		for(i=0;i<n;i++){
			printf("Student %d  Average: %0.2f  Grade: %c\n", i+1, average[i], grade[i]);
		}

	printf("\nClass Average: %0.2f\n", classAverage);
	printf("Class Median: %0.2f\n", median);



return 0;
}
