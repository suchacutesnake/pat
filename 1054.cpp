//1054 The Dominant Color
#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
    int M, N;
    cin >> M >> N;
    unordered_map<int, int> u;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int a;
            cin >> a;
            ++u[a];
        }
    }
    int res = -1, cnt = -1;
    for (auto& [a, b] : u) {
        if (b > cnt) {
            cnt = b;
            res = a;
        }
    }
    cout << res;
    return 0;
}