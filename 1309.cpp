#include<cstdio>
using namespace std;
int d[100001][3];
int n;
const int MOD = 9901;
int main()
{
	scanf("%d", &n);
	d[1][0] = d[1][1] = d[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i-1][0] + d[i - 1][1] + d[i - 1][2]) % MOD;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % MOD;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % MOD;
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += d[n][i];
		ans %= MOD;
	}
	printf("%d",ans);
	return 0;
}