//1047 Student List for Course (25 point(s))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<string> > cor_stu(K + 1);
    for (int i = 0; i < N; ++i) {
        char ch[4];
        int n;
        scanf("%s %d", ch, &n);
        string name(ch);
        for (int j = 0; j < n; ++j) {
            int cor;
            scanf("%d", &cor);
            cor_stu[cor].emplace_back(name);
        }
    }
    for (int i = 1; i <= K; ++i) {
        sort(cor_stu[i].begin(), cor_stu[i].end());
        int lines = cor_stu[i].size();
        printf("%d %d\n", i, lines);
        for (int j = 0; j < lines; ++j) printf("%s\n", cor_stu[i][j].c_str());
    }
    return 0;
}