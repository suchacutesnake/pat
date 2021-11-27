//A World Cup Betting (20 point(s))
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<char> vc(3);
    double vd = 1;
    for (int i = 0; i < 3; ++i) {
        double w, t, l;
        cin >> w >> t >> l;
        if (w > t && w > l) {
            vc[i] = 'W';
            vd *= w;
        } else if (t > w && t > l) {
            vc[i] = 'T';
            vd *= t;
        } else {
            vc[i] = 'L';
            vd *= l;
        }
    }
    for (char& ch : vc) printf("%c ", ch);
    printf("%.02lf", (vd * 0.65 - 1) * 2);
    return 0;
}