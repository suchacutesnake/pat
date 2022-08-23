//1050 String Subtraction
#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    string s1, s2, res;
    getline(cin, s1);
    getline(cin, s2);
    unordered_set<char> u;
    for (char ch : s2) u.insert(ch);
    for (char ch : s1) if (!u.count(ch)) res += ch;
    cout << res;
    return 0;
}