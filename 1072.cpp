#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;
unordered_map<string, vector<pair<int, string> > > um;
void dijk(unordered_map<string, int>& dist, unordered_set<string>& vis, priority_queue<pair<int, string> >& pq, int& minDis, int& sumDis) {
    auto cur = pq.top().second;
    pq.pop();
    if (vis.count(cur)) return;
    for (auto& p : um[cur]) {
        auto& a = p.first;
        auto& b = p.second;
        if (vis.count(b)) continue;
        if (!dist.count(b)) {
            dist[b] = dist[cur] + a;
        } else {
            sumDis -= dist[b];
            dist[b] = min(dist[b], dist[cur] + a);
        }
        if (dist[b] < minDis) minDis = dist[b];
        sumDis += dist[b];
        pq.push({dist[b], b});
    }
    vis.emplace(cur);
}
int main() {
    int N, M, K, Ds;
    cin >> N >> M >> K >> Ds;
    for (int i = 0; i < K; ++i) {
        string P1, P2;
        int dest;
        cin >> P1 >> P2 >> dest;
        um[P1].push_back({dest, P2});
        um[P2].push_back({dest, P1});
    }
    vector<pair<int, int> > m(M+1);
    for (int i = 1; i <= M; ++i) {
        string initial = "G";
        initial.push_back(i+'0');
        unordered_map<string, int> dist;
        unordered_set<string> vis;
        int minDis = 0x3f3f3f3f, sumDis = 0;
        dist[initial] = 0;
        priority_queue<pair<int, string> > pq;
        pq.push({0, initial});
        while (!pq.empty()) dijk(dist, vis, pq, minDis, sumDis);
        m[i] = {minDis, sumDis};
    }
    for (int i = 1; i <= M; ++i) printf("Gas Station number=%d, minDis=%d, sumDis=%d\n", i, m[i].first, m[i].second);
    return 0;
}