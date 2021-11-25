//score 55/120, rank1351/7951
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int main1() { //7-1 考试周 (5 point(s))
    int a, b;
    cin >> a >> b;
    printf("%d/%.01lf=%d",a, (double)a/(double)b, b);
    return 0;
}
int main2() { //7-2 真的恭喜你 (10 point(s))
    int a;
    cin >> a;
    a >= 90 ? printf("gong xi ni kao le %d fen!", a) : printf("kao le %d fen bie xie qi!", a);
    return 0;
}
int main3() { //7-3 平均成绩 (10 point(s))
    int N;
    cin >> N;
    vector<double> m, f;
    for (int i = 0; i < N; ++i) {
        int gender;
        double score;
        cin >> gender >> score;
        if (gender) m.push_back(score);
        else f.push_back(score);
    }
    double summ = 0, sumf = 0;
    for (auto& a : m) summ += a;
    for (auto& b : f) sumf += b;
    printf("%.01lf ", (summ + sumf) / (double)(f.size() + m.size()));
    if (m.empty()) printf("X ");
    else printf("%.01lf ", summ / (double)m.size());
    if (f.empty()) printf("X");
    else printf("%.01lf", sumf / (double)f.size());
    return 0;
}
int main4() { //7-4 古风A+B (15 point(s))
    int A, B;
    cin >> A >> B;
    int C = A + B;
    string s = to_string(C);
    int n = s.size();
    cout << s[0];
    for (int i = 1; i < n; ++i) {
        cout << endl << s[i];
    }
    return 0;
}
int main5() { //7-5 猜近似数字 (15 point(s))
    string a, b;
    cin >> a >> b;
    int d = a.size();
    vector<string> v;
    while (b != "-1") {
        v.emplace_back(b);
        b.clear();
        cin >> b;
    }
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].size() != d) {printf("No");}
        else {
            bool f = 0, e = 0;
            for (int j = 0; j < d; ++j) {
                if (v[i][j] == a[j]) continue;
                if (!e && abs(v[i][j] - a[j]) == 1) e = 1;
                else {printf("No"); f = 1; break;}
            }
            if (!f) printf("Yes");
        }
        if (i != n - 1) cout << endl;
        
    }
    return 0;
}

//not finished
void ying(string& s) {
    if (s == "Chuizi") printf("Bu");
    if (s == "Jiandao") printf("Chuizi");
    if (s == "Bu") printf("Jiandao");
}
void shu(string& s) {
    if (s == "Chuizi") printf("Jiandao");
    if (s == "Jiandao") printf("Bu");
    if (s == "Bu") printf("Chuizi");
}
int main6() { //7-6 随机输一次 (20 point(s))
    int N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    set<int> ss;
    for (int i = 0; i < N; ++i) {v[i] += i;ss.insert(v[i]);}
    int round = v.back();
    vector<string> vs;
    string s;
    while (s != "End") {
        cin >> s;
        vs.emplace_back(s);
    }
    int n = vs.size();
    for (int i = 0; i < n; ++i) {
        if (ss.count(i % round)) shu(vs[i]);
        else ying(vs[i]);
        if (i != n - 1) cout << endl;
    }
    return 0;
}
//not finished
int main7() {
    int N, K;
    string s = to_string(N);
    int aa = s.size() - 1;
    if (s.back() > '5') ++aa;
    long long c;
    for (int i = 1; i <= N; ++i) c *= i;
    printf("%d %d", ,aa);
}