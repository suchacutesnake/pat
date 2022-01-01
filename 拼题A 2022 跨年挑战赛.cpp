//score:55/120, rank:about 120
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main1() {
    int a, b;
    cin >> a >> b;
    cout << a + b - 1;
    return 0;
}
int main2() {
    int a = 0, b = 0, c = 0;
    while (c != -1) {
        cin >> c;
        if (c == 1) ++a;
        if (c == 0) ++b;
    }
    if (a > b) cout << "Yes" << endl;
    else if (a < b) cout << "No" << endl;
    else cout << "Tie" << endl;
    printf("%d:%d", a, b);
    return 0;
}
int main3() {
    int a, b;
    cin >> a >> b;
    int chanshiguan = a + b;
    int awang = max(a, b);
    printf("%d %d\n", awang > 0 ? awang : 0, chanshiguan > 0 ? chanshiguan : 0);
    if (awang <= 0 && chanshiguan <= 0) printf("-_-");
    else if (chanshiguan > awang) printf("^_^");
    else printf("T_T");
    return 0;
}
int determinePrize(string& a, string& b) {
    if (a[3] != b[3]) return 5;
    if (a[2] != b[2]) return 4;
    if (a[1] != b[1]) return 3;
    if (a[0] != b[0]) return 2;
    return 1;
}
int main4() {
    int N;
    cin >> N;
    vector<string> v(N), buy(3);
    for (int i = 0; i < N; ++i) cin >> v[i];
    for (int i = 0; i < 3; ++i) cin >> buy[i];
    int maxPrize = 5;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j)
            maxPrize = min(maxPrize, determinePrize(buy[j], v[i]));
    }
    vector<string> jiang({"", "YiDengJiang!!!", "ErDengJiang", "SanDengJiang",
        "SiDengJiang", "WuDengJiang"});
    cout << jiang[maxPrize];
    return 0;
}
int main5() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool carry = 0;
    int n = b.size(), cnt = 0;
    for (int i = 0; i < n; ++i) {
        a[i] -= carry;
        if (a[i] < b[i]) {
            carry = 1;
            ++cnt;
        } else carry = 0;
    }
    while (carry) {
        a[n] -= carry;
        if (a[n] < '0') {
            carry = 1;
            ++cnt;
        } else carry = 0;
        ++n;
    }
    cout << cnt;
    return 0;
}
//6,7,8 all 0 score
int main6() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    int highest = *max_element(v.begin(), v.end());
    int left = highest, right = highest;
    for (int i = highest; i > 0; --i) {
        ;
    }
    return 0;
}
string traverseDate(string& s) {
    return "";
}
int main8() {
    string s, a, b, c;
    getline(cin, s);
    cin >> a >> c >> b;
    return 0;
}