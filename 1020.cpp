//1020 Tree Traversals (25 point(s))
//build tree reference:
//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//Actually we don't have to build a tree for this question. Just simply recording 
//the level of each node is enough.
#include <iostream>
#include <vector>
#include <unordered_map>
int build_tree(std::unordered_map<int, std::vector<int> >& tree,
            std::vector<int>& in, std::vector<int>& post, std::unordered_map<int, int>& mp,
            //left inorder, right inorder, left postorder, right postorder index
            int li, int ri, int lp, int rp, int level) {
    if (lp > rp) return -1;
    int name = post[rp];
    if (!tree.count(name)) tree.insert({name, std::vector<int>(4)});
    tree[name][0] = name; //node name
    tree[name][3] = level + 1; //node level
    int mid = mp[name]; //index of node[0] in vector in
    //left subtree size, right subtree size
    int lss = std::max(mid - li, 0), rss = std::max(0, ri - mid);
    tree[name][1] = build_tree(tree, in, post, mp, li, mid - 1, lp, rp - rss - 1, level + 1); //node left child
    tree[name][2] = build_tree(tree, in, post, mp, mid + 1, ri, lp + lss, rp - 1, level + 1); //node right child
    return name;
}
void get_res(std::unordered_map<int, std::vector<int> >& tree,
            std::vector<std::vector<int> >& res, int name) {
    if (name < 0) return;
    if (res.size() <= tree[name][3]) res.resize(tree[name][3] + 1);
    res[tree[name][3]].push_back(tree[name][0]);
    get_res(tree, res, tree[name][1]); //traverse left subtree
    get_res(tree, res, tree[name][2]); //traverse right subtree
}
int main() {
    int N;
    std::cin >> N;
    std::vector<int> post(N), in(N);
    std::unordered_map<int, int> mp;
    for (int& x : post) std::cin >> x;
    for (int& x : in) std::cin >> x;
    for (int i = 0; i < N; ++i) mp[in[i]] = i;
    std::unordered_map<int, std::vector<int> > tree;
    int root = build_tree(tree, in, post, mp, 0, N - 1, 0, N - 1, 0);
    std::vector<std::vector<int> > res;
    get_res(tree, res, root);
    int cnt = 0;
    for (auto& v : res) for (int& x : v) {
        ++cnt;
        printf("%d", x);
        if (cnt != N) printf(" ");
    }
    return 0;
}
/*
N    7
post 2 3 1 5 7 6 4
in   1 2 3 4 5 6 7
      4
    1   6
     3 5 7
    2
*/