//1013 Battle Over Cities (25 point(s))
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//check connected cities
void helper(std::unordered_set<int>& vis, std::unordered_map<int, std::vector<int> >& mp, int& start, int& occupied) {
    if (vis.count(start) || start == occupied) return;
    vis.insert(start);
    for (auto& city : mp[start]) {
        helper(vis, mp, city, occupied);
    }
}
int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::unordered_map<int, std::vector<int> > mp;
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    //the city not occupied
    std::unordered_set<int> remain;
    for (int i = 1; i <= N; ++i) remain.insert(i);
    for (int i = 0; i < K; ++i) {
        int occupied;
        std::cin >> occupied;
        remain.erase(occupied);
        //the city we can visited
        std::unordered_set<int> vis;
        //travel through all cities, starting from city 1
        int start = 1, repair = -1;
        while (vis != remain) {
            //pass all visited cities
            while (vis.count(start) && start <= N || start == occupied) ++start;
            ++repair;
            helper(vis, mp, start, occupied);
        }
        printf("%d", repair);
        remain.insert(occupied);
        if (i != K - 1) printf("\n");
    }
    return 0;
}