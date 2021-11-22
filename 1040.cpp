//1040 Longest Symmetric String (25 point(s))
#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int res = 1, n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i - j >= 0 && i + j < n; ++j) {
            if (s[i-j] == s[i+j]) {if (2*j+1 > res) res = 2*j+1;}
            else break;
        }
        for (int j = 1; i - j + 1 >= 0 && i + j < n; ++j) {
            if (s[i-j+1] == s[i+j]) {if (2 * j > res) res = 2 * j;}
            else break;
        }
    }
    cout << res;
    return 0;
}