//1019 General Palindromic Number (20 point(s))
#include <iostream>
#include <vector>
int main() {
    int N, b;
    std::cin >> N >> b;
    
    //decimal to b base
    std::vector<int> a;
    while (N) {
        a.push_back(N % b);
        N /= b;
    }

    //yes or no
    bool yes = 1;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[n - i - 1] != a[i]) {
            yes = 0;
            break;
        }
    }
    if (yes) printf("Yes\n");
    else printf("No\n");
    for (int i = n - 1; i >= 0; --i) {
        std::cout << a[i];
        if (i != 0) printf(" ");
    }
    return 0;
}