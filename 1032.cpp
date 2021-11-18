//1032 Sharing (25 point(s))
#include <iostream>
#include <vector>
struct Node {
    char ch;
    int next;
} nodes[100001];
int main() {
    int ad1, ad2, N;//address1 ,address2
    scanf("%d %d %d", &ad1, &ad2, &N);
    for (int i = 0; i < N; ++i) {
        int ad;
        scanf("%d", &ad);
        scanf(" %c %d", &(nodes[ad].ch), &(nodes[ad].next));
    }
    std::vector<int> w1, w2; //word1, word2
    while (ad1 != -1) {
        w1.emplace_back(ad1);
        ad1 = nodes[ad1].next;
    }
    while (ad2 != -1) {
        w2.emplace_back(ad2);
        ad2 = nodes[ad2].next;
    }
    int n1 = w1.size(), n2 = w2.size(), i;
    for (i = 1; n1 - i >= 0 && n2 - i >= 0; ++i) {
        if (w1[n1-i] != w2[n2-i]) break;
    }
    if (i == 1) printf("%d", -1);
    else printf("%05d", w1[n1 - i + 1]);
    return 0;
}