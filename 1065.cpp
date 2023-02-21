//1065 A+B and C (64bit)
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N;cin>>N;
    for (int j = 1; j <= N; ++j) {
        vector<int> a(64), b(64), c(64);
        string A, B, C;
        cin >> A >> B >> C;
        bool aa=1,bb=1,cc=1;
        if (A[0]=='-') {aa=0;A.erase(0,1);}
        if (B[0]=='-') {bb=0;B.erase(0,1);}
        if (C[0]=='-') {cc=0;C.erase(0,1);}
        for (int i = A.size(); i >= 1; --i) a[64-i]=aa?A[A.size()-i]-'0':-(A[A.size()-i]-'0');
        for (int i = B.size(); i >= 1; --i) b[64-i]=bb?B[B.size()-i]-'0':-(B[B.size()-i]-'0');
        for (int i = C.size(); i >= 1; --i) c[64-i]=cc?C[C.size()-i]-'0':-(C[C.size()-i]-'0');
        for (int i = 0; i < 64; ++i) {
            if (a[i] + b[i] > c[i]) {
                printf("Case #%d: true\n",j);
                break;
            }
            if (i == 63) printf("Case #%d: false\n",j);
        }
    }
    return 0;
}