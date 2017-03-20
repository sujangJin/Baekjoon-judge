#include <iostream>
const int MOD = 1e9 + 7;
using namespace std;
long long d[101][101][101];
int n, r, l;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> l >> r;
	d[1][1][1] = 1;
	d[2][1][2] = 1;
	d[2][2][1] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				long long tmp = 0;
				tmp += ((i - 2) * d[i - 1][j][k]) % MOD;
				tmp += d[i - 1][j - 1][k] % MOD;
				tmp += d[i - 1][j][k - 1] % MOD;
				d[i][j][k] = tmp % MOD;
			}
		}
	}
	printf("%d", d[n][l][r]);
	return 0;
}