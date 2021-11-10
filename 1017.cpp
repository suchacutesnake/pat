//1017 Queueing at Bank (25 point(s))
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
class Customer {
public:
    //hour, minute, second, processing time
    int h, m, s, t;
    //arrive time, leave time
    int at, lt;
};
bool cmp(Customer c1, Customer c2) {return c1.at < c2.at;}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    //customer list
    std::vector<Customer> cl(N);
    for (auto& c : cl) {
        scanf("%d:%d:%d %d", &c.h, &c.m, &c.s, &c.t);
        c.at = c.h * 3600 + c.m * 60 + c.s;
    }
    sort(cl.begin(), cl.end(), cmp);
    
    //sum up waiting time, count customer processed
    double sum = 0, cnt = 0;
    //pq records the time of the next empty window
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    for (int i = 0; i < K; ++i) pq.push(3600 * 8);
    for (auto& c : cl) {
        if (c.at > 3600 * 17) break;
        ++cnt;
        //waiting time
        int wt = pq.top() - c.at;
        if (wt > 0) {
            sum += wt;
            c.lt = pq.top() + c.t * 60;
        } else c.lt = c.at + c.t * 60;
        //printf("at=%d, pq.top()=%d, lt=%d, wt=%d\n",c.at, pq.top(), c.lt, wt);
        pq.pop();
        pq.push(c.lt);
    }
    double avg = sum / 60 / cnt;
    printf("%.1lf", avg);
    return 0;
}