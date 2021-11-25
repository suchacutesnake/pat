//7-1 Forever (20 point(s))
//10points
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
//is prime
bool ip(int a) {
    for (int i = 2; i < a / 2; ++i) {
        if (a % i == 0) return 0;
    }
    return 1;
}
//greatest common divisor
int gcd(int a, int b) {
    int ret = 1;
    for (int i = 2; i <= a / 2 && i <= b / 2; ++i) {
        if (!(a % i) && !(b % i)) ret = i;
    }
    return ret;
}
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        printf("Case %d\n", i);
        int K, m;
        cin >> K >> m;
        int small = 1;
        for (int i = 1; i < K; ++i) {
            small *= 10;
        }
        bool npr = 1; // not print
        vector<pair<int, int> > pr;
        for (int A = small; A < small * 10; ++A) {
            string s = to_string(A);
            int sumA = 0;
            for (char& ch :s) sumA += ch - '0';
            if (sumA == m) {
                int B = A + 1;
                string ss = to_string(B);
                int sumB = 0;
                for (char& ch : ss) sumB += ch - '0';
                int gg = gcd(sumA, sumB);
                if (gg > 2 && ip(gg)) {
                    pr.push_back({sumB, A});
                    //printf("%d %d\n", sumB, A);
                    npr = 0;
                }
            }
        }
        if (npr) printf("No Solution");
        else {
            int n = pr.size();
            for (int k = 0; k < n; ++k) {
                printf("%d %d", pr[k].first, pr[k].second);
                if (k != n - 1) printf("\n");
            }
        }
        if (i != K - 1) cout << endl;
    }
    return 0;
}