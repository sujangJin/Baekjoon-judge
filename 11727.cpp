#include<cstdio>
using namespace std;
const int MOD = 10007;
int T, d[1001] = { 1, 1, };
int tile2(int n)
{
	if (d[n]) return d[n];
	else{
		d[n] = (tile2(n - 1) + 2 * tile2(n - 2)) % MOD;
		return d[n];
	}
}
int main()
{
	scanf("%d", &T);
	if (T > 0)
		printf("%d", tile2(T));
	return 0;
}