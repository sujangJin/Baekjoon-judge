#include <iostream>
#include <queue>
using namespace std;
int n, m, aim_x, aim_y;
char a[51][51];
bool chk[51][51];
int dist[51][51];
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q, water;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') q.push({ i,j });
			else if (a[i][j] == '*') water.push({ i,j });
			else if (a[i][j] == 'D') { aim_x = i, aim_y = j; }
		}
	}
	
	while (!q.empty()) {
		int wsize = water.size();
		for (int idx = 0; idx < wsize; idx++) {
				pair<int, int> now_w = water.front();
				water.pop();
				for (int i = 0; i < 4; i++) {
					int next_wx = now_w.first + dx[i];
					int next_wy = now_w.second + dy[i];
					if (next_wx >= 0 && next_wx < n && next_wy >= 0 && next_wy < m) {
						if (a[next_wx][next_wy] == '.' && !chk[next_wx][next_wy]) {
							a[next_wx][next_wy] = '*';
							water.push({ next_wx,next_wy });
						}
					}
				}
		}
		int size = q.size();
		for (int idx = 0; idx < size; idx++) {
			pair<int, int> now = q.front();
			chk[now.first][now.second] = true;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = now.first + dx[i];
				int next_y = now.second + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
					if (!chk[next_x][next_y] && !dist[next_x][next_y] && (a[next_x][next_y] == '.' || a[next_x][next_y] == 'D')) {
						chk[next_x][next_y] = true;
						dist[next_x][next_y] = dist[now.first][now.second] + 1;
						q.push({ next_x, next_y });
					}
				}
			}
		}
	}
	if (chk[aim_x][aim_y]) {
		cout << dist[aim_x][aim_y];
	}
	else {
		cout << "KAKTUS";
	}
	return 0;
}