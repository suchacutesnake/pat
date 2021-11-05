//1010 Radix (25 point(s))
#include <iostream>
#include <math.h>
//string to decimal int
int stdi(std::string& a, int& rad) {
    int n = a.size(), r = 0;
    for (int i = 0; i < n; ++i) {
        r += (a[i] > '9' ? a[i] - 'a' + 10 : a[i] - '0') * pow(rad, (n - i - 1));
    }
    return r;
}

int main() {
    std::string N1, N2, N;
    int tag, n = 0, radix;
    std::cin >> N1 >> N2 >> tag >> radix;
    if (tag == 1) {
        n = stdi(N1, radix);
        N = N2;
    }
    if (tag == 2) {
        n = stdi(N2, radix);
        N = N1;
    }
    char ch = '0';
    for (char& cc : N) {
        if (cc > ch) ch = cc;
    }
    bool res = 0;
    //left radix, current number, right radix
    int cr = (ch > '9' ? ch - 'a' + 10 : ch - '0') + 1, cn = 0, rr = n;
    while (cn <= n) {
        if (cn == n) {
            res = 1;
            std::cout << cr - 1;
            break;
        }
        cn = stdi(N, cr);
        ++cr;
    }
    if (!res) std::cout << "Impossible";
    return 0;
}