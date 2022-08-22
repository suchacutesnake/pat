//1049 Counting Ones
#include<iostream>
#include<cmath>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long x = (i!=0?stoll(s.substr(0, i)):0);
        long long y = (i!=n-1?stoll(s.substr(i + 1, n-i-1)):0);
        if (s[i] == '0') {
            res += x * pow(10, n - i - 1);
        }
        else if (s[i] == '1') {
            res += x * pow(10, n-i-1) + y + 1;
        }
        else {
            res +=(x+1)*pow(10, n - i - 1);
        }
        //printf("%lld,%lld\n",x,y);
    }
    printf("%lld", res);
    return 0;
}