//1011 World Cup Betting (20 point(s))
//Could also be admitted in c.
#include <stdio.h>
int main() {
    double f[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char ch[3] = {'W', 'T', 'L'};
    double mul = 1;
    for (int i = 0; i < 3; ++i) {
        scanf("%lf %lf %lf", &f[i][0], &f[i][1], &f[i][2]);
        //largest number in one line
        double ln = 0;
        //index of the largest number in that line
        int idx = 0;
        for (int j = 0; j < 3; ++j) {
            if (f[i][j] > ln) {
                ln = f[i][j];
                idx = j;
            }
        }
        mul *= ln;
        printf("%c ", ch[idx]);
    }
    printf("%.2lf", (mul * 0.65 - 1) * 2);
    return 0;
}