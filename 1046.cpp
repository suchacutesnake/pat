//1046 Shortest Distance (20 point(s))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    cin >> N;
    vector<int> v(N + 2, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i+1];
        v[i+1] += v[i];
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << min(v[b] - v[a], v[N + 1] - (v[b] - v[a]));
        if (i != M - 1) cout << endl;
    }
    return 0;
}