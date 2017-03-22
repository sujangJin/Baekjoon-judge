#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int map[101][101][101];
int dist[101][101][101];
bool chk[101][101][101];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int m, n, h; 
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) q.push(tie(i, j, k));
			}
		}
	}
	
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		if (chk[x][y][z]) continue;
		chk[x][y][z] = true;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h) {
				if (!chk[nx][ny][nz] && map[nx][ny][nz] == 0) {
					dist[nx][ny][nz] = dist[x][y][z] + 1;
					map[nx][ny][nz] = 1;
					q.push(tie(nx, ny, nz));
				}
			}
		}
	}
	
	int ans = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j][k] == 1) {
					if (ans < dist[i][j][k]) ans = dist[i][j][k];
				}
				else if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}