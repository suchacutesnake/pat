//1064 Complete Binary Search Tree
//Reference: https://blog.csdn.net/Haha_Sugar/article/details/124283299
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void traverse(int x,int N,vector<int>& v,vector<int>& in,int& k) {
    if (x > N) return;
    traverse(2*x, N,v,in,k);
    in[x] = v[k++];
    traverse(2*x+1, N,v,in,k);
}
int main() {
    int N;cin >> N;
    vector<int> v(N+1),in(N+1);
    v[0] = 0xcfcfcfcf;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int k = 1;
    traverse(1,N,v,in,k);
    for(int i = 1; i <= N; ++i) {
        cout<<in[i];
        if (i != N) cout<<' ';
    }
    return 0;
}