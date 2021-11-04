#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class TreeNode {
public:
    TreeNode(string n) {
        name = n;
    }
    string name;
    vector<string> v;
    int level;
};

//level -> level leaves
unordered_map<int, int> lc;

unordered_map<string, TreeNode*> mp;

int max_level = -1;

//determine levl, father level
void dl(TreeNode* node, int fl) {
    node->level = fl + 1;
    if (node->level > max_level) max_level = node->level;
    if (node->v.empty()) {
        //printf("empty  node->name=%s, node->level = %d\n",node->name.c_str(),node->level);
        ++lc[node->level];
        return;
    }
    for (auto& n:node->v) {
        //printf("mp[n]->name=%s, node->level = %d\n",mp[n]->name.c_str(),node->level);
        dl(mp[n], node->level);
    }
    
}
int main() {
    int N, M;
    cin >> N >> M;
    if (M == 0) {
        cout << N;
        return 0;
    }
    for (int i = 0; i < M; ++i) {
        string name;
        cin >> name;
        TreeNode* node = new TreeNode(name);
        mp[name] = node;
        //children number
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            string nn;
            cin >> nn;
            if (!mp.count(nn)) {
                TreeNode* nnode = new TreeNode(nn);
                mp[nn] = nnode;
            }
            node->v.push_back(nn);
        }
    }

    TreeNode* root = mp["01"];
    
    dl(root, 0);
    
    vector<int> res(max_level, 0);
    //printf("lcsize=%d, max_level=%d\n",lc.size(), max_level);
    for (int i = 0; i < max_level; ++i) {
        if (!lc.count(i+1)) res[i] = 0;
        else res[i] = lc[i+1];
    }
    for (int i = 0; i < max_level; ++i) {
        printf("%d", res[i]);
        if (i != max_level - 1) printf(" ");
    }
    //printf("endcase\n");
    return 0;
}