#include<iostream>
using namespace std;
int n, m;
int sx, sy, sdir;
int map[50][50], d[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int go(int x, int y, int dir, int cnt) {
	if (d[x][y] == -1) d[x][y] = cnt;

	dir = (dir + 3) % 4;
	int initial_dir = dir;
	bool ok = false;

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	do {
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (map[nx][ny] == 0 && d[nx][ny] == -1) {
				return go(nx, ny, dir, cnt + 1);
				ok = true;
				break;
			}
			else {
				dir = (dir + 3) % 4;
				nx = x + dx[dir];
				ny = y + dy[dir];
			}
		}
		else {
			dir = (dir + 3) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
	} while (dir != initial_dir);
	
	if (!ok) {
		while (1) {
			dir = (dir + 1) % 4;
			nx = x - dx[dir];
			ny = y - dy[dir];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 1) return cnt;
				else return go(nx, ny, dir, cnt);
			}
			else {
				return cnt;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	cin >> sx >> sy >> sdir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	cout << go(sx, sy, sdir, 1);
	return 0;
}