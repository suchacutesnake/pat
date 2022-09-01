//1056 Mice and Rice
//test case
//19 25 57 / 22 10 3 / 56 18 37 / 0 46
//57 22 56 / 46
//57 46
//57
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
int Np, Ng, level = 0;
map<int, vector<int> > mp;
vector<int> win(vector<int>& v, vector<int>& t) {
    //printf("\nround:%d\nwinners:",level);
    int n = t.size();
    vector<int> ret;
    for (int i = 0; i < n; i += Ng) {
        int maxNum = v[t[i]], m = i;//index of winner
        //find max
        for (int j = 0; j < Ng && i+j < n; ++j) if (v[t[i+j]] > maxNum)  {
            m = i+j;
            maxNum = v[t[i+j]];
        }
        //put winner to the next round
        ret.push_back(t[m]);
        //printf("%d ",t[m]);
        for (int j = 0; j < Ng && i+j < n; ++j) if (i+j != m) {
            mp[level].push_back(t[i+j]);
        }
    }
    ++level;
    return ret;
}
int main() {
    //input
    cin >> Np >> Ng;
    vector<int> v(Np), o(Np);
    for (int i = 0; i < Np; ++i) cin >> v[i];
    for (int i = 0; i < Np; ++i) cin >> o[i]; //order
    //simulate
    vector<vector<int> > res;
    vector<int> t = o;//index
    while (t.size() != 1) {
        vector<int> nwin = win(v, t);//new winners
        t = nwin;
    }
    mp[++level].push_back(t.front());
    //determine rank
    int cnt = 1;
    unordered_map<int, int> um;
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        int floor = cnt;
        for (int x : it->second) {
            um[x] = floor;
            ++cnt;
        }
    }
    //print
    for (int i = 0; i < Np; ++i) {
        printf("%d", um[i]);
        if (i != Np - 1) printf(" ");
    }
    return 0;
}

//interesting fact: the compiler optimized the map mp I used... How did it manage to do it???