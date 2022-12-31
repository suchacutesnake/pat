//1063 Set Similarity
#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;
int main() {
    int N, K;
    cin >> N;
    vector<unordered_set<int> > v(N);
    for (int i = 0; i < N; ++i) {
        int a;cin >> a;
        for (int j = 0; j < a; ++j) {
            int b; cin >> b;
            v[i].emplace(b);
        }
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        float Nc = 0, Nt = 0;
        for (int x : v[a]) ++Nt;
        for (int x : v[b]) {
            if (v[a].count(x)) ++Nc;
            else ++Nt;
        }
        float p = Nc/Nt;
        printf("%.1f%%", p * 100);
        if (K != i + 1) printf("\n");
    }
    return 0;
}