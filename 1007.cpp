//similar to leetcode 53
//https://leetcode-cn.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int K;
    cin >> K;
    vector<int> v(K);
    for (int i = 0; i < K; ++i) cin >> v[i];
    vector<int> ans({-1, v.front(), v.back()});
    vector<int> pre({v[0], v[0], v[0]});
    if (pre[0] > ans[0]) ans = pre;
    for (int i = 1; i < K; ++i) {
        int temp = pre[0] + v[i];
        if (temp >= v[i]) {
            pre[2] = v[i];
            pre[0] = temp;
        } else {
            pre = {v[i], v[i], v[i]};
        }
        if (pre[0] > ans[0]) ans = pre;
    }
    if (ans[0] == -1) ans[0] = 0;
    printf("%d %d %d", ans[0], ans[1], ans[2]);
    return 0;
}