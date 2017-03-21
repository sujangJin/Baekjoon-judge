#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int d[501][501], s[501];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n + 1);
		memset(d, 0, sizeof(d));
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i - 1; j >= 1; j--) {
				d[j][i] = 5e8;
				for (int k = j; k <= i; k++) {
					if (d[j][i] > d[j][k] + d[k + 1][i]) d[j][i] = d[j][k] + d[k + 1][i];
				}
				d[j][i] += s[i] - s[j - 1];
			}
		}
		cout << d[1][n] << '\n';
	}
	return 0;
}