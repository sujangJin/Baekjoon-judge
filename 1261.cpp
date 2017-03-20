#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100][100];
int dist[100][100];
bool chk[100][100];
int x, y;
int main()
{
	scanf("%d %d", &y, &x);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	memset(dist, -1, sizeof(a));
	queue<pair<int, int>> q;
	dist[0][0] = 0;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int> now = q.front();
		chk[now.first][now.second] = true;
		q.pop();
		int dx[] = { 1,-1,0,0 };
		int dy[] = { 0,0,1,-1 };
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
				if (!chk[nx][ny] || dist[nx][ny] >= dist[now.first][now.second] + 1) {
					if (a[nx][ny] == 1) {
						chk[nx][ny] = true;
						q.push({ nx,ny });
						if (dist[nx][ny] == -1) dist[nx][ny] = dist[now.first][now.second] + 1;
						else dist[nx][ny] = min(dist[nx][ny], dist[now.first][now.second] + 1);
					}
					else if (a[nx][ny] == 0) {
						chk[nx][ny] = true;
						q.push({ nx,ny });
						if (dist[nx][ny] == -1) dist[nx][ny] = dist[now.first][now.second];
						else dist[nx][ny] = min(dist[nx][ny], dist[now.first][now.second]);
					}
				}

			}
		}
	}
	printf("%d", dist[x - 1][y - 1]);
	return 0;
}