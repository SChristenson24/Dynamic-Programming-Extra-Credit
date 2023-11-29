#include <stdio.h>

// Given recurrence in pdf
int binomialCoeff(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

// added this for consistency
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
