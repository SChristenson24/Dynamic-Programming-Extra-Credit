#include <stdio.h>
#include <stdlib.h>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffUtil(int n, int k, int** dp) {
    // If value in lookup table then return
    if (dp[n][k] != -1)
        return dp[n][k];

    // store value in a table before return
    if (k == 0 || k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }

    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) + binomialCoeffUtil(n - 1, k, dp);
    return dp[n][k];
}

int binomialCoeff(int n, int k) {
    // Allocate memory for the lookup table
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((k + 1) * sizeof(int));
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1; // Initialize the lookup table with -1
        }
    }

    int result = binomialCoeffUtil(n, k, dp);

    // Free the memory allocated for the lookup table
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, k;
    printf("Please input n: ");
    scanf("%d", &n);
    printf("Please input k: ");
    scanf("%d", &k);

    printf("Value of C(%d, %d) is %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
