//1010 Radix (25 point(s))
//o(1) algorithm fails at case7(Time Limit Exceeded)
//I guess case7 is similar to: 10 9999999990 2 10
#include <iostream>
#include <math.h>
using ll = long long;
//string to decimal long long
ll stdll(std::string& a, ll& rad) {
    ll n = a.size(), r = 0;
    for (ll i = 0; i < n; ++i) {
        r += (a[i] > '9' ? a[i] - 'a' + 10 : a[i] - '0') * pow(rad, (n - i - 1));
    }
    return r;
}

int main() {
    std::string N1, N2, N;
    ll tag, radix;
    std::cin >> N1 >> N2 >> tag >> radix;
    ll n = 0;
    if (tag == 1) {
        n = stdll(N1, radix);
        N = N2;
    }
    if (tag == 2) {
        n = stdll(N2, radix);
        N = N1;
    }
    char ch = '0';
    for (char& cc : N) {
        if (cc > ch) ch = cc;
    }

    bool flag = 1;
    ll lr = (ch > '9' ? ch - 'a' + 10 : ch - '0') + 1, rr = (n<lr?lr:n);
    while (lr <= rr) {
        ll midr = (lr + rr) >> 1;
        ll mid = stdll(N, midr);
        //printf("lr=%lld, rr=%lld, midr=%lld, mid=%lld\n", lr, rr, midr, mid);
        if (mid < 0 || mid > n) rr = midr - 1;
        else if (mid == n) {
            flag = 0;
            std::cout << midr;
            break;
        }
        else lr = midr + 1;
    }
    if (flag) std::cout << "Impossible";
    return 0;
}