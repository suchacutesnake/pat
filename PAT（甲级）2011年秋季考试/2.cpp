//B The Best Rank (25 point(s))
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Student {
public:
    double C, M, E, A;
    int rank;
    char sub;
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<double> a(N), c(N), m(N), e(N);
    unordered_map<string, Student> mp;
    for (int i = 0; i < N; ++i) {
        string id;
        cin >> id;
        cin >> mp[id].C >> mp[id].M >> mp[id].E;
        mp[id].A = ((double)mp[id].C + (double)mp[id].E + (double)mp[id].M) / (double)3;
        a[i] = (mp[id].A);
        c[i] = (mp[id].C);
        m[i] = (mp[id].M);
        e[i] = (mp[id].E);
    }
    sort(a.begin(), a.end(), greater<double>());
    sort(c.begin(), c.end(), greater<double>());
    sort(m.begin(), m.end(), greater<double>());
    sort(e.begin(), e.end(), greater<double>());
    for (auto& [_id, stu] : mp) {
        for (int i = 0; i < N; ++i) if (a[i] == stu.A) {stu.rank = i + 1;stu.sub = 'A'; break;}
        for (int i = 0; i < N; ++i) if (c[i] == stu.C) {
            if (i + 1 < stu.rank) {stu.rank = i + 1;stu.sub = 'C';}
            break;
        }
        for (int i = 0; i < N; ++i) if (m[i] == stu.M) {
            if (i + 1 < stu.rank) {stu.rank = i + 1;stu.sub = 'M';}
            break;
        }
        for (int i = 0; i < N; ++i) if (e[i] == stu.E) {
            if (i + 1 < stu.rank) {stu.rank = i + 1;stu.sub = 'E';}
            break;
        }
    }
    for (int i = 0; i < K; ++i) {
        string __id;
        cin >> __id;
        if (!mp.count(__id)) cout << "N/A";
        else {
            cout << mp[__id].rank << ' ' << mp[__id].sub;
        }
        if (i != K - 1) cout << endl;
    }
    return 0;
}