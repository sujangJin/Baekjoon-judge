#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int map[1001][1001];
int dist[1001][1001][11];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;

	dist[1][1][0] = 1;
	q.push(make_tuple(1, 1, 0));
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();
		if (x == m && y == n)
		{
			int ans = dist[m][n][0];
			for (int i = 1; i <= k; i++) {
				if (ans < dist[m][n][i]) ans = dist[m][n][i];
			}
			printf("%d", ans);
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int ncnt = cnt;
			if (map[nx][ny] == 1) ncnt++;
			if (nx >= 1 && ny >= 1 && nx <= m && ny <= n)
			{
				if (ncnt <= k && dist[nx][ny][ncnt] == 0) {
					dist[nx][ny][ncnt] = dist[x][y][cnt] + 1;
					q.push(make_tuple(nx, ny, ncnt));
				}
			}
		}
	}
	puts("-1");
	return 0;
}