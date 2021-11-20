//1034 Head of a Gang (30 point(s))
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Person {
public:
    Person() {
        time = 0;
        gang = -1;
    }
    int time;     /* call time length */
    int gang;     /* belongs to gangs[gang] */
};
int main() {
    int N, K;
    cin >> N >> K;
    map<int, set<string> > gangs;
    map<string, Person> people;
    int A = 0;
    for (int i = 0; i < N; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        people[a].time += c;
        people[b].time += c;
        if (people[a].gang == -1 && people[b].gang == -1) {
            set<string> newgang({a, b});
            people[a].gang = A;
            people[b].gang = A;
            gangs[A++] = newgang;
        } else if (people[a].gang == -1) {
            people[a].gang = people[b].gang;
            gangs[people[b].gang].emplace(a);
        } else if (people[b].gang == -1) {
            people[b].gang = people[a].gang;
            gangs[people[a].gang].emplace(b);
        } else if (people[a].gang != people[b].gang) {
            int d = people[b].gang;
            for (const string& name : gangs[d]) {
                people[name].gang = people[a].gang;
                gangs[people[name].gang].emplace(name);
            }
            gangs.erase(d);
        }
    }

    /* exclude gangs sumtime < K or less than 3 people */
    vector<int> exc;
    for (auto& [a, b] : gangs) {
        int totaltime = 0;
        for (auto& name : b) totaltime += people[name].time;
        if (totaltime <= K * 2 || b.size() <= 2) exc.emplace_back(a);
    }
    for (int& a : exc) gangs.erase(a);

    /* find head of each gang */
    int n = gangs.size();
    cout << n << endl;
    vector<pair<string, int> > print;
    for (auto& [a, b] : gangs) {
        string head;
        int maxtime = 0;
        for (auto& name : b) if (people[name].time > maxtime) {
            maxtime = people[name].time;
            head = name;
        }
        print.push_back(make_pair(head, b.size()));
    }
    sort(print.begin(), print.end());

    for (int i = 0; i < n; ++i) {
        cout << print[i].first << ' ' << print[i].second;
        if (i != n - 1) cout << endl;
    }
    return 0;
}