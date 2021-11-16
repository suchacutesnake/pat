/**2021.11.16 16:53 written by cutesnake
 * 1026 Table Tennis (30 point(s))
 * the following websites help you understand the question
 * https://blog.csdn.net/weixin_43047175/article/details/106976403
 * https://blog.csdn.net/qq_33231894/article/details/106948191
 * https://blog.csdn.net/qq_39115541/article/details/99673761
 **/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
class Players {
public:
    int arr_time = 0x3f3f3f3f;
    int serve_time = 0x3f3f3f3f;
    int play_time;
    double wait_time;
    int tag;
};
bool cmp2(Players& p1, Players& p2) {
    return p1.serve_time < p2.serve_time;
}
bool cmp1(Players& p1, Players& p2) {
    return p1.arr_time < p2.arr_time;
}
int main() {
    int N;
    std::cin >> N;
    std::vector<Players> total(N + 1);
    for (int i = 0; i < N; ++i) {
        int h, m, s, pt, tag;
        scanf("%d:%d:%d %d %d\n", &h, &m, &s, &pt, &tag);
        total[i].arr_time = h * 3600 + m * 60 + s;
        total[i].play_time = pt * 60 > 7200 ? 7200 : pt * 60;//2 points
        total[i].tag = tag;
    }
    int K, M;
    std::unordered_set<int> v_idx;
    std::cin >> K >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        std::cin >> x;
        v_idx.insert(x - 1); //indices minus by 1
    }
    //sort by arr_time
    sort(total.begin(), total.end(), cmp1);
    std::vector<int> table(K, 8 * 3600); //table[i]:next available time of the ith table
    std::vector<int> count(K, 0); //count served numbers of all tables
    std::vector<int> q; //waiting queue, stores the indices of waiting players
    int j = 0; //index of next available table
    int min_table_time = *std::min_element(table.begin(), table.end());
    for (int i = 0; i <= N; ++i) {
        //new player in queue
        q.emplace_back(i);
        //fulfilling the condition below, it seems that this new player could play at soon
        //but how about those people who had waited so long? Yes, we must let them play first.
        while (total[q.back()].arr_time >= min_table_time) {
            bool is_vip = 0;
            int kk = 0x3f3f3f3f;
            //this loop is to find if there are other tables available before the jth
            for (int m = 0; m < K; ++m) {
                if (total[q.front()].arr_time >= table[m]) {
                    if (kk == 0x3f3f3f3f) kk = m; //m is the smallest available table
                    if (!total[q.front()].tag) { //the front player in queue is not vip player
                        break;
                    } else { //the front player in queue is vip player
                        if (v_idx.count(m)) { //table m is vip table
                            kk = m; //m is the smallest available vip table
                            break;
                        }
                    }
                }
            }
            if (kk != 0x3f3f3f3f) j = kk;
            //j is a vip table
            if (v_idx.count(j)) {
                //find vip in the queue
                for (int k = 0; k < q.size(); ++k) {
                    Players& p = total[q[k]];
                    if (p.tag == 1) { //vip go to vip table
                        p.serve_time = std::max(table[j], p.arr_time);
                        if (p.serve_time >= 21 * 3600) break;
                        ++count[j];
                        p.wait_time = std::max(p.serve_time - p.arr_time, 0);
                        table[j] = p.serve_time + p.play_time;
                        q.erase(q.begin() + k);
                        is_vip = 1;
                        break;
                    }
                }
            }
            if (!is_vip) { //no vip in queue, queue front go to next table
                total[q.front()].serve_time = std::max(table[j], total[q.front()].arr_time);
                if (total[q.front()].serve_time >= 21 * 3600) break;
                ++count[j];
                total[q.front()].wait_time = std::max(total[q.front()].serve_time - total[q.front()].arr_time, 0);
                table[j] = total[q.front()].serve_time + total[q.front()].play_time;
                q.erase(q.begin());
            }
            min_table_time = *std::min_element(table.begin(), table.end());
            for (int m = 0; m < K; ++m) if (table[m] == min_table_time) {j=m;break;}
            if (q.empty()) break;
        }
        if (min_table_time >= 21 * 3600) break;
    }
    total.pop_back(); //erase the arr_time=0x3f3f3f3f
    std::sort(total.begin(), total.end(), cmp2);
    for (Players& p : total) {
        if (p.serve_time >= 21 * 3600) break;
        int h = p.arr_time / 3600, m = p.arr_time % 3600 / 60, s = p.arr_time % 60;
        int hh = p.serve_time / 3600, mm = p.serve_time % 3600 / 60, ss = p.serve_time % 60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %.0lf\n", h, m, s, hh, mm, ss, round(p.wait_time / 60));//rounds up
    }
    printf("%d", count[0]);
    for (int i = 1; i < K; ++i) printf(" %d", count[i]);
    return 0;
}