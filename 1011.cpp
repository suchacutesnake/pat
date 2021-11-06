//1011 World Cup Betting (20 point(s))
//Could also be admitted in c.
#include <stdio.h>
int main() {
    double f[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char ch[3] = {'W', 'T', 'L'};
    double mul = 1;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf %lf %lf", &f[i][0], &f[i][1], &f[i][2]);
        double t = 0;
        int c = 0;
        for (int j = 0; j < 3; ++j) {
            if (f[i][j] > t) {
                t = f[i][j];
                c = j;
            }
        }
        mul *= t;
        printf("%c ", ch[c]);
    }
    printf("%.2lf", (mul * 0.65 - 1) * 2);
    return 0;
}