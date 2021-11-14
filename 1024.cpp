//1024 Palindromic Number (25 point(s))
#include <iostream>
#include <string>
#include <algorithm>
void sum_string(std::string& n, std::string& s) {
    int m = n.size(), carry = 0;
    for (int i = m - 1; i >= 0; --i) {
        int sum = n[i] + s[i] - '0' - '0' + carry;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else carry = 0;
        n[i] = sum + '0';
    }
    if (carry) n.insert(n.begin(), '1');
}
int main() {
    int K;
    std::string n;
    std::cin >> n >> K;
    for (int i = 0; i < K; ++i) {
        std::string s = n;
        reverse(s.begin(), s.end());
        if (s == n) {
            K = i;
            break;
        } else {
            sum_string(n, s);
        }
        
    }
    printf("%s\n%d", n.c_str(), K);
    return 0;
}