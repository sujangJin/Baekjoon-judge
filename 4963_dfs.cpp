#include<iostream>
#include<cstring>
using namespace std;
const int dx[] = { 1,-1,0,0,-1,1,-1,1 };
const int dy[] = { 0,0,1,-1,-1,1,1,-1 };
int map[51][51];
bool c[51][51];
int w, h;
void dfs(int x, int y, int& cnt) {
	c[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= w && ny >= 1 && ny <= h) {
			if (!c[nx][ny] && map[nx][ny] == 1) {
				dfs(nx, ny, cnt);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	while (1) {
		memset(map, 0, sizeof(map));
		memset(c, false, sizeof(c));
		cin >> h >> w;
		if (w == 0 && h == 0) break;

		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (!c[i][j] && map[i][j] == 1) {
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}