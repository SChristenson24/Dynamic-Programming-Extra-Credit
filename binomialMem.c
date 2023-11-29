#include <stdio.h>
#include <stdlib.h>

int binomial(int n, int k, int **dp)
{
    // if value in lookup table
    if (dp[n][k] != -1)
        return dp[n][k];

    // store value in table
    if (k == 0 || k == n)
    {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // save value in table
    dp[n][k] = binomial(n - 1, k - 1, dp) + binomial(n - 1, k, dp);
    return dp[n][k];
}

int binomialCoeff(int n, int k)
{
    // allocate mem for table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1; // initialize the table with -1
        }
    }

    int result = binomial(n, k, dp);

    // free the mem for table
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main()
{
    int n, k;
    printf("Please input n: ");
    scanf("%d", &n);
    printf("Please input k: ");
    scanf("%d", &k);

    printf("Value of C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
