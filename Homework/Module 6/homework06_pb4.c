// Finding the perfect numbers between 2 values. 

#include <stdio.h>

int main(void)
{
    // User inputs for range
    int low, high, t, n, d, other, sum, found; //Declaring all integers bc C99 error. 

    printf("Enter lower limit number greater than zero:\n"); if (scanf("%d", &low) != 1) { printf("Invalid input.\n"); return 1; }
    printf("Enter upper limit number:\n"); if (scanf("%d", &high) != 1) { printf("Invalid input.\n"); return 1; }
    if (low <= 0 || high <= 0) { printf("Invalid input: limits must be positive integers.\n"); return 1; }
    if (low > high) { t = low; low = high; high = t; } // Swap the values of Low and High if numbers were inputed in reverse order.

    printf("Perfect numbers between %d and %d:\n", low, high); //prints the range for checked perfect numbers

    found = 0;
    for (n = low; n <= high; n++) //looping every integer in the range.
    {
        if (n < 2) continue; //skips 1 and below since perfect numbers have to be greater than 1

        sum = 1; // 1 is a proper divisor of any n>1

        for (d = 2; d * d <= n; d++) //checks the divisors for 2 to sqrt of 'n'
        {
            if (n % d == 0) //if d divides n evenly, its proper divisor
            {
                sum += d; 
                other = n / d;
                if (other != d) sum += other;
            }
        }

        if (sum == n && n != 1) { printf("%d\n", n); found = 1; } // if sum of divisors = n, its perf .. print value and mark as found.  
    }

    if (!found) printf("No perfect numbers in the given range.\n");
    
    return 0;
}
