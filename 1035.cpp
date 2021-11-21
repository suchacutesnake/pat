//1035 Password (20 point(s))
/* Simulated test, Problem 1035~1038.
 * Started at 2021.11.21 19:30
 * 19:43
 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<string, string> > v;
    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        bool m = 0;
        for (char& ch : b) if (ch == '1' || ch == '0' || ch == 'l' || ch == 'O') {
            if (ch == '1') ch = '@';
            if (ch == '0') ch = '%';
            if (ch == 'l') ch = 'L';
            if (ch == 'O') ch = 'o';
            m = 1;
        }
        if (m) v.push_back(make_pair(a,b));
    }
    if (v.empty()) {
        if (N == 1)
        cout << "There is " << N << " account and no account is modified";
        else cout << "There are " << N << " accounts and no account is modified";
        return 0;
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << ' ' << v[i].second;
        if (i != v.size() - 1) cout << endl;
    }
    return 0;
}