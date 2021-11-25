//7-3 Postfix Expression (25 point(s))
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Node {
public:
    string data;
    int l;
    int r;
};
void findRoot(int idx, unordered_set<int>& vis, vector<Node>& v) {
    if (vis.count(idx)) return;
    vis.emplace(idx);
    if (v[idx].l == -1 && v[idx].r == -1) return;
    if (v[idx].l != -1) findRoot(v[idx].l, vis, v);
    if (v[idx].r != -1) findRoot(v[idx].r, vis, v);
}
void helper(int idx, vector<Node>& v) {
    if (v[idx].l != -1) {
        printf("(");
        helper(v[idx].l, v);
        //printf(")");
    }
    if (v[idx].r != -1) {
        printf("(");
        helper(v[idx].r, v);
        //printf(")");
    }
    cout << v[idx].data << ")";
}
int main() {
    int N;
    cin >> N;
    vector<Node> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i].data >> v[i].l >> v[i].r;
    }
    int root = 0;
    unordered_set<int> vis;
    for (int i = 1; i <= N; ++i) {
        if (!vis.count(i)) {
            root = i;
            findRoot(i, vis, v);
        }
    }
    helper(root, v);
    return 0;
}