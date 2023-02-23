//1066 Root of AVL Tree
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    Node *l, *r;
    int val;
};

//get height
int H(Node *node) {
    if (!node) return 0;
    return max(H(node->l), H(node->r)) + 1;
}

void rotate(Node *&node) {
    if (!node) return;
    if (abs(H(node->l) - H(node->r)) < 2) {
        rotate(node->l);
        rotate(node->r);
    } else {
        if (H(node->l) - H(node->r) == 2) {
            if (H(node->l->l) > H(node->l->r)) { //ll
                Node *n = node, *l = node->l;
                n->l = l->r;
                l->r = n;
                node = l;
            } else { //lr
                Node *n= node, *l = node->l, *lr = node->l->r;
                l->r = lr->l;
                n->l = lr->r;
                lr->l = l;
                lr->r = n;
                node = lr;
            }
        } 
        if (H(node->r) - H(node->l) == 2) {
            if (H(node->r->r) > H(node->r->l)) { //rr
                Node *n = node, *r = node->r;
                n->r = r->l;
                r->l = n;
                node = r;
            } else { //rl
                Node *n= node, *r = node->r, *rl = node->r->l;
                r->l = rl->r;
                n->r = rl->l;
                rl->r = r;
                rl->l = n;
                node = rl;
            }
        }
    }
}

void insert(Node *&node, int val) {
    if (node == nullptr) {
        node = new Node();
        node->val = val;
        return;
    }
    if (val > node->val) insert(node->r, val);
    else insert(node->l, val);
    rotate(node);
}

int main() {
    int N, x;
    cin >> N;
    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        insert(root, x);
    }
    printf("%d", root->val);
    return 0;
}