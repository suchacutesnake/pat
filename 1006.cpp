#include <iostream>
#include <vector>
using namespace std;
int main() {
    int M;
    cin >> M;
    vector<vector<string> > v(M, vector<string>(3));
    for (int i = 0; i < M; ++i) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    string fid = v[0][0], lid = v[0][0];
    string ftime = v[0][1], ltime = v[0][2];
    for (auto& a : v) {
        if (a[1] < ftime) {
            ftime = a[1];
            fid = a[0];
        }
        if (a[2] > ltime) {
            ltime = a[2];
            lid = a[0];
        }
    }
    cout << fid << " " << lid;
    return 0;
}