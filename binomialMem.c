/* Name: Sydney Christenson                                                NetID: sac771

   Assignment:Extra Credit Programming Assignment                          Due Date: Wednesday, Nov. 29

   Sources/Notes:
   * Class slides
   * Referenced GeeksforGeeks, StackOverflow, and Spiceworks
   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int binomial(int n, int k, int **c)
{
    // if value in lookup table
    if (c[n][k] != -1)
        return c[n][k];

    // store value in table
    if (k == 0 || k == n)
    {
        c[n][k] = 1;
        return c[n][k];
    }

    // save value in table
    c[n][k] = binomial(n - 1, k - 1, c) + binomial(n - 1, k, c);
    return c[n][k];
}

long time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long)tv.tv_sec * 1000000 + tv.tv_usec;
}

int biValue(int n, int k)
{
    // allocate mem for table
    int **c = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        c[i] = (int *)malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++)
        {
            c[i][j] = -1; // initialize the table with -1
        }
    }

    int result = binomial(n, k, c);

    // free the mem for table
    for (int i = 0; i <= n; i++)
    {
        free(c[i]);
    }
    free(c);

    return result;
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

    int result = biValue(n, k);

    // end time
    long eTime = time();

    // total time
    long totalTime = eTime - sTime;

    printf("c(%d, %d) is %d\n", n, k, result);
    printf("Time: %ld microseconds\n", totalTime);

    return 0;
}
