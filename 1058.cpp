//1058 A+B in Hogwarts
#include<iostream>
int main() {
    int g1, g2, s1, s2, k1, k2, ss = 0, gg = 0;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    if (k1 + k2 >= 29) ss = 1;
    if (s1 + s2 + ss >= 17) gg = 1;
    printf("%d.%d.%d", g1+g2+gg, (s1+s2+ss)%17, (k1+k2)%29);
    return 0;
}