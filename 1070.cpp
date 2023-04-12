//1070 Mooncake
//case2 : D is not an integer
//case3 : D > the sum of all inventory amounts 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, i;
double D;
struct Cake {
    double inventory, price, unit_price;
};
bool cmp(Cake c1, Cake c2) {
    return c1.unit_price > c2.unit_price;
}
int main() {
    cin >> N >> D;
    vector<Cake> cakes(N);
    for (i = 0; i < N; ++i) cin >> cakes[i].inventory;
    for (i = 0; i < N; ++i) {
        cin >> cakes[i].price;
        cakes[i].unit_price = cakes[i].price / cakes[i].inventory;
    }
    sort(cakes.begin(), cakes.end(), cmp);
    double res = 0;
    i = 0;
    while (D > 0 && i < N) {
        D -= cakes[i].inventory;
        res += cakes[i].price;
        if (D < 0) res -= -D * cakes[i].unit_price;
        ++i;
    }
    printf("%.2f", res);
    return 0;
}