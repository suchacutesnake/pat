#include<bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
unordered_map<int, Node*> um;
int main() {
    int N; 
    cin >> N;
    vector<int> in(N), pre(N);
    for (int i = 0; i < N; ++i) cin >> in[N];
    for (int i = 0; i < N; ++i) cin >> pre[N];
    Node* root = new Node;
    root->val = pre[0];
    um[pre[0]] = root;
    for (int i = 1; i < N; ++i) {
        Node* node = new Node;
        node->val = pre[i];
        um[pre[i]] = node;
        int idx = -1;
        bool f = 0;//find pre[i-1]
        for (int j = 0; j < N; ++j) {
            if (post[j] == pre[i-1]) f = 1;
            if (post[j] == pre[i]) {
                idx = j;
                break;
            }
        }
        if (f) um[pre[i-1]]->left = node;
        else um[pre[i-1]]->right = node; 
    }
    return 0;
}