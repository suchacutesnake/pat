//1045 Favorite Color Stripe (30 point(s))
//The annotated version uses dfs, losing 6 points because of tle
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, L;
// void helper(const vector<vector<int> >& grid, int cnt, int i, int j, int pre, int& maxcnt) {
//     if (i == M || j == grid[i].size()) return;
//     if (j == 0) while (j < grid[i].size() && grid[i][j] < pre) ++j;
//     if (j != grid[i].size()) {
//         if (++cnt > maxcnt) maxcnt = cnt;
//         pre = grid[i][j];
//         helper(grid, cnt, i, j + 1, pre, maxcnt);
//     }
//     helper(grid, cnt, i + 1, 0, pre, maxcnt);
// }
int main() {
    cin >> N >> M;
    vector<int> love(M), colordp(N + 1);
    for (int i = 0; i < M; ++i) cin >> love[i];
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int color, maxx = 0;
        cin >> color;
        for (int j = 0; j < M; ++j) {
            maxx = max(maxx, colordp[love[j]]);
            if (love[j] == color) colordp[love[j]] = maxx + 1;
        }
    }
    // vector<int> stripe(L);
    // for (int i = 0; i < L; ++i) cin >> stripe[i];
    // vector<vector<int> > grid(M);
    // for (int i = 0; i < M; ++i) {
    //     for (int j = 0; j < L; ++j) {
    //         if (love[i] == stripe[j]) grid[i].emplace_back(j);
    //     }
    // }
    // int maxcnt = 0;
    // helper(grid, 0, 0, 0, -1, maxcnt);
    // cout << maxcnt;
    cout << *max_element(colordp.begin(), colordp.end());
    return 0;
}