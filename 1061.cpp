//1061 Dating
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<string> v(4);
    for (int i = 0; i < 4; ++i) cin >> v[i];
    int d = -1000, h, m, n1 = min(v[0].size(), v[1].size()), n2 = min(v[2].size(), v[3].size());
    for (int i = 0; i < n1; ++i) {
        char c = v[0][i];
        if (d != -1000 && c == v[1][i]) {
            if ('0' <= c && c <= '9') {
                h = c - '0';
                break;
            } else if ('A' <= c && c <= 'N') {
                h = c - 'A' + 10;
                break;
            }
        }
        if (d == -1000 && c == v[1][i] && c >= 'A' && c <= 'G') d = c - 'A';
    }
    for (int i = 0; i < n2; ++i) {
        char c = v[2][i];
        if (c == v[3][i] && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z'))) {
            m = i;
            break;
        }
    }
    string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s %02d:%02d", day[d].c_str(), h, m);
    return 0;
}