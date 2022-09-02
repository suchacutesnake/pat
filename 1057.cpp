//1057 Stack
//reference:
//https://blog.csdn.net/m0_63520117/article/details/123977820
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
map<int, int> m;
map<int, int> :: iterator it = m.begin();
int preit = 0;
void moveit() {
    int mid = (st.size() + 1) / 2;
    if (preit >= mid) {
        --it;
        preit -= it->second;
    } else if (preit + it->second < mid) {
        preit += it->second;
        ++it;
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s == "Push") {
            int key;
            cin >> key;
            st.push(key);
            ++m[key];
            if (key < it->first) ++preit;
            moveit();
            continue;
        }
        if (s == "Pop") {
            if (st.empty()) printf("Invalid");
            else {
                printf("%d", st.top());
                --m[st.top()];
                if (st.top() < it->first) --preit;
                moveit();
                if (!m[st.top()]) m.erase(st.top());
                st.pop();
            }
        }
        if (s == "PeekMedian") {
            if (st.empty()) printf("Invalid");
            else printf("%d", it->first);
        }
        if (i != N - 1) printf("\n");
    }
    return 0;
}