//7-1 Prime Day (20 point(s))
//ac
#include <iostream>
#include <string>
using namespace std;
bool is_prime(string& s) {
    int a = stoi(s);
    if (a == 1 || a == 0) return 0;
    for (int i = 2; i < a; ++i) {
        if (a % i == 0) return 0;
    }
    return 1;
}
int main() {
    string s;
    cin >> s;
    bool all_prime = 1;
    while (!s.empty()) {
        string yn;
        if (is_prime(s)) yn = "Yes";
        else {
            yn = "No";
            all_prime = 0;
        }
        cout << s << ' ' << yn;
        s.erase(0, 1);
        if (!s.empty()) cout << endl;
    }
    if (all_prime) cout <<endl<< "All Prime!";
    return 0;
}