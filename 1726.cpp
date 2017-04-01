#include<iostream>
#include<queue>
#include<tuple>
#define INF 987654321
using namespace std;

int m, n;
int map[101][101];
int dist[101][101][4];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int sy, sx, sd;
int ey, ex, ed;

int outrange(int x, int y) {
	return (y<0 || y>=n || x<0 || x>=m || map[x][y] != 0);
}

int rotate(int a, int b) {
	a++; b++;
	if (a == b) return 0;
	if (a == 1 && b == 2) return 2;
	if (a == 2 && b == 1) return 2;
	if (a == 3 && b == 4) return 2;
	if (a == 4 && b == 3) return 2;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			for (int k = 0; k < 4; k++) dist[i][j][k] = INF;
		}
	}
	cin >> sx >> sy >> sd;
	cin >> ex >> ey >> ed;

	sx--; sy--; sd--; ex--; ey--; ed--;

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sx, sy, sd));
	dist[sx][sy][sd] = 0;
	while (!q.empty()) {
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		int cdir = get<2>(q.front());
		q.pop();
		if (cx == ex && cy == ey) {
			cout << dist[cx][cy][cdir] + rotate(cdir, ed);
			break;
		}
		for (int dir = 0; dir < 4; dir++) {
			int rval = rotate(cdir, dir);
			int nx = cx;
			int ny = cy;
			for (int k = 1; k <= 3; k++) {
				nx += dx[dir];
				ny += dy[dir];
				if (outrange(nx, ny)) break;
				if (dist[cx][cy][cdir] + 1 + rval < dist[nx][ny][dir]) {
					q.push(make_tuple(nx, ny, dir));
					dist[nx][ny][dir] = dist[cx][cy][cdir] + 1 + rval;
				}
			}
		}
	}
	return 0;
}