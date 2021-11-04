#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b, result;
    cin >> a >> b;
    result = a + b;
    string output = to_string(result);
    if(output.length() > 3) {
        if(output[output.length() - 4] != '-') {
            output.insert(output.length() - 3, ",");
        }
    }
    if(output.length() > 7) {
        if(output[output.length() - 8] != '-') {
            output.insert(output.length() - 7, ",");
        }
    }
    cout << output << endl;
    return 0;
}