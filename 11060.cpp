#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int map[1001];
int d[1001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> map[i];
		d[i] = INF;
	}
	d[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = d[i];
		int size = map[i];
		while (size >= 1) {
			if (i + size <= n) d[i + size] = min(d[i + size], cnt + 1);
			size--;
		}
	}
	if (d[n] == INF) cout << -1;
	else cout << d[n];
	return 0;
}