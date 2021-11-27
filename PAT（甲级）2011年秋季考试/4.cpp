//1014 Waiting in Line (30 point(s))
#include <iostream>
#include <vector>
int main() {
    int N, M, K, Q;
    std::cin >> N >> M >> K >> Q;
    //processing time, done time
    std::vector<int> pt(K), dt(K + 1);
    for (int i = 0; i < K; ++i) std::cin >> pt[i];
    //window : customers before the yellow line
    std::vector<std::vector<int> > window(N, std::vector<int>(M));
    std::vector<int> win_time(N, 0);
    //process all customers
    for (int i = 0; i < K; ++i) {
        //idx is the index of window with shortest line
        int time = 0x3f3f3f3f, idx = -1;
        //should new customer line after window[j]?
        for (int j = 0; j < N; ++j) {
            int minustime = 0, n = window[j].size();
            //full before yellow line
            if (n >= M)
            //compare the current processing time over all windows, that is,
            //last customer ending time minus (M - 1) customers' proccess time
            for (int k = 1; k < M; ++k) minustime += pt[window[j][n - k]];
            if (win_time[j] - minustime < time) {
                time = win_time[j] - minustime;
                idx = j;
            }
        }
        window[idx].push_back(i);
        win_time[idx] += pt[i];
        //recall that dt[0] is the done time of customer 1
        dt[i+1] = win_time[idx];
    }
    for (int i = 0; i < Q; ++i) {
        int cus; //customer
        std::cin >> cus;
        //why minus pt[cus]? Because if the customer can start (not end)
        //processing before 17:00, then this customer can be processed
        if (dt[cus] - pt[cus-1] >= 540) printf("Sorry\n");
        else printf("%.2d:%.2d\n", dt[cus] / 60 + 8, dt[cus] % 60);
    }
    return 0;
}