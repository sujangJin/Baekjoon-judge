#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001][1001];
int dist[1001][1001];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = max({ dist[i - 1][j], dist[i][j - 1],dist[i - 1][j - 1] }) + a[i][j];
		}
	}
	printf("%d",dist[n][m]);
	return 0;
}