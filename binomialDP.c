/* Name: Sydney Christenson                                                NetID: sac771

   Assignment:Extra Credit Programming Assignment                          Due Date: Wednesday, Nov. 29

   Sources/Notes:
   * Class slides
   * Referenced GeeksforGeeks, StackOverflow, and Spiceworks
   * Systems programming notes for timeval
   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int fmin(int a, int b);

int binomial(int n, int k) // calc bionomial
{
    // 2d array to store binomial coeffs
    int **c = (int **)malloc((n + 1) * sizeof(int *));
    // allocating mem
    for (int i = 0; i <= n; i++)
    {
        c[i] = (int *)malloc((k + 1) * sizeof(int));
    }
    // iterate over rows from 0 to n
    for (int i = 0; i <= n; i++)
    {
        // iterate over columns from 0 to min i and k
        for (int j = 0; j <= fmin(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                c[i][j] = 1;
            }
            else // recurrence
            {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }

    int result = c[n][k];
    // freeing allocated mem
    for (int i = 0; i <= n; i++)
    {
        free(c[i]);
    }

    free(c);

    return result;
}

long time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long)tv.tv_sec * 1000000 + tv.tv_usec;
}

int fmin(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, k;
    printf("Please input n: ");
    scanf("%d", &n);
    printf("Please input k: ");
    scanf("%d", &k);

    // start time
    long sTime = time();

    int result = binomial(n, k);

    // end time
    long eTime = time();

    // total time
    long totalTime = eTime - sTime;

    printf("c(%d, %d) is %d\n", n, k, result);
    printf("Time: %ld microseconds\n", totalTime);

    return 0;
}
