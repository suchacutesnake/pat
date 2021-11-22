//1039 Course List for Student (25 point(s))
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    unordered_map<string, vector<int> > mp;
    for (int i = 0; i < K; ++i) {
        int idx, n;
        cin >> idx >> n;
        for (int j = 0; j < n; ++j) {
            string name;
            cin >> name;
            mp[name].emplace_back(idx);
        }
    }
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        cout << name;
        cout << ' ' << mp[name].size();
        sort(mp[name].begin(), mp[name].end());
        for (auto& s : mp[name]) cout << ' ' << s;
        if (i != N - 1) cout << endl;
    }
    return 0;
}