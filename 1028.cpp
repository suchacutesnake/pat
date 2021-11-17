//1028 List Sorting (25 point(s))
#include <iostream>
#include <algorithm>
#include <vector>
class Student {
public:
    std::string id, name;
    int grade;
};
bool cmp1(Student& s1, Student& s2) {return s1.id < s2.id;}
bool cmp2(Student& s1, Student& s2) {return s1.name == s2.name ? s1.id < s2.id : s1.name < s2.name;}
bool cmp3(Student& s1, Student& s2) {return s1.grade == s2.grade ? s1.id < s2.id : s1.grade < s2.grade;}
int main() {
    int N, C;
    std::cin >> N >> C;
    std::vector<Student> sv(N);
    for (int i = 0; i < N; ++i) std::cin >> sv[i].id >> sv[i].name >> sv[i].grade;
    if (C == 1) std::sort(sv.begin(), sv.end(), cmp1);
    if (C == 2) std::sort(sv.begin(), sv.end(), cmp2);
    if (C == 3) std::sort(sv.begin(), sv.end(), cmp3);
    for (int i = 0; i < N; ++i) std::cout << sv[i].id << ' ' << sv[i].name << ' ' << sv[i].grade << std::endl;
    return 0;
}