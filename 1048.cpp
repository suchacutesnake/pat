//1048 Find Coins
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> v;
    for (int i = 0; i < N; ++i) {int a;cin>> a;++v[a];}
    int i;
    for (auto& [a, b] : v) {
        --b;
        if (v[M - a] > 0) {
            printf("%d %d", a, M - a);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}