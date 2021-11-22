//1041 Be Unique (20 point(s))
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int N;
    cin >> N;
    unordered_map<int, int> mp;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    for (int& x : v) ++mp[x];
    bool u = 0;
    for (int& x : v) if (mp[x] == 1) {u=1; cout << x; break;}
    if (!u) cout << "None";
    return 0;
}