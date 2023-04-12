#include<bits/stdc++.h>
using namespace std;
vector<long> vv;
bool check(vector<long>& v, int a, int b) {
    if (a>=v.size() || b == 0 || a == b) return 1;
    vector<long> v1(b-a), v2(b-a);
    v1.front() = v[a], v2.back() = v[b-1];
    for (int i = 1; i < b-a; ++i) {
        v1[i] = max(v1[i-1], v[a+i]);
        v2[b-a-i-1] = min(v2[b-a-i], v[b-i-1]);
    }
    vector<int> idx;
    for (int i = 0; i < b-a; ++i) {
        if (v1[i] == v2[i]) {
            idx.push_back(i);
        }
    }
    if (idx.empty()) return 0;
    bool f = 0;
    if (a == 0 && b == v.size()) {
        for (auto i : idx) f |= (check(v,a,i) && check(v,i+1,b));
    }
    return 1;
}
int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int N;
        cin >> N;
        vector<long> v(N);
        for (int j = 0; j < N; ++j) cin >> v[j];
        if (check(v,0,N)) printf("Yes");
        else printf("No");
        if (i != K-1) printf("\n");
    }
    return 0;
}