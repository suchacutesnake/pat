//1060 Are They Equal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//print string
string ps(string& s, int N) {
    int n = s.size();
    string ret = "0.";
    //point position
    int pos = n;
    for (int i = 0; i < n; ++i) if (s[i] == '.') {
        pos = i;
        break;
    }
    //determine exponent
    int exp = 0, i;
    
    if (s[0] == '0') {
        for (i = pos + 1; i < n; ++i) if (s[i] == '0') --exp; else break;
        for (int j = 0; j < N; ++j) if (i+j < n) ret +=s[i+j]; else ret += '0';
    } else {
        for (i = 0; i < pos; ++i) ++exp;
        for (int j = 0; j < N; ++j) if (j >= n) ret += '0';
            else if (s[j] == '.') ++N;
            else ret += s[j];
    }
    
    ret += "*10^";
    ret += to_string(exp);
    return ret;
}
int main() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    //clear pre zero
    while (!A.empty() && A[0] == '0') if (A.size() > 1 && A[1] != '.')A.erase(0, 1); else break;
    while (!B.empty() && B[0] == '0') if (B.size() > 1 && B[1] != '.')B.erase(0, 1); else break;

    //all zero
    bool z = 1;
    for (int i = 0; i < A.size(); ++i) if (A[i] != '0' && A[i] != '.') {z = 0; break;}
    if (z) A = "0";
    z = 1;
    for (int i = 0; i < B.size(); ++i) if (B[i] != '0' && B[i] != '.') {z = 0; break;}
    if (z) B = "0";

    string a = ps(A, N), b = ps(B, N);
    if (a == b) printf("YES %s", a.c_str());
    else printf("NO %s %s", a.c_str(), b.c_str());
    return 0;
}