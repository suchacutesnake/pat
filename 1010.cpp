//1010 Radix (25 point(s))
//o(1) algorithm fails at case7(Time Limit Exceeded)
//I guess case7 is similar to: 10 9999999990 2 10
#include <iostream>
#include <math.h>
//Why use long long instead of int?
//N1 and N2 contains 10 digits at most, each digit has 36 posibilities(0~9,a~z).
//The largest number N1 and N2 can indicate is 36 ^ 10 , about 3.66e+15.
//long long can hold 9.2e18 > 3.66e+15 while int can hold 2.1e+9 < 3.66e+15
//If we choose int, we can't store the correct decimal number the tag points to.
//However, I assumed that radix is less than 37 here, what if radix becomes very
//big, say, 100? Then even long long can't store the correct number.
//Shouldn't the question add a condition "radix <= 36"?
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
        //why mid < 0? To avoid overflow: if mid > 0x7fff ffff ffff ffff,
        //then it would become a negative value.
        //How could mid > 0x7fff ffff ffff ffff?
        //Because n can be much more bigger than 36. For example, n = 100,
        //then midr > 50, so mid may > 0x7fff ffff ffff ffff
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