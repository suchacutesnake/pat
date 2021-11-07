//1012 The Best Rank (25 point(s))
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> //std::sort()
int main() {
    int N, M;
    std::cin >> N >> M;
    //id -> [A,C,M,E]
    std::unordered_map<int, std::vector<double> > mp;
    //sort vector
    std::vector<std::vector<double> > sv(4, std::vector<double>(N));
    for (int i = 0; i < N; ++i) {
        //v : [A,C,M,E]
        std::vector<double> v(4);
        int id;
        //id, C, M, E
        scanf("%d %lf %lf %lf", &id, &v[1], &v[2], &v[3]);
        int sum = 0;
        for (int j = 1; j < 4; ++j) sum += v[j];
        //A
        v[0] = sum / 3;
        for (int j = 0; j < 4; ++j) sv[j][i] = v[j];
        mp[id] = v;
    }
    char c[4] = {'A', 'C', 'M', 'E'};
    //sort all grades, different i represents different subjects
    for (int i = 0; i < 4; ++i) sort(sv[i].begin(), sv[i].end(), std::greater<double>());
    for (int i = 0; i < M; ++i) {
        int id;
        //current input student id
        std::cin >> id;
        if (!mp.count(id)) printf("N/A");
        else {
            //highest index
            int hidx = -1;
            int rank = 2001;
            //determine rank in different subjucts
            for (int idx = 0; idx < 4; ++idx) {
                //j is current rank
                for (int j = 0; j < N; ++j) {
                    //sv[idx][j] is the grade of the (j+1)th student under subject idx
                    //mp[id][idx] is the grade of input id under subject idx
                    if (sv[idx][j] == mp[id][idx]) {
                        //if this is the best rank
                        if (j + 1 < rank) {
                            //record the subject
                            hidx = idx;
                            //record the rank
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