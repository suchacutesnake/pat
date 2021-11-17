//1030 Travel Plan (30 point(s))
#include <iostream>
#include <vector>
int mindis = 0x3f3f3f3f, mincost = 0x3f3f3f3f;
std::vector<int> res;
void dfs(const std::vector<std::vector<std::vector<int> > >& mp, const int& D, int dis, int cost, std::vector<int>& vis) {
    if (dis > mindis) return;
    if (vis.back() == D) {
        if (dis < mindis) {
            mindis = dis;
            mincost = cost;
            res = vis;
        } else if (dis == mindis) {
            if (cost < mincost) {
                mincost = cost;
                res = vis;
            }
        }
        return;
    }
    for (int i = 0; i < vis.size() - 1; ++i) if (vis[i] == vis.back()) return;
    for (auto& v : mp[vis.back()]) {
        vis.emplace_back(v[0]);
        dfs(mp, D, dis + v[1], cost + v[2], vis);
        vis.pop_back();
    }
}
int main() {
    int N, M, S, D;
    scanf("%d %d %d %d\n", &N, &M, &S, &D);
    //start city -> {{endcity1, distance1, cost1}, {endcity2, distance2, cost2}, ...}
    std::vector<std::vector<std::vector<int> > > mp(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c, d; //City1 City2 Distance Cost
        scanf("%d %d %d %d", &a, &b, &c, &d);
        mp[a].push_back({b, c, d});
        mp[b].push_back({a, c, d});
    }
    std::vector<int> vis({S});
    dfs(mp, D, 0, 0, vis);
    for (int& x : res) printf("%d ", x);
    printf("%d %d", mindis, mincost);
    return 0;
}