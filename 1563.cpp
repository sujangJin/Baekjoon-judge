#include<cstdio>
const int MOD = 1e6;
int n, res;
int d[1001][3];
int main()
{
	scanf("%d",&n);
	d[0][1] = 1;
	d[1][0] = d[1][1] = d[1][2] = 1;
	d[2][0] = d[2][2] = 3;
	d[2][1] = 2;
	for (int i = 3; i <= n; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % MOD;
		d[i][1] = (d[i - 1][1] + d[i - 2][1] + d[i - 3][1]) % MOD;
		d[i][2] = (d[i - 2][0] + d[i - 2][1] + d[i - 1][0] + d[i - 1][1]) % MOD;
	}
	for (int i = 0; i < 3; i++) {
		res += d[n][i];
		res %= MOD;
	}
	printf("%d",res);
	return 0;
}