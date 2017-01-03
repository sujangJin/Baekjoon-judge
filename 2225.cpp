#include<cstdio>
using namespace std;
const int MOD = 1e9;
int n, k;
long long d[201][201];
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) d[i][1] = 1;
	for (int i = 2; i <= k; i++) d[1][i] = (d[1][i - 1] + 1) % MOD;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++)
			d[i][j] = (d[i][j - 1] + d[i - 1][j]) % MOD;

	printf("%lld\n", d[n][k]);

}