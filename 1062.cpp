//1062 Talent and Virtue
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, L, H;
struct Man{
    string id;
    int v;//virtue
    int t;//talent
    int r;//rank, 0 = sages, 1 = noble man, 2 = fool man, 3 = small man
    int s;
};
bool cmp(Man m1, Man m2) {
    return m1.r == m2.r?(m1.s == m2.s? (m1.v == m2.v? m1.id < m2.id : m1.v > m2.v) : m1.s > m2.s) : m1.r < m2.r;
}
int main() {
    cin >> N >> L >> H;
    vector<Man> mans;
    for (int i = 0; i < N; ++i) {
        string str;
        int a, b, c;
        cin >> str >> a >> b;
        if (a >= L && b >= L) {
            Man m;
            m.id = str;
            m.v = a;
            m.t = b;
            m.s = a + b;
            if (a >= H && b >= H) m.r = 0;
            else if (a >= H && b < H) m.r = 1;
            else if (a < H && a >= b) m.r = 2;
            else m.r = 3;
            mans.emplace_back(m);
        }
    }
    sort(mans.begin(), mans.end(), cmp);
    cout << mans.size();
    for (Man m : mans) {
        printf("\n%s %d %d", m.id.c_str(), m.v, m.t);
    }
    return 0;
}