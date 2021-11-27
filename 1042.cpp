//1042 Shuffling Machine (20 point(shuf))
#include <iostream>
#include <vector>
using namespace std;
void printHelper(int a) {
    --a;
    int b = a / 13;
    switch (b) {
        case 0 :
            cout << 'S';
            break;
        case 1 :
            cout << 'H';
            break;
        case 2 :
            cout << 'C';
            break;
        case 3 :
            cout << 'D';
            break;
        default:
            cout << 'J';
            break;
    }
    cout << a % 13 + 1;
}
int main() {
    int K;
    cin >> K;
    vector<int> v(55), shuf(55);
    for (int i = 1; i <= 54; ++i) {
        v[i] = i;
        cin >> shuf[i];
    }
    for (int i = 0; i < K; ++i) {
        vector<int> tmp(55);
        for (int j = 1; j <= 54; ++j) {
            tmp[shuf[j]] = v[j];
        }
        v = tmp;
    }
    printHelper(v[1]);
    for (int i = 2; i <= 54; ++i) {
        cout << ' ';
        printHelper(v[i]);
    }
    return 0;
}