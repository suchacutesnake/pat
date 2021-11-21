//1038 Recover the Smallest Number (30 point(s))
//20:45 21 case016ac
//20:52 28 case2wa
//21:13 ac
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2) {
    string ss1 = s1 + s2, ss2 = s2 + s1;
    int n = ss1.size();
    for (int i = 0; i < n; ++i) {
        if (ss1[i] < ss2[i]) return 1;
        if (ss1[i] > ss2[i]) return 0;
    }
    return 0;
}
int main() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    string res;
    for (auto& s : v) res += s;
    while (res[0] == '0') res.erase(0, 1);
    if (res.empty()) res = "0";
    cout << res;
    return 0;
}