#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    int N, M;
    std::cin >> N >> M;
    std::unordered_map<int, std::vector<double> > mp;
    //sort vector
    std::vector<std::vector<int> > sv(4, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        std::vector<double> v(4);
        int id;
        scanf("%d %lf %lf %lf", &id, &v[0], &v[1], &v[2]);
        int sum = 0;
        for (int j = 0; j < 3; ++j) sum += v[j];
        v[3] = sum / 3;
        for (int j = 0; j < 4; ++j) sv[j][i] = v[j];
        mp[id] = v;
    }
    char c[4] = {'C', 'M', 'E', 'A'};
    for (int i = 0; i < 4; ++i) sort(sv[i].begin(), sv[i].end(), std::greater<double>());
    for (int i = 0; i < M; ++i) {
        int id;
        std::cin >> id;
        if (!mp.count(id)) printf("N/A");
        else {
            //highest index
            int hidx = -1;
            int rank = 2001;
            for (int idx = 3; idx >= 0; --idx) {
                for (int j = 0; j < N; ++j) {
                    if (sv[idx][j] == mp[id][idx]) {
                        if (j + 1 < rank) {
                            hidx = idx;
                            rank = j + 1;
                        }
                        break;
                    }
                }
            }
            printf("%d %c", rank, c[hidx]);
        }
        if (i != M - 1) printf("\n");
    }
}