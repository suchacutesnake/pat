#include<bits/stdc++.h>
using namespace std;
int main() {
    long long N, K, i = 1;
    cin >> N;
    K = N;
    map<long long, int> m;
    while (K != 1) {
        ++i;
        while (K % i == 0) {
            K /= i;
            ++m[i];
        }
    }
    printf("%lld=", N);
    if (N==1) printf("1");
    for (map<long long, int>::iterator it = m.begin(); it != m.end();) {
        if (it->second != 1) {
            printf("%lld^%d", it->first, it->second);
        } else printf("%lld", it->first);
        if (++it != m.end()) printf("*");
    }
    return 0;
}