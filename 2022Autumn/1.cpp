#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, h;
	cin >> n >> h;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int pos = 0x3f3f3f3f, pop = 0;
	for (int i = n-1; i >= 0; --i) {
		int sum = 0;
		for (int j = i; j >= 0; --j) {
			if (v[i] - h <= v[j]) ++sum;
			else break;
		}
		if (sum >= pop) {
			pos = v[i] - h;
			pop = sum;
		}
	}
	printf("%d %d", pos, pop);
	return 0;
}