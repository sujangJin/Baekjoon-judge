#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a[500][500];
int d[500][500];
int n;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool inRange(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int find(int x, int y) {
	if (d[x][y] == 0) {
		d[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (inRange(nx, ny) && a[nx][ny] > a[x][y]) {
				d[x][y] = max(d[x][y], find(nx, ny) + 1);
			}
		}
	}
	return d[x][y];
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d",&a[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, find(i, j));
		}
	}
	printf("%d",ans);
	return 0;
}