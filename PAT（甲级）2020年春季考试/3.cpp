//7-3 Safari Park (25 point(s))
//ac:1:15
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int N, R, K;
    cin >> N >> R >> K;
    vector<vector<int> > r(N + 1);
    for (int i = 0; i < R; ++i) {
        int a, b;
        cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        if (i != 0) cout << endl;
        vector<int> plan(N + 1);
        unordered_set<int> sp;
        for (int j = 1; j <= N; ++j) {
            cin >> plan[j];
            sp.insert(plan[j]);
        }
        if (sp.size() > K) {printf("Error: Too many species.");continue;}
        if (sp.size() < K) {printf("Error: Too few species.");continue;}
        bool f = 1;//feasible
        for (int j = 1; j <= N; ++j) {
            for (int& nei : r[j]) {
                if (plan[nei] == plan[j]) {
                    f = 0;
                    break;
                }
            }
            if (!f) break;
        }
        if(f) printf("Yes");
        else printf("No");
    }
    return 0;
}