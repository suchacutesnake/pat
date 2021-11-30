//1043 Is It a Binary Search Tree (25 point(s))
#include <iostream>
#include <vector>
using namespace std;
bool mirror = 0;
int nodeCNT = 0;
struct Node {
    Node *left = nullptr, *right = nullptr;
    int val;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
Node* buildBST(int l, int r, const vector<int>& input) {
    if (l >= r) return nullptr;
    Node* node = new Node(input[l]);
    ++nodeCNT;
    int sub_root = l + 1;
    if (sub_root >= r) return node;
    if (!mirror) {
        while (sub_root < r && input[sub_root] < node->val) sub_root++;
        int checkRight = sub_root;
        while (checkRight < r) if (input[checkRight++] < node->val) return node;
    }
    else {
        while (sub_root < r && input[sub_root] >= node->val) sub_root++;
        int checkRight = sub_root;
        while (checkRight < r) if (input[checkRight++] >= node->val) return node;
    }
    node->left = buildBST(l + 1, sub_root, input);
    node->right = buildBST(sub_root, r, input);
    return node;
}
void printPostOrder(Node* node, vector<int>& output) {
    if (!node) return;
    printPostOrder(node->left, output);
    printPostOrder(node->right, output);
    output.emplace_back(node->val);
}

int main() {
    int N;
    cin >> N;
    vector<int> input(N), output, inorder;
    for (int i = 0; i < N; ++i) cin >> input[i];
    Node* root = buildBST(0, N, input);
    if (nodeCNT != N) {nodeCNT = 0; mirror = 1;root = buildBST(0, N, input);}
    if (nodeCNT != N) {cout << "NO"; return 0;}
    if (!mirror) printPostOrder(root, output);
    else printPostOrder(root, output);
    printf("YES\n");
    cout << output[0];
    for (int i = 1; i < N; ++i) printf(" %d", output[i]);
    return 0;
}