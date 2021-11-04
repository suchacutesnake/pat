//can also be accepted as a c program
#include <string.h>
#include <stdio.h>
int main() {
    int K1, K2, K = 0, a;
    double f1[1001], f2[1001], f[2001], b;
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    memset(f, 0, sizeof(f));
    scanf("%d", &K1);
    for (int i = 0; i < K1; ++i) {
        scanf("%d %lf", &a, &b);
        f1[a] = b;
    }
    scanf("%d", &K2);
    for (int i = 0; i < K2; ++i) {
        scanf("%d %lf", &a, &b);
        f2[a] = b;
    }
    for (int i = 0; i <= 1000; ++i) {
        if (f1[i]) for (int j = 0; j <= 1000; ++j) {
            if (f2[j]) f[i + j] += f1[i] * f2[j];
        }
    }
    for (int i = 0; i <= 2000; ++i) if (f[i]) ++K;
    printf("%d", K);
    for (int i = 2000; i >= 0; --i) {
        if (f[i]) printf(" %d %.1f", i, f[i]);
    }
    
    return 0;
}