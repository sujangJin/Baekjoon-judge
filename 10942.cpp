#include<iostream>
#include<vector>
using namespace std;
int d[2001][2001];
int go(const vector<int> &a, int st, int len) {
	if (len <= 0) return 1;
	if (len == 1) {
		if (d[st][len] != 0) return d[st][len];
		else d[st][len] = 1;
		return d[st][len];
	}
	if (d[st][len] != 0) return d[st][len];

	int last = st + (len - 1);
	if (a[st] != a[last]) {
		d[st][len] = -1;
		return d[st][len];
	}
	else {
		if (d[st][len] != 0) return d[st][len];
		d[st][len] = go(a, st + 1, len - 2);
		return d[st][len];
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - (i - 1); j++) {
			go(arr, i, j);
		}
	}
	int m; cin >> m;
	while (m--) {
		int st, ed;
		cin >> st >> ed;
		int l = ed - st + 1;
		
		if (d[st][l] == 1) puts("1");
		else puts("0");
	}
	return 0;
}