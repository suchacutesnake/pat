//1021 Deepest Root (25 point(s))
//strongly recommend : https://www.bilibili.com/video/BV1Mt4y197kC?p=21  (Chinese)
#include <iostream>
#include <vector>
#include <set>
//find deepest root helper
void helper(std::set<int>& vis, std::vector<std::vector<int> >& mp, int node, int len, int& imaxlen, std::set<int>& nodelenmax2) {
    if (vis.count(node)) return;
    if (len > imaxlen) {
        imaxlen = len;
        nodelenmax2.clear();
        nodelenmax2.insert(node);
    } else if (len == imaxlen) nodelenmax2.insert(node);
    vis.insert(node);
    for (int& x : mp[node]) helper(vis, mp, x, len + 1, imaxlen, nodelenmax2);
}
//determine components
void dc(std::vector<std::vector<int> >& mp, int node, std::set<int>& visited, int len, int& maxlen, std::set<int>& nodelenmax) {
    if (visited.count(node)) return;
    if (len > maxlen) {
        maxlen = len;
        nodelenmax.clear();
        nodelenmax.insert(node);
    } else if (len == maxlen) nodelenmax.insert(node);
    visited.insert(node);
    for (int& x : mp[node]) dc(mp, x, visited, len + 1, maxlen, nodelenmax);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int> > mp(N + 1);
    for (int i = 1; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    //determine components in the graph
    std::set<int> visited, nodelenmax;
    int com = 0, startmaxlen = 0;
    for (int start = 1; start <= N; ++start) {
        if (visited.count(start)) continue;
        ++com;
        dc(mp, start, visited, 0, startmaxlen, nodelenmax);
    }
    if (com > 1) {
        printf("Error: %d components", com);
        return 0;
    }
    //is tree
    int imaxlen = 0;
    std::set<int> vis, nodelenmax2;
    helper(vis, mp, *nodelenmax.begin(), 0, imaxlen, nodelenmax2);
    
    for (const int& x : nodelenmax2) nodelenmax.insert(x);
    std::set<int>::iterator it = nodelenmax.begin();
    while (it != nodelenmax.end()) {
        std::cout << *it++ << std::endl;
    }
    return 0;
}