//7-4 Dijkstra Sequence (30 point(s))
//25points
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
void helper(unordered_map<int, vector<pair<int, int> > >& mp, int& minlen, int len, int start, int& target, unordered_set<int>& vis) {
    if (len > minlen) return;
    if (start == target) {
        if (len < minlen) minlen = len;
        return;
    }
    for (auto& pa : mp[start]) {
        if (vis.count(pa.first)) continue;
        vis.insert(pa.first);
        helper(mp, minlen, len + pa.second, pa.first, target, vis);
        vis.erase(pa.first);
    }
}
int main() {
    int Nv, Ne;
    cin >> Nv >> Ne;
    unordered_map<int, vector<pair<int, int> > > mp;
    for (int i = 0; i < Ne; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    int K;
    cin >> K;
    vector<vector<int> > que(K, vector<int>(Nv));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < Nv; ++j) cin >> que[i][j];
    }
    for (int i = 0; i < K; ++i) {
        int preminlen = 0;
        bool yes = 1;
        for (int j = 1; j < Nv; ++j) {
            int minlen = 0x3f3f3f3f;
            unordered_set<int> vis({que[i][j]});
            helper(mp, minlen, 0, que[i][j], que[i][0], vis);
            if (minlen < preminlen) {
                yes = 0;
                break;
            }
            preminlen = minlen;
        }
        if (yes) printf("Yes");
        else printf("No");
        if (i != K - 1) printf("\n");
    }
    return 0;
}