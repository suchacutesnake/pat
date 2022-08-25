//1052 Linked List Sorting
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main() {
    int N;
    cin >> N;
    string head;
    cin >> head;
    vector<pair<int, string>> v, vv;//value to address
    unordered_map<string, string> u;
    for (int i = 0; i < N; ++i) {
        int a;
        string s, t;
        cin >> s >> a >> t;
        u[s] = t;
        v.push_back({a, s});
    }
    unordered_set<string> l;
    while (u.count(head)) {
        l.emplace(head);
        head = u[head];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) if (l.count(v[i].second)) vv.push_back(v[i]);
    int n = l.size();
    if (!n) {printf("0 -1"); return 0;}
    printf("%d %s", l.size(), v[0].second.c_str());
    for (auto it = vv.begin(); it != vv.end();) {
        printf("\n");
        printf("%s %d %s", it->second.c_str(), it->first, (++it == vv.end()? "-1" : it->second.c_str()));
    }
    return 0;
}