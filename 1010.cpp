#include<iostream>
#include<cstring>
using namespace std;
int d[31][31];
int tc;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> tc;
	while (tc--) {
		int n, m;
		memset(d, 0, sizeof(d));
		cin >> n >> m;
		for (int i = 0; i <= m; i++) d[1][i] = i;

		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = i; k <= j; k++) {
					d[i][j] += d[i - 1][k - 1];
				}
			}
		}
		cout << d[n][m] << "\n";
	}
	return 0;
}