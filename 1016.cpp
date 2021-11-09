//1016 Phone Bills (25 point(s))
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
double get_cost(std::vector<double>& rate,int& d1,int& d2,int& h1,int& h2,int &m1,int& m2) {
    double cost1 = 0, cost2 = 0, sum = 0, ret = 0;
    for (auto& x : rate) sum += x;
    ret += (sum * 60) * (double)(d2 - d1);
    for (int i = 0; i < h1; ++i) cost1 += 60 * rate[i];
    cost1 += rate[h1] * (double)m1;
    for (int i = 0; i < h2; ++i) cost2 += 60 * rate[i];
    cost2 += rate[h2] * (double)m2;
    ret += cost2 - cost1;
    return ret;
}
bool cmp(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
    return a.first < b.first;
}
int main() {
    std::vector<double> rate(24, 0);
    for (int i = 0; i < 24; ++i) {
        std::cin >> rate[i];
        rate[i] /= 100;
    }
    int N;
    std::cin >> N;
    std::unordered_map<std::string, std::vector<std::pair<std::string, std::string> > > mp;
    for (int i = 0; i < N; ++i) {
        std::string name, time, status;
        std::cin >> name >> time >> status;
        mp[name].push_back({time, status});
    }

    //process data
    std::vector<std::string> name_list;
    for (auto& [a, b] : mp) {
        name_list.push_back(a);
        std::sort(b.begin(), b.end(), cmp);
        //discards records that do not paired
        while (!b.empty() && b[0].second[1] != 'n') b.erase(b.begin());//pass case 3
        for (int i = 1; i < b.size(); ++i) {
            auto nn = a;//for debug
            if (b[i].second[1] == 'n') {
                if (b[i-1].second[1] == 'n') {
                    b.erase(b.begin() + i - 1);
                    --i;
                }
            } else {
                if (b[i-1].second[1] == 'f') {
                    b.erase(b.begin() + i);
                    --i;
                }
            }
        }
        if (b.size() % 2) b.erase(b.end() - 1);
    }

    //print data
    sort(name_list.begin(), name_list.end());
    for (auto& name : name_list) {
        //No output while input is invalid
        if (mp[name].empty()) continue;
        printf("%s %c%c\n", name.c_str(), mp[name][0].first[0], mp[name][0].first[1]);
        int n = mp[name].size();
        double sum = 0;
        for (int i = 0; i < n; i += 2) {
            for (int j = 3; j <= 10; ++j) {
                std::cout << mp[name][i].first[j];
            }
            std::cout << ' ';
            for (int j = 3; j <= 10; ++j) {
                std::cout << mp[name][i + 1].first[j];
            }
            int d1,d2,h1,h2,m1,m2;
            d1 = atoi(mp[name][i].first.substr(3,2).c_str());
            h1 = atoi(mp[name][i].first.substr(6,2).c_str());
            m1 = atoi(mp[name][i].first.substr(9,2).c_str());
            d2 = atoi(mp[name][i+1].first.substr(3,2).c_str());
            h2 = atoi(mp[name][i+1].first.substr(6,2).c_str());
            m2 = atoi(mp[name][i+1].first.substr(9,2).c_str());
            std::cout << ' ' << (d2 - d1) * 60 * 24 + (h2 - h1) * 60 + (m2 - m1);
            double cost = get_cost(rate, d1,d2,h1,h2,m1,m2);
            printf(" $%.2lf\n", cost);
            sum += cost;
        }
        printf("Total amount: $%.2lf\n", sum);
    }
    return 0;
}