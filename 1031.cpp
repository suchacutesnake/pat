//1031 Hello World for U (20 point(s))
#include <iostream>
int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int n1 = (n + 2) / 3;
    if (n1 < 3) {
        int n2 = n - 2;
        printf("%c",s.front());
        for (int i = 0; i < n2 - 2; ++i) printf(" ");
        printf("%c\n",s.back());
        for (int i = 1; i < n - 1; ++i) printf("%c", s[i]);
        return 0;
    }
    int n2 = n - 2 * n1;
    for (int i = 0; i < n1 - 1; ++i) {
        printf("%c", s[i]);
        for (int j = 0; j < n2; ++j) printf(" ");
        printf("%c\n", s[n-i-1]);
    }
    for (int i = 0; i <= n2+1; ++i) {
        printf("%c", s[n1+i-1]);
    }
    return 0;
}