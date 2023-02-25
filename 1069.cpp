//1069 The Black Hole of Numbers
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string step(string& s) {
    string a = s, b = s;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<char>());
    int x = stoi(a), y = stoi(b);
    if (x < y) swap(x, y);
    int z = x - y;
    printf("%04d - %04d = %04d", x, y, z);
    string ret = to_string(z);
    while (ret.size() != 4) ret.insert(0, "0");
    return ret;
}
int main() {
    string s, a, b;
    cin >> s;
    while (s.size() != 4) s.insert(0, "0");
    s = step(s);
    while (s != "0000" && s != "6174") {
        printf("\n");
        s = step(s);
    }
    return 0;
}