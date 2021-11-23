//7-4 Replacement Selection (30 point(s))
//score: 17/30
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    vector<vector<int> > vv(N/M+1);
    for (int i = 0; i < N; ++i) {
        int level = 0;
        while (vv[level].size() >= M && v[i] < *(vv[level].end() - M)) {
            ++level;
        }
        if (vv[level].size() < M) {
            vv[level].push_back(v[i]);
            if (vv[level].size() == M)
                sort(vv[level].begin(), vv[level].end());
            continue;
        }
        vv[level].push_back(v[i]);
        sort(vv[level].end() - M, vv[level].end());
    }
    int n = vv.size();
    for (int i = 0; i < n; ++i) {
        int nn = vv[i].size();
        if (!nn) break;
        if (i != 0) cout << endl;
        cout << vv[i].front();
        for (int j = 1; j < nn; ++j) printf(" %d", vv[i][j]);
    }
    return 0;
}