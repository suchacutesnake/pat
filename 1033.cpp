//1033 To Fill or Not to Fill (25 point(s))
//test case: https://www.cnblogs.com/ldudxy/p/11515967.html
//train of thought: https://blog.csdn.net/jal517486222/article/details/99707984
#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(std::pair<double, double>& p1, std::pair<double, double>& p2) {
    return p1.second < p2.second;
}
int main() {
    double Cmax, Davg, D;
    int N;
    scanf("%lf %lf %lf %d\n", &Cmax, &D, &Davg, &N);
    std::vector<std::pair<double, double> > sta(N + 1);
    for (int i = 0; i < N; ++i) scanf("%lf %lf", &sta[i].first, &sta[i].second);
    sta[N] = std::make_pair(0x3f3f3f3f, D);
    std::sort(sta.begin(), sta.end(), cmp);
    if (sta[0].second != 0) {printf("The maximum travel distance = 0.00"); return 0;}
    double cost = 0, maxDis = Cmax * Davg, final_dis = 0, carry = 0;
    int cur_sta = 0; //current station
    while (sta[cur_sta].second != D) {
        int pre = cur_sta++;
        bool no_sta = 1, cheaper = 0;
        for (int i = cur_sta; i <= N && sta[i].second - sta[pre].second <= maxDis; ++i) {
            no_sta = 0;
            if (sta[i].first <= sta[pre].first) {
                cur_sta = i;
                cheaper = 1;
                break;
            }
            if (sta[i].first < sta[cur_sta].first) cur_sta = i;
        }
        if (no_sta) {
            final_dis = sta[pre].second + maxDis;
            break;
        }
        if (cheaper) {
            cost += (sta[cur_sta].second - sta[pre].second - carry) * sta[pre].first / Davg;
            carry = 0;
        }
        else {
            if (sta[pre].second + maxDis <= D)
            cost += sta[pre].first / Davg * (maxDis - carry);
            else {
                cost += (D - sta[pre].second - carry) * sta[pre].first / Davg;
                break;
            }
            carry = maxDis - (sta[cur_sta].second - sta[pre].second);
        }
    }
    if (final_dis) printf("The maximum travel distance = %.02lf", final_dis);
    else printf("%.2lf", cost);
    return 0;
}