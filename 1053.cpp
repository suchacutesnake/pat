//1053 Path of Equal Weight
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, S;
vector<vector<int>> res;
struct Node {
    int val;
    vector<int> c;//children
};
bool cmp(vector<int>& a, vector<int>& b) {
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 0;
}
void bfs(vector<int> path, int sum, int id, vector<Node>& v) {
    if (sum + v[id].val > S) return;
    path.push_back(v[id].val);
    if (sum + v[id].val == S && v[id].c.empty()) {
        res.emplace_back(path);
        return;
    }
    for (auto ch : v[id].c) {
        bfs(path, sum + v[id].val, ch, v);
    }
}
int main() {
    cin >> N >> M >> S;
    vector<Node> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].val;
    }
    for (int i = 0; i < M; ++i) {
        int ID, K;
        cin >> ID >> K;
        for (int j = 0; j < K; ++j) {
            int ch; //child
            cin >> ch;
            v[ID].c.push_back(ch);
        }
    }
    vector<int> path;
    bfs(path, 0, 0, v);
    sort(res.begin(), res.end(), cmp);
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        int m = res[i].size();
        for (int j = 0; j < m; ++j) {
            printf("%d", res[i][j]);
            if (j != m - 1) printf(" ");
        }
        if (i != n - 1) printf("\n");
    }
    return 0;
}