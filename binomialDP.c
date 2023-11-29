#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);

int binomial(int n, int k) {
    int** c = (int**)malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; i++) {
        c[i] = (int*)malloc((k + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }

    int result = c[n][k];

    for (int i = 0; i <= n; i++) {
        free(c[i]);
    }

    free(c);

    return result;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, k;
    printf("Please input n: ");
    scanf("%d", &n);
    printf("Please input k: ");
    scanf("%d", &k);
    printf("C(%d, %d) is %d\n", n, k, binomial(n, k));

    return 0;
}
