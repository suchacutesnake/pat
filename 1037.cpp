//1037 Magic Coupon (25 point(s))
//20:09
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int A, B;
    cin >> A;
    vector<long long> a(A);
    for (int i = 0; i < A; ++i) cin >> a[i];
    cin >> B;
    vector<long long> b(B);
    for (int i = 0; i < B; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long res = 0;
    int i;
    for (i = 0; i < A && i < B && a[i] <= 0; ++i) {
        if (b[i] > 0) break;
        res += a[i] * b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (i = 0; i < A && i < B && a[i] > 0; ++i) {
        if (b[i] <= 0) break;
        res += a[i] * b[i];
    }
    cout << res;
    return 0;
}