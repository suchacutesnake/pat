//1025 PAT Ranking (25 point(s))
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Testees {
public:
    int score;
    std::string id;
    int location_number;
    int local_rank;
    int final_rank;
};
bool my_cmp(Testees& t1, Testees& t2) {
    return t1.score == t2.score ? t1.id < t2.id : t1.score > t2.score;
}
int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<Testees> > locations(N + 1);
    std::vector<Testees> total;
    for (int i = 1; i <= N; ++i) {
        int K;
        std::cin >> K;
        auto& location = locations[i];
        location.resize(K);
        for (int j = 0; j < K; ++j) {
            Testees& testee = location[j];
            std::cin >> testee.id >> testee.score;
            testee.location_number = i;
        }
        //determine local_rank
        std::sort(location.begin(), location.end(), my_cmp);
        location.begin()->local_rank = 1;
        total.emplace_back(location.front());
        for (int j = 1; j < K; ++j) {
            if (location[j].score == location[j - 1].score)
                location[j].local_rank = location[j - 1].local_rank;
            else location[j].local_rank = j + 1;
            total.emplace_back(location[j]);
        }
    }
    //determine final_rank
    std::sort(total.begin(), total.end(), my_cmp);
    total.begin()->final_rank = 1;
    size_t n = total.size();
    std::cout << n << std::endl;
    for (int j = 1; j < n; ++j) {
        if (total[j].score == total[j - 1].score) 
            total[j].final_rank = total[j - 1].final_rank;
        else total[j].final_rank = j + 1;
    }
    for (int i = 0; i < n; ++i) {
        auto& testee = total[i];
        printf("%s %d %d %d", testee.id.c_str(), testee.final_rank, testee.location_number, testee.local_rank);
        if (i != n - 1) std::cout << std::endl;
    }
    return 0;
}