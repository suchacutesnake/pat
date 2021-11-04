#include <stdio.h>
int main() {
    int pre = 0, N, res = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        res += 5;
        int cur;
        scanf("%d", &cur);
        if (cur > pre) res += (cur - pre) * 6;
        else res += (pre - cur) * 4;
        pre = cur;
    }
    printf("%d", res);
    return 0;
}
//floor: 0     2   3     1
// time: 5 6 6 5 6 5 4 4 0