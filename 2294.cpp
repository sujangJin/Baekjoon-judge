#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		coin.push_back(val);
	}

	for (int i = 0; i <= 10000; i++) d[i] = 10001;
	d[0] = 0;

	for (int i = 0; i<=k; i++) {
		for (int j = 0; j<coin.size(); j++) {
			if (i + coin[j] <= k) d[i + coin[j]] = min(d[i + coin[j]], d[i] + 1);
		}
	}
	if (d[k] == 10001) cout << -1;
	else cout << d[k];
	return 0;
}