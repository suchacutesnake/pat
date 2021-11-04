#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
//shortest path length, maximun rescue teams, shortest path count
int spl = 0x3f3f3f3f, mrt = 0, spc = 0;
//helper function
//current city, visited city, city save, current path length, current rescue teams, map, rt
void helper(int& cr, unordered_set<int>& v, int& cs, int cpl, int crt, unordered_map<int, vector<pair<int, int>> >& mp, vector<int>& rt) {
    //reach city save
    if (cr == cs) {
        crt += rt[cr];
        if (cpl < spl) {
            spl = cpl;
            spc = 1;
            mrt = crt;
        } else if (cpl == spl) {
            ++spc;
            if (mrt < crt) mrt = crt;
        }
        return;
    }
    //circled
    if (v.count(cr)) return;
    v.insert(cr);
    for (auto& x:mp[cr]) {
        helper(x.first, v, cs, cpl + x.second, crt + rt[cr], mp, rt);
    }
    v.erase(cr);
}

int main() {
    //num cities, num roads
    int ns, nr;
    cin >> ns >> nr;
    //city current, city save
    int cc, cs;
    cin >> cc >> cs;
    //rescue team
    vector<int> rt(ns);
    for (int i = 0; i < ns; ++i) cin >> rt[i];
    //read roads
    //map[start]->[{destiny,road length}, {}, {}, ...]
    unordered_map<int, vector<pair<int, int>> > mp;
    for (int i = 0; i < nr; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    
    unordered_set<int> v;
    helper(cc, v, cs, 0, 0, mp, rt);
    printf("%d %d", spc, mrt);
}
