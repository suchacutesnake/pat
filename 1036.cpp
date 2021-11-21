//1036 Boys vs Girls (25 point(s))
//19:56
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Student {
public:
    string name;
    char gender;
    string ID;
    int grade;
};
bool cmp(Student s1, Student s2) {
    return s1.grade < s2.grade;
}
int main() {
    int N;
    cin >> N;
    vector<Student> m, f;
    for (int i = 0; i < N; ++i) {
        Student s;
        cin >> s.name >> s.gender >> s.ID >> s.grade;
        if (s.gender == 'M') m.emplace_back(s);
        else f.emplace_back(s);
    }
    if (f.empty()) cout << "Absent" << endl;
    else {
        sort(f.begin(), f.end(), cmp);
        cout << f.back().name << ' ' << f.back().ID << endl;
    }
    if (m.empty()) cout << "Absent" << endl;
    else {
        sort(m.begin(), m.end(), cmp);
        cout << m.front().name << ' ' << m.front().ID << endl;
    }
    if (m.empty() || f.empty()) cout << "NA";
    else cout << f.back().grade - m.front().grade;
    return 0;
}