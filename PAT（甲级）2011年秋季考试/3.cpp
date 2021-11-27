//C Battle Over Cities (25 point(s))
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void helper(unordered_map<int, vector<int> >& mp, unordered_set<int>& vis, int start) {
    if (vis.count(start)) return;
    vis.insert(start);
    for (auto& v : mp[start]) {
        helper(mp, vis, v);
    }
}
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    unordered_map<int, vector<int> > mp;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (int i = 0; i < K; ++i) {
        int con;
        cin >> con;
        unordered_set<int> vis({con});
        int repair = -1;
        for (int i = 1; i <= N; ++i) {
            if (vis.count(i)) continue;
            ++repair;
            helper(mp, vis, i);
        }
        cout << repair;
        if (i != K - 1) cout << endl;
    }
    return 0;
}