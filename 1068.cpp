//1068 Find More Coins
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
bool dfs(const vector<int>& v, vector<int>& ans, int sum, int cursor) {
    if (sum + v[cursor] > M) return 0;
    ans.emplace_back(v[cursor]);
    sum += v[cursor];
    if (sum == M) return 1;
    for (int i = cursor + 1; i < N && sum + v[i] <= M; ++i) {
        if (dfs(v, ans, sum, i)) return 1;
        while (i+1 < N && v[i] == v[i+1]) ++i;
    }
    ans.pop_back();
    return 0;
}
int main() {
    cin >> N >> M;
    vector<int> v(N), ans;
    for (int i = 0; i < N; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    if (dfs(v, ans, 0, 0)) {
        for (int i = 0; i < ans.size(); ++i) {
            if (i == 0) printf("%d", ans[i]);
            else printf(" %d", ans[i]);
        }
    } else printf("No Solution");
    return 0;
}