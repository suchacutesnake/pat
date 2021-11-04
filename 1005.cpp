#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (char& ch : s) {
        sum += ch - '0';
    }
    vector<string> v({"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"});
    string res = to_string(sum);
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        cout << v[res[i] - '0'];
        if (i != n - 1) cout << " ";
    }
    return 0;
}