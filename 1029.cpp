//1029 Median (25 point(s))
#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    int a, b;
    std::vector<int> v;
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {scanf("%d", &b); v.emplace_back(b);}
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {scanf("%d", &b); v.emplace_back(b);}
    int n = (v.size() - 1) >> 1;
    std::nth_element(v.begin(), v.begin() + n, v.end());
    std::cout << v[n];
    return 0;
}