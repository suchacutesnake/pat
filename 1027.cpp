//1027 Colors in Mars (20 point(s))
#include <iostream>
#include <algorithm>
std::string decimal_to_13(int& a) {
    std::string b;
    while (a) {
        int c = a % 13;
        b.push_back((c < 10 ? c + '0' : c + 'A'));
        a /= 13;
    }
    if (b.empty()) b.push_back('0');
    if (b.size() == 1) b.push_back('0');
    std::reverse(b.begin(), b.end());
    return b;
}
int main() {
    int r, g, b;
    std::cin >> r >> g >> b;
    std::string R = decimal_to_13(r), G = decimal_to_13(g), B = decimal_to_13(b);
    std::cout << '#' << R << G << B;
    return 0;
}