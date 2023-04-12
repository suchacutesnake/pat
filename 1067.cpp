#include<iostream>
#include<vector>
using namespace std;
int N, res = 0;
void dfs(int i, vector<int>& p, vector<int>& v) {
    if (v[i]) return;
    v[i] = 1;
    ++res;
    if (i == 0 || p[i] == i) res -= 2;
    dfs(p[i], p, v);
}
int main() {
    cin >> N;
    vector<int> p(N), v(N, 0);//permutation, visited
    for (int i = 0; i < N; ++i) {
        scanf("%d", &p[i]);
    }
    
    for (int i = 0; i < N; ++i) {
        if (v[i]) continue;
        dfs(i, p, v);
        ++res;
    }
    
    cout << res;
    return 0;
}