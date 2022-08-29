#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
struct Person {
    string name;
    int age;
    int net_worth;
};
bool cmp(Person& a, Person& b) {
    if (a.net_worth == b.net_worth) {
        if (a.age == b.age) {
            return a.name < b.name;
        }
        return a.age < b.age;
    }
    return a.net_worth > b.net_worth;
}
int main() {
    int K, N, M;
    cin >> N >> K;
    vector<Person> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].name >> v[i].age >> v[i].net_worth;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= K; ++i) {
        printf("Case #%d:", i);
        int cnt = 0, amin, amax;
        cin >> M >> amin >> amax;
        for (int j = 0; j < N && cnt != M; ++j) {
            if (amin <= v[j].age && amax >= v[j].age) {
                printf("\n%s %d %d", v[j].name.c_str(), v[j].age, v[j].net_worth);
                ++cnt;
            }
        }
        if (!cnt) printf("\nNone");
        if (i != K) printf("\n");
    }
    return 0;
}