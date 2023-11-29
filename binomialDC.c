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

// Given recurrence in pdf
int biValue(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return biValue(n - 1, k - 1) + biValue(n - 1, k);
}

long time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long)tv.tv_sec * 1000000 + tv.tv_usec;
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