//7-2 Merging Linked Lists (25 point(s))
//12points
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Node {
public:
    int val = 0;
    int next = -1;
} nodes[100010];
int main() {
    int fl1, fl2, N;
    cin >> fl1 >> fl2 >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        nodes[a].val = b;
        nodes[a].next = c;
    }
    int m = 1, n = 1, p1 = fl1, p2 = fl2;
    vector<int> v1({p1}), v2({p2}), vres;
    while (nodes[p1].next != -1) {
        ++m;
        p1 = nodes[p1].next;
        v1.push_back(p1);
    }
    while (nodes[p2].next != -1) {
        ++n;
        p2 = nodes[p2].next;
        v2.push_back(p2);
    }
    if (m < n) { //list1 shorter than list2
        int n2 = v2.size(), n1 = v1.size(), p1 = 0;
        reverse(v1.begin(), v1.end());
        for (int i = 0; i < n2; ++i) {
            if (i != 0 && !(i % 2)) {
                if (p1 < n1) vres.push_back(v1[p1++]);
            }
            vres.push_back(v2[i]);
        }
    } else {
        int n1 = v2.size(), n2 = v1.size(), p2 = 0;
        reverse(v2.begin(), v2.end());
        for (int i = 0; i < n1; ++i) {
            if (i != 0 && !(i % 2)) {
                if (p2 < n2) vres.push_back(v2[p2++]);
            }
            vres.push_back(v1[i]);
        }
    }
    for (int i = 0; i < vres.size() - 1; ++i) {
        printf("%05d %d %05d\n", vres[i], nodes[vres[i]], vres[i+1]);
    }
    printf("%05d %d %d\n", vres.back(), nodes[vres.back()], -1);
    return 0;
}