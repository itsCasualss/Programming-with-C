/* array.c - Script 10.3 */

#include <stdio.h>
#include <stdlib.h>

int main (void) {

	/* Define an integer pointer variable. */
	int *x = NULL;
	int sum = 0;
	
	/* Define two integer variables. */
	int i, count;

	/* Prompt for the number of items. Store
	 * the user's reply in the count variable. */
	printf("Number of items? ");
	scanf("%d", &count);

 x = malloc(count*sizeof(int));
	/* We have omitted the check for NULL
	 * here. You must always check for a NULL
	 * return value from malloc(). */
for (i=0; i < count; i++)
	{
		x[i] = rand();
		sum=sum+x[i];}
	/* Print all values in the array. */
	for (i = 0; i < count; i++) {
		printf("The value of array element %d is %d.\n", i, x[i]);
	}

	/* Return the block to the pool. */
	free(x);
	x = NULL;
	/* Pause and wait for input before terminating. */
	getchar();
	getchar();

	return 0;

}
