//7-2 The Judger (25 point(s))
//Remaining Time:1:50 case5tle
//score 21/25
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    vector<int> exi(2);
    scanf("%d %d %d %d", &exi[0], &exi[1], &N, &M);
    vector<vector<int> > v(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) scanf("%d", &v[i][j]);
    }
    unordered_set<int> out, diff({abs(exi[0] - exi[1])}), exii({exi[0], exi[1]});
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (out.count(j)) continue;
            int& num = v[j][i];
            if (!diff.count(num) || exii.count(num)) {
                out.emplace(j);
                printf("Round #%d: %d is out.\n", i + 1, j + 1);
                continue;
            }
            for (auto& x : exi) diff.emplace(abs(x - num));
            exii.emplace(num);
            exi.emplace_back(num);
        }
    }
    vector<int> winner;
    for (int i = 0; i < N; ++i) {
        if (out.count(i)) continue;
        winner.emplace_back(i);
    }
    if (winner.empty()) printf("No winner.");
    else {
        printf("Winner(s):");
        for (int& x : winner) printf(" %d", x + 1);
    }
    return 0;
}