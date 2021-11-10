//1018 Public Bike Management (30 point(s))
//case5,7 : https://blog.csdn.net/m0_50796573/article/details/108566011
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstdlib>
//arguments of helper:
//mp, visited station, station, result, Sp, minimum bike count, minimum path length
//current station, current path length
void helper(std::unordered_map<int, std::vector<std::pair<int, int> > >& mp,
            std::vector<int>& vis, std::vector<int>& station,
            std::vector<std::vector<int> >& res, int& Sp, int& mpl, int cpl) {
    if (cpl > mpl) return;
    int cs = vis.back();
    int n = vis.size();
    for (int i = 0; i < n - 1; ++i) if (vis[i] == cs) return;
    if (cs == Sp) {
        if (cpl < mpl) {
            res.clear();
            res.push_back(vis);
            mpl = cpl;
        } else res.push_back(vis);
        return;
    }
    for (auto& p : mp[cs]) {
        vis.push_back(p.first);
        helper(mp, vis, station, res, Sp, mpl, cpl + p.second);
        vis.pop_back();
    }
}
int main() {
    int Cmax, N, Sp, M;
    std::cin >> Cmax >> N >> Sp >> M;
    int perfect = Cmax >> 1;
    std::vector<int> station(N + 1);
    for (int i = 1; i <= N; ++i) std::cin >> station[i];
    std::unordered_map<int, std::vector<std::pair<int, int> > > mp;
    for (int i = 0; i < M; ++i) {
        int Tij, Si, Sj;
        std::cin >> Si >> Sj >> Tij;
        mp[Si].push_back({Sj, Tij});
        mp[Sj].push_back({Si, Tij});
    }

    //find shortest path
    std::vector<std::vector<int> > res; //vector of shortest path
    std::vector<int> vis({0}); //visited station
    int mpl = 0x3f3f3f3f; //minimum path length
    helper(mp, vis, station, res, Sp, mpl, 0);

    //determine PBMC bike count and right res index
    int min_send = 0x3f3f3f3f, min_receive = 0x3f3f3f3f, idx = -1;
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        int send = 0, receive = 0, carry = 0;
        for (int j = 1, m = res[i].size(); j < m; ++j) {
            carry += station[res[i][j]] - perfect;
            if (carry < 0) {
                send -= carry;
                carry = 0;
            } else if (carry > Cmax) {
                receive += carry - Cmax;
                carry = Cmax;
            }
        }
        receive += carry;
        if (send < min_send) {
            idx = i;
            min_send = send;
            min_receive = receive;
        } else if (send == min_send) {
            if (receive < min_receive) {
                min_receive = receive;
                idx = i;
            }
        }
    }

    //printing session
    printf("%d ", min_send == 0x3f3f3f3f ? 0 : min_send);
    for (int i = 0, nn = res[idx].size(); i < nn; ++i) {
        printf("%d", res[idx][i]);
        if (i != nn - 1) printf("->");
    }
    //case 2,5~9: min_receive != 0
    printf(" %d", min_receive == 0x3f3f3f3f ? 0 : min_receive);
    return 0;
}