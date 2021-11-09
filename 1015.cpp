//1015 Reversible Primes (20 point(s))
#include <iostream>
#include <cmath>
std::string to_D(int a, int& D) {
    std::string str;
    while (a) {
        str += a % D + '0';
        a /= D;
    }
    //notice that str is reversed
    return str;
}
int to_decimal(std::string& a, int& D) {
    int n = a.size(), dec = 0;
    for (int i = 0; i < a.size(); ++i) dec += (a[i] - '0') * pow(D, n - i - 1);
    return dec;
}
bool is_prime(int& a) {
    if (a == 1) return 0;//1 is not a prime
    for (int i = 2; i < a; ++i) if (!(a % i)) return 0;
    return 1;
}
int main() {
    int N, D;
    std::cin >> N;
    while (N > 0) {
        std::cin >> D;
        std::string a = to_D(N, D);
        int d = to_decimal(a, D);
        if (is_prime(N) && is_prime(d)) printf("Yes");
        else printf("No");
        std::cin >> N;
        printf("\n");
    }
    return 0;
}