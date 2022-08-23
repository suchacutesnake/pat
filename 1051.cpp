//1051 Pop Sequence
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
    int N, M, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        stack<int> st;
        queue<int> q;
        bool flag = 1;
        for (int j = 1; j <= N; ++j) {
            int a;
            cin >> a;
            st.push(j);
            if (st.size() > M) {
                flag = 0;
                //break;
            }
            q.push(a);
            while (!st.empty() && !q.empty() && st.top() == q.front()) {
                st.pop();
                q.pop();
            }
        }
        if (flag && st.empty() && q.empty()) printf("YES");
        else printf("NO");
        if (i != K-1) printf("\n");
    }
    return 0;
}