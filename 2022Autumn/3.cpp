#include<bits/stdc++.h>
using namespace std;
struct User {
    unordered_set<int> fo;//follow, fans, leader fans
    int lfa = 0, fa = 0;
    bool isLeader = 0;
};
int main() {
    int N, T;
    cin >> N >> T;
    vector<User> v(N+1);
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            int b;
            cin >> b;
            v[i].fo.insert(b);
            v[b].fa++;
        }
    }
    for (int i = 1; i <= N; ++i) {
        int a = v[i].fa, b = v[i].fo.size();
        if (!b) continue;
        if (a / b >= T) v[i].isLeader = 1;
    }
    for (int i = 1; i <= N; ++i) {
        if (!v[i].isLeader) continue;
        for (int a : v[i].fo) ++v[a].lfa;
    }
    vector<int> res;
    int lfam = 0;//leader fan max
    for (int i = 1; i <= N; ++i) {
        if (!v[i].isLeader) continue;
        if (v[i].lfa > lfam) {
            lfam = v[i].lfa;
            res.clear();
            res.push_back(i);
        } else if (v[i].lfa == lfam) res.push_back(i);
    }

    sort(res.begin(), res.end());
    int tt = res.size();
    for (int i = 0; i < tt; ++i) {
        printf("%d", res[i]);
        if (i != tt - 1) printf(" ");
    }
    return 0;
}