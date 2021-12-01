//1044 Shopping in Mars (25 point(s))
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    int l = 0, r = 0, sum = 0, over = 0x3f3f3f3f;
    vector<vector<int> > res;
    while (l < N) {
        while (r < N && sum < M) sum += v[r++];
        if (sum - M < over && sum - M >= 0) {
            over = sum - M;
            res.clear();
        }
        if (sum - M == over) res.push_back({l + 1, r});
        sum -= v[l++];
    }
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        printf("%d-%d", res[i][0], res[i][1]);
        if (i != n - 1) cout << endl;
    }
    return 0;
}