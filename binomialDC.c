#include <stdio.h>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k) {
    // Base cases
    if (k == 0 || k == n) {
        return 1;
    }

    // Recursively calculate C(n-1, k-1) + C(n-1, k)
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
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
