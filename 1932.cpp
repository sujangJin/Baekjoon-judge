#include<cstdio>
#include<algorithm>
using namespace std;
int d[501][501];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d",&d[i][j]);
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] += max(d[i - 1][j], d[i - 1][j - 1]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[n][i]);
	}
	printf("%d",ans);
	return 0;
}