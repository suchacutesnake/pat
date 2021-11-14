//1023 Have Fun with Numbers (20 point(s))
#include <iostream>
#include <vector>
int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> cnt(10, 0), cnt2(10, 0);
    int n = s.size(), carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        ++cnt[s[i] - '0'];
        int sum = s[i] - '0' + s[i] - '0' + carry;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else carry = 0;
        s[i] = sum + '0';
    }
    if (carry) s.insert(s.begin(), '1');
    for (int i = 0; i < n; ++i) ++cnt2[s[i] - '0'];
    if (s.size() != n || cnt2 != cnt) printf("No\n");
    else printf("Yes\n");
    for (char& ch : s) printf("%c",ch);
    return 0;
}